#include "header.h"

/*Saya Bayu Wicaksono mengerjakan UTS dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main(){
	int i, j, n[5];
	minyak data[5][51];
	char sort[10];
	scanf("%s", &sort);//input
	for(i = 0; i < 3; i++){
		scanf("%d", &n[i]);
		for(j = 0; j < n[i]; j++){
			scanf("%s %lf %lf %d", &data[i][j].nama, &data[i][j].kalori, &data[i][j].lemak, &data[i][j].harga);
			data[i][j].t = data[i][j].harga / (data[i][j].kalori + data[i][j].lemak);//mencari minyak goreng yang memenuhi kebutuhan customer
			data[i][j].sign = i+1;//tanda untuk data tersebut punya supplier berapa
		}
	}
	n[3] = n[0] + n[1];//mencari panjang array ke 3
	n[4] = n[3] + n[2];//mencari panjang array ke 4
	//mengecek metode mana yang akan digunakan
	if(strcmp(sort, "is")==0){//untuk kasus yang menggunakan metode sorting insertion
		insertion(0, data, n);
		insertion(1, data, n);
		insertion(2, data, n);
	}
	else if(strcmp(sort, "ss") == 0){//untuk kasus yang menggunakan metode sorting selection
		selection(0, data, n);
		selection(1, data, n);
		selection(2, data, n);
	}
	else if(strcmp(sort, "bs") == 0){//untuk kasus yang menggunakan metode sorting bubble
		bubble(0, data, n);
		bubble(1, data, n);
		bubble(2, data, n);
	}
	else{//untuk kasus yang menggunakan metode sorting quick
		quick(0, data, n, 0, n[0]-1);
		quick(1, data, n, 0, n[1]-1);
		quick(2, data, n, 0, n[2]-1);
	}
	//memanggil prosedur untuk menggabungkan 2 buah array
	merge(0, 1, 3, data, n);
	merge(2, 3, 4, data, n);
	
	//output
	printf("Per Supplier:\n");
	for(i = 0; i < 3; i++){
		printf("Supplier %d:\n", i+1);
		print(i, data, n);
		printf("\n");
	}
	printf("Semua:\n");
	print1(4, data, n);
		
	return 0;
}