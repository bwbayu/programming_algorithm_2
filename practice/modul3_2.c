#include <stdio.h>

void biner(int n){
	if(n != 0){
		biner(n/2);
		printf("%d\n", n%2);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	biner(n);
	
	return 0;
}