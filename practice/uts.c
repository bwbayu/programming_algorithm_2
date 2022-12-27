#include <stdio.h>
#include <string.h>

typedef struct{
	char nama[100];
	int harga, sign;
	double kalori, lemak, t;
}minyak;

void insertion(int x, minyak data[5][51], int n[5]){
	int i, j;
	minyak key;
	
	for(i = 1; i < n[x]; i++){
		key = data[x][i];
		j = i - 1;
		while(j >= 0 && key.t < data[x][j].t){
			data[x][j + 1] = data[x][j];
			j--;
		}
		data[x][j + 1] = key;
	}
}

void selection(int x, minyak data[5][51], int n[5]){
	int i, j, min;
	minyak temp;

	for(i = 0; i < n[x]-1; i++){
		min = i;
		for(j = i + 1; j < n[x]; j++){
			if(data[x][min].t > data[x][j].t){
				min = j;
			}
		}
		temp = data[x][i];
		data[x][i] = data[x][min];
		data[x][min] = temp;
	}
}

void bubble(int x, minyak data[5][51], int n[5]){
	int i, swap;
	minyak temp;
	do{
		swap = 0;
		for(i = 0; i < n[x]-1; i++){
			if(data[x][i].t > data[x][i + 1].t){
				temp = data[x][i];
				data[x][i] = data[x][i + 1];
				data[x][i + 1] = temp;
				swap = 1;
			}
		}
	}while(swap == 1);
}

void quick(int x, minyak data[5][51], int n[5], int left, int right){
	int i = left, j = right;
	minyak temp;
	
	while(data[x][i].t < data[x][right].t && i <= j){
		i++;
	}
	while(data[x][j].t > data[x][left].t && i <= j){
		j--;
	}

	if(i < j){
		temp = data[x][i];
		data[x][i] = data[x][j];
		data[x][j] = temp;
		i++; j--;
	}

	if(left < j){
		quick(x, data, n, left, j);
	}
	if(i < right){
		quick(x, data, n, i, right);
	}
}

void merge(int x, int y, int z, minyak data[5][51], int n[5]){
	int i=0, j = 0, hitung = 0, sisa;

	while(i < n[x] && j > n[y]){
		if(data[x][i].t > data[y][j].t){
			data[z][hitung] = data[x][i];
			i++; hitung++;
		}
		else if(data[y][j].t < data[x][i].t){
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

void print(int x, minyak data[5][51], int n[5]){
	int i, j;
	for(i = 0; i < n[x]; i++){
		int temp1 = data[x][i].kalori;
		int temp2 = data[x][i].lemak;
		int temp3 = data[x][i].t;
		if(data[x][i].t == temp3){
			printf("%s %d %d %d - %d\n", data[x][i].nama, temp1, temp2, data[x][i].harga, temp3);
		}
		else{
			printf("%s %d %d %d - %0.2lf\n", data[x][i].nama, temp1, temp2, data[x][i].harga, data[x][i].t);
		}	
	}
}

void print1(int x, minyak data[5][51], int n[5]){
	int i, j;
	for(i = 0; i < n[x]; i++){
		int temp1 = data[x][i].kalori;
		int temp2 = data[x][i].lemak;
		int temp3 = data[x][i].t;
		if(data[x][i].t == temp3){
			printf("%s %d %d %d - %d Supplier %d\n", data[x][i].nama, temp1, temp2, data[x][i].harga, temp3, data[x][i].sign);
		}
		else{
			printf("%s %d %d %d - %0.2lf Supplier %d\n", data[x][i].nama, temp1, temp2, data[x][i].harga, data[x][i].t, data[x][i].sign);
		}	
	}
}

int main(){
	int i, j, n[5];
	minyak data[5][51];
	char sort[10];
	scanf("%s", &sort);
	for(i = 0; i < 3; i++){
		scanf("%d", &n[i]);
		for(j = 0; j < n[i]; j++){
			scanf("%s %lf %lf %d", &data[i][j].nama, &data[i][j].kalori, &data[i][j].lemak, &data[i][j].harga);
			data[i][j].t = data[i][j].harga / (data[i][j].kalori + data[i][j].lemak);
			data[i][j].sign = i+1;
		}
	}
	n[3] = n[0] + n[1];
	n[4] = n[3] + n[2];
	//--------------------------------------------
	if(strcmp(sort, "is")==0){
		insertion(0, data, n);
		insertion(1, data, n);
		insertion(2, data, n);
	}
	else if(strcmp(sort, "ss") == 0){
		selection(0, data, n);
		selection(1, data, n);
		selection(2, data, n);
	}
	else if(strcmp(sort, "bs") == 0){
		bubble(0, data, n);
		bubble(1, data, n);
		bubble(2, data, n);
	}
	else{
		quick(0, data, n, 0, n[0]-1);
		print1(0, data, n);
		//quick(1, data, n, 0, n[1]-1);
		//quick(2, data, n, 0, n[2]-1);
	}
	//merge(0, 1, 3, data, n);
	//merge(2, 3, 4, data, n);
	//--------------------------------------------------
	//printf("Per Supplier:\n");
	//for(i = 0; i < 3; i++){
	//	printf("Supplier %d:\n", i+1);
	//	print(i, data, n);
	//	printf("\n");
	//}
	//printf("Semua:\n");
	//print1(4, data, n);
		
	return 0;
}