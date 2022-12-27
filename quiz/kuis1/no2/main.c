#include "header.h"

/*Saya Bayu Wicaksono mengerjakan kuis dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main(){
	int a1, a2, a3, banyak;
	scanf("%d %d %d %d", &a1, &a2, &a3, &banyak);
	int g[banyak+1], i, h[banyak+1];//array untuk menampung deret
	
	for(i = 0; i <= banyak; i++){
		g[i] = mid(a2, i);//memanggil fungsi mid
		h[i] = last(a2, a3, i);//memanggil fungsi last
	}
	for(i = 0; i <= banyak; i++){//output
		printf("%d %d %d", a1, g[i], h[i]);
		if(i < banyak){
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}