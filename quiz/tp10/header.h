#include <stdio.h>
#include <string.h>

/*Saya Bayu Wicaksono mengerjakan TP10 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

// tipe terstruktur untuk pengelompokkan data
typedef struct
{
    char tkata[101][101];
} kelkata;

int idx,                                    // untuk index karakter pita
    length,                                 // untuk menampung panjang kata
    indeks[3];                              // untuk menampung banyak data tiap kelompok
char cw[101];                               // untuk menampung kata
void start(char str[], int *sign, char cx); // prosedur untuk memulai pembacaan pita
int eop(char str[]);                        // fungsi untuk memeriksa akhir dari proses
void inc(char str[], int *sign, char cx);   // prosedur untuk memajukan kata
int getlen();                               // fungsi untuk mendapatkan panjang kata saat ini
char *getcw();                              // fungsi untuk mendapatkan kata saat ini
void kelompok(int sign, kelkata kata[51]);  // prosedur untuk pengelompokkan kata
int getidx(int tipe);                       // fungsi untuk mendapatkan banyak data suatu kelompok
void sort(int n, kelkata kata[n]);          // prosedur untuk mengurutkan secara ascending