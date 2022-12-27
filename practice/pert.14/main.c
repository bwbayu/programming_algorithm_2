#include "header.h"

int main()
{
    char pita[101];
    int n = 0;
    scanf("%100[^\n]s", pita);

    start(pita);
    if (getlength() % 2 == 1)
        n++;
    while (eop(pita) == 0)
    {
        inc(pita);
        if (getlength() % 2 == 1)
            n++;
    }

    printf("%d\n", n);

    return 0;
}

// hitung kata yang mengandung minimal 3 vokal
// start(pita);
//     if (cekvokal() > 2)
//         n++;
//     while (eop(pita) == 0)
//     {
//         inc(pita);
//         if (cekvokal() > 2)
//             n++;
//     }
//     printf("%d\n", n);

// hitung kata yang memiliki panjang ganjil
// start(pita);
//     if (getlength() % 2 == 1)
//         n++;
//     while (eop(pita) == 0)
//     {
//         inc(pita);
//         if (getlength() % 2 == 1)
//             n++;
//     }
//     printf("%d\n", n);

// tampilkan kata yang palindrom
// start(pita);
//     if (cekpalindrome() == 1)
//         printf("%s\n", getcc());
//     while (eop(pita) == 0)
//     {
//         inc(pita);
//         if (cekpalindrome() == 1)
//             printf("%s\n", getcc());
//     }