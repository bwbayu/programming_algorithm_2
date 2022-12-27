#include "header.h"

/*Saya Bayu Wicaksono mengerjakan kuis 2 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

void sortasc(int n, makanan data[n]) // prosedur untuk sorting ascending
{
    int i, j, min;
    makanan temp; // deklarasi tipe bungkusan temp untuk menyimpan data
    for (i = 0; i < n - 1; i++)
    {
        min = i; // menginisialisasi untuk index min
        // perulangan untuk mencari index dengan nilai min dari index i+1 sampai index terakhir array
        for (j = i + 1; j < n; j++)
        {
            if (data[min].harga > data[j].harga)
            {
                min = j;
            }
        }
        // pertukaran posisi antara data[i] dengan data[min]
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}

void sortdesc(int n, makanan data[n]) // prosedur untuk sorting descending
{
    int i, j, max;
    makanan temp; // deklarasi tipe bungkusan temp untuk menyimpan data
    for (i = 0; i < n - 1; i++)
    {
        max = i; // menginisialisasi untuk index max
        // perulangan untuk mencari index dengan nilai max dari index i+1 sampai index terakhir array
        for (j = i + 1; j < n; j++)
        {
            if (data[max].kalori < data[j].kalori)
            {
                max = j;
            }
        }
        // pertukaran posisi antara data[i] dengan data[max]
        temp = data[i];
        data[i] = data[max];
        data[max] = temp;
    }
}

void binary1(int cari, int n, makanan data[n]) // prosedur untuk binary search yang di sorting ascending
{
    // pencarian data
    int i = 0, j = n, k, found = 0;
    while (i <= j && found == 0)
    {
        k = (i + j) / 2;           // melakukan pencarian dari tengah data
        if (data[k].harga == cari) // jika data yang dicari ada di dalam tipe terstruktur maka perulangan while akan berhenti
        {
            found = 1;
        }
        else // jika tidak ditemukan maka akan dilakukan pengecekan
        {
            // pengecekan untuk menentukan data yang dicari ada dibagian kanan / kiri
            if (data[k].harga > cari)
                j = k - 1;
            else
                i = k + 1;
        }
    }
    // keluaran
    if (found == 0)
    {
        printf("tidak ditemukan\n");
    }
    else
    {
        printf("nama makanan: %s\n", data[k].nama);
        printf("harga: %d\n", data[k].harga);
        printf("tempat penjualan: %s\n", data[k].tempat);
        printf("persen kalori: %d\n", data[k].kalori);
    }
}

void binary2(int cari, int n, makanan data[n]) // prosedur untuk binary search yang di sorting descending
{
    // pencarian data
    int i = 0, j = n, k, found = 0;
    while (i <= j && found == 0)
    {
        k = (i + j) / 2;            // melakukan pencarian dari tengah data
        if (data[k].kalori == cari) // jika data yang dicari ada di dalam tipe terstruktur maka perulangan while akan berhenti
        {
            found = 1;
        }
        else // jika tidak ditemukan maka akan dilakukan pengecekan
        {
            // pengecekan untuk menentukan data yang dicari ada dibagian kanan / kiri
            if (data[k].kalori < cari)
                j = k - 1;
            else
                i = k + 1;
        }
    }
    // keluaran
    if (found == 0)
    {
        printf("tidak ditemukan\n");
    }
    else
    {
        printf("nama makanan: %s\n", data[k].nama);
        printf("harga: %d\n", data[k].harga);
        printf("tempat penjualan: %s\n", data[k].tempat);
        printf("persen kalori: %d\n", data[k].kalori);
    }
}