#include "header.h"

int main()
{
     Reservasi reservasi[baris][kolom];
     initReservasi(reservasi);
     int pilihan;

     do {    
          system("cls");
          menu();
          scanf("%d", &pilihan);

          switch (pilihan) {
          case 1:
               system("cls");
               printf("\t [Input Data Reservasi] \n");
               pesanMejaResto(reservasi);
               break;
          case 2:
               system("cls");
               printf("\t [Print All Reservasi] \n");
               getAll(reservasi);
               break;
          case 3:
               system("cls");
               printf("\t [Print Khusus] \n");
               getDetail(reservasi);
               break;
          case 4:
               system("cls");
               printf("\t [Update Khusus] \n");
               updateReservasi(reservasi);
               break;
          case 5:
               system("cls");
               printf("\t [Batalkan Reservasi] \n");
               batalkanReservasi(reservasi);
               break;
          case 0:
               printf("[!] Keluar Dari Program [!] \n");
               printf("I Dewa Putu Adhiya Wiraguna | C | 250713478 \n");
               break;
          }
          
          getch();
     } while (pilihan != 0);

     return 0;
}