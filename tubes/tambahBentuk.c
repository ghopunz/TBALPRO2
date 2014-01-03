#include "LiteTetris.h"

//untuk menghitung jumlah data yang ada pada FILE
int banyakDataBentuk(){

	char huruf[3], kodeBentuk[3];
	int jumlahData = 0;

	FILE *fSumber = fopen("tbentuk.txt", "r");
	
	fscanf(fSumber, "%s %s", huruf, kodeBentuk);
	while(strcmp(huruf, "##") != 0 && strcmp(kodeBentuk, "##") != 0){
	
		jumlahData++;
		fscanf(fSumber, "%s %s", huruf, kodeBentuk);
	}

	fclose(fSumber);
	return jumlahData;
}

//mengecek apakah nama bentuk ada pada file
int adaNamaBentuk(char namaBentuk[3]){

	int ketemu = 0;
	FILE *fSumber = fopen("tbentuk.txt", "r");

	char tempNamaBentuk[3], tempKodeBentuk[3];

	fscanf(fSumber, "%s %s", tempNamaBentuk, tempKodeBentuk);
	while(strcmp(tempNamaBentuk, "##") != 0 && ketemu == 0){

		if(strcmp(namaBentuk, tempNamaBentuk) == 0){

			ketemu = 1;
		}

		fscanf(fSumber, "%s %s", tempNamaBentuk, tempKodeBentuk);
	}

	fclose(fSumber);

	return ketemu;
}

//untuk menampilkan data yang ada saat ini
void tampilDataBentuk(){

	//baca file
	FILE *fSumber = fopen("tbentuk.txt", "r");

	//variabel untuk menampuk huruf dan kode bentuk
	char huruf[3], kodeBentuk[3];
	int i;

	//print tampilan
	printf("Isi bentuk saat ini:\n");
	printf("-----------------------\n");
	printf("|huruf   |kode bentuk |\n");
	printf("-----------------------\n");

	//inputan dari file berupa huruf dan kode bentuk
	fscanf(fSumber, "%s %s", huruf, kodeBentuk);
	while(strcmp(huruf, "##") != 0 && strcmp(kodeBentuk, "##") != 0){
		
		//cetak huruf dari file
		printf("|%s", huruf);
		//cetak spasi
		for(i = 0; i < 7; i++){

			printf(" ");
		}
		
		//cetak kode bentuk dari file
		printf("|%s", kodeBentuk);
		for(i = 0; i < 11; i++){

			printf(" ");
		}
		printf("|\n");
		// printf("|%s%s\n", huruf,  kodeBentuk);
		fscanf(fSumber, "%s %s", huruf, kodeBentuk);
	}
	printf("-----------------------\n");

	fclose(fSumber);
}

//untuk menambah data
void addBentuk(char huruf[3], char kodeBentuk[3]){

	//banyaknya data yang ada pada file
	int jumData = banyakDataBentuk();

	//alokasi array berdasarkan banyak data yang ada pada file
	char tempHuruf[jumData][3], tempKodeBentuk[jumData][3];

	//baca file
	FILE *fSumber = fopen("tbentuk.txt", "r");

	int i;

	//membaca file sebanyak jumData yang ada pada File
	for(i = 0; i < jumData; i++){

		fscanf(fSumber, "%s %s", tempHuruf[i], tempKodeBentuk[i]);
	}

	fclose(fSumber);

	//menulis file sebanyak data yang sebelumnya disimpan di temporari
	//ditambah inputan data dari user
	fSumber = fopen("tbentuk.txt", "w");

	for(i = 0; i < jumData; i++){

		fprintf(fSumber, "%s %s\n", tempHuruf[i], tempKodeBentuk[i]);
	}

	//menambah inputan data huruf dan kode bentuk dari user
	fprintf(fSumber, "%s %s\n", huruf, kodeBentuk);
	//menambah dummy data pada file
	fprintf(fSumber, "## ##\n");

	fclose(fSumber);
}