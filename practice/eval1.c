#include <stdio.h>
#include <string.h>

typedef struct{
	int nilai;
	char nama[51], nim[11];
}mahasiswa;

void selectionasc(int x, int n[7], mahasiswa data[][51]){
	int i, j, min;
	mahasiswa temp;
	for(i = 0; i < n[x]-1; i++){
		min = i;
		for(j = i+1; j < n[x]; j++){
			if(strcmp(data[x][min].nim, data[x][j].nim) > 0){
				min = j;
			}
		}
		temp = data[x][i];
		data[x][i] = data[x][min];
		data[x][min] = temp;
	}
}

void selectiondesc(int x, int n[7], mahasiswa data[][51]){
	int i, j, max;
	mahasiswa temp;
	for(i = 0; i < n[x]-1; i++){
		max = i;
		for(j = i+1; j < n[x]; j++){
			if(strcmp(data[x][max].nilai, data[x][j].nim) < 0){
				max = j;
			}
		}
		temp = data[x][i];
		data[x][i] = data[x][max];
		data[x][max] = temp;
	}
}

void mergeasc(int x, int y, int z, int n[7], mahasiswa data[][51]){
	int i=0, j=0;
	int hitung=0;
	int sisa;

	while(i < n[x] && j < n[y]){
		if(strcmp(data[x][i].nim, data[y][j].nim) > 0){
			data[z][hitung] = data[x][i];
			i++; hitung++;
		}
		else if(strcmp(data[y][j].nim, data[x][i].nim) < 0){
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

void bagi(int x, int y, int z, int n[7], mahasiswa data[][51]){
	int i, j, k=0;
	for(i = 0; i < n[y]; i++){
		data[y][i] = data[x][i];
	}
	for(j = i; j < n[x]; j++){
		data[z][k] = data[x][j];
		k++;
	}
}

void print(int x, int n[7], mahasiswa data[][51]){
	int i;
	printf("====================\n");
	for(i = 0; i < n[x]; i++){
		printf("%s %s %d\n", data[x][i].nim, data[x][i].nama, data[x][i].nilai);
	}
}

int main(){
	int n[7], i, j;
	mahasiswa data[7][51];
	for(i = 0; i < 3; i++){
		scanf("%d", &n[i]);
		for(j = 0; j < n[i]; j++){
			scanf("%s %s %d", &data[i][j].nim, &data[i][j].nama, &data[i][j].nilai);
		}
	}
	
	n[3]=n[0]+n[1];
	n[4]=n[2]+n[3];
	for(i = 0; i < 3; i++){
		selectionasc(i, n, data);
	}
	mergeasc(0, 1, 3, n, data);
	mergeasc(2, 3, 4, n, data);
	//---------------------------------------------------
	n[5] = n[4]/2;
	n[6] = n[5];
	bagi(4, 5, 6, n, data);
	for(i = 5; i < 7; i++){
		selectiondesc(i, n, data);
	}
	for(i = 4; i < 7; i++){
		print(i, n, data);
	}
	printf("====================\n");

	return 0;
}