#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TP8 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int read(char string[101], film data[51]) // fungsi untuk membaca file yang isinya 2 data
{
    int n = 0;
    FILE *fdata;
    fdata = fopen(string, "r");                       // membuka file dengan mode "read"
    fscanf(fdata, "%s %s", data[n].id, data[n].nama); // menyimpan data file dalam tipe terstruktur
    // mengecek apakah file tersebut ada datanya atau kosong
    if (strcmp(data[n].id, "####") == 0)
        printf("File Kosong!\n");

    else
        while (strcmp(data[n].id, "####") != 0) // penyimpanan data file ke dalam tipe terstruktur akan terus berlangsung hingga menemukan EOF
        {
            n++; // iterasi
            fscanf(fdata, "%s %s", data[n].id, data[n].nama);
        }
    fclose(fdata); // menutup file

    return n; // mengembalikan jumlah data dalam suatu file
}

int read1(char string[101], film data[51]) // fungsi untuk membaca file yg isinya 4 data
{
    int n = 0;
    FILE *fdata;
    fdata = fopen(string, "r");                                                                    // membuka file dengan mode "read"
    fscanf(fdata, "%s %s %s %s", data[n].nama, data[n].sutradara, data[n].genre, data[n].bioskop); // menyimpan data file dalam tipe terstruktur
    // mengecek apakah file tersebut ada datanya atau kosong
    if (strcmp(data[n].nama, "####") == 0)
        printf("File Kosong!\n");
    else
        while (strcmp(data[n].nama, "####") != 0) // penyimpanan data file ke dalam tipe terstruktur akan terus berlangsung hingga menemukan EOF
        {
            n++;
            fscanf(fdata, "%s %s %s %s", data[n].nama, data[n].sutradara, data[n].genre, data[n].bioskop);
        }
    fclose(fdata); // menutup file

    return n; // mengembalikan jumlah data dalam suatu file
}

void write(char str[51], int n, film data[51]) // prosedur untuk menyalin file yg isinya 2 data
{
    FILE *fdata;
    fdata = fopen(str, "w");    // membuka file dengan mode "write"
    for (int i = 0; i < n; i++) // menyalin data dari tipe terstruktur ke file
        fprintf(fdata, "%s %s\n", data[i].id, data[i].nama);
    fprintf(fdata, "#### ####\n"); // EOF
    fclose(fdata);                 // menutup file
}

void write1(char str[51], int n, film data[51]) // prosedur untuk menyalin file yg isinya 4 data
{
    FILE *fdata;
    fdata = fopen(str, "w");    // membuka file dengan mode "write"
    for (int i = 0; i < n; i++) // menyalin data dari tipe terstruktur ke file
        fprintf(fdata, "%s %s %s %s\n", data[i].nama, data[i].sutradara, data[i].genre, data[i].bioskop);
    fprintf(fdata, "#### #### #### ####\n"); // EOF
    fclose(fdata);                           // menutup file
}

int maxstr(int n, char arr[51][101]) // fungsi untuk menemukan string terpanjang pada suatu kolom
{
    int i, max = strlen(arr[0]);
    for (i = 1; i < n; i++) // mencari string terpanjang
        if (strlen(arr[i]) > max)
            max = strlen(arr[i]);
    max += 2;
    return max; // mengembalikan nilai string terpanjang
}

void garis(int totalspasi) // prosedur untuk menampilkan garis
{
    for (int i = 0; i < totalspasi; i++)
        printf("-");
}

void spasi(int spasitabel, char str[101]) // prosedur untuk menampilkan spasi
{
    int n = spasitabel - strlen(str);
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void print(int max[4], int total, film data[51], int bdata) // prosedur untuk menampilkan isi data dari file ListFilmFinal
{
    garis(total);
    // nama tabel
    printf("\n|Judul");
    if (max[0] < strlen("Judul"))
        max[0] = strlen("Judul");
    spasi(max[0], "Judul");
    printf("|Sutradara");
    if (max[1] < strlen("Sutradara"))
        max[1] = strlen("Sutradara");
    spasi(max[1], "Sutradara");
    printf("|Genre");
    if (max[2] < strlen("Genre"))
        max[2] = strlen("Genre");
    spasi(max[2], "Genre");
    printf("|Bioskop");
    if (max[3] < strlen("Bioskop"))
        max[3] = strlen("Bioskop");
    spasi(max[3], "Bioskop");
    printf("|\n|");
    // pembatas
    garis(max[0]);
    printf("+");
    garis(max[1]);
    printf("+");
    garis(max[2]);
    printf("+");
    garis(max[3]);
    printf("|\n");
    // isi tabel
    for (int i = 0; i < bdata; i++)
    {
        printf("|%s", data[i].nama);
        spasi(max[0], data[i].nama);
        printf("|%s", data[i].sutradara);
        spasi(max[1], data[i].sutradara);
        printf("|%s", data[i].genre);
        spasi(max[2], data[i].genre);
        printf("|%s", data[i].bioskop);
        spasi(max[3], data[i].bioskop);
        printf("|\n");
    }
    garis(total);
    printf("\n");
}

void isimenu1() // prosedur untuk mempersiapkan tabel yang akan diisi oleh data dari file ListFilmFinal
{
    int i, j, max[4];
    film data[51];
    // membaca file listfilmfinal
    int n = read1("ListFilmFinal.dat", data);
    // mencari string terpanjang masing masing tabel dalam file
    char arr[51][101];
    // judul film
    for (i = 0; i < n; i++)
        strcpy(arr[i], data[i].nama);
    max[0] = maxstr(n, arr);
    // sutradara film
    for (i = 0; i < n; i++)
        strcpy(arr[i], data[i].sutradara);
    max[1] = maxstr(n, arr);
    // genre film
    for (i = 0; i < n; i++)
        strcpy(arr[i], data[i].genre);
    max[2] = maxstr(n, arr);
    // nama bioskop
    for (i = 0; i < n; i++)
        strcpy(arr[i], data[i].bioskop);
    max[3] = maxstr(n, arr);
    // menampilkan file
    int stot = 5 + max[0] + max[1] + max[2] + max[3];
    print(max, stot, data, n);
}

void listfilmfinal() // prosedur untuk mengganti semua id dalam file ListFilm dan menyalinnya di file ListFilmFinal
{
    int i, j, n;
    // membaca file ListFilm
    film data[51];
    n = read1("ListFilm.dat", data);

    // membaca file sutradara
    film datas[51];
    int m = read("Sutradara.dat", datas);
    // mengisi id sutradara dalam ListFilm film dengan data sutradaranya
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            if (strcmp(data[i].sutradara, datas[j].id) == 0)
            {
                strcpy(data[i].sutradara, datas[j].nama);
                break;
            }
        }

    // membaca file genre
    film datag[51];
    // mengisi id genre dalam file ListFilm dengan data genrenya
    int o = read("Genre.dat", datag);
    for (i = 0; i < n; i++)
        for (j = 0; j < o; j++)
        {
            if (strcmp(data[i].genre, datag[j].id) == 0)
            {
                strcpy(data[i].genre, datag[j].nama);
                break;
            }
        }

    // membaca file bioskop
    film datab[51];
    // mengisi id bioskop dalam file ListFilm dengan data bioskopnya
    int p = read("Bioskop.dat", datab);
    for (i = 0; i < n; i++)
        for (j = 0; j < p; j++)
        {
            if (strcmp(data[i].bioskop, datab[j].id) == 0)
            {
                strcpy(data[i].bioskop, datab[j].nama);
                break;
            }
        }

    // menyalin hasil akhir ke file ListFilmFinal
    write1("ListFilmFinal.dat", n, data);
    // memanggil prosedur untuk menampilkan isi file ListFilmFinal
    isimenu1();
}

void sort(int kiri, int kanan, film data[51]) // prosedur untuk mengurutkan data yang ada di dalam tipe terstruktur
{
    int i, j;
    film temp;
    i = kiri, j = kanan;
    // perulangan untuk menggeser i dan j
    while (strcmp(data[i].id, data[kanan].id) < 0 && i <= j)
    {
        i++;
    }
    while (strcmp(data[j].id, data[kiri].id) > 0 && i <= j)
    {
        j--;
    }
    // proses pemindahan data
    if (i < j)
    {
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
        i++;
        j--;
    }
    // sorting untuk sub-bagian
    if (kiri < j)
    {
        sort(kiri, j, data);
    }
    if (i < kanan)
    {
        sort(i, kanan, data);
    }
}

void cari(char id[10], char str[51]) // prosedur untuk mencari suatu data dari id masukan user pada file tertentu
{
    // membaca file dari data yang dicari
    film data2[51];
    int m = read(str, data2), i = 0, found = 0, j = 0;
    // pencarian dengan metode binary search
    int n = m - 1;
    sort(0, n, data2);
    while (i <= n && found == 0)
    {
        j = (i + n) / 2;
        if (strcmp(data2[j].id, id) == 0)
        {
            found = 1;
            printf("Data dari id yang dicari : %s\n\n", data2[j].nama);
        }
        else
        {
            if (strcmp(data2[j].id, id) > 0)
                n = j - 1;
            else
                i = j + 1;
        }
    }
    if (found == 0)
    {
        printf("Data tidak ditemukan.\n\n");
    }
}

void listmenu2() // prosedur untuk menu mencari data
{
    // menu pencarian data
    system("cls");
    printf("1. Cari Data Sutradara\n");
    printf("2. Cari Data Genre\n");
    printf("3. Cari Data Bioskop\n");
    printf("=================================\n");
    printf("Pilih menu : ");
    int x;
    scanf("%d", &x);
    char id[10];
    // mengecek file mana yang akan dicari
    if (x == 1 || x == 2 || x == 3)
    {
        printf("- Id terdiri dari 1 digit huruf dan 3 digit angka, contohnya S001, G003, B005.\n- Dimana S mewakili Sutradara, G mewakili Genre, dan B mewakili Bioskop.\n");
        printf("Masukkan id yang ingin dicari : ");
        scanf("%s", id);
        if (x == 1)
            cari(id, "Sutradara.dat");
        else if (x == 2)
            cari(id, "Genre.dat");
        else
            cari(id, "Bioskop.dat");
    }
    else // jika yang dipilih bukan menu 1/2/3 maka akan menampilkan lagi menu pencarian data
    {
        listmenu2();
    }
}

char cek(char temp[100], int n, film data[51]) // fungsi untuk memeriksa id agar tidak terjadi redundansi
{
    int i = 0, j = 0;
    // perulangan untuk mencari apakah data id masukan user ada di dalam data id tipe terstruktur
    while (i < n && strcmp(temp, data[i].id) != 0)
    {
        i++;
    }
    if (i == n) // jika tidak ada data id yang sama maka akan mengembalikan nilai 'y'
    {
        return 'y';
    }
    else // jika ada data id yang sama maka akan mengembalikan nilai 'n'
    {
        return 'n';
    }
}

void appends(int n, film data[51]) // prosedur untuk menambahkan data ke file sutradara
{
    char sign, temp[100];
    // masukan user
    printf("Masukkan id sutradara: ");
    scanf("%s", temp);
    sign = cek(temp, n, data); // memeriksa id masukan user
    // mengecek kembalian dari variabel sign
    if (sign == 'y') // jika 'y' maka id tersebut dapat digunakan untuk menambahkan data
    {
        n++;
        strcpy(data[n].id, temp);
        printf("Masukkan nama sutradara: ");
        scanf("%s", data[n].nama);
    }
    else // jika 'n' maka akan meminta user untuk memasukkan id lagi
    {
        printf("Id tersebut sudah ada di dalam file. Silahkan gunakan id lain...\n");
        appends(n, data);
    }
}

void appendg(int n, film data[51]) // prosedur untuk menambahkan data ke file genre
{
    char sign, temp[100];
    // masukan user
    printf("Masukkan id genre: ");
    scanf("%s", temp);
    sign = cek(temp, n, data); // memeriksa id masukan user
    // mengecek kembalian dari variabel sign
    if (sign == 'y') // jika 'y' maka id tersebut dapat digunakan untuk menambahkan data
    {
        strcpy(data[n].id, temp);
        printf("Masukkan nama genre: ");
        scanf("%s", data[n].nama);
    }
    else // jika 'n' maka akan meminta user untuk memasukkan id lagi
    {
        printf("Id tersebut sudah ada di dalam file. Silahkan gunakan id lain...\n");
        appendg(n, data);
    }
}

void appendb(int n, film data[51]) // prosedur untuk menambahkan data ke file bioskop
{
    char sign, temp[100];
    // masukan user
    printf("Masukkan id bioskop: ");
    scanf("%s", temp);
    sign = cek(temp, n, data); // memeriksa id masukan user
    // mengecek kembalian dari variabel sign
    if (sign == 'y') // jika 'y' maka id tersebut dapat digunakan untuk menambahkan data
    {
        strcpy(data[n].id, temp);
        printf("Masukkan nama bioskop: ");
        scanf("%s", data[n].nama);
    }
    else // jika 'n' maka akan meminta user untuk memasukkan id lagi
    {
        printf("Id tersebut sudah ada di dalam file. Silahkan gunakan id lain...\n");
        appendb(n, data);
    }
}

void listmenu3() // prosedur untuk menu tambah data
{
    // menu penambahan data
    system("cls");
    printf("1. Tambah Data List Film\n");
    printf("2. Tambah Data Sutradara\n");
    printf("3. Tambah Data Genre\n");
    printf("4. Tambah Data Bioskop\n");
    printf("=================================\n");
    printf("Pilih menu : ");
    int x, y, n;
    scanf("%d", &x);
    film data3[51];
    // mengecek file mana yang datanya akan ditambahkan
    if (x == 1)
    {
        printf("- List Film terdiri dari judul film, id sutradara, id genre, dan id bioskop.\n- Id terdiri dari 1 digit huruf dan 3 digit angka, contohnya S001, G003, B005.\n- Dimana S mewakili Sutradara, G mewakili Genre, dan B mewakili Bioskop.\n- Jika penambahan data selesai, akhiri dengan #### #### #### ####.\n");
        // membaca file dan menyalinnya ke tipe terstruktur
        n = read1("ListFilm.dat", data3);
        n--;
        // masukan user
        do
        {
            n++;
            printf("Masukkan judul film : ");
            scanf("%s", data3[n].nama);
            printf("Masukkan id sutradara : ");
            scanf("%s", data3[n].sutradara);
            printf("Masukkan id genre : ");
            scanf("%s", data3[n].genre);
            printf("Masukkan id bioskop : ");
            scanf("%s", data3[n].bioskop);
        } while (strcmp(data3[n].nama, "####") != 0);
        write1("ListFilm.dat", n, data3); // menyalin dari data dari tipe terstruktur ke file
    }
    else
    {
        printf("- Sutradara/genre/bioskop terdiri dari id dan nama.\n- Id terdiri dari 1 digit huruf dan 3 digit angka, contohnya S001, G003, B005.\n- Dimana S mewakili Sutradara, G mewakili Genre, dan B mewakili Bioskop.\n- Jika penambahan data selesai, akhiri dengan #### ####.\n");
        char sign, temp[100];
        if (x == 2)
        {
            // membaca file dan menyalinnya ke tipe terstruktur
            n = read("Sutradara.dat", data3);
            n--;
            printf("- Id terakhir yang ditambahkan %s\n", data3[n].id);
            // masukan user
            do
            {
                // masukan user
                printf("Masukkan id sutradara: ");
                scanf("%s", temp);
                sign = cek(temp, n, data3); // memeriksa id masukan user
                // mengecek kembalian dari variabel sign
                if (sign == 'y') // jika 'y' maka id tersebut dapat digunakan untuk menambahkan data
                {
                    n++;
                    strcpy(data3[n].id, temp);
                    printf("Masukkan nama sutradara: ");
                    scanf("%s", data3[n].nama);
                }
                else // jika 'n' maka akan meminta user untuk memasukkan id lagi
                {
                    printf("Id tersebut sudah ada di dalam file. Silahkan gunakan id lain...\n");
                    appends(n, data3);
                }
            } while (strcmp(data3[n].nama, "####") != 0);
            write("Sutradara.dat", n, data3); // menyalin dari data dari tipe terstruktur ke file
        }
        else if (x == 3)
        {
            // membaca file dan menyalinnya ke tipe terstruktur
            n = read("Genre.dat", data3);
            n--;
            printf("- Id terakhir yang ditambahkan %s\n", data3[n].id);
            // masukan user
            do
            {
                // masukan user
                printf("Masukkan id genre: ");
                scanf("%s", temp);
                sign = cek(temp, n, data3); // memeriksa id masukan user
                // mengecek kembalian dari variabel sign
                if (sign == 'y') // jika 'y' maka id tersebut dapat digunakan untuk menambahkan data
                {
                    n++;
                    strcpy(data3[n].id, temp);
                    printf("Masukkan nama genre: ");
                    scanf("%s", data3[n].nama);
                }
                else // jika 'n' maka akan meminta user untuk memasukkan id lagi
                {
                    printf("Id tersebut sudah ada di dalam file. Silahkan gunakan id lain...\n");
                    appendg(n, data3);
                }
            } while (strcmp(data3[n].nama, "####") != 0);
            write("Genre.dat", n, data3); // menyalin dari data dari tipe terstruktur ke file
        }
        else if (x == 4)
        {
            // membaca file dan menyalinnya ke tipe terstruktur
            n = read("Bioskop.dat", data3);
            n--;
            printf("- Id terakhir yang ditambahkan %s\n", data3[n].id);
            // masukan user
            do
            {
                // masukan user
                printf("Masukkan id bioskop: ");
                scanf("%s", temp);
                sign = cek(temp, n, data3); // memeriksa id masukan user
                // mengecek kembalian dari variabel sign
                if (sign == 'y') // jika 'y' maka id tersebut dapat digunakan untuk menambahkan data
                {
                    n++;
                    strcpy(data3[n].id, temp);
                    printf("Masukkan nama bioskop: ");
                    scanf("%s", data3[n].nama);
                }
                else // jika 'n' maka akan meminta user untuk memasukkan id lagi
                {
                    printf("Id tersebut sudah ada di dalam file. Silahkan gunakan id lain...\n");
                    appendb(n, data3);
                }
            } while (strcmp(data3[n].nama, "####") != 0);
            write("Bioskop.dat", n, data3); // menyalin dari data dari tipe terstruktur ke file
        }
        else // jika yang dipilih bukan menu 1/2/3/4 maka akan menampilkan lagi menu penambahan data
        {
            listmenu3();
        }
    }
}