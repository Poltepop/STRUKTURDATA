#include "header.h"

void menu(){
	printf("\t ==== Atma Fest ====\n");
	printf("-- Insert Data --\n");
	printf("[1] Insert Data First\n");
	printf("[2] Insert Data Last\n");
	printf("-- Delete Data --\n");
	printf("[3] Delete Data First\n");
	printf("[4] Delete Data Last\n");
	printf("[5] Print Data\n");
	printf("[6] Rerata Umur \n");
	printf("-- Bonus --\n");
	printf("[7] Cari Penonton\n");
    printf("[8] Hitung Hasil Penjualan\n");
	printf("-- Tugas -- \n");
	printf("[0] Exit\n");
	printf("Pilih Menu: ");
}

bool isEmpty(address first){
	return first == NULL;
}

bool isHaveOneElement(address first){
	return first->next == NULL;
}

void init(address *first){
	*first = NULL;
}

address memoryAllocation(string nama, int umur, string kategori){
	address temp;
	temp = malloc(sizeof(tNode));
	
	strcpy(temp->nama, nama);
	temp->umur = umur;
	strcpy(temp->kategori, kategori);
	temp->next = NULL;
	
	return temp;
}

void insertFirst(address *first, string nama, int umur, string kategori){
	address temp = memoryAllocation(nama, umur, kategori);
	
	temp->next = *first;
	*first = temp;
	
	printf("[+] Data Berhasil Dimasukan Ke awal List [+] \n");
}

void insertLast(address *first, string nama, int umur, string kategori){
	if(isEmpty(*first)){
		insertFirst(first, nama, umur, kategori);
		return;
	}
	
	address temp = memoryAllocation(nama, umur, kategori);
	address last = *first;
	
	while(last->next != NULL){
		last = last->next;
	}
	
	last->next = temp;
	
	printf("[+] Data Berhasil Dimasukan diakhir list [+] \n");
}

void deleteFirst(address *first){
	address temp;
	
	if(isEmpty(*first)){
		printf("[!] List Masih Kosong [!]\n");
		return;
	}
	
	temp = *first;
	*first = temp->next;
	free(temp);
	
	printf("[-] Data  Berhasil dihapus diawal list[-] \n");
}

void deleteLast(address *first){
	if(isEmpty(*first)){
		printf("[!] List Masih Kosong [!]\n");
		return;
	}
	
	if(isHaveOneElement(*first)){
		deleteFirst(first);
		return;
	}
	
	
	address temp = *first;
	
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	
	address last = temp->next;
	temp->next = NULL;
	free(last);
	
	printf("[-] Data  Berhasil dihapus diakhir list[-] \n");
}

void printData(address first){
	if(isEmpty(first)){
		printf("[!] List Masih Kosong [!]\n");
		return;
	}
	
	address temp = first;
	
	printf("\t=== Tampil Data ===\n");
	
	while(temp != NULL){
		printf("Nama      : %s \n", temp->nama);
		printf("Umur      : %d \n", temp->umur);
		printf("Kategori  : %s \n", temp->kategori);
		printf("---------------------------------------\n");
		
		temp = temp->next;
	}
}

void mean(address first){
	if(isEmpty(first)){
		printf("[!] list masih kosong [!]\n");
		return;
	}
	
	address temp = first;
	int count;
	int sum = 0;
	float hasil;
	
	while(temp != NULL){
		sum += temp->umur;
		count++;
		temp = temp->next;
	}
	
	hasil = (float) sum / (float) count;
	printf("rerata umur penonton atma fest adalah %.2f tahun \n", hasil);
}

void searchByName(address first, string getName){
	if(isEmpty(first)){
		printf("[!] list masih kosong [!]\n");
		return;
	}
	
	address temp = first;
	
	while(temp != NULL && strcmp(temp->nama, getName) != 0){
		temp = temp->next;
	}
	
	if(temp == NULL){
		printf("[!] Nama Tidak ditemukan [!]\n");
		return;
	}
	
	printf("Nama      : %s \n", temp->nama);
	printf("Umur      : %d \n", temp->umur);
	printf("Kategori  : %s \n", temp->kategori);
	printf("---------------------------------------\n");
}

void hasilPenjualan(address first){
    if(isEmpty(first)){
		printf("[!] list masih kosong [!]\n");
		return;
	}

    int vip = 150000;
    int reguler = 100000;
    int countVip = 0;
    int countReguler = 0;
    int hasil = 0;
    address temp = first;

    while(temp != NULL){
        if(strcmpi(temp->kategori, "vip") == 0){
            hasil += vip;
            countVip++;
        }else if(strcmpi(temp->kategori, "reguler") == 0){
            hasil += reguler;
            countReguler++;
        }
		temp = temp->next;
	}

    printf("\t --- [ Hasil Penjualan Tiket ] --- \n");
    printf("Ticket VIP terjual %d, dengan pemasukan sebesar %d\n", countVip, (countVip * vip));
    printf("Ticket Reguler terjual %d, dengan pemasukan sebesar %d\n", countReguler, (countReguler * reguler));
    printf("Total Pemasukan: %d\n", hasil);
    printf("--------------------------------------------------------------- \n");

}