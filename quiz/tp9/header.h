#include <stdio.h>

/*Saya Bayu Wicaksono mengerjakan TP9 dalam mata kuliah Algoritma dan Pemrograman 2 untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int indeks; // deklarasi variabel global untuk index karakter
char cc;    // deklarasi variabel global untuk karakter

void start(char str[]); // prosedur untuk memulai pembacaan pita/string
void dec(char str[]);   // prosedur untuk decrement karakter dan jika bertemu spasi, maka spasi tsb akan dilewati hingga bertemu karakter baru
int eop();              // fungsi untuk mengecek apakah bertemu ('.') atau tidak
void adv(char str[]);   // prosedur untuk increment karakter dan jika bertemu spasi, maka spasi tsb akan dilewati hingga bertemu karakter
char getcc();           // fungsi untuk mengembalikan nilai karakter saat ini
void cek();             // prosedur untuk mengubah karakter yang uppercase menjadi lowercase