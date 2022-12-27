#include "header.h"
/*Saya Bayu Wicaksono mengerjakan evaluasi 2 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int eop(char str[]) // fungsi untuk mengecek eop pita
{
    if (str[idx] == ';') // jika bertemu eop pita maka akan mengembalikan nilai 1
    {
        return 1;
    }
    else // jika tidak akan mengembalikan nilai 0
    {
        return 0;
    }
}

void start(char str[]) // prosedur untuk memulai pembacaan pita
{
    // inisialisasi variabel idx dan length dengan 0
    idx = 0;
    length = 0;

    while (str[idx] == ' ') // jika bertemu spasi maka akan diabaikan
    {
        idx++;
    }

    while (str[idx] != ' ' && eop(str) == 0) // selama tidak bertemu spasi dan eop pita, kata akan ditampung di variabel global
    {
        w[length] = str[idx];
        idx++;
        length++;
    }

    w[length] = '\0'; // menutup kata dengan null
}

void inc(char str[]) // prosedur untuk memajukan pembacaan pita
{
    length = 0;             // inisialisasi ulang
    while (str[idx] == ' ') // jika bertemu spasi maka akan diabaikan
    {
        idx++;
    }

    while (str[idx] != ' ' && eop(str) == 0) // selama tidak bertemu spasi dan eop pita, kata akan ditampung di variabel global
    {
        w[length] = str[idx];
        idx++;
        length++;
    }

    w[length] = '\0'; // menutup kata dengan null
}

char *getkata() // fungsi untuk mendapatkan kata saat ini
{
    return w;
}

int cari(char src[], int *cidx) // fungsi untuk mencari nama barang masukan user di tipe struct
{
    int i = 0, f = 0;
    while (i < ndata && f == 0) // mencari data masukan user di tipe struct
    {
        if (strcmp(data[i].nama, src) == 0)
        {
            f = 1;
            *cidx = i;
        }
        else
            i++;
    }
    // mengembalikan nilai f
    if (f == 0)
        return 0;
    else
        return 1;
}

void insert() // prosedur untuk memasukkan data masukan user ke tipe struct
{
    strcpy(data[ndata].nama, temp.nama);
    strcpy(data[ndata].harga, temp.harga);
    strcpy(data[ndata].status, temp.status);
    ndata++;
}

void readquery(char str[]) // prosedur untuk pembacaan pita
{
    int cidx,          // deklarasi variabel untuk menyimpan index ketika suatu data ditemukan di tipe struct
        find;          // variabel untuk menampung return dari fungsi cari
    char tmp[151];     // deklarasi untuk menampung suatu data
    start(str);        // memulai pembacaan pita
    if (eop(str) == 0) // cek eop
    {
        if (strcmp(getkata(), "INSERT") == 0) // untuk insert
        {
            inc(str);          // memajukan pembacaan pita
            if (eop(str) == 0) // cek eop
            {
                strcpy(temp.nama, getkata()); // menyimpan data masukan user di tipe struct temp
                inc(str);                     // memajukan pembacaan pita
                if (eop(str) == 0)            // cek eop
                {
                    strcpy(temp.harga, getkata()); // menyimpan data masukan user di tipe struct temp
                    inc(str);                      // memajukan pembacaan pita
                    if (eop(str) == 1)             // cek eop
                    {
                        strcpy(temp.status, getkata()); // menyimpan data masukan user di tipe struct temp
                        insert();                       // memanggil prosedur untuk memasukkan data ke tipe struct
                    }
                }
            }
        }
        else if (strcmp(getkata(), "UPDATE") == 0) // untuk update
        {
            inc(str);          // memajukan pembacaan pita
            if (eop(str) == 0) // cek eop
            {
                strcpy(tmp, getkata()); // menyimpan data masukan user di tipe struct temp
                inc(str);               // memajukan pembacaan pita
                if (eop(str) == 0)      // cek eop
                {
                    find = cari(getkata(), &cidx); // mencari data masukan user di tipe struct
                    // cek data mana yang akan diubah
                    if (strcmp(tmp, "NAMA") == 0 && find == 1)
                    {
                        inc(str);                               // memajukan pembacaan pita
                        if (eop(str) == 1)                      // cek eop
                            strcpy(data[cidx].nama, getkata()); // mengganti data di tipe struct dengan data masukan user
                    }
                    else if (strcmp(tmp, "HARGA") == 0 && find == 1)
                    {
                        inc(str);                                // memajukan pembacaan pita
                        if (eop(str) == 1)                       // cek eop
                            strcpy(data[cidx].harga, getkata()); // mengganti data di tipe struct dengan data masukan user
                    }
                    else if (strcmp(tmp, "STATUS") == 0 && find == 1)
                    {
                        inc(str);                                 // memajukan pembacaan pita
                        if (eop(str) == 1)                        // cek eop
                            strcpy(data[cidx].status, getkata()); // mengganti data di tipe struct dengan data masukan user
                    }
                }
            }
        }
    }
}

int maxstr(char arr[101][151]) // fungsi untuk mencari string terpanjang suatu kolom
{
    int i, max = strlen(arr[0]);
    for (i = 1; i < ndata; i++)
        if (strlen(arr[i]) > max) // mencari string terpanjang
            max = strlen(arr[i]);
    max += 2;
    return max; // mengembalikan nilai string terpanjang
}

void garis(int total) // prosedur untuk menampilkan garis tabel
{
    for (int i = 0; i < total; i++)
        printf("=");
}

void spasi(int space) // prosedur untuk menampilkan spasi
{
    for (int i = 0; i < space; i++)
        printf(" ");
}

void tampil() // prosedur untuk menampilkan output
{
    int max[3],         // variabel untuk menampung nilai string terpanjang tiap kolom
        total;          // variabel untuk menampung panjang garis tabel
    char arr[101][151]; // variabel untuk menampung data tiap kolom

    // mencari str terpanjang di setiap kolom
    // untuk kolom nama
    for (int i = 0; i < ndata; i++)
        strcpy(arr[i], data[i].nama);
    max[0] = maxstr(arr);
    if (max[0] < strlen(" BARANG "))
        max[0] = strlen(" BARANG ");

    // untuk kolom harga
    for (int i = 0; i < ndata; i++)
        strcpy(arr[i], data[i].harga);
    max[1] = maxstr(arr);
    max[1] += 3;
    if (max[1] < strlen(" HARGA "))
        max[1] = strlen(" HARGA ");

    // untuk kolom status
    for (int i = 0; i < ndata; i++)
        strcpy(arr[i], data[i].status);
    max[2] = maxstr(arr);
    if (max[2] < strlen(" STATUS "))
        max[2] = strlen(" STATUS ");

    total = 4 + max[0] + max[1] + max[2]; // mencari total untuk tabel

    garis(total); // memanggil prosedur untuk garis tabel
    // menampilkan judul tabel
    printf("\n| BARANG ");
    spasi(max[0] - strlen(" BARANG "));

    printf("| HARGA ");
    spasi(max[1] - strlen(" HARGA "));

    printf("| STATUS ");
    spasi(max[2] - strlen(" STATUS "));
    printf("|\n");
    garis(total); // memanggil prosedur untuk garis tabel
    printf("\n");
    // menampilkan data
    for (int i = 0; i < ndata; i++)
    {
        printf("| %s", data[i].nama);
        spasi(max[0] - strlen(data[i].nama) - 1);
        printf("| Rp.%s", data[i].harga);
        spasi(max[1] - strlen(data[i].harga) - 3 - 1);
        printf("| %s", data[i].status);
        spasi(max[2] - strlen(data[i].status) - 1);
        printf("|\n");
    }
    garis(total); // memanggil prosedur untuk garis tabel
    printf("\n%d data ditampilkan.\n", ndata);
}