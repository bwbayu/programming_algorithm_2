#include <stdio.h>
#include <string.h>
typedef struct{
	float jumlah, berat, kalori;
	char nama[50];
	int spasi1, spasi2;
}makanan;


void spasistr(int n, makanan m[n]){
	int i, max;
	max = strlen(m[0].nama);
	for(i = 1; i < n; i++){
		if(strlen(m[i].nama) > max){
			max = strlen(m[i].nama);
		}
	}
	for(i = 0; i < n; i++){
		m[i].spasi1 = (max-strlen(m[i].nama)) + 2;
	}
}

void spasinum(int n, makanan m[n]){
	int i, temp, max, tmp;
    for(i = 0; i < n; i++){
		temp=0;
		tmp = m[i].jumlah;
		while(tmp != 0){
			tmp /= 10;
			temp++;
		}
		m[i].spasi2 = temp;
	}
	max = m[0].spasi2;
	for(i = 1; i < n; i++){
		if(m[i].spasi2 > max){
			max = m[i].spasi2;
		}
	}
	for(i = 0; i < n; i++){
		m[i].spasi2 = (max-m[i].spasi2) + 2;
	}
}

void bubbleasc(int n, makanan m[n]){
	int i, swap;
	makanan temp;
	do{
		swap=0;
		for(i = 0; i < n-1; i++){
			if(m[i].kalori > m[i+1].kalori){
				temp = m[i];
				m[i] = m[i+1];
				m[i+1] = temp;
				swap = 1;
			}
		}
	}while(swap == 1);
}

void bubbledesc(int n, makanan m[n]){
	int i, swap;
	makanan temp;
	do{
		swap=0;
		for(i = 0; i < n-1; i++){
			if(m[i].kalori < m[i+1].kalori){
				temp = m[i];
				m[i] = m[i+1];
				m[i+1] = temp;
				swap = 1;
			}
		}
	}while(swap == 1);
}

void quickasc(makanan m[], int l, int r){
	int i, j;
	makanan temp;
	i = l, j = r;
	double pivot = m[(l + r)/2].kalori;

	do{
		while(m[i].kalori < pivot && i <= j){
			i++;
		}
		while(m[j].kalori > pivot && i <= j){
			j--;
		}
		
		if(i < j){
			temp = m[i];
			m[i] = m[j];
			m[j] = temp;
			i++; j--;
		}
	}while(i < j);
	
	if(l < j && j < r){
		quickasc(m, l, j);
	}
	if(i < r && i > l){
		quickasc(m, i, r);
	}
}

void quickdesc(makanan m[], int l, int r){
	int i, j;
	makanan temp;
	i = l, j = r;
	double pivot = m[(l + r)/2].kalori;

	do{
		while(m[i].kalori > pivot && i <= j){
			i++;
		}
		while(m[j].kalori < pivot && i <= j){
			j--;
		}
		
		if(i < j){
			temp = m[i];
			m[i] = m[j];
			m[j] = temp;
			i++; j--;
		}
	}while(i < j);
	
	if(l < j && j < r){
		quickdesc(m, l, j);
	}
	if(i < r && i > l){
		quickdesc(m, i, r);
	}
}


void print(int n, makanan m[n]){
	int i, j;
	printf("Daftar Menu Makanan :\n");
	for(i = 0; i < n; i++){
		printf("%s", m[i].nama);
		for(j = 0; j < m[i].spasi1; j++){
			printf(" ");
		}
		int x = m[i].jumlah;
		printf("%d", x);
		for(j = 0; j < m[i].spasi2; j++){
			printf(" ");
		}
		int y = m[i].berat;
		printf("%d\n", y);
	}
}

int main(){
	int n, i, j;
	char metode, urutan;
	scanf("%d", &n);
	makanan m[n];
	for(i = 0; i < n; i++){
		scanf("%s %f %f", &m[i].nama, &m[i].jumlah, &m[i].berat);
		m[i].kalori = m[i].jumlah / m[i].berat;
	}
	scanf(" %c %c", &metode, &urutan);
	spasistr(n, m);
	spasinum(n, m);

	if(metode == 'b'){
		if(urutan == 'a'){
			bubbleasc(n, m);
		}
		else{
			bubbledesc(n, m);
		}
	}
	else{
		if(urutan == 'a'){
			quickasc(m, 0, n-1);
		}
		else{
			quickdesc(m, 0, n-1);
		}
	}
	
	
	print(n, m);
	return 0;
}