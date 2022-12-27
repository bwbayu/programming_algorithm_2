#include "header.h"
/*Saya Bayu Wicaksono mengerjakan evaluasi 2 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main()
{
    char str[151];
    ndata = 0;
    // masukan
    scanf(" %150[^\n]s", &str);
    while (strcmp(str, "SELESAI;") != 0) // cek eop inputan
    {
        readquery(str); // memanggil prosedur untuk memulai pembacaan inputan
        scanf(" %150[^\n]s", &str);
    }
    tampil(); // memanggil prosedur untuk menampilkan output

    return 0;
}