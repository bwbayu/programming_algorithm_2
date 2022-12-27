#include <stdio.h>
#include <string.h>

// deklarasi tipe bungkusan mahasiswa.
typedef struct
{
    char nim[16];
    char nama[52];
    char nilai[8];
} student;

// deklarasi variabel

int idx,     // indeks dari karakter terakhir kata
    wlen;    // panjang kata
char cw[52]; // kata "saat ini" (current word)

// bagian untuk memulai mereset, dan mengakhiri mesin kata.
void start(char str[]);
void reset();
int eop(char str[]);

// bagian memajukan mesin kata
void inc(char str[]);

// bagian mendapatkan atribut mesin kata.
int getlen();
char *getcw();

// prosedur dan fungsi tambahan
void modifydata(char str[], student *data);
