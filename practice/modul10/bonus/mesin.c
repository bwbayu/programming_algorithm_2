#include "header.h"

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
    start(str); // memanggil prosedur start untuk memulai pembacaan pita
    // melakukan pengecekan, perintah mana yang akan dijalankan
    if (strcmp(getcw(), "INSERT") == 0) // jika perintahnya INSERT
    {
        inc(str);
        // melakukan pengecekan tabel
        if (strcmp(getcw(), "mahasiswa") == 0)
        {
            inc(str);
            i = 1;
            while (i <= j && sign == 0) // mengecek nim yang dimasukan user ada dalam tipe terstruktur atau tidak
            {
                if (strcmp(getcw(), (data - i)->nim) == 0)
                {
                    sign = 1; // tanda perintah berhasil dijalankan
                }
                i++;
            }
            if (sign == 0) // jika belum ada maka masukan user tsb akan dimasukkan ke tipe terstruktur
            {
                strcpy(data->nim, getcw());
                inc(str);
                strcpy(data->nama, getcw());
                inc(str);
                strcpy(data->nilai, getcw());

                return 1; // jika perintah berhasil dijalankan maka akan mengembalikan nilai 1
            }
            else // error handling jika data nim sudah ada dalam tipe terstruktur
            {
                printf("==================================================================\n");
                printf("Query ke-%d salah, data nim %s sudah ada!\n", idxquery + 1, getcw());
                printf("==================================================================\n");
                inc(str);
                inc(str);
                *error = 1; // tanda adanya error dan program akan meminta masukan revisi
                return 0;
            }
        }
        else // error handling jika salah masukan tabel
        {
            printf("==================================================================\n");
            printf("Query ke-%d salah, tabel %s tidak ada!\n", idxquery + 1, getcw());
            printf("==================================================================\n");
            inc(str);
            inc(str);
            inc(str);
            *error = 1; // tanda adanya error dan program akan meminta masukan revisi
            return 0;
        }
    }
    else if (strcmp(getcw(), "UPDATE") == 0) // jika perintahnya UPDATE
    {
        inc(str);
        // melakukan pengecekan tabel
        if (strcmp(getcw(), "mahasiswa") == 0)
        {
            inc(str);
            i = 1;
            while (i <= j && sign == 0) // melakukan pengecekan apakah nim yang akan di update ada atau tidak
            {
                if (strcmp(getcw(), (data - i)->nim) == 0) // jika nim-nya ada, maka data di tipe terstruktur akan diganti oleh data dari masukan user
                {
                    inc(str);
                    strcpy((data - i)->nama, getcw());
                    inc(str);
                    strcpy((data - i)->nilai, getcw());
                    sign = 1; // tanda perintah berhasil dijalankan
                    return 0; // jika update berhasil dijalankan maka akan mengembalikan nilai 0
                }
                i++;
            }
            if (sign == 0) // error handling jika data nim tidak ada di tipe terstruktur
            {
                printf("==================================================================\n");
                printf("Query ke-%d salah, data nim %s tidak ada!\n", idxquery + 1, getcw());
                printf("==================================================================\n");
                inc(str);
                inc(str);
                *error = 1; // tanda adanya error dan program akan meminta masukan revisi
                return 0;
            }
        }
        else
        { // error handling jika salah masukan tabel
            printf("==================================================================\n");
            printf("Query ke-%d salah, tabel %s tidak ada!\n", idxquery + 1, getcw());
            printf("==================================================================\n");
            inc(str);
            inc(str);
            inc(str);
            *error = 1; // tanda adanya error dan program akan meminta masukan revisi
            return 0;
        }
    }
    else if (strcmp(getcw(), "DELETE") == 0) // jika perintahnya DELETE
    {
        inc(str);
        // melakukan pengecekan tabel
        if (strcmp(getcw(), "mahasiswa") == 0)
        {
            inc(str);
            // mengecek apakah nim ada atau tidak di dalam tipe terstruktur
            if (strcmp(getcw(), (data - j)->nim) == 0) // jika data di index = 0
            {
                for (i = j; i > 1; i--) // menggeser data satu tempat ke depan
                {
                    strcpy((data - i)->nim, (data - i + 1)->nim);
                    strcpy((data - i)->nama, (data - i + 1)->nama);
                    strcpy((data - i)->nilai, (data - i + 1)->nilai);
                }
                // data di index terakhir akan diisi null
                strcpy((data - 1)->nim, "\0");
                strcpy((data - 1)->nama, "\0");
                strcpy((data - 1)->nilai, "\0");
                sign = 1; // tanda perintah berhasil dijalankan
            }
            else if (strcmp(getcw(), (data - 1)->nim) == 0) // jika data di index terakhir
            {
                // data di index terakhir akan diganti null
                strcpy((data - 1)->nim, "\0");
                strcpy((data - 1)->nama, "\0");
                strcpy((data - 1)->nilai, "\0");
                sign = 1; // tanda perintah berhasil dijalankan
            }
            else // jika data di index tengah
            {
                int x = j;
                while (x > 0 && sign == 0) // melakukan pengecekan data dari index 0 sampai index terakhir
                {
                    // mengecek data nim
                    if (strcmp(getcw(), (data - x)->nim) == 0) // jika data nim ditemukan
                    {
                        sign = 1; // tanda perintah berhasil dijalankan
                    }
                    else // jika data nim tidak ditemukan
                    {
                        x--;
                    }
                }
                if (sign == 1) // jika perintah berhasil dijalankan maka
                {
                    for (int n = x; n > 1; n--) // menggeser data satu tempat ke depan dari index ditemukannya nim
                    {
                        strcpy((data - n)->nim, (data - n + 1)->nim);
                        strcpy((data - n)->nama, (data - n + 1)->nama);
                        strcpy((data - n)->nilai, (data - n + 1)->nilai);
                    }
                    // data di index terakhir akan diisi null
                    strcpy((data - 1)->nim, "\0");
                    strcpy((data - 1)->nama, "\0");
                    strcpy((data - 1)->nilai, "\0");
                }
            }

            if (sign == 1) // jika perintah delete berhasil dijalankan
            {
                return -1; // maka akan mengembalikan nilai -1
            }
            else // error handling jika data nim tidak ditemukan dalam tipe terstruktur
            {
                printf("==================================================================\n");
                printf("Query ke-%d salah, data nim %s tidak ada!\n", idxquery + 1, getcw());
                printf("==================================================================\n");
                *error = 1; // tanda adanya error dan program akan meminta masukan revisi
                return 0;
            }
        }
        else // error handling jika salah masukan tabel
        {
            printf("==================================================================\n");
            printf("Query ke-%d salah, tabel %s tidak ada!\n", idxquery + 1, getcw());
            printf("==================================================================\n");
            inc(str);
            *error = 1; // tanda adanya error dan program akan meminta masukan revisi
            return 0;
        }
    }
}