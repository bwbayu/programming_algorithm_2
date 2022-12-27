#include "header.h"

/*Saya Bayu Wicaksono mengerjakan UTS dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

void insertion(int x, minyak data[5][51], int n[5]){//prosedur untuk sorting dengan metode sorting insertion secara ascending
	int i, j;
	minyak key;
	
	for(i = 1; i < n[x]; i++){
		key = data[x][i];//menyimpan data tipe bungkusan data[x][i]
		j = i - 1;
		//perulangan untuk membandingkan dua buah variabel t dalam tipe bungkusan
		/*perulangan akan terus terjadi selama variabel t dalam tipe bungkusan key lebih kecil
		daripada variabel t dalam tipe bungkusan data[x][j]*/
		while(j >= 0 && key.t < data[x][j].t){
			//menyimpan isi tipe bungkusan data[x][j] pada tipe bungkusan data[x][j+1]
			data[x][j + 1] = data[x][j];
			j--;
		}
		//menyimpan isi tipe bungkusan key pada tipe bungkusan data[x][j+1]
		data[x][j + 1] = key;
	}
}

void selection(int x, minyak data[5][51], int n[5]){//prosedur untuk sorting dengan metode sorting selection secara ascending
	int i, j, min;
	minyak temp;//deklarasi tipe bungkusan temp untuk menyimpan data

	for(i = 0; i < n[x]-1; i++){
		min = i;//menginisialisasi untuk index min
		//perulangan untuk mencari index dengan min dari index i+1 sampai index terakhir array
		for(j = i + 1; j < n[x]; j++){
			if(data[x][min].t > data[x][j].t){
				min = j;
			}
		}
		//pertukaran isi data antara data[x][i] dengan data[x][min]
		temp = data[x][i];
		data[x][i] = data[x][min];
		data[x][min] = temp;
	}
}

void bubble(int x, minyak data[5][51], int n[5]){//prosedur untuk sorting dengan metode sorting bubble secara ascending
	int i, swap;
	minyak temp;//deklarasi tipe bungkusan temp untuk menyimpan data
	do{
		//variabel swap tanda apakah ada data yang ditukar atau tidak
		swap = 0;//diinisialisasikan dengan 0
		//mengecek semua data
		for(i = 0; i < n[x]-1; i++){
			//jika variabel t pada tipe bungkusan data[x][i] lebih besar daripada variabel t pada tipe bungkusan data[x][i+1]
			if(data[x][i].t > data[x][i + 1].t){
				//pertukaran data
				temp = data[x][i];
				data[x][i] = data[x][i + 1];
				data[x][i + 1] = temp;
				swap = 1;//dan variabel swap akan diinisialisasikan dengan 1
			}
		}
	}while(swap == 1);//perulangan akan terus terjadi selama ada data yang tertukar
}

void quick(int x, minyak data[5][51], int n[5], int left, int right){//prosedur untuk sorting dengan metode sorting quick secara ascending
	int i = left, j = right;
	minyak temp;

	do{
		//perulangan while untuk menggeser variabel i dan j
		//selama variabel t dalam tipe bungkusan data[x][i] lebih kecil daripada variabel t dalam tipe bungkusan data[x][right] dan i <= j maka i akan bertambah
		while(data[x][i].t < data[x][right].t && i <= j){
			i++;
		}
		//selama variabel t dalam tipe bungkusan data[x][j] lebih besar daripada variabel t dalam tipe bungkusan data[x][left] dan i <= j maka j akan berkurang
		while(data[x][j].t > data[x][left].t && i <= j){
			j--;
		}

		if(i < j){//jika memenuhi persyaratan if maka akan terjadi pertukaran data
			temp = data[x][i];
			data[x][i] = data[x][j];
			data[x][j] = temp;
			i++; j--;
		}
	}while(i < j);
	//melakukan sorting untuk sub bagian
	if(left < j){//untuk sub bagian yang sebelah kiri
		quick(x, data, n, left, j);
	}
	if(i < right){//untuk sub bagian yang sebelah kanan
		quick(x, data, n, i, right);
	}
}

void merge(int x, int y, int z, minyak data[5][51], int n[5]){//prosedur untuk menyatukan 2 array secara ascending
	int i=0, j = 0, hitung = 0, sisa;

	while(i < n[x] && j < n[y]){
		//jika variabel t dalam tipe bungkusan data[x][i] lebih kecil daripada variabel t dalam tipe bungkusan data[y][j]
		if(data[x][i].t < data[y][j].t){
			//maka tipe bungkusan data[z][hitung] akan diisi oleh tipe bungkusan data[x][i]
			data[z][hitung] = data[x][i];
			i++; hitung++;
		}
		else if(data[y][j].t < data[x][i].t){//jika variabel t dalam tipe bungkusan data[y][j] lebih kecil daripada variabel t dalam tipe bungkusan data[x][i]
			//maka tipe bungkusan data[z][hitung] akan diisi oleh tipe bungkusan data[y][j]
			data[z][hitung] = data[y][j];
			j++; hitung++;
		}
		else{//jika variabel t dalam tipe bungkusan data[y][j] sama dengan variabel t dalam tipe bungkusan data[x][i]
			//maka tipe bungkusan data[z][hitung] akan diisi oleh tipe bungkusan data[x][i]
			data[z][hitung] = data[x][i];
			i++; hitung++;
			//dan tipe bungkusan data[z][hitung] akan diisi oleh tipe bungkusan data[y][j]
			data[z][hitung] = data[y][j];
			j++; hitung++;
		}
	}

	if(i < n[x]){//jika tipe bungkusan data[x] masih memiliki sisa
		//maka tipe bungkusan data[z] akan diisi oleh sisa tipe bungkusan data[x]
		for(sisa = i; sisa < n[x]; sisa++){
			data[z][hitung] = data[x][sisa];
			hitung++;
		}
	}
	if(j < n[y]){//jika tipe bungkusan data[y] masih memiliki sisa
		//maka tipe bungkusan data[z] akan diisi oleh sisa tipe bungkusan data[y]
		for(sisa = j; sisa < n[y]; sisa++){
			data[z][hitung] = data[y][sisa];
			hitung++;
		}
	}
}

void print(int x, minyak data[5][51], int n[5]){//prosedur untuk menampilkan isi array berdasarkan supplier
	int i, j;
	for(i = 0; i < n[x]; i++){
		//mengubah tipe data double menjadi integer
		int temp1 = data[x][i].kalori;
		int temp2 = data[x][i].lemak;
		int temp3 = data[x][i].t;
		/*mengecek apakah variabel t ada angka dibelakang koma atau tidak
		jika ada maka akan dikeluarkan 2 angka dibelakang koma
		jika tidak ada maka menampilkan dalam tipe data integer*/
		if(data[x][i].t == temp3){
			printf("%s %d %d %d - %d\n", data[x][i].nama, temp1, temp2, data[x][i].harga, temp3);
		}
		else{
			printf("%s %d %d %d - %0.2lf\n", data[x][i].nama, temp1, temp2, data[x][i].harga, data[x][i].t);
		}	
	}
}

void print1(int x, minyak data[5][51], int n[5]){//prosedur untuk menampilkan isi array setelah di sorting dan di merge
	int i, j;
	for(i = 0; i < n[x]; i++){
		//mengubah tipe data double menjadi integer
		int temp1 = data[x][i].kalori;
		int temp2 = data[x][i].lemak;
		int temp3 = data[x][i].t;
		/*mengecek apakah variabel t ada angka dibelakang koma atau tidak
		jika ada maka akan dikeluarkan 2 angka dibelakang koma
		jika tidak ada maka menampilkan dalam tipe data integer*/
		if(data[x][i].t == temp3){
			printf("%s %d %d %d - %d Supplier %d\n", data[x][i].nama, temp1, temp2, data[x][i].harga, temp3, data[x][i].sign);
		}
		else{
			printf("%s %d %d %d - %0.2lf Supplier %d\n", data[x][i].nama, temp1, temp2, data[x][i].harga, data[x][i].t, data[x][i].sign);
		}	
	}
}