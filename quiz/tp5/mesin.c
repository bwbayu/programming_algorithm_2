#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TP5 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

void spasistr(int n, makanan m[n]){//prosedur untuk mencari spasi tiap data antara nama makanan dan jumlah kalori
	int i, max;//mendeklarasikan variabel-variabel yang yang akan digunakan
	max = strlen(m[0].nama);//menginisialisasi nilai index ke 0 di variabel max
	for(i = 1; i < n; i++){//perulangan mulai dari index 1
		if(strlen(m[i].nama) > max){//jika data ke i lebih besar daripada variabel max maka variabel max akan diisi oleh data ke i tsb
			max = strlen(m[i].nama);
		}
	}
	for(i = 0; i < n; i++){//perulangan untuk menentukan spasi tiap data lalu mengalokasikan nilainya ke variabel spasi1 dalam tipe data bungkusan
		m[i].spasi1 = (max-strlen(m[i].nama)) + 2;
	}
}

void spasinum(int n, makanan m[n]){//prosedur untuk mencari spasi tiap data antara jumlah kalori dan berat
	int i, temp, max, tmp;//mendeklarasikan variabel-variabel yang yang akan digunakan
    for(i = 0; i < n; i++){//perulangan untuk mencari panjang integer
		temp=0;//variabel untuk menyimpan panjang integer
		tmp = m[i].jumlah;//memasukkan ke variabel tmp yang bertipe data int karena tipe data jumlah dalam tipe bungkusan adalah double
		while(tmp != 0){//perulangan akan terus terjadi selama integer tsb tidak sama dengan 0
			tmp /= 10;//untuk menghitung panjang integer, data dibagi 10
			temp++;//iterasi
		}
		m[i].spasi2 = temp;//mengalokasikan panjang integer ke variabel spasi2 dalam tipe data bungkusan
	}
	max = m[0].spasi2;//menginisialisasi nilai index ke 0 di variabel max
	for(i = 1; i < n; i++){//perulangan dimulai dari index 1
		if(m[i].spasi2 > max){//jika data ke 1 lebih besar daripada variabel max maka variabel max akan diisi oleh data ke i tsb
			max = m[i].spasi2;
		}
	}
	for(i = 0; i < n; i++){//perulangan untuk menentukan spasi tidak data lalu mengalokasikan nilainya ke variabel spasi2 dalam tipe data bungkusan
		m[i].spasi2 = (max-m[i].spasi2) + 2;
	}
}

void bubbleasc(int n, makanan m[n]){//prosedur sorting menggunakan bubble sort dengan urutan ascending
	int i, swap;
	makanan temp;//mendeklarasikan tipe bungkusan untuk pertukaran data
	do{
		//variabel swap tanda apakah ada data yang ditukar atau tidak
		swap=0;//diinisialisasikan dengan 0
		//mengecek semua data
		for(i = 0; i < n-1; i++){
			//jika nilai kalori ke i lebih besar daripada nilai kalori ke i+1 maka akan terjadi pertukaran antara kedua data
			if(m[i].kalori > m[i+1].kalori){
				temp = m[i];
				m[i] = m[i+1];
				m[i+1] = temp;
				swap = 1;//dan variabel swap akan berubah menjadi 1, tanda adanya pertukaran
			}
		}
	}while(swap == 1);//perulangan akan terus dilakukan selama terjadi pertukaran data
}

void bubbledesc(int n, makanan m[n]){//prosedur sorting menggunakan bubble sort dengan urutan descending
	int i, swap;
	makanan temp;//mendeklarasikan tipe bungkusan untuk pertukaran data
	do{
		//variabel swap tanda apakah ada data yang ditukar atau tidak
		swap=0;//diinisialisasikan dengan 0
		//mengecek semua data
		for(i = 0; i < n-1; i++){
			//jika nilai kalori ke i lebih kecil daripada nilai kalori ke i+1 maka akan terjadi pertukaran antara kedua data
			if(m[i].kalori < m[i+1].kalori){
				temp = m[i];
				m[i] = m[i+1];
				m[i+1] = temp;
				swap = 1;//dan variabel swap akan berubah menjadi 1, tanda adanya pertukaran
			}
		}
	}while(swap == 1);//perulangan akan terus dilakukan selama terjadi pertukaran data
}

void quickasc(makanan m[], int l, int r){//prosedur sorting menggunakan quick sort dengan urutan ascending
	int i, j;
	makanan temp;//mendeklarasikan tipe bungkusan untuk pertukaran data
	i = l, j = r;
	double pivot = m[(l + r)/2].kalori;//menyimpan nilai tengah dari data

	do{
		//perulangan while untuk menggeser variabel i dan j
		//selama variabel kalori dalam tipe bungkusan m index ke i lebih kecil dari pivot dan i <= j maka i akan bertambah
		while(m[i].kalori < pivot && i <= j){
			i++;
		}
		//selama variabel kalori dalam tipe bungkusan m index ke j lebih besar dari pivot dan i <= j maka j akan berkurang
		while(m[j].kalori > pivot && i <= j){
			j--;
		}
		
		if(i < j){//jika nilai i lebih kecil dari j maka akan terjadi pertukaran data
			temp = m[i];
			m[i] = m[j];
			m[j] = temp;
			i++; j--;
		}
	}while(i < j);//perulangan akan terus terjadi selama nilai i lebih kecil daripada nilai j
	
	//sorting untuk sub-bagian
	if(l < j && j < r){//bagian kiri pivot
		quickasc(m, l, j);
	}
	if(i < r && i > l){//bagian kanan pivot
		quickasc(m, i, r);
	}
}

void quickdesc(makanan m[], int l, int r){//prosedur sorting menggunakan quick sort dengan urutan descending
	int i, j;
	makanan temp;//mendeklarasikan tipe bungkusan untuk pertukaran data
	i = l, j = r;
	double pivot = m[(l + r)/2].kalori;//menyimpan nilai tengah dari data

	do{
		//perulangan while untuk menggeser variabel i dan j
		//selama variabel kalori dalam tipe bungkusan m index ke i lebih besar dari pivot dan i <= j maka i akan bertambah
		while(m[i].kalori > pivot && i <= j){
			i++;
		}
		//selama variabel kalori dalam tipe bungkusan m index ke j lebih kecil dari pivot dan i <= j maka j akan berkurang
		while(m[j].kalori < pivot && i <= j){
			j--;
		}
		
		if(i < j){//jika nilai i lebih kecil dari j maka akan terjadi pertukaran data
			temp = m[i];
			m[i] = m[j];
			m[j] = temp;
			i++; j--;
		}
	}while(i < j);//perulangan akan terus terjadi selama nilai i lebih kecil daripada nilai j
	//sorting untuk sub-bagian
	if(l < j && j < r){//bagian kiri pivot
		quickdesc(m, l, j);
	}
	if(i < r && i > l){//bagian kanan pivot
		quickdesc(m, i, r);
	}
}


void print(int n, makanan m[n]){//prosedur untuk menampilkan data
	int i, j;
	printf("Daftar Menu Makanan :\n");
	for(i = 0; i < n; i++){
		printf("%s", m[i].nama);//output untuk nama makanan
		for(j = 0; j < m[i].spasi1; j++){//output untuk spasi antara nama makanan dan jumlah kalori
			printf(" ");
		}
		int x = m[i].jumlah;//mengubah tipe data yang asalnya double menjadi integer
		printf("%d", x);//output jumlah kalori
		for(j = 0; j < m[i].spasi2; j++){//output untuk spasi antara jumlah kalori dan berat
			printf(" ");
		}
		int y = m[i].berat;//mengubah tipe data yang asalnya double menjadi integer
		printf("%d\n", y);//output untuk berat
	}
}