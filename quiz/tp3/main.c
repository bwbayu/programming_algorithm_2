#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TP3 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main(){
	int n, i;
	scanf("%d", &n);//inputan banyak pengecekan
	int a[n], b[n], x[n];
	for(i = 0; i < n; i++){
		scanf("%d %d %d", &a[i], &b[i], &x[i]);//inputan jumlah virus pada jam ke-0 dan 1, serta jam yg ingin di cek jumlah virusnya
	}
	int sum[n];
	for(i = 0; i < n; i++){
		sum[i] = fib(a[i], b[i], x[i]);//mamanggil fungsi fib
	}
	for(i = 0; i < n; i++){
		printf("%d\n", sum[i]);//output
	}
	return 0;
}