#include "header.h"


int main(int argc, char *argv[]) {
	Queue Q;
	Queue A;
	Queue B;
	init(&Q);
	init(&A);
	init(&B);
	int pilihan;
	int nomorOrder;
	
	do{
		system("cls");
		menu();
		scanf("%d", &pilihan);
		
		switch(pilihan){
			case 1:
				system("cls");
				printf("[Terima Pesanan] \n");
				if(isFull(Q)){
					printf("[-] Antrian Pesanan Masuk Sudah Penuh (MAX 5) [-]");
					break;
				}
				printf("Nomor Order: ");
				scanf("%d", &nomorOrder);
				enqueue(&Q, nomorOrder);
				printf("Order %d Ditambahkan ke antrian \n", nomorOrder);
			break;
			case 2:
				system("cls");
				mulaiProsesPesanan(&Q, &A, &B);
			break;
			case 3:
				system("cls");
				cekStatusDapur(A, 'A');
				cekStatusDapur(B, 'B');
			break;
			case 4:
				system("cls");
				statistikPesanan(Q, A, B);
			break;
			case 0:
				printf("I Dewa Putu Adhitya Wiraguna -250713478 - C \n");
			break;
		}
		
		getch();
	}while(pilihan != 0);
	
	return 0;
}
