#include "header.h"

// prosedur memulai mesin kata.
void start(char str[])
{
    // inisialisasi indeks dan panjang kata
    idx = 0;
    wlen = 0;

    // jika karakter dalam pita adalah spasi, indeks terus maju
    while (str[idx] == ' ')
    {
        idx++;
    }

    // jika masukan berupa karakter selain spasi dan eop, kata diatur ke variabel global.
    while ((str[idx] != ' ') && (str[idx] != ';'))
    {
        cw[wlen] = str[idx];
        idx++;
        wlen++;
    }

    // mengatur agar kata saat ini indeks terakhir menjadi null
    cw[wlen] = '\0';
}

// prosed untuk mengosongkan kata yang dibaca dalam mesin kata.
void reset()
{
    // inisialisasi panjang kata dan kata saat ini agar null
    wlen = 0;
    cw[wlen] = '\0';
}

// fungsi untuk memeriksa akhir dari proses
int eop(char str[])
{
    // memeriksa apakah karakter saat ini merupakan simbol akhir pita
    if (str[idx] == ';')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// bagian memajukan mesin kata

// prosedur untuk memajukan kata
void inc(char str[])
{

    // inisialisasi ulang panjang kata
    wlen = 0;

    // jika karakter dalam pita adalah spasi, indeks trus maju
    while (str[idx] == ' ')
    {
        idx++;
    }

    // jika masukan berupa karakter selain spasi dan eop,  kata di atur ke variabel global
    while ((str[idx] != ' ') && (str[idx] != ';'))
    {
        cw[wlen] = str[idx];
        idx++;
        wlen++;
    }

    // mengatur agar kata saat ini indeks terakhirnya menjadi null
    cw[wlen] = '\0';
}

// bagian mendapatkan atribut mesin kata

// fungsi untuk mendapatkan panjang kata saaat ini
int getlen()
{
    return wlen;
}

// fungsi untuk mendapatkan kata saat ini
char *getcw()
{
    return cw;
}

// prosedur dan fungsi tambahan

// prosedur untuk memodifikasi mdata (data eror handling)
void modifydata(char str[], student *data)
{
    // memulai mesin kata
    start(str);

    if (strcmp(getcw(), "INSERT") == 0)
    {
        inc(str);
        if (strcmp(getcw(), "mahasiswa") == 0)
        {
            inc(str);
            strcpy(data->nim, getcw());
            inc(str);
            strcpy(data->nama, getcw());
            inc(str);
            strcpy(data->nilai, getcw());
        }
    }
}