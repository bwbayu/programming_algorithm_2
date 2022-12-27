#include <stdio.h>
#include <string.h>

/*Saya Bayu Wicaksono mengerjakan evaluasi 1 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

typedef struct{
	int nilai;
	char nama[51], nim[11];
}mahasiswa;//tipe data bungkusan untuk menampung data mahasiswa

void selectionasc(int x, int n[7], mahasiswa data[][51]);//prosedur untuk sorting ascending
void selectiondesc(int x, int n[7], mahasiswa data[][51]);//prosedur untuk sorting descending
void mergeasc(int x, int y, int z, int n[7], mahasiswa data[][51]);//prosedur untuk menyatukan 2 buah array secara ascending
void bagi(int x, int y, int z, int n[7], mahasiswa data[][51]);//prosedur untuk membagi array menjadi 2 buah array
void print(int x, int n[7], mahasiswa data[][51]);//prosedur untuk output