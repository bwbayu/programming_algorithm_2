#include <stdio.h>

/*Saya Bayu Wicaksono mengerjakan UAS dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int idx,                            // variabel untuk index pita
    length;                         // variabel untuk panjang kata
char cw[501];                       // variabel untuk menampung kata
int eop(char str[]);                // fungsi untuk memeriksa akhir dari pita
void start(char str[]);             // prosedur untuk memulai pembacaan pita
void inc(char str[]);               // prosedur untuk memajukan kata
char *getcw();                      // fungsi untuk mendapatkan kata saat ini
void group(char str[], char src[]); // prosedur untuk mengecek string yang dicari ada atau tidak