#include "header.h"

int total(int n, song lagu[n]){
	int i, temp=0;
	for(i = 0; i < n; i++){
		lagu[i].tdur = (lagu[i].min*60)+lagu[i].sec;
		temp += lagu[i].tdur;
	}
	return temp;
}

void print(int n, song lagu[n], int time, char u[10]){
	int i, menit, detik;
	menit = time/60;
	detik = time%60;
	printf("Playlist (%dm %ds) :\n", menit, detik);

	if(strcmp(u, "asc")==0){
		for(i = 0; i < n; i++){
			printf("%d.", lagu[i].min);
			if(lagu[i].sec < 10){
				printf("0%d", lagu[i].sec);
			}
			else{
				printf("%d", lagu[i].sec);
			}
			printf(" %s\n", lagu[i].judul);
		}
	}
	else if(strcmp(u, "desc")==0){
		for(i = n-1; i >= 0; i--){
			printf("%d.", lagu[i].min);
			if(lagu[i].sec < 10){
				printf("0%d", lagu[i].sec);
			}
			else{
				printf("%d", lagu[i].sec);
			}
			printf(" %s\n", lagu[i].judul);
		}
	}
}

void insertion(int n, song lagu[n], char p[10]){
	int i, j;
	song key;
	for(i = 1; i < n; i++){
		key = lagu[i];
		j = i-1;
		
		if(strcmp(p, "durasi")==0){
			while(j >= 0 && key.tdur < lagu[j].tdur){
				lagu[j+1] = lagu[j];
				j--;
			}
		}
		else if(strcmp(p, "judul")==0){
			while(j >= 0 && strcmp(key.judul, lagu[j].judul) < 0){
				lagu[j+1] = lagu[j];
				j--;
			}
		}
		lagu[j+1] = key;
	}
}

void selection(int n, song lagu[n], char p[10]){
	int i, j, min;
	for(i = 0; i < n-1; i++){
		song temp;
		min = i;
		for(j = i+1; j < n; j++){
			if(strcmp(p, "durasi")==0){
				if(lagu[min].tdur > lagu[j].tdur){
					min = j;
				}
			}
			else if(strcmp(p, "judul")==0){
				if(strcmp(lagu[min].judul, lagu[j].judul) > 0){
					min = j;
				}
			}
		}
		temp = lagu[i];
		lagu[i] = lagu[min];
		lagu[min] = temp;
	}
}