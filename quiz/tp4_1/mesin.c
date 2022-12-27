#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TP4 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int total(int n, song lagu[n]){//fungsi untuk mengubah durasi waktu yang berbentuk menit detik menjadi detik
	int i, temp=0;
	for(i = 0; i < n; i++){
		lagu[i].tdur = (lagu[i].min*60)+lagu[i].sec;//mengubah durasi waktu dari menit detik menjadi detik dan mengalokasikannya di variabel tdur
		temp += lagu[i].tdur;//mencari total durasi lagu
	}
	return temp;//mengembalikan total durasi lagu dalam detik
}

void insertionstrasc(int n, song lagu[n]){//prosedur untuk data yang di sorting dengan metode insertion secara ascending dan patokan sortingnya berdasarkan judul
	int i, j;
	song key;
	for(i = 1; i < n; i++){
		key = lagu[i]; //menyimpan data tipe bungkusan lagu ke-i dalam tipe bungkusan key
		j = i-1;
		//perulangan akan terus terjadi selama j >= 0 dan selama nilai string judul pada tipe bungkusan key lebih kecil daripada nilai string judul pada tipe bungkusan lagu ke-j
		while(j >= 0 && strcmp(key.judul, lagu[j].judul) < 0){
			lagu[j+1] = lagu[j];//mengalokasikan isi tipe bungkusan lagu ke-j ke-j+1/ke kanan
			j--;
		}
		lagu[j+1] = key; //menempatkan tipe bungkusan key pada tipe bungkusan lagu ke-j+1
	}
}

void insertionstrdesc(int n, song lagu[n]){//prosedur untuk data yang di sorting dengan metode insertion secara descending dan patokan sortingnya berdasarkan judul
	int i, j;
	song key;
	for(i = 1; i < n; i++){
		key = lagu[i];//menyimpan data tipe bungkusan lagu ke-i dalam tipe bungkusan key
		j = i-1;
		//perulangan akan terus terjadi selama j >= 0 dan selama nilai string judul pada tipe bungkusan key lebih besar daripada nilai string judul pada tipe bungkusan lagu ke-j
		while(j >= 0 && strcmp(key.judul, lagu[j].judul) > 0){
			lagu[j+1] = lagu[j];//mengalokasikan isi tipe bungkusan lagu ke-j ke-j+1/ke kanan
			j--;
		}
		lagu[j+1] = key;//menempatkan tipe bungkusan key pada tipe bungkusan lagu ke-j+1
	}
}

void insertionintasc(int n, song lagu[n]){//prosedur untuk data yang di sorting dengan metode insertion secara ascending dan patokan sortingnya berdasarkan durasi
	int i, j;
	song key;
	for(i = 1; i < n; i++){
		key = lagu[i];//menyimpan data tipe bungkusan lagu ke-i dalam tipe bungkusan key
		j = i-1;
		//perulangan akan terus terjadi selama j >= 0 dan selama total durasi pada tipe bungkusan key lebih kecil daripada total durasi pada tipe bungkusan lagu ke-j
		while(j >= 0 && key.tdur < lagu[j].tdur){
			lagu[j+1] = lagu[j];//mengalokasikan isi tipe bungkusan lagu ke-j ke-j+1/ke kanan
			j--;
		}
		lagu[j+1] = key;//menempatkan tipe bungkusan key pada tipe bungkusan lagu ke-j+1
	}
}

void insertionintdesc(int n, song lagu[n]){//prosedur untuk data yang di sorting dengan metode insertion secara descending dan patokan sortingnya berdasarkan durasi
	int i, j;
	song key;
	for(i = 1; i < n; i++){
		key = lagu[i];//menyimpan data tipe bungkusan lagu ke-i dalam tipe bungkusan key
		j = i-1;
		//perulangan akan terus terjadi selama j >= 0 dan selama total durasi pada tipe bungkusan key lebih besar daripada total durasi pada tipe bungkusan lagu ke-j
		while(j >= 0 && key.tdur > lagu[j].tdur){
			lagu[j+1] = lagu[j];//mengalokasikan isi tipe bungkusan lagu ke-j ke-j+1/ke kanan
			j--;
		}
		lagu[j+1] = key;//menempatkan tipe bungkusan key pada tipe bungkusan lagu ke-j+1
	}
}

void selectionstrasc(int n, song lagu[n]){//prosedur untuk data yang di sorting dengan metode selection secara ascending dan patokan sortingnya berdasarkan judul
	int i, j, min;
	for(i = 0; i < n-1; i++){
		song temp;//deklarasi tipe bungkusan temp untuk menyimpan data
		min = i;//menginisialisasi untuk index minimum
		for(j = i+1; j < n; j++){
			//mengecek jika nilai string judul dalam tipe bungkusan lagu index ke-min lebih besar daripada nilai string judul dalam tipe bungkusan lagu index ke-j
			if(strcmp(lagu[min].judul, lagu[j].judul) > 0){
				min = j;
			}
		}
		//pertukaran posisi antara index i dan minimum
		temp = lagu[i];
		lagu[i] = lagu[min];
		lagu[min] = temp;
	}
}

void selectionstrdesc(int n, song lagu[n]){//prosedur untuk data yang di sorting dengan metode selection secara descending dan patokan sortingnya berdasarkan judul
	int i, j, min;
	for(i = 0; i < n-1; i++){
		song temp;//deklarasi tipe bungkusan temp untuk menyimpan data
		min = i;//menginisialisasi untuk index minimum
		for(j = i+1; j < n; j++){
			//mengecek jika nilai string judul dalam tipe bungkusan lagu index ke-min lebih kecil daripada nilai string judul dalam tipe bungkusan lagu index ke-j
			if(strcmp(lagu[min].judul, lagu[j].judul) < 0){
				min = j;
			}
		}
		//pertukaran posisi antara index i dan minimum
		temp = lagu[i];
		lagu[i] = lagu[min];
		lagu[min] = temp;
	}
}

void selectionintasc(int n, song lagu[n]){//prosedur untuk data yang di sorting dengan metode selection secara ascending dan patokan sortingnya berdasarkan durasi
	int i, j, min;
	for(i = 0; i < n-1; i++){
		song temp;//deklarasi tipe bungkusan temp untuk menyimpan data
		min = i;//menginisialisasi untuk index minimum
		for(j = i+1; j < n; j++){
			//mengecek jika total durasi dalam tipe bungkusan lagu index ke-min lebih besar daripada total durasi dalam tipe bungkusan lagu index ke-j
			if(lagu[min].tdur > lagu[j].tdur){
				min = j;
			}
		}
		//pertukaran posisi antara index i dan minimum
		temp = lagu[i];
		lagu[i] = lagu[min];
		lagu[min] = temp;
	}
}

void selectionintdesc(int n, song lagu[n]){//prosedur untuk data yang di sorting dengan metode selection secara descending dan patokan sortingnya berdasarkan durasi
	int i, j, min;
	for(i = 0; i < n-1; i++){
		song temp;//deklarasi tipe bungkusan temp untuk menyimpan data
		min = i;//menginisialisasi untuk index minimum
		for(j = i+1; j < n; j++){
			//mengecek jika total durasi dalam tipe bungkusan lagu index ke-min lebih kecil daripada total durasi dalam tipe bungkusan lagu index ke-j
			if(lagu[min].tdur < lagu[j].tdur){
				min = j;
			}
		}
		//pertukaran posisi antara index i dan minimum
		temp = lagu[i];
		lagu[i] = lagu[min];
		lagu[min] = temp;
	}
}

void print(int n, song lagu[n]){//prosedur untuk keluaran
	int i;
	//output data
	for(i = 0; i < n; i++){
		printf("%d.", lagu[i].min);
		if(lagu[i].sec < 10){//jika detik kurang dari 10 maka akan dimunculkan 0 di depannya
			printf("0%d", lagu[i].sec);
		}
		else{
			printf("%d", lagu[i].sec);
		}
		printf(" %s\n", lagu[i].judul);
	}
}