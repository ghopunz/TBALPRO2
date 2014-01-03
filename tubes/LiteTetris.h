// Saya, Abdul Ghofur bersumpah demi Tuhan tidak melakukan kecurangan 
// yang dispesifikasikan pada tugas besar Alpro 2 pada saat mengerjakan 
// Tugas Besar Alpro 2.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>	//handle pewarnaan

//
HANDLE console;


typedef struct{

	int panjang;
	int lebar;

}kotak;

typedef struct {
	
	char namaBentuk[3];
	int korX;
	int korY;
	int derajat;

}karakter;

typedef struct {
	
	char isi[3];

}titik;

typedef struct 
{
	char namaBentuk[3];
	char kodeBentuk[3];

}bentuk;

// kotak K;

// fungsi dan prosedur yang ada di tambahBentuk.c
//+++++++++++++++++++++++++++++++++++++++++
//menghitung banyak Data
int banyakDataBentuk();
//menampilkan data 
void tampilDataBentuk();
//menambah data ke file
void addBentuk(char huruf[3], char kodeBentuk[3]);

// fungsi dan prosedur yang ada di tambahGerak.c
//+++++++++++++++++++++++++++++++++++++++++
//menghitung banyak Gerak
int banyakDataGerak();
//cek apakah ada namabentuk di file tbentuk
int adaNamaBentuk(char namaBentuk[3]);
//menambah gerak ke file
void addGerak(karakter KARAKTER);
// void addGerak(char namaBentuk[3], int korX, int korY, int derajat);
//menampilkan gerak yang ada pada file
void tampilDataGerak();
//sorting
void bubleSort(int jumlahData, karakter K[]);


// fungsi dan prosedur yang ada di kotekArea.c
//+++++++++++++++++++++++++++++++++++++++++
//======== Area kotak
//dimensi kotak
// void dimensiKotak(int panjang, int lebar);
//menampilkan nilai dimensi kotak
void tampilDimensiKotak(kotak K);
//cetak batas untuk bawah dan atas
void border(int panjang);
// void border(kotak K);
//cetak fill kosong
void fillKosong(kotak K);

//inisialisasi awal area
void initLayar(int lebar, int panjang, titik TITIK[lebar+1][panjang+1]);

//cetak gambar animasi
void gambar(int lebar, int panjang, titik TITIK[lebar+1][panjang+1], char kode[3]);

// fungsi dan prosedur yang ada di bidak.c
//+++++++++++++++++++++++++++++++++++++++++

const char * cariKodeBentuk(int banyakNamaBentuk, bentuk BENTUK[banyakNamaBentuk], char cari[3]);
//menyalin data gerak ke Array
void salinKarakter(int banyakGerak, karakter KARAKTER[banyakGerak]);
void salinNamaBentuk(int banyakNamaBentuk, bentuk BENTUK[banyakNamaBentuk]);

//tipe A
// void kodeA(kotak K, karakter Kar);
void kodeA(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex);
void kodeA90(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex);
void kodeA180(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex);
void kodeA270(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex);

//tipe B
// void kodeB(kotak K, karakter Kar);
void kodeB(karakter Kar, int lebar, int panjang, titik TITIK[lebar+1][panjang+1], int tempIndex);
//tipeB 90 derajat
void kodeB90(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex);
// void kodeB180(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex);
// void kodeB270(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex);

//kode C
void kodeC(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex);
void kodeC90(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex);
void kodeC180(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex);
void kodeC270(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex);

//kode D
void kodeD(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex);
void kodeD90(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex);
void kodeD180(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex);
void kodeD270(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex);

//kode E
void kodeE(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex);
void kodeE90(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex);


//kode F
void kodeF(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex);

// fungsi dan prosedur di animasi.c
//waktu 
void wait(float x);
void play(int banyakGerak, karakter KARAKTER[], int lebar, int panjang, titik TITIK[lebar+1][panjang+1], int banyakNamaBentuk, bentuk BENTUK[banyakNamaBentuk]);