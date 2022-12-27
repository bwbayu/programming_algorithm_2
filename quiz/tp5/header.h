#include <stdio.h>
#include <string.h>

/*Saya Bayu Wicaksono mengerjakan TP5 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

typedef struct{
	double jumlah, berat, kalori;
	char nama[50];
	int spasi1, spasi2;
}makanan;//tipe bungkusan untuk data

void spasistr(int n, makanan m[n]);//prosedur untuk mencari spasi tiap data antara nama makanan dan jumlah kalori
void spasinum(int n, makanan m[n]);//prosedur untuk mencari spasi tiap data antara jumlah kalori dan berat
void bubbleasc(int n, makanan m[n]);//prosedur sorting menggunakan bubble sort dengan urutan ascending
void bubbledesc(int n, makanan m[n]);//prosedur sorting menggunakan bubble sort dengan urutan descending
void quickasc(makanan m[], int l, int r);//prosedur sorting menggunakan quick sort dengan urutan ascending
void quickdesc(makanan m[], int l, int r);//prosedur sorting menggunakan quick sort dengan urutan descending
void print(int n, makanan m[n]);//prosedur untuk menampilkan data