/*Saya Bayu Wicaksono mengerjakan evaluasi 2 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include <stdio.h>
#include <string.h>
// deklarasi tipe struct untuk menampung data
typedef struct
{
    char nama[151], status[151], harga[151];
} barang;

int idx,          // variabel untuk index pita
    length;       // variabel untuk panjang kata
char w[151];      // variabel untuk menampung kata
barang data[101]; // deklarasi tipe struct untuk menampung data barang
int ndata;        // variabel untuk menampung banyak data dalam tipe struct
barang temp;      // variabel untuk menampung masukan user

int eop(char str[]);             // fungsi untuk mengecek eop pita
void start(char str[]);          // prosedur untuk memulai pembacaan pita
void inc(char str[]);            // prosedur untuk memajukan pembacaan pita
char *getkata();                 // fungsi untuk mendapatkan kata saat ini
int cari(char src[], int *cidx); // fungsi untuk mencari nama barang masukan user di tipe struct
void insert();                   // prosedur untuk memasukkan data masukan user ke tipe struct
void readquery(char str[]);      // prosedur untuk pembacaan pita
int maxstr(char arr[101][151]);  // fungsi untuk mencari string terpanjang suatu kolom
void garis(int total);           // prosedur untuk menampilkan garis tabel
void spasi(int space);           // prosedur untuk menampilkan spasi
void tampil();                   // prosedur untuk menampilkan output