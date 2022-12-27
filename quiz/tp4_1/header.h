#include <stdio.h>
#include <string.h>

/*Saya Bayu Wicaksono mengerjakan TP4 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

typedef struct{ //tipe bungkusan yang berisi durasi lagu, judul lagu
	int min, sec, tdur;
	char judul[100];
}song;
int total(int n, song lagu[n]);//fungsi untuk mengubah durasi waktu yang berbentuk menit detik menjadi detik
void insertionstrasc(int n, song lagu[n]);//prosedur untuk data yang di sorting dengan metode insertion secara ascending dan patokan sortingnya berdasarkan judul
void insertionstrdesc(int n, song lagu[n]);//prosedur untuk data yang di sorting dengan metode insertion secara descending dan patokan sortingnya berdasarkan judul
void insertionintasc(int n, song lagu[n]);//prosedur untuk data yang di sorting dengan metode insertion secara ascending dan patokan sortingnya berdasarkan durasi
void insertionintdesc(int n, song lagu[n]);//prosedur untuk data yang di sorting dengan metode insertion secara descending dan patokan sortingnya berdasarkan durasi
void selectionstrasc(int n, song lagu[n]);//prosedur untuk data yang di sorting dengan metode selection secara ascending dan patokan sortingnya berdasarkan judul
void selectionstrdesc(int n, song lagu[n]);//prosedur untuk data yang di sorting dengan metode selection secara descending dan patokan sortingnya berdasarkan judul
void selectionintasc(int n, song lagu[n]);//prosedur untuk data yang di sorting dengan metode selection secara ascending dan patokan sortingnya berdasarkan durasi
void selectionintdesc(int n, song lagu[n]);//prosedur untuk data yang di sorting dengan metode selection secara descending dan patokan sortingnya berdasarkan durasi
void print(int n, song lagu[n]);//prosedur untuk keluaran