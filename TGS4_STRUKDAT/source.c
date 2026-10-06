#include "header.h"

void menu(){
    printf("\n[1]. Tambahkan chart \n");
    printf("[2]. Tampilkan Semua Chart \n");
    printf("[3]. Edit Chart \n");
    printf("[4]. Hapus Chart \n");
    printf("[5]. Cari Chart \n\n");
    printf("[6]. | TUGAS | rata-rata tingkat kesulitan\n");
    printf("[0]. Keluar \n");
    printf(">>>");
}

int getMaxSize(int *maxSize){
    printf("Masukan Jumlah Chart Maksimal Yang ditampung: ");
    scanf("%d", maxSize);
}

void init(Chart *C, int maxSize){
    int i;
    for(i = 0; i < maxSize; i++){
        (C+i)->idChart = -1;
        strcpy((C + i)->nameChart, "-");
        (C+i)->difficultyChart = -1.0;
    }   
}

Chart* alokasi(int maxSize){
    Chart* C = (Chart*) malloc(maxSize * sizeof(Chart));

    if(C == NULL){ 
      return NULL;
    }

    return C;
}

bool isEmpty(Chart *C, int maxSize){
    int i;
    for(i = 0; i < maxSize; i++){
        if((C + i)->idChart != -1){
            return false;
        }
    }

    return true;
}

bool isFull(Chart *C, int maxSize){
    int i;
    int count = 0;

    for(i = 0; i < maxSize; i++){
        if((C + i)->idChart != -1){
            count++;
        }
    }

    return count == maxSize;
}

void createData(Chart *C, int index, int idChart, string namaChart, float difficultyChart){
    (C + index)->idChart = idChart;
    strcpy((C + index)->nameChart, namaChart);
    (C + index)->difficultyChart = difficultyChart;
}

void insertData(Chart *C, int maxSize){
    int i;

    int idChart;
    string nameChart;
    float difficultyChart;

    printf("Masukan ID Chart Baru: ");
    scanf("%d", &idChart);

    if(idChart < 0){
        printf("[!] ID Chart Tidak Boleh Kurang Dari 0 [!]\n");
        return;
    }

    printf("Masukan Judul Chart: ");
    fflush(stdin);
    gets(nameChart);

    printf("Masukan Tingkat Kesulitan: ");
    scanf("%f", &difficultyChart);

    if(isFull(C, maxSize)){
        printf("[!] Tempat Penyimpanan Penuh, Tidak Bisa Menyimpan Data Baru [!] \n");
        return;
    }

    for(i = 0; i < maxSize; i++){
        if((C + i)->idChart == -1){
            createData(C, i, idChart, nameChart, difficultyChart);
            printf("[+] Berhasil Memasukan Chart ke array di index %d [+]\n", i);
            return;
        }
    }
}

void getAll(Chart *C, int maxSize){
    int i;
    printf("\t [Daftar Chart] \n");

    for(i = 0; i < maxSize; i++){
        if((C + i)->idChart != -1){
            printf("Slot Chart ke-%d (Index ke-%d)\n", i + 1, i);
            printf("ID Chart                : %d\n", (C + i)->idChart);
            printf("Nama Chart              : %s\n", (C + i)->nameChart);
            printf("Tingkat Kesulitan       : %.2f\n\n", (C + i)->difficultyChart);
        }
    }
}

int getIndex(Chart *C, int maxSize, int id){
    int i; 
    for(i = 0; i < maxSize; i++){
        if((C + i)->idChart == id){
            return i;
        }
    }

    return -1;
}

void updateData(Chart *C, int maxSize){
    int id;
    printf("\t [EDIT DATA CHART] \n");
    printf("Masukan ID Chart yang ingin diganti: ");
    scanf("%d", &id);

    if(getIndex(C, maxSize, id) == -1 || id == -1){
        printf("[!]Chart Tidak Ditemukan[!]\n");
        return;
    }

    int index = getIndex(C, maxSize, id);
    int oldId = (C + index)->idChart;
    
    printf("Masukan ID Chart Baru: ");
    fflush(stdin);
    gets((C + index)->nameChart);
    // scanf("%d", &((C + index)->idChart));

    if((C + index)->idChart < 0){
        printf("[!] ID Chart Tidak Boleh Kurang Dari 0 [!]\n");
        (C + index)->idChart = oldId;
        return;
    }

    printf("Masukan Judul Chart: ");
    scanf("%s", (C + index)->nameChart);

    printf("Masukan Tingkat Kesulitan: ");
    scanf("%f", &((C + index)->difficultyChart));

    printf("[+] Berhasil Mengubah Chart ke array di index %d [+]\n", index);
}

void deleteData(Chart *C, int maxSize){
    int id;
    printf("\t [RESET/DELETE DATA CHART] \n");
    printf("Masukan ID Chart yang ingin dihapus: ");
    scanf("%d", &id);

    if(getIndex(C, maxSize, id) == -1 || id == -1){
        printf("[!]Chart Tidak Ditemukan[!]\n");
        return;
    }

    int index = getIndex(C, maxSize, id);

    (C+index)->idChart = -1;
    strcpy((C + index)->nameChart, "-");
    (C+index)->difficultyChart = -1.0;
    printf("[+] Berhasil Menghapus Chart ke array di index %d [+]\n", index);
}

void cariChart(Chart *C, int maxSize){
    int id;
    printf("\t [RESET/DELETE DATA CHART] \n");
    printf("Masukan ID Chart yang ingin dihapus: ");
    scanf("%d", &id);

    if(getIndex(C, maxSize, id) == -1 || id == -1){
        printf("[!]Chart Tidak Ditemukan[!]\n");
        return;
    }

    int index = getIndex(C, maxSize, id);
    printf("Ditemukan di index ke-", index);
    printf("ID Chart                : %d\n", (C + index)->idChart);
    printf("Nama Chart              : %s\n", (C + index)->nameChart);
    printf("Tingkat Kesulitan       : %.2f\n\n", (C + index)->difficultyChart);
}



void cariMaxMin(Chart *C, int maxSize){
    printf("[BONUS] \n");
    if(isEmpty(C, maxSize)){
        printf("[!] Array Masih Kosong [!]\n");
        return;
    }

    int i = 0;
    
    while((C + i)->idChart == -1){
        i++;
    }

    int idxMax = i;
    int idxMin = i;
    float maxDiff = (C + i)->difficultyChart;
    float minDiff = (C + i)->difficultyChart;

    for(i = 0; i < maxSize; i++){
        if((C + i)->idChart != -1){
            if((C + i)->difficultyChart >= maxDiff){
                maxDiff = (C + i)->difficultyChart;
                idxMax = i;
            }
            if((C + i)->difficultyChart <= minDiff){
                minDiff = (C + i)->difficultyChart;
                idxMin = i;
            }
        }
    }

    printf("\nCHART DENGAN DIFFICULTY TERENDAH: \n");
    printf("ID Chart                : %d\n", (C + idxMin)->idChart);
    printf("Nama Chart              : %s\n", (C + idxMin)->nameChart);
    printf("Tingkat Kesulitan       : %.2f\n", (C + idxMin)->difficultyChart);

    printf("\nCHART DENGAN DIFFICULTY TERTINGGI: \n");
    printf("ID Chart                : %d\n", (C + idxMax)->idChart);
    printf("Nama Chart              : %s\n", (C + idxMax)->nameChart);
    printf("Tingkat Kesulitan       : %.2f\n", (C + idxMax)->difficultyChart);
}

void mean(Chart *C, int maxSize){
    printf("[RATA - RATA TINGAK KESULITAN] \n");
    if(isEmpty(C, maxSize)){
        printf("[!] Array masih kosng! [!]\n");
        return;
    }

    int i;
    int count = 0; 
    float sum = 0.0;
    float hasil = 0.0;

    for(i = 0; i < maxSize; i++){
        if((C + i)->idChart != -1){
            count++;
            sum += (float) (C + i)->difficultyChart;
        }       
    }

    hasil = sum / count;

    printf("Rata-rata tingkat kesulitan Chart: %.2f\n", hasil);
}