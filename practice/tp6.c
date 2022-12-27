#include <stdio.h>
#include <string.h>

typedef struct{
	int total;
	char nama[100];
}daftar;

void insertionasc(int x, int n[5], daftar data[][51]){
	int i, j;
	daftar key;
	for(i = 1; i < n[x]; i++){
		key = data[x][i];
		j = i - 1;
		while(j >= 0 && key.total < data[x][j].total){
			data[x][j + 1] = data[x][j];
			j--;
		}	
		data[x][j + 1] = key;
	}
}

void insertiondesc(int x, int n[5], daftar data[][51]){
	int i, j;
	daftar key;
	for(i = 1; i < n[x]; i++){
		key = data[x][i];
		j = i - 1;
		while(j >= 0 && key.total > data[x][j].total){
			data[x][j + 1] = data[x][j];
			j--;
		}	
		data[x][j + 1] = key;
	}
}

void selectionasc(int x, int n[5], daftar data[][51]){
	int i, j, min;
	daftar temp;
	for(i = 0; i < n[x]-1; i++){
		min = i;
		for(j = i+1; j < n[x]; j++){
			if(data[x][min].total > data[x][j].total){
				min = j;
			}
		}
		
		temp = data[x][i];
		data[x][i] = data[x][min];
		data[x][min] = temp;
	}
}

void selectiondesc(int x, int n[5], daftar data[][51]){
	int i, j, min;
	daftar temp;
	for(i = 0; i < n[x]-1; i++){
		min = i;
		for(j = i+1; j < n[x]; j++){
			if(data[x][min].total < data[x][j].total){
				min = j;
			}
		}
		
		temp = data[x][i];
		data[x][i] = data[x][min];
		data[x][min] = temp;
	}
}

void bubbleasc(int x, int n[5], daftar data[][51]){
	int i, swap;
	daftar temp;
	
	do{
		swap=0;
		for(i = 0; i < n[x]-1; i++){
			if(data[x][i].total > data[x][i+1].total){
				temp = data[x][i];
				data[x][i] = data[x][i+1];
				data[x][i+1] = temp;
				swap=1;
			}
		}
	}while(swap == 1);
}

void bubbledesc(int x, int n[5], daftar data[][51]){
	int i, swap;
	daftar temp;
	
	do{
		swap=0;
		for(i = 0; i < n[x]-1; i++){
			if(data[x][i].total < data[x][i+1].total){
				temp = data[x][i];
				data[x][i] = data[x][i+1];
				data[x][i+1] = temp;
				swap=1;
			}
		}
	}while(swap == 1);
}

void quickasc(int x, daftar data[][51], int l, int r){
	int i=l, j=r;
	daftar temp;
	int pivot = data[x][(l+r)/2].total;
	
	do{
		while(data[x][i].total < pivot && i <= j){
			i++;
		}
		while(data[x][j].total > pivot && i <= j){
			j--;
		}
		
		if(i < j){
			temp = data[x][i];
			data[x][i] = data[x][j];
			data[x][j] = temp;
			i++; j--;
		}
		
	}while(i < j);
	
	if(l < j && j < r){
		quickasc(x, data, l, j);
	}
	if(i < r && i > l){
		quickasc(x, data, i, r);
	}
}

void quickdesc(int x, daftar data[][51], int l, int r){
	int i=l, j=r;
	daftar temp;
	int pivot = data[x][(l+r)/2].total;
	
	do{
		while(data[x][i].total > pivot && i <= j){
			i++;
		}
		while(data[x][j].total < pivot && i <= j){
			j--;
		}
		
		if(i < j){
			temp = data[x][i];
			data[x][i] = data[x][j];
			data[x][j] = temp;
			i++; j--;
		}
		
	}while(i < j);
	
	if(l < j && j < r){
		quickdesc(x, data, l, j);
	}
	if(i < r && i > l){
		quickdesc(x, data, i, r);
	}
}

void mergeasc(int x, int y, int z, int n[5], daftar data[][51]){
	int i=0, j=0, hitung=0, sisa;
	
	while(i < n[x] && j < n[y]){
		if(data[x][i].total < data[y][j].total){
			data[z][hitung] = data[x][i];
			i++; hitung++;
		}
		else if(data[y][j].total < data[x][i].total){
			data[z][hitung] = data[y][j];
			j++; hitung++;
		}
		else{
			data[z][hitung] = data[x][i];
			i++; hitung++;
			data[z][hitung] = data[y][j];
			j++; hitung++;
		}
	}

	if(i < n[x]){
		for(sisa = i; sisa < n[x]; sisa++){
			data[z][hitung] = data[x][sisa];
			hitung++;
		}
	}
	if(j < n[y]){
		for(sisa = j; sisa < n[y]; sisa++){
			data[z][hitung] = data[y][sisa];
			hitung++;
		}
	}
}

void mergedesc(int x, int y, int z, int n[5], daftar data[][51]){
	int i=0, j=0, hitung=0, sisa;
	
	while(i < n[x] && j < n[y]){
		if(data[x][i].total > data[y][j].total){
			data[z][hitung] = data[x][i];
			i++; hitung++;
		}
		else if(data[y][j].total > data[x][i].total){
			data[z][hitung] = data[y][j];
			j++; hitung++;
		}
		else{
			data[z][hitung] = data[x][i];
			i++; hitung++;
			data[z][hitung] = data[y][j];
			j++; hitung++;
		}
	}

	if(i < n[x]){
		for(sisa = i; sisa < n[x]; sisa++){
			data[z][hitung] = data[x][sisa];
			hitung++;
		}
	}
	if(j < n[y]){
		for(sisa = j; sisa < n[y]; sisa++){
			data[z][hitung] = data[y][sisa];
			hitung++;
		}
	}
}

void print(int x, int n[5], daftar data[][51]){
	int i;
	
	for(i=0; i<n[x]; i++){
		printf("%s %d\n", data[x][i].nama, data[x][i].total);
	}
}

int main(){
	int i, j, t, harga, n[5];
	double berat;
	daftar data[5][51];
	for(i = 0; i < 3; i++){
		scanf("%d", &n[i]);
		for(j = 0; j < n[i]; j++){
			scanf("%s %d %lf", &data[i][j].nama, &harga, &berat);
			data[i][j].total = harga * berat;
		}
	}
	char m, sort[10];
	scanf("%d %c %s", &t, &m, &sort);

	//-------------------------------------------
	n[3]=n[0]+n[1];
	n[4]=n[3]+n[2];
	//------------------------------------------
	if(m == 'i'){
		if(strcmp(sort, "asc") == 0){
			insertionasc(0, n, data);
			insertionasc(1, n, data);
			insertionasc(2, n, data);
			mergeasc(0, 1, 3, n, data);
			mergeasc(2, 3, 4, n, data);
		}
		else{
			insertiondesc(0, n, data);
			insertiondesc(1, n, data);
			insertiondesc(2, n, data);
			mergedesc(0, 1, 3, n, data);
			mergedesc(2, 3, 4, n, data);
		}
	}
	else if(m == 's'){
		if(strcmp(sort, "asc") == 0){
			selectionasc(0, n, data);
			selectionasc(1, n, data);
			selectionasc(2, n, data);
			mergeasc(0, 1, 3, n, data);
			mergeasc(2, 3, 4, n, data);
		}
		else{
			selectiondesc(0, n, data);
			selectiondesc(1, n, data);
			selectiondesc(2, n, data);
			mergedesc(0, 1, 3, n, data);
			mergedesc(2, 3, 4, n, data);
		}
	}
	else if(m == 'b'){
		if(strcmp(sort, "asc") == 0){
			bubbleasc(0, n, data);
			bubbleasc(1, n, data);
			bubbleasc(2, n, data);
			mergeasc(0, 1, 3, n, data);
			mergeasc(2, 3, 4, n, data);
		}
		else{
			bubbledesc(0, n, data);
			bubbledesc(1, n, data);
			bubbledesc(2, n, data);
			mergedesc(0, 1, 3, n, data);
			mergedesc(2, 3, 4, n, data);
		}
	}
	else{
		if(strcmp(sort, "asc") == 0){
			quickasc(0, data, 0, n[0]-1);
			quickasc(1, data, 0, n[1]-1);
			quickasc(2, data, 0, n[2]-1);
			mergeasc(0, 1, 3, n, data);
			mergeasc(2, 3, 4, n, data);
		}
		else{
			quickdesc(0, data, 0, n[0]-1);
			quickdesc(1, data, 0, n[1]-1);
			quickdesc(2, data, 0, n[2]-1);
			mergedesc(0, 1, 3, n, data);
			mergedesc(2, 3, 4, n, data);
		}
	}
	//-----------------------------------------
	printf("Daftar Snack:\n-------------------------------\n");
	print(4, n, data);
	printf("===============================\n");
	printf("snack yang dibeli:\n-------------------------------\n");
	if(t >= data[4][0].total){
		int a=0, tharga=0;
		while(a < n[4] && data[4][a].total <= t){
			t -= data[4][a].total;
			tharga += data[4][a].total;
			printf("%s %d\n", data[4][a].nama, data[4][a].total);
			a++;
		}
		printf("===============================\n");
		printf("total pengeluaran : Rp. %d\n", tharga);
		printf("sisa budget       : Rp. %d\n", t);
		printf("===============================\n");
	}
	else{
		printf("tidak ada snack yang dibeli\n");
		printf("===============================\n");
		printf("total pengeluaran : Rp. 0\n");
		printf("sisa budget       : Rp. %d\n", t);
		printf("===============================\n");
	}
	
	return 0;
}
