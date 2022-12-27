#include <stdio.h>
#include <string.h>

typedef struct{
	int min, sec, tdur;
	char judul[100];
}song;

int total(int n, song lagu[n]);
void print(int n, song lagu[n], int time, char u[10]);
void insertion(int n, song lagu[n], char p[10]);
void selection(int n, song lagu[n], char p[10]);