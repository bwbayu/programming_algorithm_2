#include <stdio.h>
#include <string.h>

/*Saya Bayu Wicaksono mengerjakan TP6 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

typedef struct{
	int total;
	char nama[100];
}daftar;//tipe bungkusan untuk nama makanan dan total harga

void insertionasc(int x, int n[5], daftar data[][51]);//prosedur untuk sorting dengan metode insertion secara ascending
void insertiondesc(int x, int n[5], daftar data[][51]);//prosedur untuk sorting dengan metode insertion secara descending
void selectionasc(int x, int n[5], daftar data[][51]);//prosedur untuk sorting dengan metode selection secara ascending
void selectiondesc(int x, int n[5], daftar data[][51]);//prosedur untuk sorting dengan metode selection secara descending
void bubbleasc(int x, int n[5], daftar data[][51]);//prosedur untuk sorting dengan metode bubble secara ascending
void bubbledesc(int x, int n[5], daftar data[][51]);//prosedur untuk sorting dengan metode bubble secara descending
void quickasc(int x, daftar data[][51], int l, int r);//prosedur untuk sorting dengan metode quick secara ascending
void quickdesc(int x, daftar data[][51], int l, int r);//prosedur untuk sorting dengan metode quick secara descending
void mergeasc(int x, int y, int z, int n[5], daftar data[][51]);//prosedur untuk menyatukan 2 array secara ascending
void mergedesc(int x, int y, int z, int n[5], daftar data[][51]);//prosedur untuk menyatukan 2 array secara descending
void print(int x, int n[5], daftar data[][51]);//prosedur untuk menampilkan array