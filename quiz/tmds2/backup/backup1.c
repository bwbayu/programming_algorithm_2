#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    // file user
    char id_user[10], username[100], level[10];
    // file karakter
    char id_char[10], job_char[50], skill[100];
} game;

int idx, length; // variabel global untuk index pita dan panjang kata
char w[51];      // variabel global untuk kata dalam pita
int nuser;
int nchar;
game user[501];
game character[501];
game edata;

int readuser(char file[], game user[])
{
    int n = 0;
    FILE *fdata;
    fdata = fopen(file, "r");
    fscanf(fdata, "%s %s %s %s", &user[n].id_user, &user[n].username, &user[n].id_char, &user[n].level);
    if (strcmp(user[n].id_user, "####") == 0)
        printf("File user.dat kosong.\n");
    else
        while (strcmp(user[n].id_user, "####") != 0)
        {
            n++;
            fscanf(fdata, "%s %s %s %s", &user[n].id_user, &user[n].username, &user[n].id_char, &user[n].level);
        }
    fclose(fdata);

    return n;
}

int readchar(char file[], game character[])
{
    int n = 0;
    FILE *fdata;
    fdata = fopen(file, "r");
    fscanf(fdata, "%s %s %s", &character[n].id_char, &character[n].job_char, &character[n].skill);
    if (strcmp(character[n].id_char, "####") == 0)
        printf("File user.dat kosong.\n");
    else
        while (strcmp(character[n].id_char, "####") != 0)
        {
            n++;
            fscanf(fdata, "%s %s %s", &character[n].id_char, &character[n].job_char, &character[n].skill);
        }
    fclose(fdata);

    return n;
}

void writeuser(char file[], game user[])
{
    FILE *fdata;
    fdata = fopen(file, "w");
    for (int i = 0; i < nuser; i++)
        fprintf(fdata, "%s %s %s %s\n", user[i].id_user, user[i].username, user[i].id_char, user[i].level);
    fprintf(fdata, "#### #### #### ####\n");
    fclose(fdata);
}

void writechar(char file[], game character[])
{
    FILE *fdata;
    fdata = fopen(file, "w");
    for (int i = 0; i < nchar; i++)
        fprintf(fdata, "%s %s %s\n", character[i].id_char, character[i].job_char, character[i].skill);
    fprintf(fdata, "#### #### ####\n");
    fclose(fdata);
}

int eop(char str[])
{
    if (str[idx] == ';')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void start(char str[])
{
    idx = 0;
    length = 0;

    while (str[idx] == ' ')
    {
        idx++;
    }

    while (str[idx] != ' ' && eop(str) == 0)
    {
        w[length] = str[idx];
        idx++;
        length++;
    }

    w[length] = '\0';
}

void inc(char str[])
{
    length = 0;
    while (str[idx] == ' ')
    {
        idx++;
    }

    while (str[idx] != ' ' && eop(str) == 0)
    {
        w[length] = str[idx];
        idx++;
        length++;
    }

    w[length] = '\0';
}

char *getkata()
{
    return w;
}

int cariuser(char src[], int sum, game user[], int *cidx)
{
    // for (int i = 0; i < nuser; i++)
    //     printf("%s %s %s %s\n", user[i].id_user, user[i].username, user[i].id_char, user[i].level);
    int n = sum - 1, i = 0, f = 0;

    while (i <= n && f == 0)
    {
        *cidx = (i + n) / 2;
        if (strcmp(user[*cidx].id_user, src) == 0)
            f = 1;
        else
        {
            if (strcmp(user[*cidx].id_user, src) > 0)
                n = *cidx - 1;
            else
                i = *cidx + 1;
        }
    }
    if (f == 0)
        return 0;
    else
        return 1;
}

int carichar(char src[], int sum, game character[], int *cidx)
{
    int n = sum - 1, i = 0, f = 0;

    while (i <= n && f == 0)
    {
        *cidx = (i + n) / 2;
        if (strcmp(character[*cidx].id_char, src) == 0)
            f = 1;
        else
        {
            if (strcmp(character[*cidx].id_char, src) > 0)
                n = *cidx - 1;
            else
                i = *cidx + 1;
        }
    }
    if (f == 0)
        return 0;
    else
        return 1;
}

void entryuser(game edata, game user[]) // entry data buat user, dibuat untuk data dari depan, tengah, belakang
{
    if (strcmp(edata.id_user, user[0].id_user) < 0) // data didepan
    {
        for (int i = nuser - 1; i >= 0; i--)
        {
            strcpy(user[i + 1].id_user, user[i].id_user);
            strcpy(user[i + 1].username, user[i].username);
            strcpy(user[i + 1].id_char, user[i].id_char);
            strcpy(user[i + 1].level, user[i].level);
        }
        nuser++;
        strcpy(user[0].id_user, edata.id_user);
        strcpy(user[0].username, edata.username);
        strcpy(user[0].id_char, edata.id_char);
        strcpy(user[0].level, edata.level);
    }
    else if (strcmp(edata.id_user, user[nuser - 1].id_user) > 0) // data dibelakang
    {
        strcpy(user[nuser].id_user, edata.id_user);
        strcpy(user[nuser].username, edata.username);
        strcpy(user[nuser].id_char, edata.id_char);
        strcpy(user[nuser].level, edata.level);
        nuser++;
    }
    else // data ditengah
    {
        int i = 0, stop = 0;
        while (i < nuser && stop == 0)
        {
            if (strcmp(user[i].id_user, edata.id_user) > 0)
                stop = 1;
            else
                i++;
        }
        for (int j = nuser - 1; j >= i; j--)
        {
            strcpy(user[j + 1].id_user, user[j].id_user);
            strcpy(user[j + 1].username, user[j].username);
            strcpy(user[j + 1].id_char, user[j].id_char);
            strcpy(user[j + 1].level, user[j].level);
        }
        strcpy(user[i].id_user, edata.id_user);
        strcpy(user[i].username, edata.username);
        strcpy(user[i].id_char, edata.id_char);
        strcpy(user[i].level, edata.level);
        nuser++;
    }
}

void entrychar(game edata, game character[]) // entry data buat charakter, dibuat untuk data dari depan, tengah, belakang
{
    if (strcmp(edata.id_char, character[0].id_char) < 0) // data didepan
    {
        for (int i = nchar - 1; i >= 0; i--)
        {
            strcpy(character[i + 1].id_char, character[i].id_char);
            strcpy(character[i + 1].job_char, character[i].job_char);
            strcpy(character[i + 1].skill, character[i].skill);
        }
        nchar++;
        strcpy(character[0].id_char, edata.id_char);
        strcpy(character[0].job_char, edata.job_char);
        strcpy(character[0].skill, edata.skill);
    }
    else if (strcmp(edata.id_char, character[nchar - 1].id_char) > 0) // data dibelakang
    {
        strcpy(character[nchar].id_char, edata.id_char);
        strcpy(character[nchar].job_char, edata.job_char);
        strcpy(character[nchar].skill, edata.skill);
        nchar++;
    }
    else // data ditengah
    {
        int i = 0, stop = 0;
        while (i < nchar && stop == 0)
        {
            if (strcmp(character[i].id_char, edata.id_char) > 0)
                stop = 1;
            else
                i++;
        }
        for (int j = nchar - 1; j >= i; j--)
        {
            strcpy(character[j + 1].id_char, character[j].id_char);
            strcpy(character[j + 1].job_char, character[j].job_char);
            strcpy(character[j + 1].skill, character[j].skill);
        }
        strcpy(character[i].id_char, edata.id_char);
        strcpy(character[i].job_char, edata.job_char);
        strcpy(character[i].skill, edata.skill);
        nchar++;
    }
}

void updateuser(game edata, game user[], int x) // cari primary key, ganti data lain
{
    strcpy(user[x].username, edata.username);
    strcpy(user[x].id_char, edata.id_char);
    strcpy(user[x].level, edata.level);
}

void updatechar(game edata, game character[], int x) // cari primary key, ganti data lain
{
    strcpy(character[x].job_char, edata.job_char);
    strcpy(character[x].skill, edata.skill);
}

void deluser(game user[], int x) // cari primary key, dibuat untuk hapus data di awal, akhir, tengah
{
    for (int i = x; i < nuser - 1; i++)
    {
        strcpy(user[i].id_user, user[i + 1].id_user);
        strcpy(user[i].username, user[i + 1].username);
        strcpy(user[i].id_char, user[i + 1].id_char);
        strcpy(user[i].level, user[i + 1].level);
    }
    strcpy(user[nuser - 1].id_user, "\0");
    strcpy(user[nuser - 1].username, "\0");
    strcpy(user[nuser - 1].id_char, "\0");
    strcpy(user[nuser - 1].level, "\0");
    nuser -= 1;
}

void delchar(game character[], int x) // cari primary key, dibuat untuk hapus data diawal, akhir, tengah
{
    for (int i = x; i < nchar - 1; i++)
    {
        strcpy(character[i].id_char, character[i + 1].id_char);
        strcpy(character[i].job_char, character[i + 1].job_char);
        strcpy(character[i].skill, character[i + 1].skill);
    }
    strcpy(character[nchar - 1].id_char, "\0");
    strcpy(character[nchar - 1].job_char, "\0");
    strcpy(character[nchar - 1].skill, "\0");
    nchar -= 1;
}

void readquery(char str[])
{
    int nins = 0, ins1 = 0, ins2 = 0, ins3 = 0, ins4 = 0;
    char temp[100];
    int find = 0, cidx;
    start(str);

    while (strcmp(getkata(), "ENTRY") == 0 || strcmp(getkata(), "UBAH") == 0 || strcmp(getkata(), "HAPUS") == 0 || strcmp(getkata(), "TAMPIL") == 0 && eop(str) == 0)
    {
        if (strcmp(getkata(), "ENTRY") == 0)
            ins1 = 1;
        else if (strcmp(getkata(), "UBAH") == 0)
            ins2 = 1;
        else if (strcmp(getkata(), "HAPUS") == 0)
            ins3 = 1;
        else
            ins4 = 1;
        nins++;
        inc(str);
    }

    if (nins > 2) // jika query awal lebih dari 2
    {
        printf("Silahkan memperbaiki query yang anda masukan!\n");
    }
    else
    {
        if (eop(str) == 1 && ins4 == 1 && nins == 1) // query tampil yang benar -> TAMPIL <nama tabel>;
        {
            if (strcmp(getkata(), "user") == 0)
            {
                printf("Berikut data dari file user!\n\n");
                for (int i = 0; i < nuser; i++)
                    printf("%s %s %s %s\n", user[i].id_user, user[i].username, user[i].id_char, user[i].level);
            }
            else if (strcmp(getkata(), "character") == 0)
            {
                printf("\nBerikut data dari file character!\n\n");
                for (int i = 0; i < nchar; i++)
                    printf("%s %s %s\n", character[i].id_char, character[i].job_char, character[i].skill);
            }
            else
            {
                printf("Silahkan memperbaiki query, tabel %s tidak ditemukan!\n", getkata());
            }
        }
        else if (ins4 == 1 && nins > 1) // kondisi ketika query tampil yang salah -> ENTRY TAMPIL <nama tabel>; / TAMPIL HAPUS <nama tabel>;
        {
            printf("Silahkan memperbaiki query!\n");
        }
        else if (ins4 == 1 && nins == 1) // menampilkan join
        {
            strcpy(temp, getkata());
            inc(str);
            if (((strcmp(temp, "user") == 0 && strcmp(getkata(), "character") == 0) || (strcmp(temp, "character") == 0 && strcmp(getkata(), "user") == 0)) && eop(str) == 1)
            {
            }
        }
        else // untuk query entry, ubah, hapus
        {
            if (strcmp(getkata(), "user") == 0)
            {
                inc(str);
                if (eop(str) == 0) // cek eop
                {
                    find = cariuser(getkata(), nuser, user, &cidx);

                    if (ins1 == 1 && ins2 == 0 && ins3 == 0 && ins4 == 0) // entry doang
                    {
                        if (find == 1) // jika data ditemukan
                        {
                            printf("Data tersebut telah tersedia. Silahkan masukkan data lain atau query lainnya!\n");
                        }
                        else // jika data tidak ditemukan
                        {
                            // data id user
                            strcpy(edata.id_user, getkata());
                            // data username
                            inc(str);
                            if (eop(str) == 0) // cek op
                            {
                                strcpy(edata.username, getkata());
                                // data id char
                                inc(str);
                                if (eop(str) == 0) // cek eop
                                {
                                    strcpy(edata.id_char, getkata());
                                    // data level
                                    inc(str);
                                    if (eop(str) == 1) // cek eop
                                    {
                                        strcpy(edata.level, getkata());
                                        // memasukkan data ke tipe terstruktur
                                        entryuser(edata, user);
                                        printf("Perintah yang dijalankan adalah\nENTRY user %s %s %s %s;\n", edata.id_user, edata.username, edata.id_char, edata.level);
                                        writeuser("user.dat", user);
                                    }
                                    else
                                    {
                                        printf("Silahkan memperbaiki query!\n");
                                    }
                                }
                                else
                                {
                                    printf("Silahkan memperbaiki query!\n");
                                }
                            }
                            else
                            {
                                printf("Silahkan memperbaiki query!\n");
                            }
                        }
                    }
                    else if (ins1 == 0 && ins2 == 1 && ins3 == 0 && ins4 == 0) // ubah doang
                    {
                        if (find == 1) // jika data ditemukan
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
                                    if (eop(str) == 1) // cek eop
                                    {
                                        strcpy(edata.level, getkata());
                                        // memasukkan data ke tipe terstruktur
                                        updateuser(edata, user, cidx);
                                        printf("Perintah yang dijalankan adalah\nUBAH user %s %s %s %s;\n", edata.id_user, edata.username, edata.id_char, edata.level);
                                        writeuser("user.dat", user);
                                    }
                                    else
                                    {
                                        printf("Silahkan memperbaiki query!\n");
                                    }
                                }
                                else
                                {
                                    printf("Silahkan memperbaiki query!\n");
                                }
                            }
                            else
                            {
                                printf("Silahkan memperbaiki query!\n");
                            }
                        }
                        else
                        {
                            printf("Data tidak ditemukan. Silahkan masukkan data lain atau query lainnya!\n");
                        }
                    }
                    else if (ins1 == 0 && ins2 == 0 && ins3 == 1 && ins4 == 0) // hapus doang
                    {
                        if (find == 1) // jika data ditemukan
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
                                    if (eop(str) == 1) // cek eop
                                    {
                                        strcpy(edata.level, getkata());
                                        // memasukkan data ke tipe terstruktur
                                        deluser(user, cidx);
                                        printf("Perintah yang dijalankan adalah\nHAPUS user %s %s %s %s;\n", edata.id_user, edata.username, edata.id_char, edata.level);
                                        writeuser("user.dat", user);
                                    }
                                    else
                                    {
                                        printf("Silahkan memperbaiki query!\n");
                                    }
                                }
                                else
                                {
                                    printf("Silahkan memperbaiki query!\n");
                                }
                            }
                            else
                            {
                                printf("Silahkan memperbaiki query!\n");
                            }
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
                                    if (eop(str) == 1) // cek eop
                                    {
                                        strcpy(edata.level, getkata());
                                        // memasukkan data ke tipe terstruktur
                                        updateuser(edata, user, cidx);
                                        printf("Perintah yang dijalankan adalah\nUBAH user %s %s %s %s;\n", edata.id_user, edata.username, edata.id_char, edata.level);
                                        writeuser("user.dat", user);
                                    }
                                    else
                                    {
                                        printf("Silahkan memperbaiki query!\n");
                                    }
                                }
                                else
                                {
                                    printf("Silahkan memperbaiki query!\n");
                                }
                            }
                            else
                            {
                                printf("Silahkan memperbaiki query!\n");
                            }
                        }
                        else // jika data tidak ditemukan
                        {
                            // yg bakal dijalanin yg entry
                            // data id user
                            strcpy(edata.id_user, getkata());
                            // data username
                            inc(str);
                            if (eop(str) == 0) // cek op
                            {
                                strcpy(edata.username, getkata());
                                // data id char
                                inc(str);
                                if (eop(str) == 0) // cek eop
                                {
                                    strcpy(edata.id_char, getkata());
                                    // data level
                                    inc(str);
                                    if (eop(str) == 1) // cek eop
                                    {
                                        strcpy(edata.level, getkata());
                                        // memasukkan data ke tipe terstruktur
                                        entryuser(edata, user);
                                        printf("Perintah yang dijalankan adalah\nENTRY user %s %s %s %s;\n", edata.id_user, edata.username, edata.id_char, edata.level);
                                        writeuser("user.dat", user);
                                    }
                                    else
                                    {
                                        printf("Silahkan memperbaiki query!\n");
                                    }
                                }
                                else
                                {
                                    printf("Silahkan memperbaiki query!\n");
                                }
                            }
                            else
                            {
                                printf("Silahkan memperbaiki query!\n");
                            }
                        }
                    }
                    else if (ins1 == 1 && ins2 == 0 && ins3 == 1 && ins4 == 0) // entry hapus
                    {
                        if (find == 1) // jika data ditemukan
                        {
                            // yang bakal dijalanin yang hapus
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
                                    if (eop(str) == 1) // cek eop
                                    {
                                        strcpy(edata.level, getkata());
                                        // memasukkan data ke tipe terstruktur
                                        deluser(user, cidx);
                                        printf("Perintah yang dijalankan adalah\nHAPUS user %s %s %s %s;\n", edata.id_user, edata.username, edata.id_char, edata.level);
                                        writeuser("user.dat", user);
                                    }
                                    else
                                    {
                                        printf("Silahkan memperbaiki query!\n");
                                    }
                                }
                                else
                                {
                                    printf("Silahkan memperbaiki query!\n");
                                }
                            }
                            else
                            {
                                printf("Silahkan memperbaiki query!\n");
                            }
                        }
                        else // jika data tidak ditemukan
                        {
                            // yang bakal dijalanin yang entry
                            // data id user
                            strcpy(edata.id_user, getkata());
                            // data username
                            inc(str);
                            if (eop(str) == 0) // cek op
                            {
                                strcpy(edata.username, getkata());
                                // data id char
                                inc(str);
                                if (eop(str) == 0) // cek eop
                                {
                                    strcpy(edata.id_char, getkata());
                                    // data level
                                    inc(str);
                                    if (eop(str) == 1) // cek eop
                                    {
                                        strcpy(edata.level, getkata());
                                        // memasukkan data ke tipe terstruktur
                                        entryuser(edata, user);
                                        printf("Perintah yang dijalankan adalah\nENTRY user %s %s %s %s;\n", edata.id_user, edata.username, edata.id_char, edata.level);
                                        writeuser("user.dat", user);
                                    }
                                    else
                                    {
                                        printf("Silahkan memperbaiki query!\n");
                                    }
                                }
                                else
                                {
                                    printf("Silahkan memperbaiki query!\n");
                                }
                            }
                            else
                            {
                                printf("Silahkan memperbaiki query!\n");
                            }
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
                    printf("Silahkan memperbaiki query!\n");
                }
            }
            else if (strcmp(getkata(), "character") == 0)
            {
                inc(str);
                if (eop(str) == 0) // cek eop
                {
                    find = carichar(getkata(), nchar, character, &cidx);

                    if (ins1 == 1 && ins2 == 0 && ins3 == 0 && ins4 == 0) // entry doang
                    {
                        if (find == 1) // jika data ditemukan
                        {
                            printf("Data tersebut telah tersedia. Silahkan masukkan data lain atau query lainnya!\n");
                        }
                        else // jika data tidak ditemukan
                        {
                            // data id char
                            strcpy(edata.id_char, getkata());
                            inc(str);
                            if (eop(str) == 0) // cek op
                            {
                                // data job
                                strcpy(edata.job_char, getkata());
                                inc(str);
                                if (eop(str) == 1) // cek eop
                                {
                                    // data skill
                                    strcpy(edata.skill, getkata());
                                    // memasukkan data ke tipe terstruktur
                                    entrychar(edata, character);
                                    printf("Perintah yang dijalankan adalah\nENTRY character %s %s %s;\n", edata.id_char, edata.job_char, edata.skill);
                                    writechar("character.dat", character);
                                }
                                else
                                {
                                    printf("Silahkan memperbaiki query!\n");
                                }
                            }
                            else
                            {
                                printf("Silahkan memperbaiki query!\n");
                            }
                        }
                    }
                    else if (ins1 == 0 && ins2 == 1 && ins3 == 0 && ins4 == 0) // ubah doang
                    {
                        if (find == 1) // jika data ditemukan
                        {
                            // data id char
                            strcpy(edata.id_char, getkata());
                            inc(str);
                            if (eop(str) == 0) // cek eop
                            {
                                // data job
                                strcpy(edata.job_char, getkata());
                                inc(str);
                                if (eop(str) == 1) // cek eop
                                {
                                    // data skill
                                    strcpy(edata.skill, getkata());
                                    // memasukkan data ke tipe terstruktur
                                    updatechar(edata, character, cidx);
                                    printf("Perintah yang dijalankan adalah\nUBAH character %s %s %s;\n", edata.id_char, edata.job_char, edata.skill);
                                    writechar("character.dat", character);
                                }
                                else
                                {
                                    printf("Silahkan memperbaiki query!\n");
                                }
                            }
                            else
                            {
                                printf("Silahkan memperbaiki query!\n");
                            }
                        }
                        else
                        {
                            printf("Data tidak ditemukan. Silahkan masukkan data lain atau query lainnya!\n");
                        }
                    }
                    else if (ins1 == 0 && ins2 == 0 && ins3 == 1 && ins4 == 0) // hapus doang
                    {
                        if (find == 1) // jika data ditemukan
                        {
                            // data id char
                            strcpy(edata.id_char, getkata());
                            inc(str);
                            if (eop(str) == 0) // cek eop
                            {
                                // data job
                                strcpy(edata.job_char, getkata());
                                inc(str);
                                if (eop(str) == 1) // cek eop
                                {
                                    // data skill
                                    strcpy(edata.skill, getkata());
                                    // memasukkan data ke tipe terstruktur
                                    delchar(character, cidx);
                                    printf("Perintah yang dijalankan adalah\nUBAH character %s %s %s;\n", edata.id_char, edata.job_char, edata.skill);
                                    writechar("character.dat", character);
                                }
                                else
                                {
                                    printf("Silahkan memperbaiki query!\n");
                                }
                            }
                            else
                            {
                                printf("Silahkan memperbaiki query!\n");
                            }
                        }
                        else
                        {
                            printf("Data tidak ditemukan. Silahkan masukkan data lain atau query lainnya!\n");
                        }
                    }
                    else if (ins1 == 1 && ins2 == 1 && ins3 == 0 && ins4 == 0) // entry, ubah
                    {
                        if (find == 1) // jika data ditemukan
                        {
                            // yg bakal dijalanin yang ubah
                            // data id char
                            strcpy(edata.id_char, getkata());
                            inc(str);
                            if (eop(str) == 0) // cek eop
                            {
                                // data job
                                strcpy(edata.job_char, getkata());
                                inc(str);
                                if (eop(str) == 1) // cek eop
                                {
                                    // data skill
                                    strcpy(edata.skill, getkata());
                                    // memasukkan data ke tipe terstruktur
                                    updatechar(edata, character, cidx);
                                    printf("Perintah yang dijalankan adalah\nUBAH character %s %s %s;\n", edata.id_char, edata.job_char, edata.skill);
                                    writechar("character.dat", character);
                                }
                                else
                                {
                                    printf("Silahkan memperbaiki query!\n");
                                }
                            }
                            else
                            {
                                printf("Silahkan memperbaiki query!\n");
                            }
                        }
                        else // jika data tidak ditemukan
                        {
                            // yg bakal dijalanin yg entry
                            // data id char
                            strcpy(edata.id_char, getkata());
                            inc(str);
                            if (eop(str) == 0) // cek op
                            {
                                // data job
                                strcpy(edata.job_char, getkata());
                                inc(str);
                                if (eop(str) == 1) // cek eop
                                {
                                    // data skill
                                    strcpy(edata.skill, getkata());
                                    // memasukkan data ke tipe terstruktur
                                    entrychar(edata, character);
                                    printf("Perintah yang dijalankan adalah\nENTRY character %s %s %s;\n", edata.id_char, edata.job_char, edata.skill);
                                    writechar("character.dat", character);
                                }
                                else
                                {
                                    printf("Silahkan memperbaiki query!\n");
                                }
                            }
                            else
                            {
                                printf("Silahkan memperbaiki query!\n");
                            }
                        }
                    }
                    else if (ins1 == 1 && ins2 == 0 && ins3 == 1 && ins4 == 0) // entry hapus
                    {
                        if (find == 1) // jika data ditemukan
                        {
                            // yang bakal dijalanin yang hapus
                            // data id char
                            strcpy(edata.id_char, getkata());
                            inc(str);
                            if (eop(str) == 0) // cek eop
                            {
                                // data job
                                strcpy(edata.job_char, getkata());
                                inc(str);
                                if (eop(str) == 1) // cek eop
                                {
                                    // data skill
                                    strcpy(edata.skill, getkata());
                                    // memasukkan data ke tipe terstruktur
                                    delchar(character, cidx);
                                    printf("Perintah yang dijalankan adalah\nUBAH character %s %s %s;\n", edata.id_char, edata.job_char, edata.skill);
                                    writechar("character.dat", character);
                                }
                                else
                                {
                                    printf("Silahkan memperbaiki query!\n");
                                }
                            }
                            else
                            {
                                printf("Silahkan memperbaiki query!\n");
                            }
                        }
                        else // jika data tidak ditemukan
                        {
                            // yang bakal dijalanin yang entry
                            // data id char
                            strcpy(edata.id_char, getkata());
                            inc(str);
                            if (eop(str) == 0) // cek op
                            {
                                // data job
                                strcpy(edata.job_char, getkata());
                                inc(str);
                                if (eop(str) == 1) // cek eop
                                {
                                    // data skill
                                    strcpy(edata.skill, getkata());
                                    // memasukkan data ke tipe terstruktur
                                    entrychar(edata, character);
                                    printf("Perintah yang dijalankan adalah\nENTRY character %s %s %s;\n", edata.id_char, edata.job_char, edata.skill);
                                    writechar("character.dat", character);
                                }
                                else
                                {
                                    printf("Silahkan memperbaiki query!\n");
                                }
                            }
                            else
                            {
                                printf("Silahkan memperbaiki query!\n");
                            }
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
                    printf("Silahkan memperbaiki query!\n");
                }
            }
            else // jika tabel yang dimasukkan salah
            {
                printf("Silahkan memperbaiki query, tabel %s tidak ditemukan.\n", getkata());
            }
        }
    }
}

int eopdbms(char str[])
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

int main()
{
    system("cls");
    // memulai query
    printf("Wilujeng Sumping di DBMS Koreksian Bayu\nVersi 1.0\n\n");
    char query[501];

    printf("dbms Bayu> ");
    scanf(" %500[^\n]s", &query);
    printf("\n");
    while (eopdbms(query) == 0)
    {
        nuser = readuser("user.dat", user);
        nchar = readchar("character.dat", character);
        readquery(query);
        // perulangan
        printf("\n");
        printf("dbms Bayu> ");
        scanf(" %500[^\n]s", &query);
        printf("\n");
    }

    // keluar akhir
    printf("Terima kasih telah menggunakan dbms bayu :)");
    printf("\nDibuat oleh Bayu Wicaksono dengan cinta.\n");
    system("exit");
    return 0;
}