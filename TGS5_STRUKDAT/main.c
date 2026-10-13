#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	address first;
	init(&first);
	int pilihan;
	
	// -- Models --
	string nama;
	int umur;
	string kategori;
	
	string getName;
	
//	
//	insertFirst(&first, "Joko", 10, "VIP");
//	insertLast(&first, "Budi", 20, "Reguler");
//	
//	mean(first);
//	searchByName(first, "Joko");
//		
//	deleteLast(&first);
//	deleteFirst(&first);
//	
//	printData(first);

	do{
		system("cls");
		menu();
		scanf("%d", &pilihan);
		
		switch(pilihan){
			case 1: 
				system("cls");
				printf("Masukan Nama: ");
				fflush(stdin);
				gets(nama);
				
				if(strlen(nama) == 0){
					printf("[!] Nama Tidak Boleh Kosong [!]\n");
					break;
				}
				
				printf("Masukan Umur: ");
				scanf("%d", &umur);
				
				if(umur < 5){
					printf("[!] Penonton dibawah usia 5 tahun dilarang masuk [!]\n");
					break;
				}
				
				printf("Masukan Kategori: ");
				fflush(stdin);
				gets(kategori);
				
				if(strlen(kategori) == 0){
					printf("[!] Kategori Tidak Boleh Kosong [!]\n");
					break;
				}
				
				if(strcmpi(kategori, "vip") != 0 && strcmpi(kategori, "reguler") != 0){
					printf("[!] Kategori Tiket Yang Tersedia hanya VIP dan reguler [!]\n");
					break;
				}
				
				insertFirst(&first, nama, umur, kategori);
			break;
			case 2:
				system("cls"); 
				printf("Masukan Nama: ");
				fflush(stdin);
				gets(nama);
				
				if(strlen(nama) == 0){
					printf("[!] Nama Tidak Boleh Kosong [!]\n");
					break;
				}
				
				printf("Masukan Umur: ");
				scanf("%d", &umur);
				
				if(umur < 5){
					printf("[!] Penonton dibawah usia 5 tahun dilarang masuk [!]\n");
					break;
				}
				
				printf("Masukan Kategori: ");
				fflush(stdin);
				gets(kategori);
				
				if(strlen(kategori) == 0){
					printf("[!] Kategori Tidak Boleh Kosong [!]\n");
					break;
				}
				
				if(strcmpi(kategori, "vip") != 0 && strcmpi(kategori, "reguler") != 0){
					printf("[!] Kategori Tiket Yang Tersedia hanya VIP dan reguler [!]\n");
					break;
				}
				
				insertLast(&first, nama, umur, kategori);
			break;
			case 3: 
				system("cls");
				deleteFirst(&first);
			break;
			case 4: 
				system("cls");
				deleteLast(&first);
			break;
			case 5: 
				system("cls");
				printData(first);
			break;
			case 6: 
				system("cls");
				mean(first);
			break;
			case 7:
				system("cls");
				printf("Masukan Nama: ");
				fflush(stdin);
				gets(getName);
				
				if(strlen(getName) == 0){
					printf("[!] Nama Tidak Boleh Kosong [!]\n");
					break;
				}
				
				searchByName(first, getName);
			break;
            case 8:
                system("cls");
                hasilPenjualan(first);
            break;
			case 0: 
				system("cls");
				printf("Keluar...\n");
				printf("I Dewa Putu Adhitya Wiraguna 250713478 C \n");
			break;
		}
		
		getch();
	}while(pilihan != 0);
	
	return 0;
}