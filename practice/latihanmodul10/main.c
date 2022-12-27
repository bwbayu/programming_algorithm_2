#include "header.h"
// Program membaca kata satu per satu dari pita menggunakan mesin kata.
int main()
{
    // Deklarasi variabel jumlah perintah dan pita.
    int i, n;
    char tape[128];
    student data[52]; // Hardcode saja,kan cuma contoh.
    // Masukan.
    printf("Masukkan jumlah perintah : ");
    scanf("%d", &n);
    // Memulai perulangan untuk menjalankan setiap perintah.
    for (i = 0; i < n; i++)
    {
        scanf(" %127[^\n]s", &tape); // Pakai spasi sebelum lambang%.
        modifydata(tape, &data[i]);  // Belum termasuk error handling ...
    }
    for (i = 0; i < n; i++)
    {
        printf("%d. %s %s %s\n", (i + 1), data[i].nim, data[i].nama, data[i].nilai);
    }
    // Akhir program.
    return 0;
}