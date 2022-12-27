#include "header.h"

/*Saya Bayu Wicaksono mengerjakan UAS dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main()
{
    // deklarasi variabel
    int n, sign = 0, // variabel tanda ada karakter yang dicari atau tidak
        i = 0,       // variabel untuk indeks pengelompokkan karakter
        j = 0;       // variabel untuk banyak kelompok karakter yang memiliki karakter yang dicari
    char kx, str[501];
    // masukan
    scanf("%d %c", &n, &kx);
    scanf(" %500[^\n]s", &str);

    start(str);        // memulai pembacaan pita
    if (getcc() == kx) // mengecek karakter saat ini, jika sama maka variabel sign akan menjadi 1
    {
        sign = 1;
    }
    if (eop() == 0) // jika karakter saat ini bukan simbol akhir pita maka variabel i akan diincrement
    {
        i++;
    }
    // mengecek variabel i
    if (i == n)
    {
        i = 0; // inisialisasi ulang variabel i
        // mengecek variabel sign
        if (sign == 1)
        {
            j++;      // increment
            sign = 0; // inisialisasi ulang variabel sign
        }
    }
    while (eop() == 0) // perulangan terjadi selama karakter saat ini bukan simbol akhir pita
    {
        inc(str);          // memajukan pembacaan pita
        if (getcc() == kx) // mengecek karakter saat ini, jika sama maka variabel sign akan menjadi 1
        {
            sign = 1;
        }
        if (eop() == 0) // jika karakter saat ini bukan simbol akhir pita maka variabel i akan diincrement
        {
            i++;
        }
        // mengecek variabel i
        if (i == n)
        {
            i = 0; // inisialisasi ulang variabel i
            // mengecek variabel sign
            if (sign == 1)
            {
                j++;      // increment
                sign = 0; // inisialisasi ulang variabel sign
            }
        }
    }
    // mengecek variabel i
    if (i == n)
    {
        i = 0; // inisialisasi ulang variabel i
        // mengecek variabel sign
        if (sign == 1)
        {
            j++;      // increment
            sign = 0; // inisialisasi ulang variabel sign
        }
    }
    printf("%d\n", j); // keluaran

    return 0;
}