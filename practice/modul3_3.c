#include <stdio.h>

int idk(int n, int x){
	if(n < 1){
		return 0;
	}
	else{
		printf("(%d|%d)\n", n, x);
		return idk(n/2, x*2);
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	idk(n , m);
	
	return 0;
}