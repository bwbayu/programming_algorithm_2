#include <stdio.h>
#include <string.h>

typedef struct{
	int n;
	char str[51][100];
}array;

void convert(int x, array data[5], int konso[4][51]){
	int num, i, j;
	for(i = 0; i < data[x].n; i++){
		num=0;
		for(j = 0; j < strlen(data[x].str[i]); j++){
			if(data[x].str[i][j] != 'a' && data[x].str[i][j] != 'i' && data[x].str[i][j] != 'e' && data[x].str[i][j] != 'u' && data[x].str[i][j] != 'o'){
				num++;
			}
		}
		konso[x][i] = num;
	}
}

void insertion(int x, array data[5], int konso[4][51]){
	int i, j, key;
	char temp[100];
	
	for(i = 1; i < data[x].n; i++){
		key = konso[x][i];
		strcpy(temp, data[x].str[i]);
		j = i-1;
		
		while(j >= 0 && key > konso[x][j]){
			konso[x][j + 1] = konso[x][j];
			strcpy(data[x].str[j + 1], data[x].str[j]);
			j--;
		}
		konso[x][j + 1] = key;
		strcpy(data[x].str[j + 1], temp);
	}
}

void selection(int x, array data[5], int konso[4][51]){
	int i, j, max, tmp;
	char temp[100];
	
	for(i = 0; i < data[x].n-1; i++){
		max = i;
		for(j = i+1; j < data[x].n; j++){
			if(konso[x][max] < konso[x][j]){
				max = j;
			}
		}
		//------------------
		tmp = konso[x][i];
		konso[x][i] = konso[x][max];
		konso[x][max] = tmp;
		//--------------------------------
		strcpy(temp, data[x].str[i]);
		strcpy(data[x].str[i], data[x].str[max]);
		strcpy(data[x].str[max], temp);
	}
}

void bubble(int x, array data[5], int konso[4][51]){
	int i, tmp, swap;
	char temp[100];
	do{
		swap = 0;
		for(i = 0; i < data[x].n-1; i++){
			if(konso[x][i] < konso[x][i+1]){
				strcpy(temp, data[x].str[i]);
				strcpy(data[x].str[i], data[x].str[i + 1]);
				strcpy(data[x].str[i + 1], temp);
				//-------------------------------------------
				tmp = konso[x][i];
				konso[x][i] = konso[x][i + 1];
				konso[x][i + 1] = tmp;
				//--------------------------------
				swap = 1;
			}
		}
	}while(swap == 1);
}

void quick(int x, array data[5], int konso[4][51], int left, int right){
	int i=left, j=right, pivot=konso[x][left+right/2], tmp;
	char temp[100];
	
	do{
		while(konso[x][i] > pivot && i <= j){
			i++;
		}
		while(konso[x][j] < pivot && i <= j){
			j--;
		}
		
		if(i < j){
			strcpy(temp, data[x].str[i]);
			strcpy(data[x].str[i], data[x].str[j]);
			strcpy(data[x].str[j], temp);
			//-------------------------------------------
			tmp = konso[x][i];
			konso[x][i] = konso[x][j];
			konso[x][j] = tmp;
			//-----------------------------
			i++; j--;
		}
	}while(i < j);
	
	if(left < j && j < right){
		quick(x, data, konso, left, j);
	}
	if(i < right && i > left){
		quick(x, data, konso, i, right);
	}
}

void merge(int x, int y, int z, array data[5], int konso[4][51]){
	int i=0, j=0, hitung=0, sisa;
	
	while(i < data[x].n && i < data[y].n){
		if(konso[x][i] > konso[y][j]){
			konso[z][hitung] = konso[x][i];
			strcpy(data[z].str[hitung], data[x].str[i]);
			i++; hitung++;
		}
		else if(konso[y][j] > konso[x][i]){
			konso[z][hitung] = konso[y][j];
			strcpy(data[z].str[hitung], data[y].str[j]);
			j++; hitung++;
		}
		else{
			konso[z][hitung] = konso[x][i];
			strcpy(data[z].str[hitung], data[x].str[i]);
			i++; hitung++;
			//---------------------------------------------
			konso[z][hitung] = konso[y][j];
			strcpy(data[z].str[hitung], data[y].str[j]);
			j++; hitung++;
		}
	}
	
	if(i < data[x].n){
		for(sisa = i; sisa < data[x].n; sisa++){
			konso[z][hitung] = konso[x][sisa];
			strcpy(data[z].str[hitung], data[x].str[sisa]);
			hitung++;
		}
	}
	if(j < data[y].n){
		for(sisa = j; sisa < data[y].n; sisa++){
			konso[z][hitung] = konso[y][sisa];
			strcpy(data[z].str[hitung], data[y].str[sisa]);
			hitung++;
		}
	}
}

void print(int x, array data[x]){
	int i;
	for(i=0; i < data[x].n; i++){
		printf("%s\n", data[x].str[i]);
	}
}

int main(){
	int i, j;
	char sorting[20];
	scanf("%s", &sorting);
	array data[5];
	int konso[4][51];
	for(i=0; i<3; i++){
		scanf("%d", &data[i].n);
		for(j=0; j<data[i].n; j++){
			scanf(" %s", &data[i].str[j]);
		}
		convert(i, data, konso);
	}
	data[3].n = data[0].n + data[1].n;
	data[4].n = data[2].n + data[3].n;
	
	insertion(0, data, konso);
	insertion(1, data, konso);
	insertion(2, data, konso);
	merge(0, 1, 3, data, konso);
	merge(2, 3, 4, data, konso);
	print(4, data);

	return 0;
}
