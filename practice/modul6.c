#include <stdio.h>
#include <string.h>

typedef struct{
	int n;
	char str[51][100];
}array;

void quick(int x, array arr[x], int l, int r){
	int i=l, j=r;
	char pivot[100], temp[100];
	strcpy(pivot, arr[x].str[(l+r/2)]);
	
	do{
		while(strcmp(arr[x].str[i], pivot) > 0 && i <= j){
			i++;
		}
		while(strcmp(arr[x].str[j], pivot) < 0 && i <= j){
			j--;
		}
		if(i < j){
			strcpy(temp, arr[x].str[i]);
			strcpy(arr[x].str[i], arr[x].str[j]);
			strcpy(arr[x].str[j], temp);
			
			i++; j--;
		}
	}while(i < j);
	
	if(l < j && j < r){
		quick(x, arr, l, j);
	}
	if(i < r && i > l){
		quick(x, arr, i, r);
	}
}

void merge(int x, int y, int z, array arr[]){
	int i=0, j=0, hitung=0, sisa;
	
	while(i < arr[x].n && j < arr[y].n){
		//printf("%s %s", arr[x].str[i], arr[y].str[j]);
		if(strcmp(arr[x].str[i], arr[y].str[j]) > 0){
			strcpy(arr[z].str[hitung], arr[x].str[i]);
			i++; hitung++;
		}
		else if(strcmp(arr[y].str[j], arr[x].str[i]) > 0){
			strcpy(arr[z].str[hitung], arr[y].str[j]);
			j++; hitung++;
		}
		else{
			strcpy(arr[z].str[hitung], arr[x].str[i]);
			i++; hitung++;
			strcpy(arr[z].str[hitung], arr[y].str[j]);
			j++; hitung++;
		}
	}
	if(i < arr[x].n){
		for(sisa = i; sisa < arr[x].n; sisa++){
			strcpy(arr[z].str[hitung], arr[x].str[sisa]);
			hitung++;
		}
	}
	
	if(j < arr[y].n){
		for(sisa = j; sisa < arr[y].n; sisa++){
			strcpy(arr[z].str[hitung], arr[y].str[sisa]);
			hitung++;
		}
	}
}

void print(int x, array arr[]){
	int i;
	for(i=0; i < arr[x].n; i++){
		printf("%s\n", arr[x].str[i]);
	}
	printf("\n");
}


int main(){
	int i, j;
	array arr[5];
	for(i=0; i<3; i++){
		scanf("%d", &arr[i].n);
		for(j=0; j<arr[i].n; j++){
			scanf(" %s", &arr[i].str[j]);
		}
	}
	for(i = 0; i < 3; i++){
		quick(i, arr, 0, (arr[i].n)-1);
	}
	
	arr[3].n = arr[0].n + arr[1].n;
	merge(0, 1, 3, arr);
	arr[4].n = arr[2].n + arr[3].n;
	merge(2, 3, 4, arr);
	print(4, arr);
	return 0;
}