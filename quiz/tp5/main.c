#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TP5 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main(){
	int n, i, j;
	char metode, urutan;
	scanf("%d", &n);//masukan
	makanan m[n];
	for(i = 0; i < n; i++){//masukan
		scanf("%s %lf %lf", &m[i].nama, &m[i].jumlah, &m[i].berat);
		m[i].kalori = m[i].jumlah / m[i].berat;//mencari nilai jumlah kalori/gram lalu mengalokasikannya ke variabel kalori dalam tipe bungkusan
	}
	scanf(" %c %c", &metode, &urutan);//masukan
	spasistr(n, m);//memanggil prosedur spasistr
	spasinum(n, m);//memanggil prosedur spasinum
	
	//mengecek metode sorting yg digunakan
	if(metode == 'b'){//jika metodenya bubble maka akan mengeksekusi program dalam if
		//mengecek data akan diurutkan secara ascending atau descending
		if(urutan == 'a'){//jika urutannya ascending maka akan mengeksekusi program dalam if
			bubbleasc(n, m);//yaitu memanggil prosedur bubbleasc
		}
		else{//jika urutannya descending maka akan mengeksekusi program dalam else
			bubbledesc(n, m);//yaitu memanggil prosedur bubbledesc
		}
	}
	else{//jika metodenya quick maka akan mengeksekusi program dalam else
		//mengecek data akan diurutkan secara ascending atau descending
		if(urutan == 'a'){//jika urutannya ascending maka akan mengeksekusi program dalam if
			quickasc(m, 0, n-1);//yaitu memanggil prosedur quickasc
		}
		else{//jika urutannya descending maka akan mengeksekusi program dalam else
			quickdesc(m, 0, n-1);//yaitu memanggil prosedur quickdesc
		}
	}
	
	
	print(n, m);//memanggil prosedur print untuk menampilkan data
	return 0;
}