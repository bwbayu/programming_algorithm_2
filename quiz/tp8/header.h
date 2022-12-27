#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Saya Bayu Wicaksono mengerjakan TP8 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

typedef struct
{
    char id[10], nama[101], sutradara[51], genre[51], bioskop[51];
} film; // tipe data terstruktur untuk menyimpan data

int read(char string[101], film data[51]);                   // fungsi untuk membaca file yang isinya 2 data
int read1(char string[101], film data[51]);                  // fungsi untuk membaca file yg isinya 4 data
void write(char str[51], int n, film data[51]);              // prosedur untuk menyalin file yg isinya 2 data
void write1(char str[51], int n, film data[51]);             // prosedur untuk menyalin file yg isinya 4 data
int maxstr(int n, char arr[51][101]);                        // fungsi untuk menemukan string terpanjang pada suatu kolom
void garis(int totalspasi);                                  // prosedur untuk menampilkan garis
void spasi(int spasitabel, char str[101]);                   // prosedur untuk menampilkan spasi
void print(int max[4], int total, film data[51], int bdata); // prosedur untuk menampilkan isi data dari file ListFilmFinal
void isimenu1();                                             // prosedur untuk mempersiapkan tabel yang akan diisi oleh data dari file ListFilmFinal
void listfilmfinal();                                        // prosedur untuk mengganti semua id dalam file ListFilm dan menyalinnya di file ListFilmFinal
void sort(int kiri, int kanan, film data[51]);               // prosedur untuk mengurutkan data yang ada di dalam tipe terstruktur
void cari(char id[10], char str[51]);                        // prosedur untuk mencari suatu data dari id masukan user pada file tertentu
void listmenu2();                                            // prosedur untuk menampilkan list menu ketika ingin mencari data
char cek(char temp[100], int n, film data[51]);              // fungsi untuk memeriksa id agar tidak terjadi redundansi
void appends(int n, film data[51]);                          // prosedur untuk menambahkan data ke file sutradara
void appendg(int n, film data[51]);                          // prosedur untuk menambahkan data ke file genre
void appendb(int n, film data[51]);                          // prosedur untuk menambahkan data ke file bioskop
void listmenu3();                                            // prosedur untuk menampilkan list menu ketika ingin menambahkan data
