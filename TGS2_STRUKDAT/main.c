#include "header.h"

int main(){
    Hanoi hanoi[MAX];
    init(hanoi); 
    int langkah = 0;
    // towerHanoi(hanoi);
    int pilihan;

    do{
        system("cls");
        menu();
        scanf("%d", &pilihan);
        switch(pilihan){
            case 1:
                langkah = 0;
                init(hanoi);
                towerHanoi(hanoi, &langkah);
            break;
            case 2:
                TampilkanJumlahLangkah(langkah);
            break;
            case 0:
                printf("\t[~] Keluar dari program...\n");
                printf("\t[~] I Dewa Putu Adhitya Wiraguna - 250713478 - C \n");
            break;
        }
        getch();
    }while(pilihan != 0);

    return 0;
}