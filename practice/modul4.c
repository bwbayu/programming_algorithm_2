#include <stdio.h>
#include <string.h>

void output(int n, char nama[n][10]){
	int i;
	printf("Hasil Sorting:\n");
	for(i = 0; i < n; i++){
		printf("%s\n", nama[i]);
	}
}

void insert(int n, char nama[n][10]){
	int i, j;
	char key[10];
	for(i = 1; i < n; i++){
		strcpy(key, nama[i]);
		j = i-1;
		while(j >= 0 && strcmp(key, nama[j]) < 0){
			strcpy(nama[j+1], nama[j]);
			j--;
		}
		strcpy(nama[j+1], key);
	}
	output(n, nama);
}

void select(int n, char nama[n][10]){
	int i, j;
	char temp[10];
	for(i = 0; i < n-1; i++){
		int min=i;
		for(j = i+1; j < n; j++){
			if(strcmp(nama[j], nama[i])>0){
				min = j;
			}
		}
		strcpy(temp, nama[i]);
		strcpy(nama[i], nama[min]);
		strcpy(nama[min], temp);
	}
	output(n, nama);
}

int main(){
	int n, i;
	scanf("%d", &n);
	char nama[n][10], metode[10];
	for(i = 0; i < n; i++){
		scanf("%s", &nama[i]);
	}
	scanf("%s", &metode);
	
	if(strcmp(metode, "insertion")==0){
		insert(n, nama);
	}
	else if(strcmp(metode, "selection")==0){
		select(n, nama);
	}
	
	
	return 0;
}