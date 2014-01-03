#include "LiteTetris.h"

//untuk menghitung jumlah gerak yang ada pada FILE
int banyakDataGerak(){

	karakter tempKar;
	// char tempNamaBentuk[3];
	// int tempKorX, tempKorY, tempDerajat;
	int jumlahData = 0;

	FILE *fSumber = fopen("tgerak.txt", "r");
	
	fscanf(fSumber, "%s %d %d %d", tempKar.namaBentuk, &tempKar.korX, &tempKar.korY, &tempKar.derajat);
	while(strcmp(tempKar.namaBentuk, "##") != 0){
	
		jumlahData++;
		fscanf(fSumber, "%s %d %d %d", tempKar.namaBentuk, &tempKar.korX, &tempKar.korY, &tempKar.derajat);
	}

	fclose(fSumber);
	return jumlahData;
}



//untuk menambah gerak
void addGerak(karakter KARAKTER){

	//banyaknya data yang ada pada file
	int jumData = banyakDataGerak();

	//alokasi array berdasarkan banyak gerak yang ada pada file
	karakter tempKar[jumData+1];

	//baca file
	FILE *fSumber = fopen("tgerak.txt", "r");

	int i;

	//membaca file sebanyak jumData yang ada pada File tgerak
	for(i = 0; i < jumData; i++){

		fscanf(fSumber, "%s %d %d %d", tempKar[i].namaBentuk, &tempKar[i].korX, &tempKar[i].korY, &tempKar[i].derajat);
	}

	fclose(fSumber);

	//memasukkan data dari user ke aray tempKar
	strcpy(tempKar[i].namaBentuk, KARAKTER.namaBentuk);
	tempKar[i].korX = KARAKTER.korX;
	tempKar[i].korY = KARAKTER.korY;
	tempKar[i].derajat = KARAKTER.derajat;

	//lakukan pengurutan
	bubleSort(jumData+1, tempKar);
	
	//menulis file sebanyak data yang sebelumnya disimpan di temporari
	//ditambah inputan data dari user
	fSumber = fopen("tgerak.txt", "w");

	for(i = 0; i < jumData+1; i++){

		fprintf(fSumber, "%s %d %d %d\n", tempKar[i].namaBentuk, tempKar[i].korX, tempKar[i].korY, tempKar[i].derajat);
	}

	//menambah inputan gerak huruf dan kode bentuk dari user
	// fprintf(fSumber, "%s %d %d %d\n", KARAKTER.namaBentuk, KARAKTER.korX, KARAKTER.korY, KARAKTER.derajat);
	//menambah dummy data pada file
	fprintf(fSumber, "## ## ## ##\n");

	fclose(fSumber);
}

//untuk menampilkan data gerak yang ada saat ini
void tampilDataGerak(){

	//baca file
	FILE *fSumber = fopen("tgerak.txt", "r");

	//variabel untuk menampuk huruf dan kode bentuk
	karakter tempKar;

	int i;

	//print tampilan
	printf("Isi gerak saat ini:\n");
	printf("-----------------------------------------\n");
	printf("|nama bentuk 	|korX 	|korY 	|derajat|\n");
	printf("-----------------------------------------\n");

	//inputan dari file berupa namabentuk, korX, korY, derajat
	fscanf(fSumber, "%s %d %d %d", tempKar.namaBentuk, &tempKar.korX, &tempKar.korY, &tempKar.derajat);
	while(strcmp(tempKar.namaBentuk, "##") != 0){
		
		//cetak huruf dari file
		printf("|%s", tempKar.namaBentuk);
		//cetak spasi
		for(i = 0; i < 14; i++){

			printf(" ");
		}
		
		//cetak kor X
		printf("|%d 	", tempKar.korX);
		

		//cetak kor Y
		printf("|%d 	", tempKar.korY);
	
		//cetak derajat
		printf("|%d 	", tempKar.derajat);
		

		printf("|\n");
		// printf("|%s%s\n", huruf,  kodeBentuk);
		fscanf(fSumber, "%s %d %d %d", tempKar.namaBentuk, &tempKar.korX, &tempKar.korY, &tempKar.derajat);
	}
	printf("-----------------------------------------\n");

	fclose(fSumber);
}

//sorting
void bubleSort(int jumlahData, karakter K[]){

	int i;
	karakter tempKar;

	int tukar = 0;

	//urut dari kecil ke besar
	do{

		tukar = 0;
		for(i = 0; i < jumlahData-1; i++){

			//urut berdasarkan alfabet
			if(strcmp(K[i].namaBentuk, K[i+1].namaBentuk) > 0){

				tempKar = K[i];
				K[i] = K[i+1];
				K[i+1] = tempKar;
				tukar = 1;
			}
			//jika huruf sama, maka lakukan perbandingan dengan korY
			else if(strcmp(K[i].namaBentuk, K[i+1].namaBentuk) == 0){

				if(K[i].korY > K[i+1].korY){

					tempKar = K[i];
					K[i] = K[i+1];
					K[i+1] = tempKar;
					tukar = 1;
				}
			}
		}
	}while(tukar == 1);
}