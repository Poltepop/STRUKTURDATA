#include "header.h"

int main(){
    Chart *chart = NULL ;
    int maxSize;
    int pilihan;

    getMaxSize(&maxSize);

    chart = alokasi(maxSize);

    if(chart == NULL){
        printf("[!] Gagal Mengalokasikan Data Chart [!] \n");
        printf("[!] Menghentikan Program [!] \n");
        return 0;
    } 

    if(maxSize < 1){
        printf("[!] Jumlah Maksimal Tidak Boleh Kurang 1 [!] \n");
        printf("[I Dewa Putu Adhitya Wiraguna - 250713478 - C] \n");
        return 0;
    }

    init(chart, maxSize); 

    do {
        system("cls");
        printf("\t [ATYA CHART RECORD] \n");
        cariMaxMin(chart, maxSize);
        menu();
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                system("cls");
                insertData(chart, maxSize);
                break;
            case 2:
                system("cls");
                getAll(chart, maxSize);
                break;
            case 3:
                system("cls");
                updateData(chart, maxSize);
                break;
            case 4:
                system("cls");
                deleteData(chart, maxSize);
                break;
            case 5:
                system("cls");
                cariChart(chart, maxSize);
                break;
            case 6:
                system("cls");
                mean(chart, maxSize);
                break;
            case 0:
                system("cls");
                printf("[I Dewa Putu Adhitya Wiraguna - 250713478 - C] \n");
                break;
            default:
                system("cls");
                printf("[!] Pilihan tidak valid! [!]\n");
        }
        
        getch();
    } while(pilihan != 0);

    free(chart);
    return 0;
}