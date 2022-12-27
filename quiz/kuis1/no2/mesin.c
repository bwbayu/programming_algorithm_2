#include "header.h"

/*Saya Bayu Wicaksono mengerjakan kuis dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int mid(int b, int x){//fungsi untuk deret posisi 2
	if(x == 0){//base condition untuk deret ke-0
		return b;
	}
	return mid(b, x-1) * mid(b, x-1);//rekrusif
}

int last(int b, int c, int x){//fungsi untuk deret posisi 3
	if(x == 0){//base condition untuk deret ke-0
		return c;
	}
	else if(x == 1){//base condition untuk deret ke-1
		return mid(b, x) + c;
	}
	return mid(b, x) + last(b, c, x-1);//rekrusif
}