#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TP10 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main()
{
    // deklarasi
    int hx,        // untuk variabel jumlah kata yang menandakan ciri-ciri kata palsu
        sign = 0,  // untuk tanda jika di suatu kata terdapat huruf yang yang menandakan ciri-ciri kata palsu
        sign1 = 0, // untuk tanda kelompok tiap kata
        sign2 = 0; // untuk tanda jika ditemukan/ada kata palsu
    char str[101], // untuk menampung pita
        cx;        // untuk variabel huruf/karakter yang menandakan ciri-ciri kata palsu
    kelkata kata[3];
    // inputan
    scanf(" %c %d", &cx, &hx);
    scanf(" %100[^\n]s", &str);

    // memulai pembacaan pita
    start(str, &sign, cx);
    // mengecek kata saat ini masuk ke kelompok mana

    if (getlen() == hx && sign == 1) // kondisi jika suatu kata memenuhi 2 ciri-ciri kata palsu
    {
        sign1 = 1;  // kata palsu akan masuk kelompok 1
        sign2 += 1; // tanda kata palsu ditemukan/ada akan bertambah
    }
    else
    {
        if (sign2 == 0) // selama kata palsu belum ditemukan maka kata tersebut akan masuk kelompok kata asli
        {
            sign1 = 2; // kata asli akan masuk kelompok 2
        }
        else // jika kata palsu sudah ditemukan dan kata tersebut tidak memenuhi 2 ciri-ciri kata palsu, kata tsb akan masuk kelompok kata dicurigai
        {
            sign1 = 3; // kata dicurigai akan masuk kelompok 3
        }
    }
    // memanggil prosedur kelompok untuk memasukkan kata saat ini berdasarkan kelompoknya
    kelompok(sign1, kata);
    // pembacaan pita akan terus dilakukan selama belum menemukan eop yaitu (;)
    while (eop(str) == 0)
    {
        // inisialisasi ulang
        sign = 0, sign1 = 0;
        // memanggil prosedur untuk memajukan kata
        inc(str, &sign, cx);
        // mengecek kata saat ini masuk ke kelompok mana
        if (getlen() == hx && sign == 1) // kondisi jika suatu kata memenuhi 2 ciri-ciri kata palsu
        {
            sign1 = 1;  // kata palsu akan masuk kelompok 1
            sign2 += 1; // tanda kata palsu ditemukan/ada akan bertambah
        }
        else
        {
            if (sign2 == 0) // selama kata palsu belum ditemukan maka kata tersebut akan masuk kelompok kata asli
            {
                sign1 = 2; // kata asli akan masuk kelompok 2
            }
            else // jika kata palsu sudah ditemukan dan kata tersebut tidak memenuhi 2 ciri-ciri kata palsu, kata tsb akan masuk kelompok kata dicurigai
            {
                sign1 = 3; // kata dicurigai akan masuk kelompok 3
            }
        }
        // memanggil prosedur kelompok untuk memasukkan kata saat ini berdasarkan kelompoknya
        kelompok(sign1, kata);
    }

    // output
    printf("KATA ASLI\n");
    // mengecek kelompok tersebut ada datanya atau tidak
    if (getidx(0) == 0)
    {
        printf("- TIDAK ADA.\n");
    }
    else
    {
        // jika ada, maka kelompok tersebut akan disorting dulu secara ascending sebelum ditampilkan
        sort(0, kata);
        for (int i = 0; i < getidx(0); i++)
        {
            printf("- %s\n", kata[0].tkata[i]);
        }
    }
    printf("\nKATA PALSU\n");
    // mengecek kelompok tersebut ada datanya atau tidak
    if (getidx(1) == 0)
    {
        printf("- TIDAK ADA.\n");
    }
    else
    {
        // jika ada, maka kelompok tersebut akan disorting dulu secara ascending sebelum ditampilkan
        sort(1, kata);
        for (int i = 0; i < getidx(1); i++)
        {
            printf("- %s\n", kata[1].tkata[i]);
        }
    }
    printf("\nKATA DICURIGAI\n");
    // mengecek kelompok tersebut ada datanya atau tidak
    if (getidx(2) == 0)
    {
        printf("- TIDAK ADA.\n");
    }
    else
    {
        // jika ada, maka kelompok tersebut akan disorting dulu secara ascending sebelum ditampilkan
        sort(2, kata);
        for (int i = 0; i < getidx(2); i++)
        {
            printf("- %s\n", kata[2].tkata[i]);
        }
    }

    return 0;
}