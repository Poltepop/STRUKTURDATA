#include "header.h"

void menu(){
    printf("\t [Tugas Tower Hanoi]\n");
    printf("[1] Tower hanoi \n");
    printf("[2] Tampilkan Jumlah Langkah \n");
    printf("[0] Exit \n");
    printf(">>>");
}

void init(Hanoi stack[]){
    stack[0].top = MAX - 1;
    stack[1].top = -1;
    stack[2].top = -1;
    stack[0].items[0] = 3;
    stack[0].items[1] = 2;
    stack[0].items[2] = 1;

    stack[1].items[0] = 0;
    stack[1].items[1] = 0;
    stack[1].items[2] = 0;

    stack[2].items[0] = 0;
    stack[2].items[1] = 0;
    stack[2].items[2] = 0;
}


bool isEmpty(Hanoi stack[], int indexTower){
    return stack[indexTower].top == -1; 
}

bool isFull(Hanoi stack[], int indexTower){
    return stack[indexTower].top == MAX - 1;
}

void push(Hanoi stack[], int indexTower, int value){
    if(isFull(stack, indexTower)){
        printf("[!] MENARA FULL [!]\n");
        return;
    }

    stack[indexTower].top++;
    stack[indexTower].items[stack[indexTower].top] = value;
}

void pop(Hanoi stack[], int indexTower){
    if(isEmpty(stack, indexTower)){
        printf("[!] MENARA KOSONG [!]\n");
        return;
    }

    stack[indexTower].items[stack[indexTower].top] = 0;
    stack[indexTower].top--;
}

void read(Hanoi stack[], int indexTower){
    printf("Current Potition: %d - %d\n", stack[indexTower].items[stack[indexTower].top], stack[indexTower].top);
}

void readTower(Hanoi stack[], int langkah){
    int i;

    printf("\t | a |   | b |   | c |\n\n");

    for(i = MAX - 1; i >= 0; i--){
        printf("\t | %d |   | %d |   | %d |\n", stack[0].items[i], stack[1].items[i], stack[2].items[i]);
    }

    printf("\t [Steps: %d]\n", langkah);
    printf("\t [*] Input 'd' Untuk Keluar [*] \n");
}

void towerHanoi(Hanoi stack[], int *langkah){
    system("cls");
    readTower(stack, *langkah);
    char pilihanAsal;
    char pilihanTujuan;
    int indexTowerAsal;
    int indexTowerTujuan;

    do{
        printf("Masukan Tower Asal (a/b/c): ");
        scanf(" %c", &pilihanAsal);
        
        if (pilihanAsal == 'a') {
            indexTowerAsal = 0;
            break;
        } else if (pilihanAsal == 'b') {
            indexTowerAsal = 1;
            break;
        } else if (pilihanAsal == 'c') {
            indexTowerAsal = 2;
            break;
        } else if (pilihanAsal == 'd') {
            printf("[+] Keluar dari Tower Hanoi...\n");
            break;
        } else {
            printf("[!] TIDAK VALID [!] \n");
        }
    }while(pilihanAsal != 'd');

    if (pilihanAsal == 'd') return; 

    do{
        printf("Masukan Tower Tujuan (a/b/c): ");
        scanf(" %c", &pilihanTujuan);
        
        if (pilihanTujuan == 'a') {
            indexTowerTujuan = 0;
            break;
        } else if (pilihanTujuan == 'b') {
            indexTowerTujuan = 1;
            break;
        } else if (pilihanTujuan == 'c') {
            indexTowerTujuan = 2;
            break;
        } else if (pilihanTujuan == 'd') {
            printf("[+] Keluar dari Tower Hanoi...\n");
            break;
        } else {
            printf("[!] TIDAK VALID [!] \n");
        }
    }while(pilihanTujuan != 'd');

    if (pilihanTujuan == 'd') return; 

    if(pilihanAsal == pilihanTujuan){
        printf("[!] TIDAK VALID [!]\n");
        getch();
        towerHanoi(stack, langkah);
        return;
    }

    if (isEmpty(stack, indexTowerAsal)) {
        printf("[!] Tower %c Kosong[!]\n", pilihanAsal);
        getch();
        towerHanoi(stack, langkah);
        return;
    }
    
    if (!isEmpty(stack, indexTowerTujuan)) {
        // printf("%d\n", stack[indexTowerTujuan].items[stack[indexTowerTujuan].top]);
        
        if(stack[indexTowerAsal].items[stack[indexTowerAsal].top] > stack[indexTowerTujuan].items[stack[indexTowerTujuan].top]){
            printf("[!] TIDAK VALID [!]\n");
            getch();
            towerHanoi(stack, langkah);
            return;
        }
    }
    
    // read(stack, indexTowerTujuan);

    push(stack, indexTowerTujuan, stack[indexTowerAsal].items[stack[indexTowerAsal].top]);
    pop(stack, indexTowerAsal);
    *langkah += 1;
    // readTower(stack);
    towerHanoi(stack, langkah);
    return;
}

void TampilkanJumlahLangkah(int langkah){
    printf("[+] Jumlah langkah yang telah dilakukan: %d [+]\n", langkah);
}