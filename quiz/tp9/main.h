#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TP9 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main()
{
    char str[101], key;
    int n = 0;
    char temp, temp2;
    scanf(" %c %100[^\n]s", &key, &str);

    start(str);
    while (eop() == 0)
    {
        temp = getcc();
        inc(str);
        if (eop() == 0)
        {
            if (getcc() == ' ')
            {
                adv(str);
            }
            if (getcc() == key)
            {
                inc(str);
                if (eop() == 0)
                {
                    if (getcc() == ' ')
                        adv(str);
                    if (temp > 64 && temp < 91)
                    {
                        temp += 32;
                    }
                    temp2 = getcc();
                    if (temp2 > 64 && temp2 < 91)
                    {
                        temp2 += 32;
                    }
                    if (temp == temp2)
                        n++;
                }
            }
        }
    }

    if (n == 0)
        printf("Teks asli.\n");
    else
        printf("Teks palsu.\n");
    return 0;
}