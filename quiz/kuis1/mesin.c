#include "header.h"

/*Saya Bayu Wicaksono mengerjakan kuis dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

//prosedur untuk inputan
void inputan(int b, int k, matrix m[b][k]){
	int i, j;
	for(i = 0; i < b; i++){
		for(j = 0; j < k; j++){
			scanf("%d %d", &m[i][j].pembilang, &m[i][j].penyebut);//inputan
		}
	}
}
//prosedur untuk memasukkan matrix kecil ke matrix besar
void twomat(int b1, int k1, matrix m1[b1][k1], int b2, int k2, matrix m2[b2][k2], int p1, int p2){
	int bk=0, kk, i, j;
	//bk dan kk untuk index dari matrix kecil
	for(i = p1; i < b1; i++){//langsung memasukkan matrix kecil ke matrix besar sesuai patokan koordinat(p1, p2)
		kk=0;
		for(j = p2; j < k1; j++){
			m1[i][j].pembilang *= m2[bk][kk].pembilang;
			m1[i][j].penyebut *= m2[bk][kk].penyebut;
			kk++;
		}
		bk++;
	}
	//menampilkan output
	for(i = 0; i < b1; i++){
		for(j = 0; j < k1; j++){
			printf("%d %d\n", m1[i][j].pembilang, m1[i][j].penyebut);
		}
	}
}