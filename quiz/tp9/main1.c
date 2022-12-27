#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TP9 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main()
{
    char str[101], key;
    int n = 0;
    char temp, temp2;
    // masukan
    scanf(" %c %100[^\n]s", &key, &str);
    char key2;
    // karena uppercase = lowercase
    if (key > 64 && key < 91) // jika key uppercase
    {
        key2 = key + 32; // key2 untuk kondisi lowercase
    }
    else // jika key lowercase
    {
        key2 = key - 32; // key2 untuk kondisi uppercase
    }

    start(str);        // memulai pembacaan pita/string
    while (eop() == 0) // perulangan terjadi selama prosedur eop() == 0
    {
        cek();                                 // memanggil prosedur cek untuk mengubah yang uppercase menjadi lowercase
        temp = getcc();                        // menampung karakter terbaru di variabel
        adv(str);                              // memanggil prosedur adv untuk increment karakter + jika bertemu spasi, maka spasi tsb akan dilewati hingga bertemu karakter baru
        if (getcc() == key || getcc() == key2) // mengecek apakah karakter saat ini sama dengan karakter kunci
        {
            adv(str);          // memanggil prosedur adv untuk increment karakter + jika bertemu spasi, maka spasi tsb akan dilewati hingga bertemu karakter baru
            cek();             // memanggil prosedur cek untuk mengubah yang uppercase menjadi lowercase
            temp2 = getcc();   // menampung karakter terbaru di variabel
            if (temp == temp2) // membandingkan 2 karakter yang mengapit karakter kunci
            {
                n++; // jika sama maka n bertambah
            }
            dec(str); // memanggil prosedur dec untuk decrement karakter + jika bertemu spasi, maka spasi tsb akan dilewati hingga bertemu karakter
        }
    }

    if (n == 0) // mengecek jumlah n
        printf("Teks asli.\n");
    else
        printf("Teks palsu.\n");
    return 0;
}