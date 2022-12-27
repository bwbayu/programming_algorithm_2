#include <stdio.h>

typedef struct{
	int pembilang, penyebut, num;
}pecahan;

void data(int n, pecahan p[n]){
	int i, temp=1;
	for(i = 0; i < n; i++){
		temp *= p[i].penyebut;
	}
	for(i = 0; i < n; i++){
		p[i].num = temp / p[i].penyebut * p[i].pembilang;
	}
}

void bubble(int n, pecahan p[n]){
	int i, swap;
	pecahan temp;
	do{
		swap=0;
		for(i = 0; i < n-1; i++){
			if(p[i].num > p[i+1].num){
				temp = p[i];
				p[i] = p[i+1];
				p[i+1] = temp;
				swap = 1;
			}
		}
	}while(swap == 1);
}

void quick(pecahan p[], int kiri, int kanan){
	int i, j;
	pecahan temp;
	i = kiri, j = kanan;
	
	do{
		while(p[i].num < p[kanan].num && i <= j){
			i++;
		}
		while(p[j].num > p[kiri].num && i <= j){
			j--;
		}
		
		if(i < j){
			temp = p[i];
			p[i] = p[j];
			p[j] = temp;
			i++; j--;
		}
	}while(i < j);
	
	if(kiri < j){
		quick(p, kiri, j);
	}
	if(i < kanan){
		quick(p, i, kanan);
	}
}

void print(int n, pecahan p[n]){
	int i;
	for(i = 0; i < n; i++){
		printf("%d", p[i].pembilang);
		if(i < n-1){
			printf(" ");
		}
	}
	printf("\n");
	for(i = 0; i < n; i++){
		printf("-");
		if(i < n-1){
			printf(" ");
		}
	}
	printf("\n");
	for(i = 0; i < n; i++){
		printf("%d", p[i].penyebut);
		if(i < n-1){
			printf(" ");
		}
	}
	printf("\n");
}

int main(){
	int n, i;
	char s;
	scanf("%d", &n);
	pecahan p[n];
	for(i = 0; i < n; i++){
		scanf("%d %d", &p[i].pembilang, &p[i].penyebut);
	}
	scanf(" %c", &s);
	data(n, p);
	if(s == 'b'){
		bubble(n, p);
	}
	else{
		quick(p, 0, n-1);
	}
	print(n, p);
	return 0;
}