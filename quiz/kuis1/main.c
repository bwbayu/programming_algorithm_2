#include "header.h"

/*Saya Bayu Wicaksono mengerjakan kuis dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main(){
	int b1, k1, b2, k2, i, j;
	scanf("%d %d", &b1, &k1);
	matrix m1[b1][k1];
	inputan(b1, k1, m1);//memanggil prosedur inputan
	scanf("%d %d", &b2, &k2);
	matrix m2[b2][k2];//memanggil prosedur inputan
	inputan(b2, k2, m2);
	int p1, p2;
	scanf("%d %d", &p1, &p2);
	
	//memeriksa matrix mana yang lebih besar
	if(b1*k1 > b2*k2){
		twomat(b1, k1, m1, b2, k2, m2, p1, p2);//memanggil prosedur twomat untuk memasukkan matrix kecil ke matrix besar
	}
	else{
		twomat(b2, k2, m2, b1, k1, m1, p1, p2);//memanggil prosedur twomat untuk memasukkan matrix kecil ke matrix besar
	}
	
	
	return 0;
}