#include <stdio.h>

void alfa(int n){
	if(n < 'z'){
		alfa(n+1);
	}
	printf("%c\n", n);
}

int main(){
	alfa('a');
	
	return 0;
}