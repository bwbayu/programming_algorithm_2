#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[10], nama[100], nilai[10];
} mahasiswa; // tipe terstruktur
// deklarasi variabel global
int idx, length, sign;
char w[51];
// bagian untuk memulai, memajukan, dan mengakhiri mesin kata
void start(char str[]);
void inc(char str[]);
int eop(char str[]);
// bagian untuk mendapatkan atribut mesin kata
char *getcw();
// fungsi untuk menjalankan perintah masukan
int modifydata(char str[], int j, mahasiswa *data, int idxquery, int *error);