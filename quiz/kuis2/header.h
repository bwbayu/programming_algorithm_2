#include <stdio.h>
#include <string.h>

/*Saya Bayu Wicaksono mengerjakan kuis 2 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

typedef struct
{
    char nama[100], tempat[100];
    int harga, kalori;
} makanan; // tipe terstruktur untuk data

void sortasc(int n, makanan data[n]);           // prosedur untuk sorting ascending
void sortdesc(int n, makanan data[n]);          // prosedur untuk sorting descending
void binary1(int cari, int n, makanan data[n]); // prosedur untuk binary search yang di sorting ascending
void binary2(int cari, int n, makanan data[n]); // prosedur untuk binary search yang di sorting descending