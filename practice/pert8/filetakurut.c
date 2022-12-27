#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[10], nama[100], nilai[5];
} nilaimatkul;

int main()
{
    nilaimatkul record1;
    nilaimatkul record2;
    FILE *arsipmatkul1;
    FILE *arsipmatkul2;
    FILE *arsipmatkul3;
    arsipmatkul1 = fopen("arsipmatkul1.dat", "r");
    arsipmatkul2 = fopen("arsipmatkul2.dat", "r");
    arsipmatkul3 = fopen("arsipmatkul3.dat", "w");
    // proses penggabungan file
    fscanf(arsipmatkul1, "%s %s %s", record1.nim, record1.nama, record1.nilai);

    while (strcmp(record1.nim, "XXXXXX") != 0)
    {
        fprintf(arsipmatkul3, "%s %s %s\n", record1.nim, record1.nama, record1.nilai);
        fscanf(arsipmatkul1, "%s %s %s", record1.nim, record1.nama, record1.nilai);
    }

    fscanf(arsipmatkul2, "%s %s %s", record2.nim, record2.nama, record2.nilai);
    while (strcmp(record2.nim, "XXXXXX") != 0)
    {
        fprintf(arsipmatkul3, "%s %s %s\n", record2.nim, record2.nama, record2.nilai);
        fscanf(arsipmatkul2, "%s %s %s", record2.nim, record2.nama, record2.nilai);
    }
    fprintf(arsipmatkul3, "XXXXXX XXXX X\n");

    fclose(arsipmatkul1);
    fclose(arsipmatkul2);
    fclose(arsipmatkul3);

    return 0;
}