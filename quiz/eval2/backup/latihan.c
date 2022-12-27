#include <stdio.h>
#include <string.h>

typedef struct
{
    char nama[51], status[51], harga[51];
} barang;

int idx, length;
char w[51];
barang data[501];
int ndata;
barang temp;

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

int cari(char src[], int *cidx)
{
    int i = 0, f = 0;
    while (i < ndata && f == 0)
    {
        if (strcmp(data[i].nama, src) == 0)
        {
            f = 1;
            *cidx = i;
        }
        else
            i++;
    }

    if (f == 0)
        return 0;
    else
        return 1;
}

void insert()
{
    strcpy(data[ndata].nama, temp.nama);
    strcpy(data[ndata].harga, temp.harga);
    strcpy(data[ndata].status, temp.status);
    ndata++;
}

void readquery(char str[])
{
    int cidx, find;
    char tmp[51];
    start(str);
    if (eop(str) == 0)
    {
        if (strcmp(getkata(), "INSERT") == 0)
        {
            inc(str);
            find = cari(getkata(), &cidx);
            if (eop(str) == 0 && find == 0)
            {
                strcpy(temp.nama, getkata());
                inc(str);
                if (eop(str) == 0)
                {
                    strcpy(temp.harga, getkata());
                    inc(str);
                    if (eop(str) == 1)
                    {
                        strcpy(temp.status, getkata());
                        insert();
                    }
                }
            }
        }
        else if (strcmp(getkata(), "UPDATE") == 0)
        {
            inc(str);
            if (eop(str) == 0)
            {
                strcpy(tmp, getkata());
                inc(str);
                if (eop(str) == 0)
                {
                    find = cari(getkata(), &cidx);
                    if (strcmp(tmp, "NAMA") == 0)
                    {
                        inc(str);
                        if (eop(str) == 1)
                            strcpy(data[cidx].nama, getkata());
                    }
                    else if (strcmp(tmp, "HARGA") == 0)
                    {
                        inc(str);
                        if (eop(str) == 1)
                            strcpy(data[cidx].harga, getkata());
                    }
                    else if (strcmp(tmp, "STATUS") == 0)
                    {
                        inc(str);
                        if (eop(str) == 1)
                            strcpy(data[cidx].status, getkata());
                    }
                }
            }
        }
    }
}

int maxstr(char arr[501][51])
{
    int i, max = strlen(arr[0]);
    for (i = 1; i < ndata; i++)
        if (strlen(arr[i]) > max)
            max = strlen(arr[i]);
    max += 2;
    return max;
}

void garis(int total)
{
    for (int i = 0; i < total; i++)
        printf("=");
}

void spasi(int space)
{
    for (int i = 0; i < space; i++)
        printf(" ");
}

void tampil()
{
    int max[3], total;
    char arr[501][51];

    for (int i = 0; i < ndata; i++)
        strcpy(arr[i], data[i].nama);
    max[0] = maxstr(arr);
    if (max[0] < strlen(" BARANG "))
        max[0] = strlen(" BARANG ");

    for (int i = 0; i < ndata; i++)
        strcpy(arr[i], data[i].harga);
    max[1] = maxstr(arr);
    max[1] += 3;
    if (max[1] < strlen(" HARGA "))
        max[1] = strlen(" HARGA ");

    for (int i = 0; i < ndata; i++)
        strcpy(arr[i], data[i].status);
    max[2] = maxstr(arr);
    if (max[2] < strlen(" STATUS "))
        max[2] = strlen(" STATUS ");

    total = 4 + max[0] + max[1] + max[2];
    // printf("%d", max[1]);
    garis(total);
    printf("\n| BARANG ");
    spasi(max[0] - strlen(" Id User"));

    printf("| HARGA ");
    spasi(max[1] - strlen(" HARGA "));

    printf("| STATUS ");
    spasi(max[2] - strlen(" STATUS "));
    printf("|\n");
    garis(total);
    printf("\n");
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
    garis(total);
    printf("\n%d data ditampilkan.\n", ndata);
}

int main()
{
    char str[51];
    ndata = 0;
    scanf(" %50[^\n]s", &str);
    while (strcmp(str, "SELESAI;") != 0)
    {
        readquery(str);
        scanf(" %50[^\n]s", &str);
    }
    tampil();

    return 0;
}