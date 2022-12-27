#include "header.h"

/*Saya Bayu Wicaksono mengerjakan UAS dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main()
{
    int sign = 0; // deklarasi variabel untuk tanda string yang dicari ada atau tidak
    char strx[501], str[501];
    // masukan
    scanf("%s", &strx);
    scanf(" %500[^\n]s", &str);

    start(str);           // memulai pembacaan pita
    group(getcw(), strx); // memulai mengecek kata yang dicari ada atau tidak di kata saat ini
    while (eop(str) == 0) // perulangan akan terus terjadi selama belum menemukan simbol akhir pita
    {
        inc(str);             // memanggil prosedur untuk memajukan pembacaan pita
        group(getcw(), strx); // memulai mengecek kata yang dicari ada atau tidak di kata saat ini
    }

    return 0;
}