#include "header.h"

int main(){
	int n, i, j;
	scanf("%d", &n);
	char m[20], u[10], p[10];
	song lagu[n];
	for(i = 0; i < n; i++){
		scanf("%s %d.%d", &lagu[i].judul, &lagu[i].min, &lagu[i].sec);
	}
	scanf("%s %s %s", &m, &u, &p);
	
	int time = total(n, lagu);

	if(strcmp(m, "insertion")==0){
		insertion(n, lagu, p);
	}
	else if(strcmp(m, "selection")==0){
		selection(n, lagu, p);
	}
	print(n, lagu, time, u);
	
	
	
	return 0;
}