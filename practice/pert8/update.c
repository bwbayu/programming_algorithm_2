#include <stdio.h>
#include <string.h>

typedef struct
{
    char id[10], nama[100];
} data;

int read(char string[101], data genre[51])
{
    int n = 0;
    FILE *fgenre;
    fgenre = fopen(string, "r");
    fscanf(fgenre, "%s %s", genre[n].id, genre[n].nama);
    if (strcmp(genre[n].id, "####") == 0)
        printf("File Kosong!\n");

    else
        while (strcmp(genre[n].id, "####") != 0)
        {
            n++;
            fscanf(fgenre, "%s %s", genre[n].id, genre[n].nama);
        }
    fclose(fgenre);

    return n;
}

void cari(int n, data genre[101], char id[10])
{
    int i = 0, found = 0;
    while (found == 0 && i < n)
    {
        if (strcmp(id, genre[i].id) == 0)
        {
            found = 1;
        }
        i++;
    }
    if (found == 1)
    {
        printf("masukkan data baru ke id-%s\n", id);
        printf("masukkan nama genre ");
        char update[100];
        scanf("%s", update);
        strcpy(genre[i - 1].nama, update);
    }
    else
    {
        printf("id tidak ditemukan.\n");
    }
}

void binary(int n, data genre[101], char id[10])
{
    int i = 0, k = 0, found = 0;
    while (i <= n && found == 0)
    {
        k = (int)((i + n) / 2);
        if (strcmp(genre[k].id, id) == 0)
        {
            found = 1;
        }
        else
        {
            if (strcmp(genre[k].id, id) > 0)
            {
                n = k - 1;
            }
            else
            {
                i = k + 1;
            }
        }
    }
    if (found == 1)
    {
        printf("masukkan data baru ke id-%s\n", id);
        printf("masukkan nama genre ");
        char update[100];
        scanf("%s", update);
        strcpy(genre[k].nama, update);
    }
    else
    {
        printf("id tidak ditemukan.\n");
    }
}

void cari1(int n, data genre[101], char id[10])
{
    if (strcmp(id, genre[0].id) == 0)
    {
        printf("masukkan nama genre ");
        scanf("%s", genre[0].nama);
    }
    else if (strcmp(id, genre[n - 1].id) == 0)
    {
        printf("masukkan nama genre ");
        scanf("%s", genre[n - 1].nama);
    }
    else
    {
        binary(n - 1, genre, id);
    }
}

void write(char str[51], int n, data genre[51])
{
    FILE *fgenre;
    fgenre = fopen(str, "w");
    for (int i = 0; i < n; i++)
        fprintf(fgenre, "%s %s\n", genre[i].id, genre[i].nama);
    fprintf(fgenre, "#### ####\n");
    fclose(fgenre);
}

int main()
{
    data genre[101];
    int n = read("Genre.dat", genre);
    // ubah data
    char id[10];
    printf("Masukkan id yang datanya ingin diubah ");
    scanf("%s", id);
    cari1(n, genre, id);
    write("Genre.dat", n, genre);

    return 0;
}