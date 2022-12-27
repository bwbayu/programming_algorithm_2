#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[10], nama[100], nilai[10];
} mahasiswa;

int idx, length, sign;
char w[51];

void start(char str[])
{
    idx = 0;
    length = 0;

    while (str[idx] == ' ')
    {
        idx++;
    }

    while (str[idx] != ' ' && str[idx] != ';')
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

    while (str[idx] != ' ' && str[idx] != ';')
    {
        w[length] = str[idx];
        idx++;
        length++;
    }

    w[length] = '\0';
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

char *getcw()
{
    return w;
}

int modifydata(char str[], int j, mahasiswa *data, int idxquery, int *error)
{
    int i;
    sign = 0;
    char temp[100];
    start(str);
    if (strcmp(getcw(), "INSERT") == 0)
    {
        inc(str);
        if (strcmp(getcw(), "mahasiswa") == 0)
        {
            inc(str);
            i = 1;
            while (i <= j && sign == 0)
            {
                if (strcmp(getcw(), (data - i)->nim) == 0)
                {
                    sign = 1;
                }
                i++;
            }
            if (sign == 0)
            {
                strcpy(data->nim, getcw());
                inc(str);
                strcpy(data->nama, getcw());
                inc(str);
                strcpy(data->nilai, getcw());

                return 1;
            }
            else
            {
                printf("==================================================================\n");
                printf("Query ke-%d salah, data nim %s tidak ada!\n", idxquery + 1, getcw());
                printf("==================================================================\n");
                inc(str);
                inc(str);
                *error = 1;
                return 0;
            }
        }
        else
        {
            printf("==================================================================\n");
            printf("Query ke-%d salah, tabel %s tidak ada!\n", idxquery + 1, getcw());
            printf("==================================================================\n");
            inc(str);
            inc(str);
            inc(str);
            *error = 1;
            return 0;
        }
    }
    else if (strcmp(getcw(), "UPDATE") == 0)
    {
        inc(str);
        if (strcmp(getcw(), "mahasiswa") == 0)
        {
            inc(str);
            i = 1;
            while (i <= j && sign == 0)
            {
                if (strcmp(getcw(), (data - i)->nim) == 0)
                {
                    inc(str);
                    strcpy((data - i)->nama, getcw());
                    inc(str);
                    strcpy((data - i)->nilai, getcw());
                    sign = 1;
                    return 0;
                }
                i++;
            }
            if (sign == 0) // error handling sementara
            {
                printf("==================================================================\n");
                printf("Query ke-%d salah, data nim %s tidak ada!\n", idxquery + 1, getcw());
                printf("==================================================================\n");
                inc(str);
                inc(str);
                *error = 1;
                return 0;
            }
        }
        else
        { // error handling sementara
            printf("==================================================================\n");
            printf("Query ke-%d salah, tabel %s tidak ada!\n", idxquery + 1, getcw());
            printf("==================================================================\n");
            inc(str);
            inc(str);
            inc(str);
            *error = 1;
            return 0;
        }
    }
    else if (strcmp(getcw(), "DELETE") == 0)
    {
        inc(str);
        if (strcmp(getcw(), "mahasiswa") == 0)
        {
            inc(str);
            if (strcmp(getcw(), (data - j)->nim) == 0)
            {
                for (i = j; i > 1; i--)
                {
                    strcpy((data - i)->nim, (data - i + 1)->nim);
                    strcpy((data - i)->nama, (data - i + 1)->nama);
                    strcpy((data - i)->nilai, (data - i + 1)->nilai);
                }
                strcpy((data - 1)->nim, "\0");
                strcpy((data - 1)->nama, "\0");
                strcpy((data - 1)->nilai, "\0");
                sign = 1;
            }
            else if (strcmp(getcw(), (data - 1)->nim) == 0)
            {
                strcpy((data - 1)->nim, "\0");
                strcpy((data - 1)->nama, "\0");
                strcpy((data - 1)->nilai, "\0");
                sign = 1;
            }
            else
            {
                int x = j;
                while (x > 0 && sign == 0)
                {
                    if (strcmp(getcw(), (data - x)->nim) == 0)
                    {
                        sign = 1;
                    }
                    else
                    {
                        x--;
                    }
                }
                if (sign == 1)
                {
                    for (int n = x; n > 1; n--)
                    {
                        strcpy((data - n)->nim, (data - n + 1)->nim);
                        strcpy((data - n)->nama, (data - n + 1)->nama);
                        strcpy((data - n)->nilai, (data - n + 1)->nilai);
                    }
                    strcpy((data - 1)->nim, "\0");
                    strcpy((data - 1)->nama, "\0");
                    strcpy((data - 1)->nilai, "\0");
                }
            }

            if (sign == 1)
            {
                return -1;
            }
            else
            {
                printf("==================================================================\n");
                printf("Query ke-%d salah, data nim %s tidak ada!\n", idxquery + 1, getcw());
                printf("==================================================================\n");
                *error = 1;
                return 0;
            }
        }
        else
        {
            printf("==================================================================\n");
            printf("Query ke-%d salah, tabel %s tidak ada!\n", idxquery + 1, getcw());
            printf("==================================================================\n");
            inc(str);
            *error = 1;
            return 0;
        }
    }
}

int main()
{
    char query[100], m;
    int n, sum = 0, error = 0;
    mahasiswa data[51];
    scanf("%d%c", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf(" %99[^\n]s", &query);
        sum += modifydata(query, sum, &data[sum], i, &error);
        while (error == 1)
        {
            printf("masukkan revisi:\n");
            error = 0;
            scanf(" %99[^\n]s", &query);
            sum += modifydata(query, sum, &data[sum], i, &error);
        }
    }

    for (int i = 0; i < sum; i++)
    {
        printf("%d. %s %s %s\n", (i + 1), data[i].nim, data[i].nama, data[i].nilai);
    }

    return 0;
}
