#include "header.h"

// Saya Bayu Wicaksono mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
// Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
// melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

int readuser(char file[]) // fungsi untuk membaca file user
{
    int n = 0;
    FILE *fdata;
    fdata = fopen(file, "r");                                                                            // membuka file dengan mode read
    fscanf(fdata, "%s %s %s %s", &user[n].id_user, &user[n].username, &user[n].id_char, &user[n].level); // menyalin data dari file user ke tipe struct
    if (strcmp(user[n].id_user, "####") == 0)                                                            // mengecek eop file
        printf("File user.dat kosong.\n");                                                               // error handling
    else
        while (strcmp(user[n].id_user, "####") != 0) // menyalin data dari file user hingga bertemu eop file
        {
            n++; // increment
            fscanf(fdata, "%s %s %s %s", &user[n].id_user, &user[n].username, &user[n].id_char, &user[n].level);
        }
    fclose(fdata); // menutup file

    return n; // mengembalikan nilai banyak data dalam file user
}

int readchar(char file[]) // fungsi untuk membaca file character
{
    int n = 0;
    FILE *fdata;
    fdata = fopen(file, "r");                                                                      // membuka file dengan mode read
    fscanf(fdata, "%s %s %s", &character[n].id_char, &character[n].job_char, &character[n].skill); // menyalin data dari file character ke tipe struct
    if (strcmp(character[n].id_char, "####") == 0)                                                 // mengecek eop file
        printf("File user.dat kosong.\n");                                                         // error handling
    else
        while (strcmp(character[n].id_char, "####") != 0) // menyalin data dari file hingga bertemu eop file
        {
            n++;
            fscanf(fdata, "%s %s %s", &character[n].id_char, &character[n].job_char, &character[n].skill);
        }
    fclose(fdata); // menutup file

    return n; // mengembalikan nilai banyak data dalam file character
}

void writeuser(char file[]) // prosedur untuk menulis data ke file user
{
    FILE *fdata;
    fdata = fopen(file, "w");       // membuka file dengan mode write
    for (int i = 0; i < nuser; i++) // menyalin data dari tipe struct ke dalam file
        fprintf(fdata, "%s %s %s %s\n", user[i].id_user, user[i].username, user[i].id_char, user[i].level);
    fprintf(fdata, "#### #### #### ####\n"); // eop file
    fclose(fdata);                           // menutup file
}

void writechar(char file[]) // prosedur untuk menulis data ke file character
{
    FILE *fdata;
    fdata = fopen(file, "w");       // membuka file dengan mode write
    for (int i = 0; i < nchar; i++) // menyalin data dari tipe struct ke dalam file
        fprintf(fdata, "%s %s %s\n", character[i].id_char, character[i].job_char, character[i].skill);
    fprintf(fdata, "#### #### ####\n"); // eop file
    fclose(fdata);                      // menutup file
}

int eop(char str[]) // fungsi untuk mengecek eop pita
{
    while (str[idx] == ' ') // jika membaca spasi maka akan dilewati
    {
        idx++;
    }
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
    idx = 0;    // inisialisasi untuk index pita
    length = 0; // inisialisasi untuk panjang kata

    while (str[idx] == ' ') // jika bertemu spasi maka akan dilewati
    {
        idx++;
    }

    while (str[idx] != ' ' && eop(str) == 0) // selama tidak bertemu spasi dan eop pita, kata akan ditampung di variabel global
    {
        w[length] = str[idx];
        // increment
        idx++;
        length++;
    }

    w[length] = '\0'; // menutup kata dengan null
}

void inc(char str[]) // prosedur untuk memajukan pembacaan pita
{
    length = 0;             // inisialisasi ulang untuk panjang kata
    while (str[idx] == ' ') // jika bertemu spasi maka akan dilewati
    {
        idx++;
    }

    while (str[idx] != ' ' && eop(str) == 0) // selama tidak bertemu spasi dan eop pita, kata akan ditampung di variabel global
    {
        w[length] = str[idx];
        // increment
        idx++;
        length++;
    }

    w[length] = '\0'; // menutup kata dengan null
}

char *getkata() // fungsi untuk mengembalikan kata saat ini
{
    return w;
}

int cariuser(char src[], int sum, int *cidx) // fungsi untuk mencari data dari file user yang ada di tipe struct
{
    int n = sum - 1, i = 0, f = 0;

    while (i <= n && f == 0) // mencari dari index 0 sampai index terakhir atau sampai variabel f berubah menjadi 1, yang artinya data yang kita cari ada di dalam file
    {
        *cidx = (i + n) / 2;
        if (strcmp(user[*cidx].id_user, src) == 0) // jika data yang kita cari ditemukan maka variabel f akan diinisialisasikan dengan 1
            f = 1;
        else
        {
            if (strcmp(user[*cidx].id_user, src) > 0) // mengecek apakah data yang kita cari ada di sisi kanan atau kiri
                n = *cidx - 1;
            else
                i = *cidx + 1;
        }
    }
    // mengembalikan variabel f, sebagai tanda apakah data yang kita cari ditemukan atau tidak
    if (f == 0)
        return 0;
    else
        return 1;
}

int carichar(char src[], int sum, int *cidx) // fungsi untuk mencari data dari file character yang ada di tipe struct
{
    int n = sum - 1, i = 0, f = 0;

    while (i <= n && f == 0) // mencari dari index 0 sampai index terakhir atau sampai variabel f berubah menjadi 1, yang artinya data yang kita cari ada di dalam file
    {
        *cidx = (i + n) / 2;
        if (strcmp(character[*cidx].id_char, src) == 0) // jika data yang kita cari ditemukan maka variabel f akan diinisialisasikan dengan 1
            f = 1;
        else
        {
            if (strcmp(character[*cidx].id_char, src) > 0) // mengecek apakah data yang kita cari ada di sisi kanan atau kiri
                n = *cidx - 1;
            else
                i = *cidx + 1;
        }
    }
    // mengembalikan variabel f, sebagai tanda apakah data yang kita cari ditemukan atau tidak
    if (f == 0)
        return 0;
    else
        return 1;
}

void entryuser() // entry data untuk file user
{
    if (strcmp(edata.id_user, user[0].id_user) < 0) // jika data didepan
    {
        for (int i = nuser - 1; i >= 0; i--) // menggeser semua data file ke kanan
        {
            strcpy(user[i + 1].id_user, user[i].id_user);
            strcpy(user[i + 1].username, user[i].username);
            strcpy(user[i + 1].id_char, user[i].id_char);
            strcpy(user[i + 1].level, user[i].level);
        }
        nuser++; // increment
        // mengisi index 0 dengan data inputan
        strcpy(user[0].id_user, edata.id_user);
        strcpy(user[0].username, edata.username);
        strcpy(user[0].id_char, edata.id_char);
        strcpy(user[0].level, edata.level);
    }
    else if (strcmp(edata.id_user, user[nuser - 1].id_user) > 0) // jika data dibelakang
    {
        // index terakhir akan diisi oleh data inputan
        strcpy(user[nuser].id_user, edata.id_user);
        strcpy(user[nuser].username, edata.username);
        strcpy(user[nuser].id_char, edata.id_char);
        strcpy(user[nuser].level, edata.level);
        nuser++;
    }
    else // jika data ditengah
    {
        int i = 0, stop = 0;
        while (i < nuser && stop == 0) // mencari tempat untuk memasukkan data inputan ke tipe struct
        {
            if (strcmp(user[i].id_user, edata.id_user) > 0)
                stop = 1;
            else
                i++;
        }
        for (int j = nuser - 1; j >= i; j--) // menggeser semua data ke kanan dari index ditemukannya tempat untuk memasukkan data  user ke tipe struct
        {
            strcpy(user[j + 1].id_user, user[j].id_user);
            strcpy(user[j + 1].username, user[j].username);
            strcpy(user[j + 1].id_char, user[j].id_char);
            strcpy(user[j + 1].level, user[j].level);
        }
        // di index tsb akan diisi oleh data inputan
        strcpy(user[i].id_user, edata.id_user);
        strcpy(user[i].username, edata.username);
        strcpy(user[i].id_char, edata.id_char);
        strcpy(user[i].level, edata.level);
        nuser++;
    }
}

void entrychar() // entry data untuk file character
{
    if (strcmp(edata.id_char, character[0].id_char) < 0) // jika data didepan
    {
        for (int i = nchar - 1; i >= 0; i--) // menggeser semua data file ke kanan
        {
            strcpy(character[i + 1].id_char, character[i].id_char);
            strcpy(character[i + 1].job_char, character[i].job_char);
            strcpy(character[i + 1].skill, character[i].skill);
        }
        nchar++;
        // mengisi index 0 dengan data inputan
        strcpy(character[0].id_char, edata.id_char);
        strcpy(character[0].job_char, edata.job_char);
        strcpy(character[0].skill, edata.skill);
    }
    else if (strcmp(edata.id_char, character[nchar - 1].id_char) > 0) // jika data dibelakang
    {
        // index terakhir akan diisi oleh data inputan
        strcpy(character[nchar].id_char, edata.id_char);
        strcpy(character[nchar].job_char, edata.job_char);
        strcpy(character[nchar].skill, edata.skill);
        nchar++;
    }
    else // jika data ditengah
    {
        int i = 0, stop = 0;
        while (i < nchar && stop == 0) // mencari tempat untuk memasukkan data inputan ke tipe struct
        {
            if (strcmp(character[i].id_char, edata.id_char) > 0)
                stop = 1;
            else
                i++;
        }
        for (int j = nchar - 1; j >= i; j--) // menggeser semua data ke kanan dari index ditemukannya tempat untuk memasukkan data  user ke tipe struct
        {
            strcpy(character[j + 1].id_char, character[j].id_char);
            strcpy(character[j + 1].job_char, character[j].job_char);
            strcpy(character[j + 1].skill, character[j].skill);
        }
        // di index tsb akan diisi oleh data inputan
        strcpy(character[i].id_char, edata.id_char);
        strcpy(character[i].job_char, edata.job_char);
        strcpy(character[i].skill, edata.skill);
        nchar++;
    }
}

void updateuser(int x) // ubah data untuk file user
{
    // mengganti data yang ada di tipe struct pada index ke-x dengan data inputan
    strcpy(user[x].username, edata.username);
    strcpy(user[x].id_char, edata.id_char);
    strcpy(user[x].level, edata.level);
}

void updatechar(int x) // ubah data untuk file character
{
    // mengganti data yang ada di tipe struct pada index ke-x dengan data inputan
    strcpy(character[x].job_char, edata.job_char);
    strcpy(character[x].skill, edata.skill);
}

void deluser(int x) // hapus data untuk file user
{
    for (int i = x; i < nuser - 1; i++) // menggeser ke kiri data dari index ke-x
    {
        strcpy(user[i].id_user, user[i + 1].id_user);
        strcpy(user[i].username, user[i + 1].username);
        strcpy(user[i].id_char, user[i + 1].id_char);
        strcpy(user[i].level, user[i + 1].level);
    }
    // mengisi data index terakhir dengan null
    strcpy(user[nuser - 1].id_user, "\0");
    strcpy(user[nuser - 1].username, "\0");
    strcpy(user[nuser - 1].id_char, "\0");
    strcpy(user[nuser - 1].level, "\0");
    nuser -= 1;
}

void delchar(int x) // hapus data untuk file character
{
    for (int i = x; i < nchar - 1; i++) // menggeser ke kiri data dari index ke-x
    {
        strcpy(character[i].id_char, character[i + 1].id_char);
        strcpy(character[i].job_char, character[i + 1].job_char);
        strcpy(character[i].skill, character[i + 1].skill);
    }
    // mengisi data index terakhir dengan null
    strcpy(character[nchar - 1].id_char, "\0");
    strcpy(character[nchar - 1].job_char, "\0");
    strcpy(character[nchar - 1].skill, "\0");
    nchar -= 1;
}

void pentryuser(char str[]) // proses pembacaan pita untuk query entry untuk file user
{
    // data id user
    strcpy(edata.id_user, getkata());
    inc(str);
    if (eop(str) == 0) // cek op
    {
        // data username
        strcpy(edata.username, getkata());
        inc(str);
        if (eop(str) == 0) // cek eop
        {
            // data id char
            strcpy(edata.id_char, getkata());
            inc(str);
            if (eop(str) == 1 && strcmp(getkata(), "\0") != 0) // cek eop
            {
                // data level
                strcpy(edata.level, getkata());
                // memasukkan data ke tipe terstruktur
                entryuser(edata); // memanggil prosedur untuk entry data
                printf("Perintah yang dijalankan adalah\nENTRY user %s %s %s %s;\n", edata.id_user, edata.username, edata.id_char, edata.level);
                printf("\nData berhasil dimasukkan!\n");
                writeuser("user.dat"); // menulis data dari tipe struct ke file user.dat
            }
            else // error handling
            {
                printf("Query tidak tepat, silahkan memperbaiki query!\n");
            }
        }
        else // error handling
        {
            printf("Data inputan tidak lengkap atau query tidak tepat! Silahkan memperbaiki query!\n");
        }
    }
    else // error handling
    {
        printf("Data inputan tidak lengkap atau query tidak tepat! Silahkan memperbaiki query!\n");
    }
}

void pupdateuser(char str[], int cidx) // proses pembacaan pita untuk query ubah untuk file user
{
    // data id user
    strcpy(edata.id_user, getkata());
    // data username
    inc(str);
    if (eop(str) == 0) // cek eop
    {
        strcpy(edata.username, getkata());
        // data id char
        inc(str);
        if (eop(str) == 0) // cek eop
        {
            strcpy(edata.id_char, getkata());
            // data level
            inc(str);
            if (eop(str) == 1 && strcmp(getkata(), "\0") != 0) // cek eop
            {
                strcpy(edata.level, getkata());
                // memasukkan data ke tipe terstruktur
                updateuser(cidx); // memanggil prosedur untuk mengubah data
                printf("Perintah yang dijalankan adalah\nUBAH user %s %s %s %s;\n", edata.id_user, edata.username, edata.id_char, edata.level);
                printf("\nData berhasil diubah!\n");
                writeuser("user.dat"); // menulis data dari tipe struct ke file user.dat
            }
            else // error handling
            {
                printf("Query tidak tepat, silahkan memperbaiki query!\n");
            }
        }
        else // error handling
        {
            printf("Data inputan tidak lengkap atau query tidak tepat! Silahkan memperbaiki query!\n");
        }
    }
    else // error handling
    {
        printf("Data inputan tidak lengkap atau query tidak tepat! Silahkan memperbaiki query!\n");
    }
}

void pdeluser(char str[], int cidx) // proses pembacaan pita untuk query hapus untuk file user
{
    // data id user
    strcpy(edata.id_user, getkata());
    inc(str);
    if (eop(str) == 0) // cek eop
    {
        // data username
        strcpy(edata.username, getkata());
        inc(str);
        if (eop(str) == 0) // cek eop
        {
            // data id char
            strcpy(edata.id_char, getkata());
            inc(str);
            if (eop(str) == 1 && strcmp(getkata(), "\0") != 0) // cek eop
            {
                // data level
                strcpy(edata.level, getkata());
                // memasukkan data ke tipe terstruktur
                deluser(cidx); // memanggil prosedur untuk menghapus data
                printf("Perintah yang dijalankan adalah\nHAPUS user %s %s %s %s;\n", edata.id_user, edata.username, edata.id_char, edata.level);
                printf("\nData berhasil di hapus!\n");
                writeuser("user.dat"); // menulis data dari tipe struct ke file user.dat
            }
            else // error handling
            {
                printf("Query tidak tepat, silahkan memperbaiki query!\n");
            }
        }
        else // error handling
        {
            printf("Data inputan tidak lengkap atau query tidak tepat! Silahkan memperbaiki query!\n");
        }
    }
    else // error handling
    {
        printf("Data inputan tidak lengkap atau query tidak tepat! Silahkan memperbaiki query!\n");
    }
}

void pentrychar(char str[]) // proses pembacaan pita untuk query entry untuk file character
{
    // data id char
    strcpy(edata.id_char, getkata());
    inc(str);
    if (eop(str) == 0) // cek op
    {
        // data job
        strcpy(edata.job_char, getkata());
        inc(str);
        if (eop(str) == 1 && strcmp(getkata(), "\0") != 0) // cek eop
        {
            // data skill
            strcpy(edata.skill, getkata());
            // memasukkan data ke tipe terstruktur
            entrychar(); // memanggil prosedur untuk entry data
            printf("Perintah yang dijalankan adalah\nENTRY character %s %s %s;\n", edata.id_char, edata.job_char, edata.skill);
            printf("\nData berhasil dimasukkan!\n");
            writechar("character.dat"); // menulis data dari tipe struct ke file character.dat
        }
        else // error handling
        {
            printf("Query tidak tepat, silahkan memperbaiki query!\n");
        }
    }
    else // error handling
    {
        printf("Data inputan tidak lengkap atau query tidak tepat! Silahkan memperbaiki query!\n");
    }
}

void pupdatechar(char str[], int cidx) // proses pembacaan pita untuk query ubah untuk file character
{
    // data id char
    strcpy(edata.id_char, getkata());
    inc(str);
    if (eop(str) == 0) // cek eop
    {
        // data job
        strcpy(edata.job_char, getkata());
        inc(str);
        if (eop(str) == 1 && strcmp(getkata(), "\0") != 0) // cek eop
        {
            // data skill
            strcpy(edata.skill, getkata());
            // memasukkan data ke tipe terstruktur
            updatechar(cidx); // memanggil prosedur untuk mengubah data
            printf("Perintah yang dijalankan adalah\nUBAH character %s %s %s;\n", edata.id_char, edata.job_char, edata.skill);
            printf("\nData berhasil diubah!\n");
            writechar("character.dat"); // menulis data dari tipe struct ke file character.dat
        }
        else // error handling
        {
            printf("Query tidak tepat, silahkan memperbaiki query!\n");
        }
    }
    else // error handling
    {
        printf("Data inputan tidak lengkap atau query tidak tepat! Silahkan memperbaiki query!\n");
    }
}

void pdelchar(char str[], int cidx) // proses pembacaan pita untuk query hapus untuk file character
{
    // data id char
    strcpy(edata.id_char, getkata());
    inc(str);
    if (eop(str) == 0) // cek eop
    {
        // data job
        strcpy(edata.job_char, getkata());
        inc(str);
        if (eop(str) == 1 && strcmp(getkata(), "\0") != 0) // cek eop
        {
            // data skill
            strcpy(edata.skill, getkata());
            // memasukkan data ke tipe terstruktur
            delchar(cidx); // memanggil prosedur untuk menghapus data
            printf("Perintah yang dijalankan adalah\nUBAH character %s %s %s;\n", edata.id_char, edata.job_char, edata.skill);
            printf("\nData berhasil di hapus!\n");
            writechar("character.dat"); // menulis data dari tipe struct ke file character.dat
        }
        else // error handling
        {
            printf("Query tidak tepat, silahkan memperbaiki query!\n");
        }
    }
    else // error handling
    {
        printf("Data inputan tidak lengkap atau query tidak tepat! Silahkan memperbaiki query!\n");
    }
}

int maxstr(char arr[501][101]) // fungsi untuk menemukan string terpanjang pada suatu kolom
{
    int i, max = strlen(arr[0]);
    for (i = 1; i < nuser; i++) // mencari string terpanjang
        if (strlen(arr[i]) > max)
            max = strlen(arr[i]);
    max += 2;
    return max; // mengembalikan nilai string terpanjang
}

void garis(int tot) // prosedur untuk garis tabel
{
    for (int i = 0; i < tot; i++)
        printf("-");
}

void spasi(int scol) // prosedur untuk spasi tabel
{
    for (int i = 0; i < scol; i++)
    {
        printf(" ");
    }
}

void batas(int max[], int bdata) // prosedur untuk tabel
{
    printf("+");
    for (int i = 0; i < bdata; i++)
    {
        garis(max[i]);
        printf("+");
    }
    printf("\n");
}

void tampiluser() // prosedur untuk menampilkan data dari file user
{
    int max[5],         // variabel untuk menyimpan string terpanjang pada tiap kolom
        total;          // variabel untuk menampung panjang garis tabel
    char arr[501][101]; // variabel untuk menampung data dari file user per kolom

    // mencari str terpanjang di kolom id user
    for (int i = 0; i < nuser; i++)
        strcpy(arr[i], user[i].id_user);
    max[0] = maxstr(arr);
    if (max[0] - 2 < strlen("Id User"))
        max[0] = strlen(" Id User") + 2;

    // mencari str terpanjang di kolom username
    for (int i = 0; i < nuser; i++)
        strcpy(arr[i], user[i].username);
    max[1] = maxstr(arr);
    if (max[1] - 2 < strlen("Username"))
        max[1] = strlen(" Username") + 2;

    // mencari str terpanjang di kolom id char
    for (int i = 0; i < nuser; i++)
        strcpy(arr[i], user[i].id_char);
    max[2] = maxstr(arr);
    if (max[2] - 2 < strlen("Id Char"))
        max[2] = strlen(" Id Char") + 2;

    // mencari str terpanjang di kolom level
    for (int i = 0; i < nuser; i++)
        strcpy(arr[i], user[i].level);
    max[3] = maxstr(arr);
    if (max[3] - 2 < strlen("Level"))
        max[3] = strlen(" Level") + 2;

    total = 5 + max[0] + max[1] + max[2] + max[3]; // mencari total untuk tabel

    // menampilkan tabel + data user

    batas(max, 4);
    printf("| Id User");
    spasi(max[0] - strlen(" Id User"));

    printf("| Username");
    spasi(max[1] - strlen(" Username"));

    printf("| Id Char");
    spasi(max[2] - strlen(" Id Char"));

    printf("| Level");
    spasi(max[3] - strlen(" Level"));
    printf("|\n");

    batas(max, 4);
    for (int i = 0; i < nuser; i++)
    {
        printf("| %s", user[i].id_user);
        spasi(max[0] - strlen(user[i].id_user) - 1);
        printf("| %s", user[i].username);
        spasi(max[1] - strlen(user[i].username) - 1);
        printf("| %s", user[i].id_char);
        spasi(max[2] - strlen(user[i].id_char) - 1);
        printf("| %s", user[i].level);
        spasi(max[3] - strlen(user[i].level) - 1);
        printf("|\n");
    }
    batas(max, 4);
}

void tampilchar() // prosedur untuk menampilkan data dari file character
{
    int max[4],         // variabel untuk menyimpan string terpanjang pada tiap kolom
        total;          // variabel untuk menampung panjang garis tabel
    char arr[501][101]; // variabel untuk menampung data dari file user per kolom

    // mencari str terpanjang di kolom id char
    for (int i = 0; i < nchar; i++)
        strcpy(arr[i], character[i].id_char);
    max[0] = maxstr(arr);
    if (max[0] - 2 < strlen("Id Char"))
        max[0] = strlen(" Id Char") + 2;

    // mencari str terpanjang di kolom job char
    for (int i = 0; i < nchar; i++)
        strcpy(arr[i], character[i].job_char);
    max[1] = maxstr(arr);
    if (max[1] - 2 < strlen("Job Char"))
        max[1] = strlen(" Job Char") + 2;

    // mencari str terpanjang di kolom skill
    for (int i = 0; i < nchar; i++)
        strcpy(arr[i], character[i].skill);
    max[2] = maxstr(arr);
    if (max[2] - 2 < strlen("Skill"))
        max[2] = strlen(" Skill") + 2;

    total = 4 + max[0] + max[1] + max[2]; // mencari total untuk tabel

    // menampilkan tabel + data user

    batas(max, 3);
    printf("| Id Char");
    spasi(max[0] - strlen(" Id Char"));

    printf("| Job Char");
    spasi(max[1] - strlen(" Job Char"));

    printf("| Skill");
    spasi(max[2] - strlen(" Skill"));

    printf("|\n");

    batas(max, 3);
    for (int i = 0; i < nchar; i++)
    {
        printf("| %s", character[i].id_char);
        spasi(max[0] - strlen(character[i].id_char) - 1);
        printf("| %s", character[i].job_char);
        spasi(max[1] - strlen(character[i].job_char) - 1);
        printf("| %s", character[i].skill);
        spasi(max[2] - strlen(character[i].skill) - 1);
        printf("|\n");
    }
    batas(max, 3);
}

void join() // prosedur untuk menggabungkan tabel user dan character
{
    int cidx, find;
    for (int i = 0; i < nuser; i++)
    {
        // memasukkan data id user dan username ke tipe struct untuk join
        strcpy(datagame[i].id_user, user[i].id_user);
        strcpy(datagame[i].username, user[i].username);
        find = carichar(user[i].id_char, nchar, &cidx); // mencari id char pada file user di file character
        if (find == 1)                                  // jika menemukan id char di file character
        {
            // data job char dan skill akan dimasukkan ke tipe struct untuk join
            strcpy(datagame[i].job_char, character[cidx].job_char);
            strcpy(datagame[i].skill, character[cidx].skill);
        }
        else // jika id char tidak dari file user tidak ditemukan di file character, maka akan diganti -
        {
            strcpy(datagame[i].job_char, " - ");
            strcpy(datagame[i].skill, " - ");
        }
        // memasukkan data level ke tipe struct untuk join
        strcpy(datagame[i].level, user[i].level);
    }
}

void tampiljoin() // prosedur untuk menampilkan data hasil join table user dan character
{
    int max[6],         // variabel untuk menyimpan string terpanjang pada tiap kolom
        total;          // variabel untuk menampung panjang garis tabel
    char arr[501][101]; // variabel untuk menampung data dari file user per kolom

    // mencari str terpanjang di kolom id user
    for (int i = 0; i < nuser; i++)
        strcpy(arr[i], datagame[i].id_user);
    max[0] = maxstr(arr);
    if (max[0] - 2 < strlen("Id User"))
        max[0] = strlen(" Id User") + 2;

    // mencari str terpanjang di kolom username
    for (int i = 0; i < nuser; i++)
        strcpy(arr[i], datagame[i].username);
    max[1] = maxstr(arr);
    if (max[1] - 2 < strlen("Username"))
        max[1] = strlen(" Username") + 2;

    // mencari str terpanjang di kolom job char
    for (int i = 0; i < nuser; i++)
        strcpy(arr[i], datagame[i].job_char);
    max[2] = maxstr(arr);
    if (max[2] - 2 < strlen("Job Char"))
        max[2] = strlen(" Job Char") + 2;

    // mencari str terpanjang di kolom skill
    for (int i = 0; i < nuser; i++)
        strcpy(arr[i], datagame[i].skill);
    max[3] = maxstr(arr);
    if (max[3] - 2 < strlen("Skill"))
        max[3] = strlen(" Skill") + 2;

    // mencari str terpanjang di kolom level
    for (int i = 0; i < nuser; i++)
        strcpy(arr[i], datagame[i].level);
    max[4] = maxstr(arr);
    if (max[4] - 2 < strlen("Level"))
        max[4] = strlen(" Level") + 2;

    total = 6 + max[0] + max[1] + max[2] + max[3] + max[4]; // mencari total untuk tabel

    // menampilkan tabel + data user

    batas(max, 5);
    printf("| Id User");
    spasi(max[0] - strlen(" Id User"));

    printf("| Username");
    spasi(max[1] - strlen(" Username"));

    printf("| Job Char");
    spasi(max[2] - strlen(" Job Char"));

    printf("| Skill");
    spasi(max[3] - strlen(" Skill"));

    printf("| Level");
    spasi(max[4] - strlen(" Level"));

    printf("|\n");

    batas(max, 5);
    for (int i = 0; i < nuser; i++)
    {
        printf("| %s", datagame[i].id_user);
        spasi(max[0] - strlen(datagame[i].id_user) - 1);
        printf("| %s", datagame[i].username);
        spasi(max[1] - strlen(datagame[i].username) - 1);
        printf("| %s", datagame[i].job_char);
        spasi(max[2] - strlen(datagame[i].job_char) - 1);
        printf("| %s", datagame[i].skill);
        spasi(max[3] - strlen(datagame[i].skill) - 1);
        printf("| %s", datagame[i].level);
        spasi(max[4] - strlen(datagame[i].level) - 1);
        printf("|\n");
    }
    batas(max, 5);
}

void readquery(char str[]) // prosedur proses pembacaan query
{
    int nins = 0,                               // variabel untuk menyimpan jumlah query awal
        ins1 = 0, ins2 = 0, ins3 = 0, ins4 = 0, // variabel untuk menyimpan tanda tiap query awal
        errins = 0;                             // variabel untuk tanda apakah ada error ketika memasukkan query awal
    char temp[100];                             // variabel untuk menyimpan data inputan
    int find = 0,                               // variabel untuk menampung hasil return dari fungsi cari
        cidx;                                   // variabel untuk menampung index jika suatu data ditemukan dari fungsi cari
    start(str);                                 // memulai pembacaan pita

    // perulangan untuk menginisialisasikan query awal dan mengecek query awal
    while (strcmp(getkata(), "ENTRY") == 0 || strcmp(getkata(), "UBAH") == 0 || strcmp(getkata(), "HAPUS") == 0 || strcmp(getkata(), "TAMPIL") == 0 && eop(str) == 0)
    {
        if (strcmp(getkata(), "ENTRY") == 0) // jika query awal entry maka var ins1 akan diinisialisasikan menjadi 1
        {
            if (ins1 == 0) // mengecek apakah query awal entry sudah pernah ada atau belum
                ins1 = 1;
            else // jika sudah pernah ada maka var errins akan diinisialisasikan menjadi 1
                errins = 1;
        }
        else if (strcmp(getkata(), "UBAH") == 0) // jika query awal ubah maka var ins2 akan diinisialisasikan menjadi 1
        {
            if (ins2 == 0) // mengecek apakah query awal ubah sudah pernah ada atau belum
                ins2 = 1;
            else // jika sudah pernah ada maka var errins akan diinisialisasikan menjadi 1
                errins = 1;
        }
        else if (strcmp(getkata(), "HAPUS") == 0) // jika query awal hapus maka var ins3 akan diinisialisasikan menjadi 1
        {
            if (ins3 == 0) // mengecek apakah query awal hapus sudah pernah ada atau belum
                ins3 = 1;
            else // jika sudah pernah ada maka var errins akan diinisialisasikan menjadi 1
                errins = 1;
        }
        else // jika query awal tampil maka var ins4 akan diinisialisasikan menjadi 1
        {
            if (ins4 == 0) // mengecek apakah query tampil ubah sudah pernah ada atau belum
                ins4 = 1;
            else // jika sudah pernah ada maka var errins akan diinisialisasikan menjadi 1
                errins = 1;
        }
        nins++;
        inc(str); // melanjutkan pembacaan pita
    }

    if (nins > 2) // jika query awal lebih dari 2
    {
        printf("Silahkan memperbaiki query yang anda masukan!\n");
    }
    else if (nins == 0)
    {
        printf("Tidak ada perintah, silahkan memperbaiki query yang anda masukkan!\n");
    }
    else if (errins == 1) // jika query awal double, e.g. ENTRY ENTRY, UBAH UBAH, etc
    {
        printf("Silahkan memperbaiki query yang anda masukan!\n");
    }
    else
    {
        if (eop(str) == 1 && ins4 == 1 && nins == 1) // query tampil yang benar -> TAMPIL <nama tabel>;
        {
            // cek tabel mana yang akan ditampilkan
            if (strcmp(getkata(), "user") == 0)
            {
                printf("Berikut data dari file user!\n\n");
                tampiluser();
            }
            else if (strcmp(getkata(), "character") == 0)
            {
                printf("Berikut data dari file character!\n\n");
                tampilchar();
            }
            else
            {
                printf("Silahkan memperbaiki query, tabel %s tidak ditemukan!\n", getkata());
            }
        }
        else if (ins4 == 1 && nins > 1) // kondisi ketika query tampil yang salah -> ENTRY TAMPIL <nama tabel>; / TAMPIL HAPUS <nama tabel>;
        {
            printf("Silahkan memperbaiki query yang anda masukan!\n");
        }
        else if (ins4 == 1 && nins == 1) // menampilkan join
        {
            strcpy(temp, getkata());
            inc(str);
            // mengecek untuk join
            if (((strcmp(temp, "user") == 0 && strcmp(getkata(), "character") == 0) || (strcmp(temp, "character") == 0 && strcmp(getkata(), "user") == 0)) && eop(str) == 1 && strcmp(getkata(), "\0") != 0)
            {
                join(); // memanggil prosedur join untuk menggabungkan tabel user dan character
                printf("Berikut data dari join tabel antara user dan character!\n\n");
                tampiljoin(); // menampilkan hasil join
            }
            else
            {
                printf("Silahkan memperbaiki query yang anda masukan!\n");
            }
        }
        else // untuk query entry, ubah, hapus
        {
            // mengecek tabel mana yang akan dieksekusi
            if (strcmp(getkata(), "user") == 0)
            {
                inc(str);
                if (eop(str) == 0) // cek eop
                {
                    // mencari data inputan di dalam file user yang sudah dimasukkan ke tipe struct
                    find = cariuser(getkata(), nuser, &cidx);

                    if (ins1 == 1 && ins2 == 0 && ins3 == 0 && ins4 == 0) // entry doang
                    {
                        if (find == 1) // jika data ditemukan
                        {
                            printf("Data tersebut telah tersedia. Silahkan masukkan data lain atau query lainnya!\n");
                        }
                        else // jika data tidak ditemukan
                        {
                            printf("Data belum tersedia.\n\n");
                            pentryuser(str);
                        }
                    }
                    else if (ins1 == 0 && ins2 == 1 && ins3 == 0 && ins4 == 0) // ubah doang
                    {
                        if (find == 1) // jika data ditemukan
                        {
                            printf("Data ditemukan.\n\n");
                            pupdateuser(str, cidx);
                        }
                        else // jika data tidak ditemukan
                        {
                            printf("Data tidak ditemukan. Silahkan masukkan data lain atau query lainnya!\n");
                        }
                    }
                    else if (ins1 == 0 && ins2 == 0 && ins3 == 1 && ins4 == 0) // hapus doang
                    {
                        if (find == 1) // jika data ditemukan
                        {
                            printf("Data ditemukan.\n\n");
                            pdeluser(str, cidx);
                        }
                        else // jika data tidak ditemukan
                        {
                            printf("Data tidak ditemukan. Silahkan masukkan kembali data atau masukkan query lainnya!\n");
                        }
                    }
                    else if (ins1 == 1 && ins2 == 1 && ins3 == 0 && ins4 == 0) // entry, ubah
                    {
                        if (find == 1) // jika data ditemukan
                        {
                            // yg bakal dijalanin yang ubah
                            printf("Data ditemukan.\n\n");
                            pupdateuser(str, cidx);
                        }
                        else // jika data tidak ditemukan
                        {
                            // yg bakal dijalanin yg entry
                            printf("Data belum tersedia.\n\n");
                            pentryuser(str);
                        }
                    }
                    else if (ins1 == 1 && ins2 == 0 && ins3 == 1 && ins4 == 0) // entry hapus
                    {
                        if (find == 1) // jika data ditemukan
                        {
                            // yang bakal dijalanin yang hapus
                            printf("Data ditemukan.\n\n");
                            pdeluser(str, cidx);
                        }
                        else // jika data tidak ditemukan
                        {
                            // yang bakal dijalanin yang entry
                            printf("Data belum tersedia.\n\n");
                            pentryuser(str);
                        }
                    }
                    else // kondisi jika hapus,ubah/ubah,tampil/hapus,tampil
                    {
                        if (find == 1)
                            printf("Data yang akan dioperasikan tersedia, silahkan memperbaiki query!\n");

                        else
                            printf("Data yang akan dioperasikan tidak tersedia!\n\nSilahkan masukkan data atau query lain yang ingin dioperasikan!\n");
                    }
                }
                else
                {
                    printf("Silahkan memperbaiki query yang anda masukan!\n");
                }
            }
            else if (strcmp(getkata(), "character") == 0)
            {
                inc(str);
                if (eop(str) == 0) // cek eop
                {
                    // mencari data inputan di dalam file character yang sudah dimasukkan ke tipe struct
                    find = carichar(getkata(), nchar, &cidx);

                    if (ins1 == 1 && ins2 == 0 && ins3 == 0 && ins4 == 0) // entry doang
                    {
                        if (find == 1) // jika data ditemukan
                        {
                            printf("Data tersebut telah tersedia. Silahkan masukkan data lain atau query lainnya!\n");
                        }
                        else // jika data tidak ditemukan
                        {
                            printf("Data belum tersedia.\n\n");
                            pentrychar(str);
                        }
                    }
                    else if (ins1 == 0 && ins2 == 1 && ins3 == 0 && ins4 == 0) // ubah doang
                    {
                        if (find == 1) // jika data ditemukan
                        {
                            printf("Data ditemukan.\n\n");
                            pupdatechar(str, cidx);
                        }
                        else // jika data tidak ditemukan
                        {
                            printf("Data tidak ditemukan. Silahkan masukkan data lain atau query lainnya!\n");
                        }
                    }
                    else if (ins1 == 0 && ins2 == 0 && ins3 == 1 && ins4 == 0) // hapus doang
                    {
                        if (find == 1) // jika data ditemukan
                        {
                            printf("Data ditemukan.\n\n");
                            pdelchar(str, cidx);
                        }
                        else // jika data tidak ditemukan
                        {
                            printf("Data tidak ditemukan. Silahkan masukkan data lain atau query lainnya!\n");
                        }
                    }
                    else if (ins1 == 1 && ins2 == 1 && ins3 == 0 && ins4 == 0) // entry, ubah
                    {
                        if (find == 1) // jika data ditemukan
                        {
                            // yg bakal dijalanin yang ubah
                            printf("Data ditemukan.\n\n");
                            pupdatechar(str, cidx);
                        }
                        else // jika data tidak ditemukan
                        {
                            // yg bakal dijalanin yg entry
                            printf("Data belum tersedia.\n\n");
                            pentrychar(str);
                        }
                    }
                    else if (ins1 == 1 && ins2 == 0 && ins3 == 1 && ins4 == 0) // entry hapus
                    {
                        if (find == 1) // jika data ditemukan
                        {
                            // yang bakal dijalanin yang hapus
                            printf("Data ditemukan.\n\n");
                            pdelchar(str, cidx);
                        }
                        else // jika data tidak ditemukan
                        {
                            // yang bakal dijalanin yang entry
                            printf("Data belum tersedia.\n\n");
                            pentrychar(str);
                        }
                    }
                    else // kondisi jika hapus,ubah/ubah,tampil/hapus,tampil
                    {
                        if (find == 1)
                            printf("Data yang akan dioperasikan tersedia, silahkan memperbaiki query!\n");

                        else
                            printf("Data yang akan dioperasikan tidak tersedia!\n\nSilahkan masukkan data atau query lain yang ingin dioperasikan!\n");
                    }
                }
                else
                {
                    printf("Silahkan memperbaiki query yang anda masukan!\n");
                }
            }
            else // jika tabel yang dimasukkan salah
            {
                printf("Silahkan memperbaiki query, tabel %s tidak ditemukan.\n", getkata());
            }
        }
    }
}

int eopdbms(char str[]) // fungsi untuk mengecek eop query
{
    if (strcmp(str, "jangan lupa bahagia hari ini;") == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}