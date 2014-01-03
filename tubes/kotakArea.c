#include "LiteTetris.h"

// void dimensiKotak(kotak K, int panjang, int lebar){

// 	K.panjang = panjang;
// 	// printf("%d\n", K.panjang);
// 	K.lebar = lebar;
// }

void tampilDimensiKotak(kotak K){

	printf("dimensi kotak:\n");
	printf("-----------------\n");
	printf("|panjang|lebar	|\n");
	printf("-----------------\n");
	printf("|%d 	", K.panjang);
	printf("|%d 	|\n", K.lebar);
	printf("-----------------\n");
}

void border(panjang){

	int i;
	printf("|");
	for(i = 0; i <= panjang; i++){

		printf("-");
	}
	printf("|");
	printf("\n");
}

void fillKosong(kotak K){

	int i;
	printf("|");
	for(i = 0; i <= K.panjang; i++){

		printf(" ");
	}
	printf("|");
	printf("\n");
}

void initLayar(int lebar, int panjang, titik TITIK[lebar+1][panjang+1]){

	int i, j;

	for(i = 0; i <= lebar; i++){

		for(j = 0; j <= panjang; j++){

			//memberi status kosong tiap titik kordinat
			// TITIK[i][j].status = 0;
			strcpy(TITIK[i][j].isi, " ");
			// strcpy(TITIK[i][j].isi, "^");
		}
	}

	// for(i = 0; i <= lebar; i++){

	// 	for(j = 0; j <= panjang; j++){

	// 		//memberi status kosong tiap titik kordinat
	// 		printf("%s ", TITIK[i][j].isi);
	// 	}
	// 	printf("\n");
	// }
}

void gambar(int lebar, int panjang, titik TITIK[lebar+1][panjang+1], char kode[3]){

	int i, j;
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	
	for(i = -1; i <= lebar + 1; i++){

		if(i == -1 || i == lebar+1){
			SetConsoleTextAttribute(console, 7);
			border(panjang);
		}
		else{
			SetConsoleTextAttribute(console, 7);
			printf("|");
			for(j = 0; j <= panjang; j++){

				//memberi status kosong tiap titik kordinat
				if(strcmp(kode, "A") == 0){

					SetConsoleTextAttribute(console, 9);
				}
				else if(strcmp(kode, "B") == 0){

					SetConsoleTextAttribute(console, 10);
				}
				else if(strcmp(kode, "C") == 0){

					SetConsoleTextAttribute(console, 11);
				}
				else if(strcmp(kode, "D") == 0){

					SetConsoleTextAttribute(console, 12);
				}
				else if(strcmp(kode, "E") == 0){

					SetConsoleTextAttribute(console, 13);
				}
				else if(strcmp(kode, "F") == 0){

					SetConsoleTextAttribute(console, 14);
				}
				printf("%s", TITIK[i][j].isi);
			}
			SetConsoleTextAttribute(console, 7);
			printf("|\n");
		}
	}
}