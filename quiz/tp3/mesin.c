#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TP3 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int fib(int a, int b, int x){ //fungsi untuk mengecek banyak virus pada jam ke x
	if(x == 1){//base condition
		return b;
	}
	else if(x == 0){//base condition 
		return a;
	}
	return 2*fib(a, b, x-1) + fib(a, b, x-2) * fib(a, b, x-2);//rekursif
}