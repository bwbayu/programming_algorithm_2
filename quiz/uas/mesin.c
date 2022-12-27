#include "header.h"

/*Saya Bayu Wicaksono mengerjakan UAS dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

void start(char str[]) // prosedur untuk memulai pembacaan pita
{
    indeks = 0;       // inisialisasi variabel global indeks
    cc = str[indeks]; // menampung karakter saat ini di variabel global cc
}

int eop() // fungsi untuk mengecek simbol akhir pita
{
    // mengecek karakter saat ini
    if (cc == '$') // jika sama dengan simbol akhir pita maka akan mengembalikan nilai 1
    {
        return 1;
    }
    else // jika tidak sama maka akan mengembalikan nilai 0
    {
        return 0;
    }
}

void inc(char str[]) // prosedur untuk memajukan pembacaan pita
{
    indeks++;         // increment
    cc = str[indeks]; // menampung karakter saat ini di variabel global cc
    // perulangan untuk mengabaikan spasi
    while (cc == ' ' && eop() == 0)
    {
        indeks++;         // increment
        cc = str[indeks]; // menampung karakter saat ini di variabel global cc
    }
}

char getcc() // fungsi untuk mengembalikan nilai karakter saat ini
{
    return cc;
}