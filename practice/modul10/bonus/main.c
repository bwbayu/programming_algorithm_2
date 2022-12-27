#include "header.h"

int main()
{
    // deklarasi
    char query[100], m;
    int n, sum = 0, error = 0;
    mahasiswa data[51];
    // masukan
    scanf("%d%c", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf(" %99[^\n]s", &query);
        sum += modifydata(query, sum, &data[sum], i, &error); // memanggil fungsi untuk menjalankan perintah
        while (error == 1)                                    // mengecek perintah error atau tidak
        {
            printf("masukkan revisi:\n"); // meminta masukan lagi
            error = 0;                    // mereset variabel error
            scanf(" %99[^\n]s", &query);
            sum += modifydata(query, sum, &data[sum], i, &error); // memanggil fungsi untuk menjalankan perintah revisi
        }
    }
    // menampilkan data
    for (int i = 0; i < sum; i++)
    {
        printf("%d. %s %s %s\n", (i + 1), data[i].nim, data[i].nama, data[i].nilai);
    }

    return 0;
}