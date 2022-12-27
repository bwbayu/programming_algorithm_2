#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TP6 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

void insertionasc(int x, int n[5], daftar data[][51]){//prosedur untuk sorting dengan metode insertion secara ascending
	int i, j;
	daftar key;
	for(i = 1; i < n[x]; i++){
		key = data[x][i]; //menyimpan data tipe bungkusan data[x][i] dalam tipe bungkusan key
		j = i - 1;
		//perulangan untuk membandingkan dua buah variabel total dalam tipe bungkusan data
		/*perulangan akan terus terjadi selama variabel total dalam tipe bungkusan key lebih kecil daripada
		variabel total dalam tipe bungkusan data[x][j]*/
		while(j >= 0 && key.total < data[x][j].total){
			data[x][j + 1] = data[x][j];
			j--;
		}	
		data[x][j + 1] = key;//menempatkan tipe bungkusan key pada tipe bungkusan data[x][j+1]
	}
}

void insertiondesc(int x, int n[5], daftar data[][51]){//prosedur untuk sorting dengan metode insertion secara descending
	int i, j;
	daftar key;
	for(i = 1; i < n[x]; i++){
		key = data[x][i];//menyimpan data tipe bungkusan data[x][i] dalam tipe bungkusan key
		j = i - 1;
		//perulangan untuk membandingkan dua buah variabel total dalam tipe bungkusan data
		/*perulangan akan terus terjadi selama variabel total dalam tipe bungkusan key lebih besar daripada
		variabel total dalam tipe bungkusan data[x][j]*/
		while(j >= 0 && key.total > data[x][j].total){
			data[x][j + 1] = data[x][j];
			j--;
		}	
		data[x][j + 1] = key;//menempatkan tipe bungkusan key pada tipe bungkusan data[x][j+1]
	}
}

void selectionasc(int x, int n[5], daftar data[][51]){//prosedur untuk sorting dengan metode selection secara ascending
	int i, j, min;
	daftar temp;//deklarasi tipe bungkusan temp untuk menyimpan data
	for(i = 0; i < n[x]-1; i++){
		min = i;//menginisialisasi untuk index min
		//perulangan untuk mencari index dengan nilai min dari index i+1 sampai index terakhir array
		for(j = i+1; j < n[x]; j++){
			if(data[x][min].total > data[x][j].total){
				min = j;
			}
		}
		//pertukaran posisi antara data[x][i] dengan data[x][min]
		temp = data[x][i];
		data[x][i] = data[x][min];
		data[x][min] = temp;
	}
}

void selectiondesc(int x, int n[5], daftar data[][51]){//prosedur untuk sorting dengan metode selection secara descending
	int i, j, max;
	daftar temp;//deklarasi tipe bungkusan temp untuk menyimpan data
	for(i = 0; i < n[x]-1; i++){
		max = i;//menginisialisasi untuk index max
		//perulangan untuk mencari index dengan nilai max dari index i+1 sampai index terakhir array
		for(j = i+1; j < n[x]; j++){
			if(data[x][max].total < data[x][j].total){
				max = j;
			}
		}
		//pertukaran posisi antara data[x][i] dengan data[x][max]
		temp = data[x][i];
		data[x][i] = data[x][max];
		data[x][max] = temp;
	}
}

void bubbleasc(int x, int n[5], daftar data[][51]){//prosedur untuk sorting dengan metode bubble secara ascending
	int i, swap;
	daftar temp;
	
	do{
		//variabel swap tanda apakah ada data yang ditukar atau tidak
		swap=0;//diinisialisasikan dengan 0
		//mengecek semua data
		for(i = 0; i < n[x]-1; i++){
			//jika variabel total pada tipe bungkusan data[x][i] lebih besar daripada variabel total pada tipe bungkusan data[x][i+1]
			if(data[x][i].total > data[x][i+1].total){
				//pertukaran data
				temp = data[x][i];
				data[x][i] = data[x][i+1];
				data[x][i+1] = temp;
				swap=1;//dan variabel swap akan diinisialisasikan dengan 1 sebagai tanda adanya pertukaran data
			}
		}
	}while(swap == 1);//perulangan akan terus terjadi selama ada data yang ditukar
}

void bubbledesc(int x, int n[5], daftar data[][51]){//prosedur untuk sorting dengan metode bubble secara descending
	int i, swap;
	daftar temp;
	
	do{
		//variabel swap tanda apakah ada data yang ditukar atau tidak
		swap=0;//diinisialisasikan dengan 0
		//mengecek semua data
		for(i = 0; i < n[x]-1; i++){
			//jika variabel total pada tipe bungkusan data[x][i] lebih kecil daripada variabel total pada tipe bungkusan data[x][i+1]
			if(data[x][i].total < data[x][i+1].total){
				//pertukaran data
				temp = data[x][i];
				data[x][i] = data[x][i+1];
				data[x][i+1] = temp;
				swap=1;//dan variabel swap akan diinisialisasikan dengan 1 sebagai tanda adanya pertukaran data
			}
		}
	}while(swap == 1);//perulangan akan terus terjadi selama ada data yang ditukar
}

void quickasc(int x, daftar data[][51], int left, int right){//prosedur untuk sorting dengan metode quick secara ascending
	int i = left, j = right;
	daftar temp;

	do{
		//perulangan while untuk menggeser variabel i dan j
		//selama variabel total dalam tipe bungkusan data[x][i] lebih kecil daripada variabel total dalam tipe bungkusan data[x][right] dan i <= j maka i akan bertambah
		while(data[x][i].total < data[x][right].total && i <= j){
			i++;
		}
		//selama variabel total dalam tipe bungkusan data[x][j] lebih besar daripada variabel total dalam tipe bungkusan data[x][left] dan i <= j maka j akan berkurang
		while(data[x][j].total > data[x][left].total && i <= j){
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
		quickasc(x, data, left, j);
	}
	if(i < right){//untuk sub bagian yang sebelah kanan
		quickasc(x, data, i, right);
	}
}

void quickdesc(int x, daftar data[][51], int left, int right){//prosedur untuk sorting dengan metode quick secara descending
	int i = left, j = right;
	daftar temp;

	do{
		//perulangan while untuk menggeser variabel i dan j
		//selama variabel total dalam tipe bungkusan data[x][i] lebih besar daripada variabel total dalam tipe bungkusan data[x][right] dan i <= j maka i akan bertambah
		while(data[x][i].total > data[x][right].total && i <= j){
			i++;
		}
		//selama variabel total dalam tipe bungkusan data[x][j] lebih kecil daripada variabel total dalam tipe bungkusan data[x][left] dan i <= j maka j akan berkurang
		while(data[x][j].total < data[x][left].total && i <= j){
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
		quickdesc(x, data, left, j);
	}
	if(i < right){//untuk sub bagian yang sebelah kanan
		quickdesc(x, data, i, right);
	}
}

void mergeasc(int x, int y, int z, int n[5], daftar data[][51]){//prosedur untuk menyatukan 2 array secara ascending
	int i=0, j=0; //iterator untuk tipe bungkusan data[x] dan data[y] yang akan digabungkan
	int hitung=0;//variabel untuk index tipe bungkusan data[z] yang akan digabungkan
	int sisa;//iterator sisa

	while(i < n[x] && j < n[y]){
		//jika variabel total pada tipe bungkusan data[x][i] lebih kecil daripada variabel total pada tipe bungkusan data[y][j]
		if(data[x][i].total < data[y][j].total){
			//maka tipe bungkusan data[z] akan diisi oleh tipe bungkusan data[x][i]
			data[z][hitung] = data[x][i];
			i++; hitung++; //index tipe bungkusan data[x] dan data[z] akan bertambah
		}
		else if(data[y][j].total < data[x][i].total){//jika variabel total pada tipe bungkusan data[y][j] lebih kecil daripada tipe bungkusan data[x][i]
			//maka tipe bungkusan data[z] akan diisi oleh tipe bungkusan data[y][j]
			data[z][hitung] = data[y][j];
			j++; hitung++; //index tipe bungkusan data[y] dan data[z] akan bertambah
		}
		else{//jika variabel total pada tipe bungkusan data[x][i] sama dengan variabel total pada tipe bungkusan data[y][j]
			//maka tipe bungkusan data[z] akan diisi oleh tipe bungkusan data[x][i]
			data[z][hitung] = data[x][i];
			i++; hitung++;
			//dan tipe bungkusan data[z] akan diisi oleh tipe bungkusan data[y][j]
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

void mergedesc(int x, int y, int z, int n[5], daftar data[][51]){//prosedur untuk menyatukan 2 array secara descending
	int i=0, j=0;//iterator untuk tipe bungkusan data[x] dan data[y] yang akan digabungkan
	int hitung=0;//variabel untuk index tipe bungkusan data[z] yang akan digabungkan
	int sisa;//iterator sisa
	
	while(i < n[x] && j < n[y]){
		//jika variabel total pada tipe bungkusan data[x][i] lebih besar daripada variabel total pada tipe bungkusan data[y][j]
		if(data[x][i].total > data[y][j].total){
			//maka tipe bungkusan data[z] akan diisi oleh tipe bungkusan data[x][i]
			data[z][hitung] = data[x][i];
			i++; hitung++;
		}
		else if(data[y][j].total > data[x][i].total){//jika variabel total pada tipe bungkusan data[y][j] lebih besar daripada tipe bungkusan data[x][i]
			//maka tipe bungkusan data[z] akan diisi oleh tipe bungkusan data[y][j]
			data[z][hitung] = data[y][j];
			j++; hitung++;
		}
		else{//jika variabel total pada tipe bungkusan data[x] index ke-i sama dengan variabel total pada tipe bungkusan data[y][j]
			//maka tipe bungkusan data[z] akan diisi oleh tipe bungkusan data[x][i]
			data[z][hitung] = data[x][i];
			i++; hitung++;
			//dan tipe bungkusan data[z] akan diisi oleh tipe bungkusan data[y][j]
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

void print(int x, int n[5], daftar data[][51]){//prosedur untuk menampilkan array
	int i;
	
	for(i=0; i<n[x]; i++){
		printf("%s %d\n", data[x][i].nama, data[x][i].total);
	}
}