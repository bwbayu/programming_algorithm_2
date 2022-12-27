#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TP10 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

void start(char str[], int *sign, char cx) // prosedur untuk memulai pembacaan pita
{
    // inisialisasi variabel
    idx = 0;
    indeks[0] = 0;
    indeks[1] = 0;
    indeks[2] = 0;
    length = 0;
    // jika diawal kata ditemukan spasi maka akan dilewati
    while (str[idx] == ' ')
    {
        idx++;
    }
    // jika masukan berupa karakter dan spasi selain titik koma dan koma, kata akan ditampung di variabel global
    while ((str[idx] != ';') && str[idx] != ',')
    {
        // jika karakter dipita sama dengan huruf yang menandakan ciri-ciri kata palsu maka variabel sign berubah menjadi 1
        if (str[idx] == cx)
        {
            *sign = 1;
        }
        cw[length] = str[idx];
        idx++;
        length++;
    }
    // mengatur agar index terakhir dari kata saat ini menjadi NULL
    cw[length] = '\0';
}

int eop(char str[]) // fungsi untuk memeriksa akhir dari proses
{
    // jika karakter saat ini merupakan simbol akhir pita
    if (str[idx] == ';')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void inc(char str[], int *sign, char cx) // prosedur untuk memajukan kata
{
    length = 0; // inisialisasi ulang variabel untuk panjang kata

    // jika karakter sebelum kata adalah spasi atau koma akan dilewati
    while (str[idx] == ' ' || str[idx] == ',')
    {
        idx++;
    }

    // jika masukan berupa karakter dan spasi selain koma dan titik koma, kata tsb akan ditampung di variabel global
    while ((str[idx] != ';') && str[idx] != ',')
    {
        // jika karakter dipita sama dengan huruf yang menandakan ciri-ciri kata palsu maka variabel sign berubah menjadi 1
        if (str[idx] == cx)
        {
            *sign = 1;
        }
        cw[length] = str[idx];
        idx++;
        length++;
    }
    // mengatur agar index terakhir dari kata saat ini menjadi NULL
    cw[length] = '\0';
}

int getlen() // fungsi untuk mendapatkan panjang kata saat ini
{
    return length;
}

char *getcw() // fungsi untuk mendapatkan kata saat ini
{
    return cw;
}

void kelompok(int sign, kelkata kata[3]) // prosedur untuk pengelompokkan kata
{
    // mengecek kata saat ini masuk ke kelompok mana
    if (sign == 1)
    {
        strcpy(kata[1].tkata[indeks[1]], cw);
        indeks[1]++;
    }
    else if (sign == 2)
    {
        strcpy(kata[0].tkata[indeks[0]], cw);
        indeks[0]++;
    }
    else
    {
        strcpy(kata[2].tkata[indeks[2]], cw);
        indeks[2]++;
    }
}

int getidx(int tipe) // fungsi untuk mendapatkan banyak data suatu kelompok
{
    // mengecek banyak data kelompok mana yang akan dikembalikan
    if (tipe == 0)
    {
        return indeks[0];
    }
    else if (tipe == 1)
    {
        return indeks[1];
    }
    else if (tipe == 2)
    {
        return indeks[2];
    }
}

void sort(int n, kelkata kata[n]) // prosedur untuk mengurutkan secara ascending
{
    char temp[101]; // variabel tampungan
    for (int i = 0; i < indeks[n] - 1; i++)
    {
        int min = i; // inisialisasi untuk index min
        // perulangan untuk mencari kata dengan nilai minimum pada array
        for (int j = i + 1; j < indeks[n]; j++)
        {
            if (strcmp(kata[n].tkata[min], kata[n].tkata[j]) > 0)
            {
                min = j;
            }
        }
        // pertukaran posisi
        strcpy(temp, kata[n].tkata[i]);
        strcpy(kata[n].tkata[i], kata[n].tkata[min]);
        strcpy(kata[n].tkata[min], temp);
    }
}