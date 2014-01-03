#include "LiteTetris.h"

int main(){

	// FILE *fSumber = fopen("tbentuk.txt", "r");

	// int jumlahData = 0;

	// printf("huruf: "); scanf("%s", huruf);
	// printf("bentuk: "); scanf("%s", kodeBentuk);
	// tampilDataBentuk();
	// addBentuk(huruf, kodeBentuk);
	// tampilDataBentuk();
	
	// char namaBentuk[3];
	// int korX, korY, derajat;

	// printf("nama bentuk: "); scanf("%s", namaBentuk);
	// printf("kordinat X: "); scanf("%d", &korX);
	// printf("kordinat Y: "); scanf("%d", &korY);
	// printf("derajat: "); scanf("%d", &derajat);
	
	// tampilDataGerak();
	// if(adaNamaBentuk(namaBentuk) == 1){

	// 	printf("ada\n");
	// 	addGerak(namaBentuk, korX, korY, derajat);
	// 	// printf("%d\n", banyakDataGerak());
	// }
	// else{
	// 	printf("tidak ada\n");
	// }
	// fscanf(fSumber, "%s %s", huruf, kodeBentuk);
	// while(strcmp(huruf, "##") != 0 && strcmp(kodeBentuk, "##") != 0){
	// 	printf("masuk\n");
	// 	jumlahData++;
	// 	fscanf(fSumber, "%s %s", huruf, kodeBentuk);
	// }

	//fclose(fSumber);

	// printf("jumlahData: %d\n", jumlahData);

	// int panjang, lebar;
	// kotak K;
	// printf("panjang: "); scanf("%d", &K.panjang);
	// printf("lebar: "); scanf("%d", &K.lebar);

	
	// dimensiKotak(K, panjang, lebar);
	// tampilDimensiKotak(K);
	// int i;

	// int korY = 1;
	// for(i = -1; i <= K.lebar+1; i++){

	// 	if(i == -1 || i == K.lebar+1){

	// 		border(K);
	// 	}

	// 	else if(i == korY){

	// 		kodeA(K, 0, 0);
	// 	}
	// 	else{

	// 		if(i != korY + 1){
	// 			fillKosong(K);
	// 		}
	// 	}

	// }

	// border(K);

	// for(i = korY; i <= K.lebar; i++){

	// 	kodeA(K, 3, i);

	// 	wait(2);

	// 	system("cls");
	// }
	// kodeA(K, 3, korY);
	// border(K);


	char huruf[3], kodeBentuk[3];
	int pilihan;
	char konfirmasi = 'T';
	int panjang = 0, lebar = 0;
	kotak K;

	char namaBentuk[3];
	int korX, korY, derajat;

	do{

		// system("cls");
		printf("Menu:\n");
		printf("1. Tambah bentuk\n");
		printf("2. Tambah gerak\n");
		printf("3. Memasukkan Panjang dan Lebar Layar\n");
		printf("4. Simulasi Lite Tetris\n");
		printf("5. Keluar\n");
		printf("Masukkan pilihan: "); scanf("%d", &pilihan);

		switch(pilihan){

			//pilihan 1
			case 1: {
					system("cls");
					tampilDataBentuk();
					printf("ingin mengisi: "); scanf(" %c", &konfirmasi);

					if(konfirmasi == 'Y' || konfirmasi == 'y'){
						
						printf("huruf: "); scanf("%s", huruf);
						printf("bentuk: "); scanf("%s", kodeBentuk);
						
						//cek apakah nama bentuk tersedia di file tbentuk
						if(adaNamaBentuk(huruf) == 0){

							addBentuk(huruf, kodeBentuk);
							printf("data bentuk berhasil disimpan.....\n");
						}
						else{

							printf("nama bentuk sudah tersedia\n");
						}
						
						system("pause");
					}

			}break;

			//pilihan 2
			case 2: {
					
					system("cls");
					tampilDataGerak();

					//variabel karakter 
					karakter KARAKTER;

					printf("ingin mengisi: "); scanf(" %c", &konfirmasi);

					if(konfirmasi == 'Y' || konfirmasi == 'y'){

						printf("nama bentuk: "); scanf("%s", KARAKTER.namaBentuk);

						//cek apakah nama bentuk tersedia di file tbentuk
						if(adaNamaBentuk(KARAKTER.namaBentuk) == 1){

							printf("\n");
							printf("nama bentuk tersedia\n");
							printf("silahkan isi data selanjutnya\n");
							printf("\n");
							printf("kordinat X: "); scanf("%d", &KARAKTER.korX);
							printf("kordinat Y: "); scanf("%d", &KARAKTER.korY);
							printf("derajat: "); scanf("%d", &KARAKTER.derajat);
							
							addGerak(KARAKTER);
							// printf("%d\n", banyakDataGerak());
							printf("data gerak berhasil disimpan.....\n");
							
						}
						else{
							printf("nama bentuk tidak tersedia\n");
							
						}

						system("pause");
					}
					
			}break;

			//pilihan 3
			case 3: {
					system("cls");
					
					// printf("panjang: "); scanf("%d", &K.panjang);
					// printf("lebar: "); scanf("%d", &K.lebar);

					printf("panjang: "); scanf("%d", &panjang);
					printf("lebar: "); scanf("%d", &lebar);

					
					
					printf("panjang dan lebar Layar(Area) disimpan.....\n");
					// tampilDimensiKotak(K);
					system("pause");

			}break;

			//pilihan 4
			case 4: {
					system("cls");

					if(panjang != 0 && lebar != 0){
						
						titik TITIK[lebar+1][panjang+1];
						// initLayar(lebar, panjang, TITIK);

						int banyakGerak = banyakDataGerak();
						karakter KARAKTER[banyakGerak];
						salinKarakter(banyakGerak, KARAKTER);

						int banyakNamaBentuk = banyakDataBentuk();
						// printf("masuk\n");

						bentuk BENTUK[banyakNamaBentuk];
						salinNamaBentuk(banyakNamaBentuk, BENTUK);
						
						play(banyakGerak, KARAKTER, lebar, panjang, TITIK, banyakNamaBentuk, BENTUK);

						system("cls");
						initLayar(lebar, panjang, TITIK);
						gambar(lebar, panjang, TITIK, "A");
						
					}
					//jalankan animasi
					// system("pause");

			}break;


			//pilihan 5
			case 5: {
					
				system("exit");
				
			}break;

		}
	}while(pilihan != 5);
	return 0;
}