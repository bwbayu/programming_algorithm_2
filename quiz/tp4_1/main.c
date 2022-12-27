#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TP4 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main(){
	int n, i, j;
	scanf("%d", &n);
	char m[20], u[10], p[10];
	song lagu[n];
	for(i = 0; i < n; i++){//inputan
		scanf("%s %d.%d", &lagu[i].judul, &lagu[i].min, &lagu[i].sec);
	}
	scanf("%s %s %s", &m, &u, &p);//inputan
	
	int time = total(n, lagu);//mencari total durasi yang dibutuhkan untuk mendengarkan musik

	//mengecek data akan dimasukkan ke prosedur mana berdasarkan metode sorting, asc/desc, dan patokan sorting (judul/durasi)
	if(strcmp(m, "insertion")==0){//jika metode sortingnya insertion maka pengecekan akan dilanjutkan
		if(strcmp(u, "asc")==0){//jika diurutkan dari kecil-besar/ascending maka pengecekan akan dilanjutkan
			if(strcmp(p, "judul")==0){//jika patokan sortingnya judul maka
				insertionstrasc(n, lagu);//akan memanggil prosedur insertionstrasc
			}
			else{//jika patokan sortingnya durasi maka
				insertionintasc(n, lagu);//akan memanggil prosedur insertionintasc
			}
		}
		else{//jika diurutkan dari besar-kecil/descending maka pengecekan akan dilanjutkan
			if(strcmp(p, "judul")==0){//jika patokan sortingnya judul maka
				insertionstrdesc(n, lagu);//akan memanggil prosedur insertionstrdesc
			}
			else{//jika patokan sortingnya durasi maka
				insertionintdesc(n, lagu);//akan memanggil prosedur insertionintdesc
			}
		}
	}
	else{//jika metode sortingnya selection maka akan masuk ke program di dalam else
		if(strcmp(u, "asc")==0){//jika diurutkan dari kecil-besar/ascending maka pengecekan akan dilanjutkan
			if(strcmp(p, "judul")==0){//jika patokan sortingnya judul maka
				selectionstrasc(n, lagu);//akan memanggil prosedur selectionstrasc
			}
			else{//jika patokan sortingnya durasi maka
				selectionintasc(n, lagu);//akan memanggil prosedur selectionintasc
			}
		}
		else{//jika diurutkan dari besar-kecil/descending maka pengecekan akan dilanjutkan
			if(strcmp(p, "judul")==0){//jika patokan sortingnya judul maka
				selectionstrdesc(n, lagu);//akan memanggil prosedur selectionstrdesc
			}
			else{//jika patokan sortingnya durasi maka
				selectionintdesc(n, lagu);//akan memanggil prosedur selectionintdesc
			}
		}
	}
	int menit, detik;
	menit = time/60;
	detik = time%60;
	printf("Playlist (%dm %ds) :\n", menit, detik);//output
	print(n, lagu);//memanggil prosedut output untuk data yang telah di sorting
	
	return 0;
}