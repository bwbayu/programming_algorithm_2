#include "header.h"

/*Saya Bayu Wicaksono mengerjakan evaluasi 1 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main(){
	int n[7], i, j;
	mahasiswa data[7][51];
	for(i = 0; i < 3; i++){
		scanf("%d", &n[i]);
		for(j = 0; j < n[i]; j++){
			scanf("%s %s %d", &data[i][j].nim, &data[i][j].nama, &data[i][j].nilai);
		}
	}
	
	//mencari panjang array ke-3 dan ke-4
	n[3]=n[0]+n[1];
	n[4]=n[2]+n[3];
	//pengulangan untuk mengurutkan array secara ascending
	for(i = 0; i < 3; i++){
		selectionasc(i, n, data);
	}
	//prosedur untuk menggabungkan 2 buah array menjadi 1 array
	mergeasc(0, 1, 3, n, data);
	mergeasc(2, 3, 4, n, data);
	//mencari panjang array ke-5 dan ke-6
	n[5] = n[4]/2;
	n[6] = n[5];
	bagi(4, 5, 6, n, data);//prosedur untuk membagi array menjadi 2 array
	//pengulangan untuk mengurutkan array secara descending
	for(i = 5; i < 7; i++){
		selectiondesc(i, n, data);
	}
	//output
	for(i = 4; i < 7; i++){
		print(i, n, data);
	}
	printf("====================\n");

	return 0;
}