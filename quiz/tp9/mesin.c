#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TP9 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

void start(char str[]) // prosedur untuk memulai pembacaan pita/string
{
    indeks = 0;       // menginisialisasikan variabel global indeks = 0
    cc = str[indeks]; // menampung karakter str[indeks] di variabel global cc
}

void dec(char str[]) // prosedur untuk decrement karakter dan jika bertemu spasi, maka spasi tsb akan dilewati hingga bertemu karakter baru
{
    indeks--;           // decrement
    cc = str[indeks];   // menampung karakter str[indeks] di variabel global cc
    while ((cc == ' ')) // perulangan jika bertemu spasi dan eop == 0 maka spasi akand dilewati hingga bertemu karakter
    {
        indeks--;         // decrement
        cc = str[indeks]; // menampung karakter str[indeks] di variabel global cc
    }
}

int eop() // fungsi untuk mengecek apakah bertemu ('.') atau tidak
{
    if (cc == '.') // jika karakter == ('.') maka akan mengembalikan nilai 1
    {
        return 1;
    }
    else // jika tidak maka akan mengembalikan nilai 0
    {
        return 0;
    }
}

void adv(char str[]) // prosedur untuk increment karakter dan jika bertemu spasi, maka spasi tsb akan dilewati hingga bertemu karakter
{
    indeks++;                           // increment
    cc = str[indeks];                   // menampung karakter str[indeks] di variabel global cc
    while ((cc == ' ') && (eop() == 0)) // perulangan jika bertemu spasi dan eop == 0 maka spasi akand dilewati hingga bertemu karakter
    {
        indeks++;         // increment
        cc = str[indeks]; // menampung karakter str[indeks] di variabel global cc
    }
}

char getcc() // fungsi untuk mengembalikan nilai karakter saat ini
{
    return cc;
}

void cek() // prosedur untuk mengubah karakter yang uppercase menjadi lowercase
{
    if (cc > 64 && cc < 91) // jika karakter uppercase
    {
        cc += 32; // karakter tsb diubah menjadi lowercase
    }
}