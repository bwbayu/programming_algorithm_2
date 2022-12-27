#include <stdio.h>

/*Saya Bayu Wicaksono mengerjakan kuis dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

typedef struct{//bungkusan untuk pembilang dan penyebut
	int pembilang, penyebut;
}matrix;
void inputan(int b, int k, matrix m[b][k]);//prosedur untuk inputan
void twomat(int b1, int k1, matrix m1[b1][k1], int b2, int k2, matrix m2[b2][k2], int p1, int p2);//prosedur untuk memasukkan matrix kecil ke matrix besar