#include <stdio.h>
#include <string.h>

/*Saya Bayu Wicaksono mengerjakan UTS dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

typedef struct{
	char nama[100];
	int harga, sign;
	double kalori, lemak, t;
}minyak;//tipe bungkusan untuk data minyak

void insertion(int x, minyak data[5][51], int n[5]);//prosedur untuk sorting dengan metode sorting insertion secara ascending
void selection(int x, minyak data[5][51], int n[5]);//prosedur untuk sorting dengan metode sorting selection secara ascending
void bubble(int x, minyak data[5][51], int n[5]);//prosedur untuk sorting dengan metode sorting bubble secara ascending
void quick(int x, minyak data[5][51], int n[5], int left, int right);//prosedur untuk sorting dengan metode sorting quick secara ascending
void merge(int x, int y, int z, minyak data[5][51], int n[5]);//prosedur untuk menyatukan 2 array secara ascending
void print(int x, minyak data[5][51], int n[5]);//prosedur untuk menampilkan isi array berdasarkan supplier
void print1(int x, minyak data[5][51], int n[5]);//prosedur untuk menampilkan isi array setelah di sorting dan di merge