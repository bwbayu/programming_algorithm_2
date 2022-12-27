#include "header.h"

// Saya Bayu Wicaksono mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
// Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
// melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

int main()
{
    system("cls");
    // memulai query
    printf("Wilujeng Sumping di DBMS Koreksian Bayu\nVersi 1.0\n\n");
    char query[501];

    printf("dbms Bayu> ");
    scanf(" %500[^\n]s", &query);
    printf("\n");
    while (eopdbms(query) == 0) // cek query dbms
    {
        // baca file
        nuser = readuser("user.dat");
        nchar = readchar("character.dat");
        readquery(query);
        // perulangan
        printf("\n");
        printf("dbms Bayu> ");
        scanf(" %500[^\n]s", &query);
        printf("\n");
    }

    // tampilan akhir
    printf("Terima kasih telah menggunakan dbms bayu :)");
    printf("\nDibuat oleh Bayu Wicaksono dengan cinta.\n");
    system("exit");
    return 0;
}