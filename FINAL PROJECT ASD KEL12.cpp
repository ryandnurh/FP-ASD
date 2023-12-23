#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdint.h>
using namespace std;

//MENETAPKAN JUMLAH ARRAY
const int arr = 10;
const int n = 6;
int jml[3][6], jml1=-1, jml2 =-1, jml3 =-1, pil1[3][6], jml4[3][arr], jml5=-1, jml6=-1, jml7=-1;
int mak=4, minn=5, des=4;
uint64_t total = 0;

//MENGELOMPOKKAN DATA
struct toko {

	string m_makanan [5] = {"Nasi Goreng\t", "Nasi Telur Balado", "Nasi Telur Geprek", "Nasi Ayam Geprek", "Nasi Orak arik"}
	                       ,	   m_minuman [6] = {"Jeruk Panas/es", "Teh Panas/es\t", "Kopi Panas/es\t", "Lemon Tea\t", "Susu Jahe\t", "Susu kental manis"}
	                       ,	   m_dessert [5] = {"ice cream\t","puding\t","dawet\t\t","tiramisu cake\t","donat\t\t"}
	                       , makan[n], minum[n], dessert[n], m_makanan_1[arr], m_minuman_1[arr], m_dessert_1[arr];
	int hargamakan [5] = {10000, 9000, 9000, 11000, 10000}
	                     ,   hargaminum [6] = {3500, 3500, 4000, 4000, 4000, 3500}
	                     , hargadessert [5] = {8000, 5000, 4000, 8000, 3000}
	                     , hargamakan_1[arr], hargaminum_1[arr], hargadessert_1[arr]
	                     , ttlmakan, ttlminum, ttldessert, hrgpesanmak[n], hrgpesanmin[n], hrgpesandes[n];

} menu, pesanan, riwayat;

//FUNGSI UTAMA
void garis () {
	cout << "\n			-------------------------------------------------------------------------\n";
}

void garis2() {
	cout << "\n			=========================================================================\n";
}

//FUNGSI LOGIN DAN DAFTAR
//FUNGSI DAFTAR
void daftar () {
    string username, password;
	system("cls");
	garis();
	cout << "			|			 	Buat Akun				|";
	garis();
    cout<< "			 Username	: ";
    cin >> username;
    cout<< "			 Password	: ";
    cin >> password;

    ofstream file(username + ".txt");
    file << username << endl << password;
    file.close();
}
//FUNGSI LOGIN
bool login (string username, string password) {
    string un, pw;
    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);
    if (un == username && pw == password) {
        return true;
    } else {
        return false;
    }
}

//FUNGSI UNTUK MENAMBAHKAN MENU
void tambahmenu () {

	int chs;
	
	do{
	
		system("cls");
		garis();
		cout << "			|			 	Tambah Menu				|";
		garis();
		cout << "			|		~~~~~Silahkan Pilih Menu Yang akan ditambahkan~~~~~	|"<<endl;
		cout << "			|	1.Makanan							|"<<endl;
		cout << "			| 	2.Minuman							|"<<endl;
		cout << "			| 	3.Dessert							|"<<endl;
		cout << "			| 	0 Untuk Kembali							|";
		garis();
		cout << "			Pilih	:	";
		cin >> chs;
	
		switch (chs) {
			case 1 :
				system("cls");
				garis();
				cout << "			| 			~~~Tambah Menu Makan~~~			|";
				garis();
				mak++;
				cin.sync();
				cout << "				 Nama Makanan	: ";
				getline(cin,menu.m_makanan_1[mak]);
				cout << "				 Harga Makanan	: ";
				cin >> menu.hargamakan_1[mak];
				system("cls");
				cout << "\n		|		.:.	Berhasil Menambahkan Menu	.:.		|";
				getch();
				break;
	
			case 2 :
				system("cls");
				garis();
				cout << "			|			~~~Tambah Menu Minum~~~			|";
				garis();
				minn++;
				cin.sync();
				cout << "			 	Nama Minuman : ";
				getline(cin,menu.m_minuman_1[minn]);
				cout << "			 	Harga Minuman : ";
				cin >> menu.hargaminum_1[minn];
				system("cls");
				cout << "\n			|		.:.	Berhasil Menambahkan Menu	.:.		|";
				getch();
				break;
	
			case 3 :
				system("cls");
				garis();
				cout << "			|			~~~Tambah Menu Dessert~~~			|";
				garis();
				des++;
				cin.sync();
				cout << "				Nama Dessert : ";
				getline(cin,menu.m_dessert_1[des]);
				cout << "				Harga Dessert : ";
				cin >> menu.hargadessert_1[des];
				system("cls");
				cout << "\n			|	.:.	Berhasil Menambahkan Menu	.:.	";
				getch();
				break;
		}
	}while ( chs != 0);
}

//FUNGSI UNTUK MENAMPILKAN MENU
//MENU MALAM
void menumakan () {
	garis();
	cout << "			|				Menu Makanan				|";
	garis();
	cout << endl;
	for (int i = 0 ; i < 5 ; i++) {
		
		cout <<"			|	"<< i+1 << ". " << menu.m_makanan[i]
		     << "\t"<< menu.hargamakan[i]<<"\t				|" << endl;

	}

	if (mak>4) {

		for (int a = 5; a <= mak; a++) {

			cout <<"			|	"<< a+1 << ". " << menu.m_makanan_1[a]
			     << "		"<< menu.hargamakan_1[a]<<"		\t		|" << endl;

		}
	}
}
//MENU MINUM
void menuminum () {

	garis();
	cout << "			|				Menu Minuman				|";
	garis();
	cout << endl;
	for (int i = 0 ; i < 6 ; i++) {

		cout <<"			|	"<< i+1 << "." << menu.m_minuman[i]
		     << "\t"<< menu.hargaminum[i] <<"	\t			|" << endl;

	}

	if (minn>5) {

		for (int a = 6; a <= minn; a++) {

			cout <<"			|	"<< a+1 << "." << menu.m_minuman_1[a]
			     << "		"<< menu.hargaminum_1[a] <<"\t				|" << endl;

		}
	}
}
//MENU DESSERT
void menudessert () {

	garis();
	cout << "			|				Menu Dessert				|";
	garis();
	cout << endl;
	for (int i=0; i< 5 ; i++) {

		cout<<"			|	"<< i + 1 << "." <<menu.m_dessert[i]
		    << "\t"<<menu.hargadessert[i] << "		\t		|" <<endl;
	}

	if (des>4) {

		for (int a = 5; a <= des; a++) {

			cout <<"			|	"<< a+1 << "." << menu.m_dessert_1[a]
			     << "		" << menu.hargadessert_1[a] <<"				|" << endl;

		}
	}
}

//FUNGSI UNTUK UBAH MENU
void updateharga (){
	int pilih2, pilih, baru;
	string cari;
	
	do{
		system("cls");
		garis();
		cout << "			-	==========>> SELAMAT DATANG DI CAFE UDIN <<==========		-";
		garis();
		cout << "			| 		Silahkan Pilih Menu Yang Akan Di Ubah : 		|"<<endl;
		cout << "			| 1. Makan								|"<<endl;
		cout << "			| 2. Minum								|"<<endl;
		cout << "			| 3. Dessert								|"<<endl;
		cout << "			| 0 Untuk Kembali							|";
		garis();
		cout << "			Pilih menu : ";
		cin >> pilih;
		
		switch(pilih){
			case 1 :
				system("cls");
				garis();
				cin.sync();
				cout << "\t\t\tMasukkan Nama Makanan yang akan di update : "; getline(cin,cari);
				
				if (mak > 4){
					system("cls");
					for (int i=0; i<= mak; i++){
						if (cari==menu.m_makanan_1[i]){
							system("cls");
							garis();
							cout <<"			|	"<< menu.m_makanan_1[i]
							     << "			" << menu.hargamakan_1[i] <<"				|";
							garis();
							cout << "\t\t\t\t\tHarga Baru : "; cin >> baru;
							menu.hargamakan_1[i] = baru;
						}
					}
				} else {
					system("cls");
					for (int i=0; i<= arr; i++){
						if (cari==menu.m_makanan[i]){
							system("cls");
							garis();
							cout <<"			|	"<< menu.m_makanan[i]
							     << "			" << menu.hargamakan[i] <<"				|";
							garis();
							cout << "\t\t\t\t\tHarga Baru : "; cin >> baru;
							menu.hargamakan[i] = baru;
						}
					}
				}
				
				system("cls");
				cout << "\t\t\t\t\t===Harga Berhasil di update===";
				getch();
				break;
				
			case 2 :
				system("cls");
				menuminum();
				garis();
				cout << "\t\tPilih Harga yang akan di update"; cin >> pilih2;
				
				if (pilih2 > 6){
					system("cls");
					garis();
					cout <<"			|	"<< menu.m_minuman_1[pilih2-1]
					     << "			" << menu.hargaminum_1[pilih2-1] <<"				|";
					garis();
					cout << "\t\t\t\t\tHarga Baru : "; cin >> baru;
					
					menu.hargaminum_1[pilih2-1] = baru;
					
				} else {
					system("cls");
					garis();
					cout <<"			|	"<< menu.m_minuman[pilih2-1]
					     << "			" << menu.hargaminum[pilih2-1] <<"				|";
					garis();
					cout << "\t\t\t\t\tHarga Baru : "; cin >> baru;
					
					menu.hargaminum[pilih2-1] = baru;
				}
				
				system("cls");
				cout << "\t\t\t\t\t===Harga Berhasil di update===";
				getch();
				break;
				
			case 3 :
				system("cls");
				menudessert();
				garis();
				cout << "\t\tPilih Harga yang akan di update"; cin >> pilih2;
				
				if (pilih2 > 5){
					system("cls");
					garis();
					cout <<"			|	"<< menu.m_dessert_1[pilih2-1]
					     << "			" << menu.hargadessert_1[pilih2-1] <<"				|";
					garis();
					cout << "\t\t\t\t\tHarga Baru : "; cin >> baru;
					
					menu.hargadessert_1[pilih2-1] = baru;
					
				} else {
					system("cls");
					garis();
					cout <<"			|	"<< menu.m_dessert[pilih2-1]
					     << "			" << menu.hargadessert[pilih2-1] <<"				|";
					garis();
					cout << "\t\t\t\t\tHarga Baru : "; cin >> baru;
					
					menu.hargadessert[pilih2-1] = baru;
				}
				
				system("cls");
				cout << "\t\t\t\t\t===Harga Berhasil di update===";
				getch();
				break;
		}
	} while (pilih != 0);
}

//FUNGSI PENJUALAN
void jual (int pil, int a, int b, int c) {

	char lagi;
	switch (pil) {
		case 1 :

			if (a<6) {

				do {
					jml1++;
					a++;
					system("cls");
					menumakan();
					garis();
					cout << "			Silahkan Pilih Makanan : ";
					cin >> pil1[0][a];
					cout << "			Jumlah Pesanan : ";
					cin >> jml[0][a];

					if (pil1[0][a] > 5) {

						for (int f = 0; f <= mak; f++) {

							if (menu.m_makanan_1[pil1[0][a]-1] == pesanan.makan[f]) {

								jml[0][f] += jml [0][a];
								pesanan.hrgpesanmak[f] += (menu.hargamakan_1[pil1[0][a]-1] * jml [0][a]);
								pesanan.ttlmakan += (menu.hargamakan_1[pil1[0][a]-1] * jml[0][a]);

								for (int g = 0; g <= jml5; g++) {
									if (menu.m_makanan_1[pil1[0][a]-1] == riwayat.makan[g]) {

										jml4[0][g] += jml [0][a];
										goto hsl1;

									}
								}

								jml5++;
								jml4[0][jml5] = jml [0][a];
								riwayat.makan[jml5] = menu.m_makanan_1[pil1[0][a]-1];
								
								hsl1:
								a--;
								jml1--;
								goto hsl3;

							}
						}
						pesanan.hrgpesanmak[a] = (menu.hargamakan_1[pil1[0][a]-1] * jml [0][a]);
						pesanan.ttlmakan += (menu.hargamakan_1[pil1[0][a]-1] * jml[0][a]);
						pesanan.makan[a] = menu.m_makanan_1[pil1[0][a]-1];

						for (int g = 0; g <= jml5; g++) {
							if (menu.m_makanan_1[pil1[0][a]-1] == riwayat.makan[g]) {

								jml4[0][g] += jml [0][a];
								goto hsl3;

							}
						}
						jml5++;
						jml4[0][jml5] = jml [0][a];
						riwayat.makan[jml5] = menu.m_makanan_1[pil1[0][a]-1];

					} else {

						for (int f = 0; f <= mak; f++) {

							if (menu.m_makanan[pil1[0][a]-1] == pesanan.makan[f]) {

								jml[0][f] += jml [0][a];
								pesanan.hrgpesanmak[f] += (menu.hargamakan[pil1[0][a]-1] * jml [0][a]);
								pesanan.ttlmakan += (menu.hargamakan[pil1[0][a]-1] * jml[0][a]);

								for (int g = 0; g <= jml5; g++) {
									if (menu.m_makanan[pil1[0][a]-1] == riwayat.makan[g]) {

										jml4[0][g] += jml [0][a];
										goto hsl2;

									}
								}

								jml5++;
								jml4[0][jml5] = jml [0][a];
								riwayat.makan[jml5] = menu.m_makanan[pil1[0][a]-1];
								
								hsl2:
								a--;
								jml1--;
								goto hsl3;

							}
						}
						pesanan.hrgpesanmak[a] = (menu.hargamakan[pil1[0][a]-1] * jml [0][a]);
						pesanan.ttlmakan += (menu.hargamakan[pil1[0][a]-1] * jml[0][a]);
						pesanan.makan[a] = menu.m_makanan[pil1[0][a]-1];

						for (int g = 0; g <= jml5; g++) {
							if (menu.m_makanan[pil1[0][a]-1] == riwayat.makan[g]) {

								jml4[0][g] += jml [0][a];
								goto hsl3;

							}
						}
						jml5++;
						jml4[0][jml5] = jml [0][a];
						riwayat.makan[jml5] = menu.m_makanan[pil1[0][a]-1];

					}
					
					hsl3:
					cout << "			Apakah ingin memesan makanan lagi? (y/t)";
					lagi=getch();

				} while (lagi=='y' && a<6);

			} else {
				cout << "			Maaf Pesanan Melebihi batas";
				getch();
				system("cls");
			}
			break;

		case 2 :

			if (b<6) {

				do {
					jml2++;
					b++;
					system("cls");
					menuminum();
					garis();
					cout << "			Silahkan Pilih Minuman : ";
					cin >> pil1[1][b];
					cout << "			Jumlah Pesanan : ";
					cin >> jml[1][b];

					if (pil1[1][b]>6) {

						for (int f = 0; f <= minn; f++) {

							if (menu.m_minuman_1[pil1[1][b]-1] == pesanan.minum[f]) {

								jml[1][f] += jml [1][b];
								pesanan.hrgpesanmin[f] += (menu.hargaminum_1[pil1[1][b]-1] * jml [1][b]);
								pesanan.ttlminum += (menu.hargaminum_1[pil1[1][b]-1] * jml[1][b]);

								for (int g = 0; g <= jml6; g++) {
									if (menu.m_minuman_1[pil1[1][b]-1] == riwayat.minum[g]) {

										jml4[1][g] += jml [1][b];
										goto hsl4;

									}
								}

								jml6++;
								jml4[1][jml6] = jml [1][b];
								riwayat.minum[jml6] = menu.m_minuman_1[pil1[1][b]-1];
								
								hsl4:
								b--;
								jml2--;
								goto hsl6;

							}
						}
						pesanan.hrgpesanmin[b] = (menu.hargaminum_1[pil1[1][b]-1] * jml [1][b]);
						pesanan.ttlminum += (menu.hargaminum_1[pil1[1][b]-1] * jml[1][b]);
						pesanan.minum[b] = menu.m_minuman_1[pil1[1][b]-1];

						for (int g = 0; g <= jml6; g++) {
							if (menu.m_minuman_1[pil1[1][b]-1] == riwayat.minum[g]) {

								jml4[1][g] += jml [1][b];
								goto hsl6;

							}
						}
						jml6++;
						jml4[1][jml6] = jml [1][b];
						riwayat.minum[jml6] = menu.m_minuman_1[pil1[1][b]-1];

					} else {

						for (int f = 0; f <= minn; f++) {

							if (menu.m_minuman[pil1[1][b]-1] == pesanan.minum[f]) {

								jml[1][f] += jml [1][b];
								pesanan.hrgpesanmin[f] += (menu.hargaminum[pil1[1][b]-1] * jml [1][b]);
								pesanan.ttlminum += (menu.hargaminum[pil1[1][b]-1] * jml[1][b]);

								for (int g = 0; g <= jml6; g++) {
									if (menu.m_minuman[pil1[1][b]-1] == riwayat.minum[g]) {

										jml4[1][g] += jml [1][b];
										goto hsl5;

									}
								}

								jml6++;
								jml4[1][jml6] = jml [1][b];
								riwayat.minum[jml6] = menu.m_minuman[pil1[1][b]-1];
								
								hsl5:
								b--;
								jml2--;
								goto hsl6;

							}
						}
						pesanan.hrgpesanmin[b] = (menu.hargaminum[pil1[1][b]-1] * jml [1][b]);
						pesanan.ttlminum += (menu.hargaminum[pil1[1][b]-1] * jml[1][b]);
						pesanan.minum[b] = menu.m_minuman[pil1[1][b]-1];

						for (int g = 0; g <= jml6; g++) {
							if (menu.m_minuman[pil1[1][b]-1] == riwayat.minum[g]) {

								jml4[1][g] += jml [1][b];
								goto hsl6;

							}
						}
						jml6++;
						jml4[1][jml6] = jml [1][b];
						riwayat.minum[jml6] = menu.m_minuman[pil1[1][b]-1];
					}
					
					hsl6:
					cout << "			Apakah ingin memesan minuman lagi? (y/t)";
					lagi=getch();

				} while (lagi=='y' && b<6);
			} else {
				cout << "			Maaf Pesanan Melebihi batas";
				getch();
				system("cls");
			}
			break;

		case 3 :

			if (c<6) {

				do {
					jml3++;
					c++;
					system("cls");
					menudessert();
					garis();
					cout << "			Silahkan Pilih Dessert : ";
					cin >> pil1[2][c];
					cout << "			Jumlah Pesanan : ";
					cin >> jml[2][c];

					if (pil1[2][c] > 5) {

						for (int f = 0; f <= des; f++) {

							if (menu.m_dessert_1[pil1[2][c]-1] == pesanan.dessert[f]) {

								jml[2][f] += jml [2][c];
								pesanan.hrgpesandes[f] += (menu.hargadessert_1[pil1[2][c]-1] * jml [2][c]);
								pesanan.ttldessert += (menu.hargadessert_1[pil1[2][c]-1] * jml[2][c]);

								for (int g = 0; g <= jml7; g++) {
									if (menu.m_dessert_1[pil1[2][c]-1] == riwayat.dessert[g]) {

										jml4[2][g] += jml [2][c];
										goto hsl7;

									}
								}

								jml7++;
								jml4[2][jml7] = jml [2][c];
								riwayat.dessert[jml7] = menu.m_dessert_1[pil1[2][c]-1];
								
								hsl7:
								c--;
								jml3--;
								goto hsl9;

							}
						}
						pesanan.hrgpesandes[c] = (menu.hargadessert_1[pil1[2][c]-1] * jml [2][c]);
						pesanan.ttldessert += (menu.hargadessert_1[pil1[2][c]-1] * jml[2][c]);
						pesanan.dessert[c] = menu.m_dessert_1[pil1[2][c]-1];

						for (int g = 0; g <= jml7; g++) {
							if (menu.m_dessert_1[pil1[2][c]-1] == riwayat.dessert[g]) {

								jml4[2][g] += jml [2][c];
								goto hsl9;

							}
						}
						jml7++;
						jml4[2][jml7] = jml [2][c];
						riwayat.dessert[jml7] = menu.m_dessert_1[pil1[2][c]-1];

					} else {

						for (int f = 0; f <= des; f++) {

							if (menu.m_dessert[pil1[2][c]-1] == pesanan.dessert[f]) {

								jml[2][f] += jml [2][c];
								pesanan.hrgpesandes[f] += (menu.hargadessert[pil1[2][c]-1] * jml [2][c]);
								pesanan.ttldessert += (menu.hargadessert[pil1[2][c]-1] * jml[2][c]);

								for (int g = 0; g <= jml7; g++) {
									if (menu.m_dessert[pil1[2][c]-1] == riwayat.dessert[g]) {

										jml4[2][g] += jml [2][c];
										goto hsl8;

									}
								}

								jml7++;
								jml4[2][jml7] = jml [2][c];
								riwayat.dessert[jml7] = menu.m_dessert[pil1[2][c]-1];
								
								hsl8:
								c--;
								jml3--;
								goto hsl9;

							}
						}
						pesanan.hrgpesandes[c] = (menu.hargadessert[pil1[2][c]-1] * jml [2][c]);
						pesanan.ttldessert += (menu.hargadessert[pil1[2][c]-1] * jml[2][c]);
						pesanan.dessert[c] = menu.m_dessert[pil1[2][c]-1];

						for (int g = 0; g <= jml7; g++) {
							if (menu.m_dessert[pil1[2][c]-1] == riwayat.dessert[g]) {

								jml4[2][g] += jml [2][c];
								goto hsl9;

							}
						}
						jml7++;
						jml4[2][jml7] = jml [2][c];
						riwayat.dessert[jml7] = menu.m_dessert[pil1[2][c]-1];
					}
					
					hsl9:
					cout << "			Apakah ingin memesan dessert lagi? (y/t)";
					lagi=getch();

				} while (lagi=='y' && c<6);
			} else {
				cout << "			Maaf Pesanan Melebihi batas";
				getch();
				system("cls");
			}

			break;

		default :
			cout << "			Maaf Pesanan Melebihi batas";
			getch();
			system("cls");
			break;
	}
}

//FUNGSI UNTUK MENCETAK STRUK
void struk () {

	int kembalian = 0, uang = 0, tambah = 0;

	garis2();
	cout << "			|		TERIMAKASIH TELAH BERBELANJA DI CAFE UDIN		|";
	garis2();
	if ( jml1 >= 0) {

		for ( int a = 0 ; a<=jml1 ; a++ ) {
			cout <<"			|	"<< pesanan.makan[a] << "\t" << jml[0][a] << " 	: " << pesanan.hrgpesanmak[a] << endl;
			pesanan.makan[a]=pesanan.makan[a+1];
			pesanan.hrgpesanmak[a]=0;
		}
		total += pesanan.ttlmakan;
		pesanan.ttlmakan=0;
		jml1=-1;
	}

	if ( jml2 >= 0) {

		for ( int b = 0 ; b<=jml2 ; b++ ) {
			cout <<"			|	"<< pesanan.minum[b] << "\t"<< jml[1][b] << "	: " << pesanan.hrgpesanmin[b] << endl;
			pesanan.minum[b]=pesanan.minum[b+1];
			pesanan.hrgpesanmin[b]=0;
		}
		total += pesanan.ttlminum;
		pesanan.ttlminum=0;
		jml2=-1;
	}

	if ( jml3 >= 0) {

		for ( int c = 0 ; c<=jml3 ; c++ ) {
			cout <<"			|	"<< pesanan.dessert[c] << "\t"<< jml[2][c] << " 	: " << pesanan.hrgpesandes[c] << endl;
			pesanan.dessert[c]=pesanan.dessert[c+1];
			pesanan.hrgpesandes[c]=0;
		}
		total += pesanan.ttldessert;
		pesanan.ttldessert=0;
		jml3=-1;
	}

	garis();
	cout << "				Total			: " << total << endl;
	cout << "				Uang Konsumen		: ";
	cin >> uang;
	kembalian = uang-total;
	while (kembalian < 0){
		cout << "				Maaf Uang anda kurang " << kembalian 
		<< "\n				Silahkan tambah uang anda		: "; cin >> tambah;
		kembalian += tambah;
	}
	garis();
	cout << "				Kembalian		: " << kembalian;
	total = 0;
	getch();
}

//METODE BUBBLE SORT DESCENDING
void penjualan_terbanyak () {
	int temp1;
	string temp2;

	for (int a = 0; a <= jml5; a++) {
		for (int j = 0; j<= jml5; j++) {
			if (jml4[0][j] < jml4[0][j+1]) {

				temp2 = riwayat.makan[j];
				temp1 = jml4[0][j];
				riwayat.makan[j] = riwayat.makan[j+1];
				jml4[0][j] = jml4[0][j+1];
				riwayat.makan[j+1] = temp2;
				jml4[0][j+1] = temp1;
			}
		}
	}
	for (int b = 1; b <= jml6; b++) {
		for (int k = 0; k<= jml6; k++) {
			if (jml4[1][k] < jml4[1][k+1]) {

				temp2 = riwayat.minum[k];
				temp1 = jml4[1][k];
				riwayat.minum[k] = riwayat.minum[k+1];
				jml4[1][k] = jml4[1][k+1];
				riwayat.minum[k+1] = temp2;
				jml4[1][k+1] = temp1;
			}
		}
	}

	for (int c = 1; c <= jml7; c++) {
		for (int p = 0; p<= jml7; p++) {
			if (jml4[2][p] < jml4[2][p+1]) {

				temp2 = riwayat.dessert[p];
				temp1 = jml4[2][p];
				riwayat.dessert[p] = riwayat.dessert[p+1];
				jml4[2][p] = jml4[2][p+1];
				riwayat.dessert[p+1] = temp2;
				jml4[2][p+1] = temp1;
			}
		}
	}

}

//MEBAMPILKAN RIWAYAT PENJUALAN
void tampilkan_riwayat () {

	if (jml5 >= 0) {
		garis();
		cout << "			-		Riwayat Jual Makanan  |  Jumlah				-";
		garis();
		for ( int q=0; q<=jml5; q++) {
			cout << "			|	" << riwayat.makan[q] << "	"<< jml4[0][q] << endl;
		}
	}

	if (jml6 > -1) {
		garis();
		cout << "			-		Riwayat Jual Minuman  |  Jumlah				-";
		garis();
		for ( int r=0; r<=jml6; r++) {
			cout << "			|	" << riwayat.minum[r] << "	"<< jml4[1][r] << endl;
		}
	}

	if (jml7 > -1) {
		garis();
		cout << "			-		Riwayat Jual Dessert  |  Jumlah				-";
		garis();
		for ( int s=0; s<=jml7; s++) {
			cout << "			|	" << riwayat.dessert[s] << "	"<< jml4[2][s] << endl;
		}
	}
}

int main () {

	system("color f0");
	string nama;
	int pil2, pil3, pil4, pil5;
	
	do{
		system("cls");
		garis();
		cout << "			-	==========>> SELAMAT DATANG DI CAFE UDIN <<==========		-";
		garis();
		cout << "			|			Silahkan Pilih Menu				|"<<endl;
		cout << "			| 1. Login								|"<<endl;
		cout << "			| 2. Daftar								|"<<endl;
		cout << "			| 0  Keluar								|";
		garis();
		cout<< "			 Pilih	: ";
	    cin >> pil5;
	
	    if (pil5 == 1) {
	        string username, password;
			system("cls");
			garis();
			cout << "			|			 	LOGIN					|";
			garis();
	    	cout<< "			 Username	: ";
	        cin >> username;
	        cout<< "			 Password	: ";
	        char pw;
	        password = "";
	        nama=username;
	        while(true){
	            pw = _getch();
	            if(pw == 13) // Jika tombol Enter ditekan
	                break;
	            else if(pw == 8){ // Jika tombol Backspace ditekan
	                if(password.length() > 0){
	                	
	                    cout << "\b \b"; // Menghapus satu karakter dari layar
	                    password.erase(password.length() - 1); // Menghapus satu karakter dari password
	                }
	            }
	            else{
	                password += pw;
	                cout << '*'; // Menampilkan bintang sebagai ganti karakter yang dimasukkan
	            }
	        }
	        if (login(username, password)) {
	        	system("cls");
				cout << endl;
				cout << "					~~~~~ BERHASIL LOGIN	~~~~~";
				getch();
				
				do {
					system("cls");
					garis();
					cout << "			-	==========>> SELAMAT DATANG " << nama << " DI CAFE UDIN <<==========		-";
					garis();
					cout << "			|			Silahkan Pilih Masuk Sebagai			|"<<endl;
					cout << "			| 1. Admin								|"<<endl;
					cout << "			| 2. Kasir								|"<<endl;
					cout << "			| 0 Untuk Keluar							|";
					garis();
					cout << "			 Pilih	: ";
					cin >>pil2;
			
					switch (pil2) {
			
						case 1 :
			
							do {
								system("cls");
								garis();
								cout << "			-	==========>> SELAMAT DATANG DI CAFE UDIN <<==========		-";
								garis();
								cout << "			| Silahkan Pilih Menu : 						|"<<endl;
								cout << "			| 1. Tampilkan Semua Menu						|"<<endl;
								cout << "			| 2. Tambah Menu							|"<<endl;
								cout << "			| 3. Update Harga Menu							|"<<endl;
								cout << "			| 4. Rekapan Penjualan							|"<<endl;
								cout << "			| 0 Untuk Kembali							|";
								garis();
								cout << "			Pilih menu : ";
								cin >> pil3;
			
								switch (pil3) {
									case 1 :
										system("cls");
										menumakan();
										cout << endl;
										menuminum();
										cout << endl;
										menudessert();
										getch();
										break;
			
									case 2 :
										tambahmenu();
										break;
										
									case 3 :
										updateharga();
										break;
			
									case 4 :
										system("cls");
										penjualan_terbanyak();
										tampilkan_riwayat();
										getch();
										break;
								}
							} while (pil3 != 0);
			
							break;
			
						case 2 :
			
							do {
								system("cls");
								garis();
								cout << "			-	==========>> SELAMAT DATANG DI CAFE UDIN <<========== 	-";
								garis();
								cout << "			| 			Silahkan Pilih Menu : 				|"<<endl;
								cout << "			| 1. Makan								|"<<endl;
								cout << "			| 2. Minum								|"<<endl;
								cout << "			| 3. Dessert								|"<<endl;
								cout << "			| 4. Cetak Struk Pesanan						|"<<endl;
								cout << "			| 0 Untuk Kembali							|";
								garis();
								cout << "			Pilih menu : ";
								cin >> pil4;
			
								switch (pil4) {
									case 1 :
			
										jual(1,jml1,0,0);
										cout << endl;
										break;
			
									case 2 :
			
										jual(2,0,jml2,0);
										cout << endl;
										break;
			
									case 3 :
			
										jual(3,0,0,jml3);
										cout << endl;
										break;
			
			
									case 4 :
										system("cls");
										struk();
										break;
								}
			
							} while ( pil4 != 0);
			
							break;
					}
			
				} while (pil2 !=0 );
	
	        } else {
	        	system("cls");
				cout << endl;
				cout << "				~~~~~ Maaf Username atau Password Yang Anda Masukkan Salah	~~~~~";
				getch();
	        }
	    } else if (pil5 == 2) {
	        daftar();
			cout << endl;
			cout << "					~~~~~ BERHASIL DAFTAR	~~~~~";
			getch();
			
	    }
	    
    } while (pil5 != 0);
		system("cls");
		cout << endl;
		cout << "					~~~~~TERIMAKASIH TELAH MENGGUNAKAN PROGRAM KAMI :)	~~~~~";
		getch();
}
