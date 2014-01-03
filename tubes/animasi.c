#include "LiteTetris.h"

//waktu jeda
void wait(float x){

	time_t start;
	time_t current;
	time(&start);

	do{

		time(&current);
	}while(difftime(current, start) < x);
}

void play(int banyakGerak, karakter KARAKTER[], int lebar, int panjang, titik TITIK[lebar+1][panjang+1], int banyakNamaBentuk, bentuk BENTUK[banyakNamaBentuk]){

	karakter currentKar;

	int gambarUlang;
	int tempIndex = 0;

	int i = 0, j = 0, k;

	int X = 0;
	//variabel untuk menghentikan animasi
	int stop = 0;

	//variabel untuk menentukan namabentuk yg sekarang sama dengan nama bentuk pada gerak selanjutnya
	int sama = 0;

	int currentDerajat = 0;

	currentKar = KARAKTER[i];
	gambarUlang = lebar - currentKar.korY;
	currentDerajat = currentKar.derajat;

	char kode[3];

	while(i < banyakGerak){


		// j = 0;
		stop = 0;
		j = currentKar.korY;
		k = 0;

		strcpy(kode, cariKodeBentuk(banyakNamaBentuk, BENTUK, currentKar.namaBentuk));
		// printf("%s\n", kode);
		// ========= untuk namabentuk A ===================
		if(strcmp(kode, "A") == 0 && (currentDerajat == 0 || currentDerajat == 360)){

			//jika korX dan kor Y masih berada di arena kotak
			if(currentKar.korY <= lebar - 1 && currentKar.korY >= 0 && currentKar.korX <= panjang-2 && currentKar.korX >= 0){

				
				//lakukan penggambaran sebanyak lebar kotak
				//dan karakter pada gerak selanjutnya tidak sama
				while(j <= lebar-1 && stop == 0){


					tempIndex = k;
					system("cls");
					initLayar(lebar, panjang, TITIK);
					//lakukan inisialisasi untuk kodeA
					kodeA(currentKar, lebar, panjang, TITIK, tempIndex);
					//lakukan penggambaran
					gambar(lebar, panjang, TITIK, kode);
					wait(1);

					sama = 0;
					X = i+1;
					while(X < banyakGerak && sama == 0){

						if(strcmp(KARAKTER[X].namaBentuk, currentKar.namaBentuk) == 0 && KARAKTER[X].korY-1 == j){

							if(KARAKTER[X].derajat == 0 || KARAKTER[X].derajat == 180 || KARAKTER[X].derajat == 360){

								if(KARAKTER[X].korY <= lebar - 1 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-2 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							else if(KARAKTER[X].derajat == 90 || KARAKTER[X].derajat == 270){

								if(KARAKTER[X].korY <= lebar - 2 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-1 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							
							
							// currentDerajat = KARAKTER[X].derajat + currentKar.derajat;

							// printf("%d\n", KARAKTER[X].derajat);
							// printf("%d\n", currentKar.derajat);
							// wait(1);
						}
						else{

							X++;
						}
					}

					if(sama == 1){

						stop = 1;
					}
					else{

						j++;
						k++;
					}

				}
				
				// printf("ngek\n");
			}
			
		}
		else if(strcmp(kode, "A") == 0 && currentDerajat == 90){


			if(currentKar.korY <= lebar - 2 && currentKar.korY >= 0 && currentKar.korX <= panjang-1 && currentKar.korX >= 0){

				while(j <= lebar-2 && stop == 0){


					tempIndex = k;
					system("cls");

					initLayar(lebar, panjang, TITIK);
					//lakukan inisialisasi untuk kodeA
					kodeA90(currentKar, lebar, panjang, TITIK, tempIndex);
					//lakukan penggambaran
					gambar(lebar, panjang, TITIK, kode);
					wait(1);

					sama = 0;
					X = i+1;
					while(X < banyakGerak && sama == 0){

						if(strcmp(KARAKTER[X].namaBentuk, currentKar.namaBentuk) == 0 && KARAKTER[X].korY-1 == j){

							if(KARAKTER[X].derajat == 0 || KARAKTER[X].derajat == 180 || KARAKTER[X].derajat == 360){

								if(KARAKTER[X].korY <= lebar - 1 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-2 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							else if(KARAKTER[X].derajat == 90 || KARAKTER[X].derajat == 270){

								if(KARAKTER[X].korY <= lebar - 2 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-1 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							
						}
						else{

							X++;
						}
					}

					if(sama == 1){

						stop = 1;
					}
					else{

						j++;
						k++;
					}

				}
				
				// printf("ngek\n");
			}
			
		}
		else if(strcmp(kode, "A") == 0 && currentDerajat == 180){


			if(currentKar.korY <= lebar - 1 && currentKar.korY >= 0 && currentKar.korX <= panjang-2 && currentKar.korX >= 0){

				while(j <= lebar-1 && stop == 0){


					tempIndex = k;
					system("cls");
					initLayar(lebar, panjang, TITIK);
					//lakukan inisialisasi untuk kodeA
					kodeA180(currentKar, lebar, panjang, TITIK, tempIndex);
					//lakukan penggambaran
					gambar(lebar, panjang, TITIK, kode);
					wait(1);

					sama = 0;
					X = i+1;
					while(X < banyakGerak && sama == 0){

						if(strcmp(KARAKTER[X].namaBentuk, currentKar.namaBentuk) == 0 && KARAKTER[X].korY-1 == j){

							if(KARAKTER[X].derajat == 0 || KARAKTER[X].derajat == 180 || KARAKTER[X].derajat == 360){

								if(KARAKTER[X].korY <= lebar - 1 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-2 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							else if(KARAKTER[X].derajat == 90 || KARAKTER[X].derajat == 270){

								if(KARAKTER[X].korY <= lebar - 2 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-1 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
						}
						else{

							X++;
						}
					}

					if(sama == 1){

						stop = 1;
					}
					else{

						j++;
						k++;
					}

				}
				
				// printf("ngek\n");
			}
			
		}
		else if(strcmp(kode, "A") == 0 && currentDerajat == 270){


			if(currentKar.korY <= lebar - 2 && currentKar.korY >= 0 && currentKar.korX <= panjang-1 && currentKar.korX >= 0){

				while(j <= lebar-2 && stop == 0){


					tempIndex = k;
					system("cls");
					initLayar(lebar, panjang, TITIK);
					//lakukan inisialisasi untuk kodeA
					kodeA270(currentKar, lebar, panjang, TITIK, tempIndex);
					//lakukan penggambaran
					gambar(lebar, panjang, TITIK, kode);
					wait(1);

					sama = 0;
					X = i+1;
					while(X < banyakGerak && sama == 0){

						if(strcmp(KARAKTER[X].namaBentuk, currentKar.namaBentuk) == 0 && KARAKTER[X].korY-1 == j){

							if(KARAKTER[X].derajat == 0 || KARAKTER[X].derajat == 180 || KARAKTER[X].derajat == 360){

								if(KARAKTER[X].korY <= lebar - 1 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-2 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							else if(KARAKTER[X].derajat == 90 || KARAKTER[X].derajat == 270){

								if(KARAKTER[X].korY <= lebar - 2 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-1 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
						}
						else{

							X++;
						}
					}

					if(sama == 1){

						stop = 1;
					}
					else{

						j++;
						k++;
					}

				}
				
				// printf("ngek\n");
			}
			
		}
		// +++++++++++++++++++++++++++++++++++++++++++++

		// ========= untuk namabentuk B ===================
		else if(strcmp(kode, "B") == 0 && (currentDerajat == 0 || currentDerajat == 360 || currentDerajat == 180)){

			if(currentKar.korY <= lebar && currentKar.korY >= 0 && currentKar.korX <= panjang-2 && currentKar.korX >= 0){

				while(j <= lebar && stop == 0){


					tempIndex = k;
					system("cls");
					initLayar(lebar, panjang, TITIK);
					//lakukan inisialisasi untuk kodeA
					kodeB(currentKar, lebar, panjang, TITIK, tempIndex);
					//lakukan penggambaran
					gambar(lebar, panjang, TITIK, kode);
					wait(1);

					sama = 0;
					X = i+1;
					while(X < banyakGerak && sama == 0){

						if(strcmp(KARAKTER[X].namaBentuk, currentKar.namaBentuk) == 0 && KARAKTER[X].korY-1 == j){

							if(KARAKTER[X].derajat == 0 || KARAKTER[X].derajat == 180 || KARAKTER[X].derajat == 360){

								if(KARAKTER[X].korY <= lebar && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-2 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							else if(KARAKTER[X].derajat == 90 || KARAKTER[X].derajat == 270){

								if(KARAKTER[X].korY <= lebar - 2 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
						}
						else{

							X++;
						}
					}

					if(sama == 1){

						stop = 1;
					}
					else{

						j++;
						k++;
					}

				}
				
				// printf("ngek\n");

			}

			
		}
		else if(strcmp(kode, "B") == 0 && (currentDerajat == 90 || currentDerajat == 270)){

			if(currentKar.korY <= lebar-2 && currentKar.korY >= 0 && currentKar.korX <= panjang && currentKar.korX >= 0){

				while(j <= lebar-2 && stop == 0){


					tempIndex = k;
					system("cls");
					initLayar(lebar, panjang, TITIK);
					//lakukan inisialisasi untuk kodeA
					kodeB90(currentKar, lebar, panjang, TITIK, tempIndex);
					//lakukan penggambaran
					gambar(lebar, panjang, TITIK, kode);
					wait(1);

					sama = 0;
					X = i+1;
					while(X < banyakGerak && sama == 0){

						if(strcmp(KARAKTER[X].namaBentuk, currentKar.namaBentuk) == 0 && KARAKTER[X].korY-1 == j){

							if(KARAKTER[X].derajat == 0 || KARAKTER[X].derajat == 180 || KARAKTER[X].derajat == 360){

								if(KARAKTER[X].korY <= lebar && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-2 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							else if(KARAKTER[X].derajat == 90 || KARAKTER[X].derajat == 270){

								if(KARAKTER[X].korY <= lebar - 2 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
						}
						else{

							X++;
						}
					}

					if(sama == 1){

						stop = 1;
					}
					else{

						j++;
						k++;
					}

				}

			
			// printf("ngek\n");
			}
			
		}
		// ========= untuk namabentuk C ===================
		else if(strcmp(kode, "C") == 0 && (currentDerajat == 0 || currentDerajat == 360)){

			//jika korX dan kor Y masih berada di arena kotak
			if(currentKar.korY <= lebar - 1 && currentKar.korY >= 0 && currentKar.korX <= panjang-2 && currentKar.korX >= 0){

				
				//lakukan penggambaran sebanyak lebar kotak
				//dan karakter pada gerak selanjutnya tidak sama
				while(j <= lebar-1 && stop == 0){


					tempIndex = k;
					system("cls");
					initLayar(lebar, panjang, TITIK);
					//lakukan inisialisasi untuk kodeA
					kodeC(currentKar, lebar, panjang, TITIK, tempIndex);
					//lakukan penggambaran
					gambar(lebar, panjang, TITIK, kode);
					wait(1);

					sama = 0;
					X = i+1;
					while(X < banyakGerak && sama == 0){

						if(strcmp(KARAKTER[X].namaBentuk, currentKar.namaBentuk) == 0 && KARAKTER[X].korY-1 == j){

							if(KARAKTER[X].derajat == 0 || KARAKTER[X].derajat == 180 || KARAKTER[X].derajat == 360){

								if(KARAKTER[X].korY <= lebar - 1 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-2 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							else if(KARAKTER[X].derajat == 90 || KARAKTER[X].derajat == 270){

								if(KARAKTER[X].korY <= lebar - 2 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-1 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
						}
						else{

							X++;
						}
					}

					if(sama == 1){

						stop = 1;
					}
					else{

						j++;
						k++;
					}

				}
				
				// printf("ngek\n");
			}
			
		}
		else if(strcmp(kode, "C") == 0 && currentDerajat == 90){


			if(currentKar.korY <= lebar - 2 && currentKar.korY >= 0 && currentKar.korX <= panjang-1 && currentKar.korX >= 0){

				while(j <= lebar-2 && stop == 0){


					tempIndex = k;
					system("cls");

					initLayar(lebar, panjang, TITIK);
					//lakukan inisialisasi untuk kodeA
					kodeC90(currentKar, lebar, panjang, TITIK, tempIndex);
					//lakukan penggambaran
					gambar(lebar, panjang, TITIK, kode);
					wait(1);

					sama = 0;
					X = i+1;
					while(X < banyakGerak && sama == 0){

						if(strcmp(KARAKTER[X].namaBentuk, currentKar.namaBentuk) == 0 && KARAKTER[X].korY-1 == j){

							if(KARAKTER[X].derajat == 0 || KARAKTER[X].derajat == 180 || KARAKTER[X].derajat == 360){

								if(KARAKTER[X].korY <= lebar - 1 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-2 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							else if(KARAKTER[X].derajat == 90 || KARAKTER[X].derajat == 270){

								if(KARAKTER[X].korY <= lebar - 2 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-1 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							
						}
						else{

							X++;
						}
					}

					if(sama == 1){

						stop = 1;
					}
					else{

						j++;
						k++;
					}

				}
				
				// printf("ngek\n");
			}
			
		}
		else if(strcmp(kode, "C") == 0 && currentDerajat == 180){


			if(currentKar.korY <= lebar - 1 && currentKar.korY >= 0 && currentKar.korX <= panjang-2 && currentKar.korX >= 0){

				while(j <= lebar-1 && stop == 0){


					tempIndex = k;
					system("cls");
					initLayar(lebar, panjang, TITIK);
					//lakukan inisialisasi untuk kodeA
					kodeC180(currentKar, lebar, panjang, TITIK, tempIndex);
					//lakukan penggambaran
					gambar(lebar, panjang, TITIK, kode);
					wait(1);

					sama = 0;
					X = i+1;
					while(X < banyakGerak && sama == 0){

						if(strcmp(KARAKTER[X].namaBentuk, currentKar.namaBentuk) == 0 && KARAKTER[X].korY-1 == j){

							if(KARAKTER[X].derajat == 0 || KARAKTER[X].derajat == 180 || KARAKTER[X].derajat == 360){

								if(KARAKTER[X].korY <= lebar - 1 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-2 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							else if(KARAKTER[X].derajat == 90 || KARAKTER[X].derajat == 270){

								if(KARAKTER[X].korY <= lebar - 2 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-1 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
						}
						else{

							X++;
						}
					}

					if(sama == 1){

						stop = 1;
					}
					else{

						j++;
						k++;
					}

				}
				
				// printf("ngek\n");
			}
			
		}
		else if(strcmp(kode, "C") == 0 && currentDerajat == 270){


			if(currentKar.korY <= lebar - 2 && currentKar.korY >= 0 && currentKar.korX <= panjang-1 && currentKar.korX >= 0){

				while(j <= lebar-2 && stop == 0){


					tempIndex = k;
					system("cls");
					initLayar(lebar, panjang, TITIK);
					//lakukan inisialisasi untuk kodeA
					kodeC270(currentKar, lebar, panjang, TITIK, tempIndex);
					//lakukan penggambaran
					gambar(lebar, panjang, TITIK, kode);
					wait(1);

					sama = 0;
					X = i+1;
					while(X < banyakGerak && sama == 0){

						if(strcmp(KARAKTER[X].namaBentuk, currentKar.namaBentuk) == 0 && KARAKTER[X].korY-1 == j){

							if(KARAKTER[X].derajat == 0 || KARAKTER[X].derajat == 180 || KARAKTER[X].derajat == 360){

								if(KARAKTER[X].korY <= lebar - 1 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-2 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							else if(KARAKTER[X].derajat == 90 || KARAKTER[X].derajat == 270){

								if(KARAKTER[X].korY <= lebar - 2 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-1 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
						}
						else{

							X++;
						}
					}

					if(sama == 1){

						stop = 1;
					}
					else{

						j++;
						k++;
					}

				}
				
				// printf("ngek\n");
			}
			
		}
		// ========= untuk namabentuk D ===================
		else if(strcmp(kode, "D") == 0 && (currentDerajat == 0 || currentDerajat == 360)){

			//jika korX dan kor Y masih berada di arena kotak
			if(currentKar.korY <= lebar - 1 && currentKar.korY >= 0 && currentKar.korX <= panjang-1 && currentKar.korX >= 0){

				
				//lakukan penggambaran sebanyak lebar kotak
				//dan karakter pada gerak selanjutnya tidak sama
				while(j <= lebar-1 && stop == 0){


					tempIndex = k;
					system("cls");
					initLayar(lebar, panjang, TITIK);
					//lakukan inisialisasi untuk kodeA
					kodeD(currentKar, lebar, panjang, TITIK, tempIndex);
					//lakukan penggambaran
					gambar(lebar, panjang, TITIK, kode);
					wait(1);

					sama = 0;
					X = i+1;
					while(X < banyakGerak && sama == 0){

						if(strcmp(KARAKTER[X].namaBentuk, currentKar.namaBentuk) == 0 && KARAKTER[X].korY-1 == j){

							if(KARAKTER[X].derajat == 0 || KARAKTER[X].derajat == 180 || KARAKTER[X].derajat == 360){

								if(KARAKTER[X].korY <= lebar - 1 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-1 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							else if(KARAKTER[X].derajat == 90 || KARAKTER[X].derajat == 270){

								if(KARAKTER[X].korY <= lebar - 1 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-1 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							// currentDerajat = KARAKTER[X].derajat + currentKar.derajat;

							// printf("%d\n", KARAKTER[X].derajat);
							// printf("%d\n", currentKar.derajat);
							// wait(1);
						}
						else{

							X++;
						}
					}

					if(sama == 1){

						stop = 1;
					}
					else{

						j++;
						k++;
					}

				}
				
				// printf("ngek\n");
			}
			
		}
		else if(strcmp(kode, "D") == 0 && currentDerajat == 90){


			if(currentKar.korY <= lebar - 1 && currentKar.korY >= 0 && currentKar.korX <= panjang-1 && currentKar.korX >= 0){

				while(j <= lebar-1 && stop == 0){


					tempIndex = k;
					system("cls");

					initLayar(lebar, panjang, TITIK);
					//lakukan inisialisasi untuk kodeA
					kodeD90(currentKar, lebar, panjang, TITIK, tempIndex);
					//lakukan penggambaran
					gambar(lebar, panjang, TITIK, kode);
					wait(1);

					sama = 0;
					X = i+1;
					while(X < banyakGerak && sama == 0){

						if(strcmp(KARAKTER[X].namaBentuk, currentKar.namaBentuk) == 0 && KARAKTER[X].korY-1 == j){

							if(KARAKTER[X].derajat == 0 || KARAKTER[X].derajat == 180 || KARAKTER[X].derajat == 360){

								if(KARAKTER[X].korY <= lebar - 1 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-1 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							else if(KARAKTER[X].derajat == 90 || KARAKTER[X].derajat == 270){

								if(KARAKTER[X].korY <= lebar - 1 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-1 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							
						}
						else{

							X++;
						}
					}

					if(sama == 1){

						stop = 1;
					}
					else{

						j++;
						k++;
					}

				}
				
				// printf("ngek\n");
			}
			
		}
		else if(strcmp(kode, "D") == 0 && currentDerajat == 180){


			if(currentKar.korY <= lebar - 1 && currentKar.korY >= 0 && currentKar.korX <= panjang-1 && currentKar.korX >= 0){

				while(j <= lebar-1 && stop == 0){


					tempIndex = k;
					system("cls");
					initLayar(lebar, panjang, TITIK);
					//lakukan inisialisasi untuk kodeA
					kodeD180(currentKar, lebar, panjang, TITIK, tempIndex);
					//lakukan penggambaran
					gambar(lebar, panjang, TITIK, kode);
					wait(1);

					sama = 0;
					X = i+1;
					while(X < banyakGerak && sama == 0){

						if(strcmp(KARAKTER[X].namaBentuk, currentKar.namaBentuk) == 0 && KARAKTER[X].korY-1 == j){

							if(KARAKTER[X].derajat == 0 || KARAKTER[X].derajat == 180 || KARAKTER[X].derajat == 360){

								if(KARAKTER[X].korY <= lebar - 1 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-1 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							else if(KARAKTER[X].derajat == 90 || KARAKTER[X].derajat == 270){

								if(KARAKTER[X].korY <= lebar - 1 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-1 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
						}
						else{

							X++;
						}
					}

					if(sama == 1){

						stop = 1;
					}
					else{

						j++;
						k++;
					}

				}
				
				// printf("ngek\n");
			}
			
		}
		else if(strcmp(kode, "D") == 0 && currentDerajat == 270){


			if(currentKar.korY <= lebar - 1 && currentKar.korY >= 0 && currentKar.korX <= panjang-1 && currentKar.korX >= 0){

				while(j <= lebar-1 && stop == 0){


					tempIndex = k;
					system("cls");
					initLayar(lebar, panjang, TITIK);
					//lakukan inisialisasi untuk kodeA
					kodeD270(currentKar, lebar, panjang, TITIK, tempIndex);
					//lakukan penggambaran
					gambar(lebar, panjang, TITIK, kode);
					wait(1);

					sama = 0;
					X = i+1;
					while(X < banyakGerak && sama == 0){

						if(strcmp(KARAKTER[X].namaBentuk, currentKar.namaBentuk) == 0 && KARAKTER[X].korY-1 == j){

							if(KARAKTER[X].derajat == 0 || KARAKTER[X].derajat == 180 || KARAKTER[X].derajat == 360){

								if(KARAKTER[X].korY <= lebar - 1 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-1 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							else if(KARAKTER[X].derajat == 90 || KARAKTER[X].derajat == 270){

								if(KARAKTER[X].korY <= lebar - 1 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-1 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
						}
						else{

							X++;
						}
					}

					if(sama == 1){

						stop = 1;
					}
					else{

						j++;
						k++;
					}

				}
				
				// printf("ngek\n");
			}
			
		}

		// ========= untuk namabentuk E ===================
		else if(strcmp(kode, "E") == 0 && (currentDerajat == 0 || currentDerajat == 360 || currentDerajat == 180)){

			if(currentKar.korY <= lebar && currentKar.korY >= 0 && currentKar.korX <= panjang-1 && currentKar.korX >= 0){

				while(j <= lebar && stop == 0){


					tempIndex = k;
					system("cls");
					initLayar(lebar, panjang, TITIK);
					//lakukan inisialisasi untuk kodeA
					kodeE(currentKar, lebar, panjang, TITIK, tempIndex);
					//lakukan penggambaran
					gambar(lebar, panjang, TITIK, kode);
					wait(1);

					sama = 0;
					X = i+1;
					while(X < banyakGerak && sama == 0){

						if(strcmp(KARAKTER[X].namaBentuk, currentKar.namaBentuk) == 0 && KARAKTER[X].korY-1 == j){

							if(KARAKTER[X].derajat == 0 || KARAKTER[X].derajat == 180 || KARAKTER[X].derajat == 360){

								if(KARAKTER[X].korY <= lebar && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-1 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							else if(KARAKTER[X].derajat == 90 || KARAKTER[X].derajat == 270){

								if(KARAKTER[X].korY <= lebar - 1 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
						}
						else{

							X++;
						}
					}

					if(sama == 1){

						stop = 1;
					}
					else{

						j++;
						k++;
					}

				}
				
				// printf("ngek\n");

			}

			
		}
		else if(strcmp(kode, "E") == 0 && (currentDerajat == 90 || currentDerajat == 270)){

			if(currentKar.korY <= lebar-2 && currentKar.korY >= 0 && currentKar.korX <= panjang && currentKar.korX >= 0){

				while(j <= lebar-1 && stop == 0){


					tempIndex = k;
					system("cls");
					initLayar(lebar, panjang, TITIK);
					//lakukan inisialisasi untuk kodeA
					kodeE90(currentKar, lebar, panjang, TITIK, tempIndex);
					//lakukan penggambaran
					gambar(lebar, panjang, TITIK, kode);
					wait(1);

					sama = 0;
					X = i+1;
					while(X < banyakGerak && sama == 0){

						if(strcmp(KARAKTER[X].namaBentuk, currentKar.namaBentuk) == 0 && KARAKTER[X].korY-1 == j){

							if(KARAKTER[X].derajat == 0 || KARAKTER[X].derajat == 180 || KARAKTER[X].derajat == 360){

								if(KARAKTER[X].korY <= lebar && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang-1 && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
							else if(KARAKTER[X].derajat == 90 || KARAKTER[X].derajat == 270){

								if(KARAKTER[X].korY <= lebar - 1 && KARAKTER[X].korY >= 0 && KARAKTER[X].korX <= panjang && KARAKTER[X].korX >= 0){

									sama = 1;
								}
								else{

									X++;
								}
							}
						}
						else{

							X++;
						}
					}

					if(sama == 1){

						stop = 1;
					}
					else{

						j++;
						k++;
					}

				}

			
			// printf("ngek\n");
			}
			
		}
		else if(strcmp(kode, "F") == 0 && (currentDerajat == 0 || currentDerajat == 90 || currentDerajat == 180 || currentDerajat == 270)){

			if(currentKar.korY <= lebar && currentKar.korY >= 0 && currentKar.korX <= panjang && currentKar.korX >= 0){

				while(j <= lebar && stop == 0){


					tempIndex = k;
					system("cls");
					initLayar(lebar, panjang, TITIK);
					//lakukan inisialisasi untuk kodeA
					kodeF(currentKar, lebar, panjang, TITIK, tempIndex);
					//lakukan penggambaran
					gambar(lebar, panjang, TITIK, kode);
					wait(1);

					sama = 0;
					X = i+1;
					while(X < banyakGerak && sama == 0){

						if(strcmp(KARAKTER[X].namaBentuk, currentKar.namaBentuk) == 0 && KARAKTER[X].korY-1 == j){

							sama = 1;
						}
						else{

							X++;
						}
					}

					if(sama == 1){

						stop = 1;
					}
					else{

						j++;
						k++;
					}

				}

			
			// printf("ngek\n");
			}
			
		}
		// printf("%d\n", i);
	
	
		
		i++;
		currentKar = KARAKTER[i];
		// gambarUlang = lebar - currentKar.korY;
		

		if(stop == 1){

			currentDerajat = currentDerajat + currentKar.derajat;
			
			if(currentDerajat > 360){

				currentDerajat = currentDerajat - 360;
			}			

		}
		else{

			currentDerajat = currentKar.derajat;
		}
		// printf("%d\n", currentDerajat);
		// wait(1);
	}
	
}