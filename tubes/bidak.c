#include "LiteTetris.h"

void salinKarakter(int banyakGerak, karakter KARAKTER[banyakGerak]){


	int i = 0;

	FILE *fSumber = fopen("tgerak.txt", "r");
	
	fscanf(fSumber, "%s %d %d %d", KARAKTER[i].namaBentuk, &KARAKTER[i].korX, &KARAKTER[i].korY, &KARAKTER[i].derajat);
	while(strcmp(KARAKTER[i].namaBentuk, "##") != 0){
	
		i++;
		fscanf(fSumber, "%s %d %d %d", KARAKTER[i].namaBentuk, &KARAKTER[i].korX, &KARAKTER[i].korY, &KARAKTER[i].derajat);
	}

	fclose(fSumber);

	// for(i = 0; i < banyakGerak; i++){

	// 	printf("%s %d %d %d\n", KARAKTER[i].namaBentuk, KARAKTER[i].korX, KARAKTER[i].korY, KARAKTER[i].derajat);
	// }

}

void salinNamaBentuk(int banyakNamaBentuk, bentuk BENTUK[banyakNamaBentuk]){


	int i = 0;

	FILE *fSumber = fopen("tbentuk.txt", "r");
	
	fscanf(fSumber, "%s %s", BENTUK[i].namaBentuk, BENTUK[i].kodeBentuk);
	while(strcmp(BENTUK[i].namaBentuk, "##") != 0){
	
		i++;
		fscanf(fSumber, "%s %s", BENTUK[i].namaBentuk, BENTUK[i].kodeBentuk);
	
	}

	fclose(fSumber);

	// for(i = 0; i < banyakNamaBentuk; i++){

	// 	printf("%s %s\n", BENTUK[i].namaBentuk, BENTUK[i].kodeBentuk);
	// }

}

const char * cariKodeBentuk(int banyakNamaBentuk, bentuk BENTUK[banyakNamaBentuk], char cari[3]){
	
	int i = 0;
	int ketemu = 0;

	static char kode[3];

	while(i < banyakNamaBentuk && ketemu == 0){

		if(strcmp(BENTUK[i].namaBentuk, cari) == 0){

			strcpy(kode, BENTUK[i].kodeBentuk);
			ketemu = 1;
		}
		else{

			i++;
		}
	}

    return kode;

}

void kodeA(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex){


	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX].isi, " ");
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX+2].isi, " ");
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX+2].isi, Kar.namaBentuk);


}

void kodeA90(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex){


	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX+1].isi, " ");
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 2 + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 2 + tempIndex][Kar.korX+1].isi, " ");


}

void kodeA180(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex){


	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX+2].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX].isi, " ");
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX+2].isi, " ");


}

void kodeA270(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex){


	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX].isi, " ");
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 2 + tempIndex][Kar.korX].isi, " ");
	strcpy(TITIK[Kar.korY + 2 + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);


}


void kodeB(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex){

	// system("COLOR 04");
	
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX+2].isi, Kar.namaBentuk);


}

void kodeB90(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex){


	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 2 + tempIndex][Kar.korX].isi, Kar.namaBentuk);


}

void kodeC(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex){

	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX].isi, " ");
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX+1].isi, " ");
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX+2].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX+2].isi, Kar.namaBentuk);


}

void kodeC90(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex){


	
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX+1].isi, " ");
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX+1].isi, " ");
	strcpy(TITIK[Kar.korY + 2 + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 2 + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);


}

void kodeC180(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex){


	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX+2].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX+1].isi, " ");
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX+2].isi, " ");


}

void kodeC270(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex){

	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX].isi, " ");
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 2 + tempIndex][Kar.korX].isi, " ");
	strcpy(TITIK[Kar.korY + 2 + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);


}

void kodeD(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex){

	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX+1].isi, " ");
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);
	
}

void kodeD90(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex){

	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX+1].isi, " ");
	
}

void kodeD180(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex){

	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX].isi, " ");
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);
	
}

void kodeD270(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex){

	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX].isi, " ");
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);
	
}


void kodeE(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex){


	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX+1].isi, Kar.namaBentuk);

}

void kodeE90(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex){


	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	strcpy(TITIK[Kar.korY + 1 + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	
}

void kodeF(karakter Kar, int lebar, int panjang,titik TITIK[lebar+1][panjang+1], int tempIndex){


	strcpy(TITIK[Kar.korY + tempIndex][Kar.korX].isi, Kar.namaBentuk);
	
}

// void kodeA(kotak K, karakter Kar){


// 	int i, j;

// 	for(i = -1; i <= K.lebar+1; i++){

// 		if(i == -1 || i == K.lebar+1){

// 			border(K);
// 		}

// 		else if(i == Kar.korY){

// 			printf("|");
// 			for(j = 0; j < Kar.korX; j++){

// 				printf(" ");
// 			}

// 			printf(" ");
// 			printf("%s", Kar.namaBentuk);
// 			printf(" ");

// 			for(j = 0; j <= K.panjang - (Kar.korX + 3); j++){

// 				printf(" ");
// 			}

// 			printf("|\n");

// 		}
// 		else if(i == Kar.korY + 1){

// 			printf("|");
// 			for(j = 0; j < Kar.korX; j++){

// 				printf(" ");
// 			}

// 			printf("%s", Kar.namaBentuk);
// 			printf("%s", Kar.namaBentuk);
// 			printf("%s", Kar.namaBentuk);

// 			for(j = 0; j <= K.panjang - (Kar.korX + 3); j++){

// 				printf(" ");
// 			}

// 			printf("|\n");
// 		}
// 		else{

// 			if(i != Kar.korY + 1){
// 				fillKosong(K);
// 			}
// 		}

// 	}

	// printf("|");
	// for(i = 0; i < korX; i++){

	// 	printf(" ");
	// }

	// printf(" ");
	// printf("*");
	// printf(" ");

	// for(i = 0; i <= K.panjang - (korX + 3); i++){

	// 	printf(" ");
	// }

	// printf("|\n");


	// printf("|");
	// for(i = 0; i < korX; i++){

	// 	printf(" ");
	// }

	// printf("*");
	// printf("*");
	// printf("*");

	// for(i = 0; i <= K.panjang - (korX + 3); i++){

	// 	printf(" ");
	// }

	// printf("|\n");
// }
// void kodeB(kotak K, karakter Kar){


// 	int i, j;

// 	for(i = -1; i <= K.lebar+1; i++){

// 		if(i == -1 || i == K.lebar+1){

// 			border(K);
// 		}

// 		else if(i == Kar.korY){

// 			printf("|");
// 			for(j = 0; j < Kar.korX; j++){

// 				printf(" ");
// 			}

// 			printf("%s", Kar.namaBentuk);
// 			printf("%s", Kar.namaBentuk);
// 			printf("%s", Kar.namaBentuk);

// 			for(j = 0; j <= K.panjang - (Kar.korX + 3); j++){

// 				printf(" ");
// 			}

// 			printf("|\n");

// 		}
// 		else{

// 			if(i != Kar.korY + 1){
// 				fillKosong(K);
// 			}
// 		}

// 	}

// }
