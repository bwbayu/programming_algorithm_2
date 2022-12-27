#include "header.h"

/*Saya Bayu Wicaksono mengerjakan kuis 2 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main()
{
    // masukan
    int n, i;
    scanf("%d", &n);
    makanan data[n];
    for (i = 0; i < n; i++)
    {
        scanf("%s %d %s %d", data[i].nama, &data[i].harga, data[i].tempat, &data[i].kalori);
    }
    char str[10];
    int cari;
    scanf("%s %d", str, &cari);

    // pencarian data
    // melakukan pengecekan data mana yang akan diurutkan
    if (strcmp(str, "harga") == 0) // jika diurutkan berdasarkan harga maka akan diurutkan secara ascending
    {
        // memanggil prosedur
        sortasc(n, data);
        binary1(cari, n, data);
    }
    else if (strcmp(str, "kalori") == 0) // jika diurutkan berdasarkan kalori maka akan diurutkan secara descending
    {
        // memanggil prosedur
        sortdesc(n, data);
        binary2(cari, n, data);
    }

    return 0;
}