#include "header.h"

/*Saya Bayu Wicaksono mengerjakan evaluasi 1 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

void selectionasc(int x, int n[7], mahasiswa data[][51]){//prosedur untuk sorting ascending
	int i, j, min;
	mahasiswa temp;//deklarasi tipe bungkusan temp untuk menyimpan data
	for(i = 0; i < n[x]-1; i++){
		min = i;//menginisialisasi untuk index elemen min
		//perulangan untuk mencari index dengan nilai min dari index i+1 sampai index terakhir array
		for(j = i+1; j < n[x]; j++){
			if(strcmp(data[x][min].nim, data[x][j].nim) > 0){
				min = j;
			}
		}
		//pertukaran isi data antara data[x][i] dengan data[x][min]
		temp = data[x][i];
		data[x][i] = data[x][min];
		data[x][min] = temp;
	}
}

void selectiondesc(int x, int n[7], mahasiswa data[][51]){//prosedur untuk sorting descending
	int i, j, max;
	mahasiswa temp;//deklarasi tipe bungkusan untuk menyimpan data
	for(i = 0; i < n[x]-1; i++){
		max = i;//menginisialisasi untuk index elemen max
		//pertukaran untuk mencari index dengan nilai max dari index i+1 sampai index terakhir array
		for(j = i+1; j < n[x]; j++){
			if(data[x][max].nilai < data[x][j].nilai){
				max = j;
			}
		}
		//pertukaran isi data antara data[x][i] dengan data[x][max]
		temp = data[x][i];
		data[x][i] = data[x][max];
		data[x][max] = temp;
	}
}

void mergeasc(int x, int y, int z, int n[7], mahasiswa data[][51]){//prosedur untuk menyatukan 2 buah array secara ascending
	int i=0, j=0;//index untuk tipe bungkusan data[x] dan data[y] yang akan digabungkan
	int hitung=0;//variabel untuk index tipe bungkusan data[z]
	int sisa;//iterator sisa

	while(i < n[x] && j < n[y]){
		//jika variabel nim pada tipe bungkusan data[x][i] lebih kecil daripada variabel nim pada tipe bungkusan data[y][j]
		if(strcmp(data[x][i].nim, data[y][j].nim) < 0){
			//maka tipe bungkusan data[z][hitung] akan diisi oleh tipe bungkusan data[x][i]
			data[z][hitung] = data[x][i];
			i++; hitung++;//index tipe bungkusan data[x] dan data[z] akan bertambah
		}
		else if(strcmp(data[y][j].nim, data[x][i].nim) < 0){//jika variabel nim pada tipe bungkusan data[y][j] lebih kecil daripada variabel nim pada tipe bungkusan data[x][i]
			//maka tipe bungkusan data[z][hitung] akan diisi oleh tipe bungkusan data[y][j]
			data[z][hitung] = data[y][j];
			j++; hitung++;//index tipe bungkusan data[y] dan data[z] akan bertambah
		}
		else{//jika variabel total pada tipe bungkusan data[x][i] sama dengan variabel total pada tipe bungkusan data[y][j]
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

void bagi(int x, int y, int z, int n[7], mahasiswa data[][51]){//prosedur untuk membagi array menjadi 2 buah array
	int i, j, k=0;
	//pengulangan untuk mengisi array yg pertama
	for(i = 0; i < n[y]; i++){
		data[y][i] = data[x][i];
	}
	//pengulangan untuk mengisi array yg kedua
	for(j = i; j < n[x]; j++){
		data[z][k] = data[x][j];
		k++;
	}
}

void print(int x, int n[7], mahasiswa data[][51]){//prosedur untuk output
	int i;
	printf("====================\n");
	for(i = 0; i < n[x]; i++){
		printf("%s %s %d\n", data[x][i].nim, data[x][i].nama, data[x][i].nilai);
	}
}