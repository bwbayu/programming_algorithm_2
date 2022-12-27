#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Saya Bayu Wicaksono mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
// Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
// melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

// tipe terstruktur untuk menampung data dari file .dat
typedef struct
{
    // file user
    char id_user[10], username[100], level[10];
    // file karakter
    char id_char[10], job_char[50], skill[100];
} game;

// deklarasi variabel
int idx,             // variabel global untuk index pita
    length;          // variabel global untuk panjang kata
char w[51];          // variabel global untuk kata dalam pita
int nuser;           // variabel global untuk banyak data dalam file user
int nchar;           // variabel global untuk banyak data dalam file character
game user[501];      // deklarasi tipe struct untuk menampung data dari file user
game character[501]; // deklarasi tipe struct untuk menampung data dari file character
game edata;          // deklarasi tipe struct untuk menampung data dari masukan user
game datagame[501];  // deklarasi tipe struct untuk menampung data dari hasil join antara file user dan character

// prosedur & fungsi untuk membaca data dari file dan menulis data ke file
// fungsi untuk membaca data dari file
int readuser(char file[]);
int readchar(char file[]);
// prosedur untuk menulis data ke file
void writeuser(char file[]);
void writechar(char file[]);

// prosedur & fungsi untuk proses pembacaan pita dengan mesin kata
int eop(char str[]);    // fungsi untuk cek eop pita
void start(char str[]); // prosedur untuk memulai pembacaan pita
void inc(char str[]);   // prosedur untuk memajukan pembacaan pita
char *getkata();        // fungsi untuk mendapatkan kata saat ini

// prosedur & fungsi untuk dbms (entry, ubah, hapus, join)
// fungsi untuk mencari data masukan user di dalam file
int cariuser(char src[], int sum, int *cidx);
int carichar(char src[], int sum, int *cidx);
// prosedur untuk menambahkan data masukan user ke dalam file
void entryuser();
void entrychar();
// prosedur untuk mengubah data di dalam file
void updateuser(int x);
void updatechar(int x);
// prosedur untuk menghapus data di dalam file
void deluser(int x);
void delchar(int x);

// prosedur & fungsi untuk pembacaan query dan menampilkan hasilnya ke cmd
// query untuk file user
void pentryuser(char str[]);
void pupdateuser(char str[], int cidx);
void pdeluser(char str[], int cidx);
// query untuk file character
void pentrychar(char str[]);
void pupdatechar(char str[], int cidx);
void pdelchar(char str[], int cidx);

// prosedur dan fungsi untuk menampilkan data dari file user/character/join
int maxstr(char arr[501][101]); // fungsi untuk mencari string terpanjang dalam suatu kolom
// prosedur untuk tampilan tabel
void garis(int tot);
void spasi(int scol);
void batas(int max[], int bdata);
// prosedur untuk menampilkan file
void tampiluser();
void tampilchar();
// prosedur untuk join tabel dan menampilkan tabel join
void join();
void tampiljoin();
// prosedur proses pembacaan query
void readquery(char str[]);

// fungsi untuk mengecek eop query
int eopdbms(char str[]);