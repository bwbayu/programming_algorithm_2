#include "header.h"

/*Saya Bayu Wicaksono mengerjakan UAS dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int eop(char str[]) // fungsi untuk memeriksa akhir dari pita
{
    // mengecek karakter saat ini
    if (str[idx] == '$') // jika sama dengan simbol akhir pita maka akan mengembalikan nilai 1
    {
        return 1;
    }
    else // jika tidak sama maka akan mengembalikan nilai 0
    {
        return 0;
    }
}

void start(char str[]) // prosedur untuk memulai pembacaan pita
{
    // inisialisasi variabel
    idx = 0;
    length = 0;
    // jika diawal kata ditemukan spasi maka akan dilewati
    while (str[idx] == ' ')
    {
        idx++;
    }
    // jika masukan berupa karakter selain spasi dan simbol akhir pita, kata akan ditampung di variabel global
    while (str[idx] != ' ' && eop(str) == 0)
    {
        cw[length] = str[idx];
        idx++;
        length++;
    }
    // mengatur agar index terakhir dari kata saat ini menjadi NULL
    cw[length] = '\0';
}

void inc(char str[]) // prosedur untuk memajukan kata
{
    // inisialisasi ulang variabel untuk panjang kata
    length = 0;
    // jika diawal kata ditemukan spasi maka akan dilewati
    while (str[idx] == ' ')
    {
        idx++;
    }
    // jika masukan berupa karakter selain spasi dan simbol akhir pita, kata akan ditampung di variabel global
    while (str[idx] != ' ' && eop(str) == 0)
    {
        cw[length] = str[idx];
        idx++;
        length++;
    }
    // mengatur agar index terakhir dari kata saat ini menjadi NULL
    cw[length] = '\0';
}
char *getcw() // fungsi untuk mendapatkan kata saat ini
{
    return cw;
}

void group(char str[], char src[]) // prosedur untuk mengecek string yang dicari ada atau tidak
{
    // inisialisasi variabel
    int i = 0, j = 0;
    // selama kata yang dicari dan kata saat ini belum sampai karakter terakhir maka perulangan akan terus terjadi
    while (str[i] != '\0' && src[j] != '\0')
    {
        // mengecek tiap karakternya
        if (str[i] != src[j])
        {
            i++;
            j = 0;
        }
        else
        {
            i++;
            j++;
        }
    }
    // jika kata yang dicari sampai hingga karakter terakhir artinya kata yang dicari tersebut ada di kata saat ini
    if (src[j] == '\0')
    {
        printf("%s\n", str);
    }
}