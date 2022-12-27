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

int cari1(int n, data genre[101], char id[10])
{
    if (strcmp(id, genre[0].id) == 0)
    {
        for (int i = 0; i < n - 1; i++)
        {
            genre[i] = genre[i + 1];
        }
        n -= 1;
    }
    else if (strcmp(id, genre[n - 1].id) == 0)
    {
        n -= 1;
    }
    else
    {
        int i = 0;
        int stop = 0;
        while (i < n - 1 && stop == 0)
        {
            if (strcmp(genre[i].id, id) == 0)
            {
                stop = 1;
            }
            else
            {
                i++;
            }
        }
        for (int j = i; j < n - 1; j++)
        {
            genre[j] = genre[j + 1];
        }
        n -= 1;
    }

    return n;
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
    printf("Masukkan id yang ingin di hapus ");
    scanf("%s", id);
    int x = cari1(n, genre, id);
    write("Genre.dat", x, genre);

    return 0;
}