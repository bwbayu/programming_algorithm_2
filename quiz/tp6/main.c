#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TP6 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main(){
	int i, j, t, harga, n[5];
	double berat;
	daftar data[5][51];
	//input
	for(i = 0; i < 3; i++){
		scanf("%d", &n[i]);
		for(j = 0; j < n[i]; j++){
			scanf("%s %d %lf", &data[i][j].nama, &harga, &berat);
			data[i][j].total = harga * berat;
		}
	}
	char m, sort[10];
	scanf("%d %c %s", &t, &m, &sort);
	//mencari banyak isi array ke 3 dan ke 4
	n[3]=n[0]+n[1];
	n[4]=n[3]+n[2];
	//mengecek metode mana yang akan digunakan dan mau diurutkan secara ascending/descending
	if(m == 'i'){//untuk kasus yang menggunakan metode insertion
		if(strcmp(sort, "asc") == 0){//untuk kasus yang diurutkan secara ascending
			insertionasc(0, n, data);
			insertionasc(1, n, data);
			insertionasc(2, n, data);
			mergeasc(0, 1, 3, n, data);
			mergeasc(2, 3, 4, n, data);
		}
		else{//untuk kasus yang diurutkan secara descending
			insertiondesc(0, n, data);
			insertiondesc(1, n, data);
			insertiondesc(2, n, data);
			mergedesc(0, 1, 3, n, data);
			mergedesc(2, 3, 4, n, data);
		}
	}
	else if(m == 's'){//untuk kasus yang menggunakan metode selection
		if(strcmp(sort, "asc") == 0){//untuk kasus yang diurutkan secara ascending
			selectionasc(0, n, data);
			selectionasc(1, n, data);
			selectionasc(2, n, data);
			mergeasc(0, 1, 3, n, data);
			mergeasc(2, 3, 4, n, data);
		}
		else{//untuk kasus yang diurutkan secara descending
			selectiondesc(0, n, data);
			selectiondesc(1, n, data);
			selectiondesc(2, n, data);
			mergedesc(0, 1, 3, n, data);
			mergedesc(2, 3, 4, n, data);
		}
	}
	else if(m == 'b'){//untuk kasus yang menggunakan metode bubble
		if(strcmp(sort, "asc") == 0){//untuk kasus yang diurutkan secara ascending
			bubbleasc(0, n, data);
			bubbleasc(1, n, data);
			bubbleasc(2, n, data);
			mergeasc(0, 1, 3, n, data);
			mergeasc(2, 3, 4, n, data);
		}
		else{//untuk kasus yang diurutkan secara descending
			bubbledesc(0, n, data);
			bubbledesc(1, n, data);
			bubbledesc(2, n, data);
			mergedesc(0, 1, 3, n, data);
			mergedesc(2, 3, 4, n, data);
		}
	}
	else{//untuk kasus yang menggunakan metode quick
		if(strcmp(sort, "asc") == 0){//untuk kasus yang diurutkan secara ascending
			quickasc(0, data, 0, n[0]-1);
			quickasc(1, data, 0, n[1]-1);
			quickasc(2, data, 0, n[2]-1);
			mergeasc(0, 1, 3, n, data);
			mergeasc(2, 3, 4, n, data);
		}
		else{//untuk kasus yang diurutkan secara descending
			quickdesc(0, data, 0, n[0]-1);
			quickdesc(1, data, 0, n[1]-1);
			quickdesc(2, data, 0, n[2]-1);
			mergedesc(0, 1, 3, n, data);
			mergedesc(2, 3, 4, n, data);
		}
	}
	
	//output
	printf("Daftar Snack:\n-------------------------------\n");
	print(4, n, data);
	printf("===============================\n");
	printf("snack yang dibeli:\n-------------------------------\n");
	
	//untuk menampilkan daftar makanan yang bisa dibeli
	
	if(t >= data[4][0].total){//mengecek jika budget >= harga makanan maka akan menampilkan seperti program di dalam if
		int a=0, tharga=0; //inisialisasi
		while(a < n[4] && data[4][a].total <= t){//selama harga makanaan <= dari budget maka daftar makanan akan ditampilkan
			t -= data[4][a].total;
			tharga += data[4][a].total;
			printf("%s %d\n", data[4][a].nama, data[4][a].total);
			a++;
		}
		printf("===============================\n");
		printf("total pengeluaran : Rp. %d\n", tharga);
		printf("sisa budget       : Rp. %d\n", t);
	}
	else{//jika budget < harga makanan maka akan menampilkan seperti program di dalam else
		printf("tidak ada snack yang dibeli\n");
		printf("===============================\n");
		printf("total pengeluaran : Rp. 0\n");
		printf("sisa budget       : Rp. %d\n", t);
	}
	printf("===============================\n");
	
	return 0;
}