#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TP8 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main()
{
    int x;
    do
    {
        // menampilkan menu awal
        printf("1. Menampilkan List Film Final\n");
        printf("2. Mencari Data\n");
        printf("3. Menambahkan Data\n");
        printf("0. Keluar Aplikasi\n");
        printf("==========================================\n");
        printf("Pilih Menu : ");
        scanf("%d", &x);
        // mengecek menu mana yang akan digunakan user
        if (x == 1)
        {
            listfilmfinal();
        }
        else if (x == 2)
        {
            listmenu2();
        }
        else if (x == 3)
        {
            listmenu3();
        }
        // mengecek apakah user masih ingin menggunakan aplikasinya atau tidak
        if (x != 0)
        {
            char a;
            printf("press y to continue | press n to exit (y/n) ... ");
            scanf(" %c", &a);
            if (a == 'y')
                system("cls");
            else if (a == 'n')
                x = 0;
            while (a != 'y' && a != 'n')
            {
                printf("press y to continue | press n to exit (y/n) ... ");
                scanf(" %c", &a);
                if (a == 'y')
                    system("cls");
                else if (a == 'n')
                    x = 0;
            }
        }
    } while (x != 0);

    return 0;
}