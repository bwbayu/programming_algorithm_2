#include <stdio.h>

/*Saya Bayu Wicaksono mengerjakan UAS dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int indeks; // deklarasi variabel global untuk index karakter
char cc;    // deklarasi variabel global untuk karakter

void start(char str[]); // prosedur untuk memulai pembacaan pita
int eop();              // fungsi untuk mengecek simbol akhir pita
void inc(char str[]);   // prosedur untuk memajukan pembacaan pita
char getcc();           // fungsi untuk mengembalikan nilai karakter saat ini