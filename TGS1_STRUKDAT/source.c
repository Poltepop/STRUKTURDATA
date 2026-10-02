#include "header.h"

void menu(){
    printf("\t [Menu] \n");
    printf("[1]. Pesan Meja Resto \n");
    printf("[2]. Print All Reservasi \n");
    printf("[3]. Print Khusus \n");
    printf("[4]. Update Reservasi \n");
    printf("[5]. Batalkan Reservasi \n");
    printf("[0]. Keluar Dari Program \n");
    printf(">>>");
}

void initReservasi(Reservasi reservasi[baris][kolom]){
    int i, j, k, l;
    int count = 1;

    for(i = 0; i < baris; i++){
        for(j = 0; j < kolom; j++){
            reservasi[i][j].kodeMeja = count;
            count++;
            strcpy(reservasi[i][j].namaPemesan, "-");
            strcpy(reservasi[i][j].jenisAcara, "-");
            strcpy(reservasi[i][j].idReservasi, "-");

            for(k = 0; k < barisPesanan; k++){
                for(l = 0; l < kolomPesanan; l++){
                      strcpy(reservasi[i][j].menuPesanan[k][l], "-");
                }
            }
        }
    }
}

void daftarMenu(){
    printf("Steak     Rp.85.000\n");
    printf("Pasta     Rp.55.000\n");
    printf("Salad     Rp.35.000\n");
    printf("Jus       Rp.25.000\n");
}

void pesanMenu(Reservasi reservasi[baris][kolom], int getBaris, int getKolom){
    int i, j;
    string temp;

    int count = 1;
    for(i = 0; i < barisPesanan; i++){
        for(j = 0; j < kolomPesanan; j++){
            do{
                printf("Masukan Menu ke-%d: ", count);
                scanf("%s", &temp);

                if(strcmpi(temp, "steak") != 0 && strcmpi(temp, "pasta") != 0 && strcmpi(temp, "salad") != 0 && strcmpi(temp, "jus") != 0){
                    printf("[!] INVALID [!]\n");
                    continue;
                }

                break;
            }while(true);

            strcpy(reservasi[getBaris][getKolom].menuPesanan[i][j], temp);

            count++;
        }
    }
}

void pesanMejaResto(Reservasi reservasi[baris][kolom]){
    int i, j;
    char pilihan;

    do{
        printf("Masukan Baris: ");
        scanf("%d", &i);
        if(i < 0 || i >= baris){
            printf("[!] BARIS NEGATIVE ATAU MELEBIHI BATAS [!]\n");
            continue;
        }
        break;
    }while(true);

    do{
        printf("Masukan Kolom: ");
        scanf("%d", &j);
        if(j < 0 || j >= kolom){
            printf("[!] KOLOM NEGATIVE ATAU MELEBIHI BATAS [!]\n");
            continue;
        }
        break;
    }while(true);

    if(strcmp(reservasi[i][j].idReservasi, "-") != 0){
        printf("[!] MEJA SUDAH TERISI [!]\n");
        return;
    }

    printf("Masukan Nama Pemesan: ");
    scanf("%s", &reservasi[i][j].namaPemesan);

    printf("Jenis Acara: ");
    scanf("%s", &reservasi[i][j].jenisAcara);

    do{
        printf("ID Reservasi: ");
        scanf("%s", &reservasi[i][j].idReservasi);
    
        if(strlen(reservasi[i][j].idReservasi) > 4 || strlen(reservasi[i][j].idReservasi) < 4){
            printf("[!] INVALID [!]\n");
            continue;
        }

        break;
    }while(true);

    printf("Apakah ingin memsan makanan/minuman (y/n): ");
    scanf(" %c", &pilihan);

    if(pilihan == 'n' || pilihan == 'N'){
        printf("[!] BATAL MEMESAN MAKANAN [!]\n");
    }else if(pilihan == 'y' || pilihan == 'Y'){
        daftarMenu();
        pesanMenu(reservasi, i, j);
    }else{
        printf("[!] INVALID [!] \n");
    }


}

void getAll(Reservasi reservasi[baris][kolom]){
    int i, j;
    for(i = 0; i < baris; i++){
        for(j = 0; j < kolom; j++){
            printf("[%4d | %4s ]   ", reservasi[i][j].kodeMeja, reservasi[i][j].jenisAcara);
        }
        printf("\n");
    }
}

void getDetail(Reservasi reservasi[baris][kolom]){
    int i, j;
    int k, l;

    printf("Masukan Baris: ");
    scanf("%d", &i);

    printf("Masukan Kolom: ");
    scanf("%d", &j);

    if(strcmp(reservasi[i][j].idReservasi, "-") == 0){
        printf("[!] MEJA MASIH KOSONG [!]\n");
        return;
    }

    printf("Reservasi Meja %d\n", reservasi[i][j].kodeMeja);
    printf("Nama Pemesan: %s\n", reservasi[i][j].namaPemesan);
    printf("ID Reservasi: %s\n", reservasi[i][j].idReservasi);
    printf("Jenis Acara: %s\n", reservasi[i][j].jenisAcara);

    if(strcmp(reservasi[i][j].menuPesanan[0][0], "-") != 0){
        for(k = 0; k < barisPesanan; k++){
            for(l = 0; l < kolomPesanan; l++){
                printf("[%5s]", reservasi[i][j].menuPesanan[k][l]);
            }
            printf("\n");
        }
    }

}


void updateReservasi(Reservasi reservasi[baris][kolom]){
    int i, j;
    char pilihan;
    char pilihanMenu;

    printf("Masukan Baris: ");
    scanf("%d", &i);

    printf("Masukan Kolom: ");
    scanf("%d", &j);

    if(strcmp(reservasi[i][j].idReservasi, "-") == 0){
        printf("[!] MEJA MASIH KOSONG [!]\n");
        return;
    }

    printf("Apakah ingin mengubah data(y/n): ");
    scanf(" %c", &pilihan);

    if(pilihan == 'n' || pilihan == 'N'){
        printf("[!] BATAL MENGINPUT DATA [!]\n");
        return;
    }else if(pilihan == 'y' || pilihan == 'Y'){
        printf("Masukan Nama Pemesan: ");
        scanf("%s", &reservasi[i][j].namaPemesan);

        printf("Jenis Acara: ");
        scanf("%s", &reservasi[i][j].jenisAcara);

        do{
            printf("ID Reservasi: ");
            scanf("%s", &reservasi[i][j].idReservasi);
        
            if(strlen(reservasi[i][j].idReservasi) > 4 || strlen(reservasi[i][j].idReservasi) < 4){
                printf("[!] INVALID [!]\n");
                continue;
            }

            break;
        }while(true);

        printf("Apakah ingin memesan makanan/minuman (y/n): ");
        scanf(" %c", &pilihanMenu);

        if(pilihanMenu == 'n' || pilihanMenu == 'N'){
            printf("[!] BATAL MEMESAN MAKANAN/MINUMAN [!]\n");
        }else if(pilihanMenu == 'y' || pilihanMenu == 'Y'){
            daftarMenu();
            pesanMenu(reservasi, i, j);
        }else{
            printf("[!] INVALID [!] \n");
        }
    }else{
        printf("[!] INVALID [!]");
    }


}

void batalkanReservasi(Reservasi reservasi[baris][kolom]){
    int i, j, k, l;
    char pilihan;

    printf("Masukan Baris: ");
    scanf("%d", &i);

    printf("Masukan Kolom: ");
    scanf("%d", &j);

    if(strcmp(reservasi[i][j].idReservasi, "-") == 0){
        printf("[!] MEJA MASIH KOSONG [!]\n");
        return;
    }

    printf("Reservasi Meja %d\n", reservasi[i][j].kodeMeja);
    printf("Nama Pemesan: %s\n", reservasi[i][j].namaPemesan);
    printf("ID Reservasi: %s\n", reservasi[i][j].idReservasi);
    printf("Jenis Acara: %s\n", reservasi[i][j].jenisAcara);

    if(strcmp(reservasi[i][j].menuPesanan[0][0], "-") != 0){
        for(k = 0; k < barisPesanan; k++){
            for(l = 0; l < kolomPesanan; l++){
                printf("[%5s]", reservasi[i][j].menuPesanan[k][l]);
            }
            printf("\n");
        }
    }

    printf("Apakah anda ingin membatalkan reservasi? (y/n): ");
    scanf(" %c", &pilihan);

    if(pilihan == 'n' || pilihan == 'N'){
        printf("[!] GAGAL MEMBATALAKN RESERVASI MEJA [!]\n");
    }else if(pilihan == 'y' || pilihan == 'Y'){
        strcpy(reservasi[i][j].namaPemesan, "-");
        strcpy(reservasi[i][j].jenisAcara, "-");
        strcpy(reservasi[i][j].idReservasi, "-");

        printf("[+] Reservasi Berhasil Di Batalkan [+]\n");
    }else{
        printf("[!] INVALID [!]\n");
    }
}