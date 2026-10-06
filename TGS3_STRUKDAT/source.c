#include "header.h"

void menu(){
	printf("\t=== RESTORAN CEPAT SAJI ATMA ===\n\n");
	printf("[1] Terima Pesanan \n");
	printf("[2] Mulai Proses Pesanan \n");
	printf("[3] Cek Status Dapur \n");
	printf("[4] [Bonus Statistik Pesanan]\n");
	printf("[0] Exit \n");
	printf(">>>");
}

void init(Queue *Q){
	Q->head = -1;
	Q->tail = -1;
}

bool isEmpty(Queue Q){
	return Q.head == -1 && Q.tail == -1;
}

bool isFull(Queue Q){
	return Q.head < Q.tail && Q.tail - Q.head == MAX - 1 || Q.head > Q.tail && Q.head - Q.tail == 1;
}

bool isOneElement(Queue Q){
	return Q.head == Q.tail && !isEmpty(Q);
}

void enqueue(Queue *Q, int value){
	if(isFull(*Q)){
		printf("[!] Queue Is Full [!] \n");
		return;
	}
	
	if(isEmpty(*Q)){
		Q->head = Q->tail = 0;
		// Bussines Logics
		Q->items[Q->tail] = value;
		return;
	}
	
	if(Q->tail == MAX - 1){
		Q->tail = 0;
	}else {
		Q-> tail++;
	}
	
	// Bussines Logics
	Q->items[Q->tail] = value;
}

void dequeue(Queue *Q){
	if(isEmpty(*Q)){
		printf("[!] Queue Is Empty [!]\n");
		return;
	}
	
	if(isOneElement(*Q)){
		init(Q);
		return;
	}
	
	if(Q->head == MAX - 1){
		Q->head = 0;
	}
	
	Q->head++;
}

void mulaiProsesPesanan(Queue *Q, Queue *A, Queue *B){
	printf("[Mulai Proses Pesanan]\n");
	
	if(isEmpty(*Q)){
		printf("[!] Antrian Pesanan Masuk Kosong, Tidak Ada Pesanan Yang Di Proses [!]\n");
		return;
	}
	
	int i;
	if(Q->head <= Q->tail){
		for(i = Q->head; i <= Q->tail; i++){
			if(Q->items[i] % 2 == 0){
				printf("[*] Order %d (Genap) -> Dapur A\n", Q->items[i]);
				enqueue(A, Q->items[i]); 
			}else{
				printf("[*] Order %d (Ganjil) -> Dapur B\n", Q->items[i]);
				enqueue(B, Q->items[i]); 
			}
		}
		
		init(Q);
		return;
	}	
	
	for(i = Q->head; i <= MAX - 1; i++){
		if(Q->items[i] % 2 == 0){
			printf("[*] Order %d (Genap) -> Dapur A\n", Q->items[i]);
			enqueue(A, Q->items[i]); 
		}else{
			printf("[*] Order %d (Ganjil) -> Dapur B\n", Q->items[i]);
			enqueue(B, Q->items[i]); 
		}
	}
	
	for(i = 0; i <= Q->tail; i++){
		if(Q->items[i] % 2 == 0){
			printf("[*] Order %d (Genap) -> Dapur A\n", Q->items[i]);
			enqueue(A, Q->items[i]); 
		}else{
			printf("[*] Order %d (Ganjil) -> Dapur B\n", Q->items[i]);
			enqueue(B, Q->items[i]); 
		}
	}
	
	init(Q);
}

void cekStatusDapur(Queue Q, char status){
	if(isEmpty(Q)){
		printf("[!] Dapur %c Masih Kosong [!] \n", status);
		return;
	}
	
	string stats;
	if(status == 'A'){
		strcpy(stats, "Genap");
	}else {
		strcpy(stats, "Ganjil");
	}
	
	printf("--- Dapur %c (%s) --- \n", status, stats);
	
	int i;
	if(Q.head <= Q.tail){
		for(i = Q.head; i <= Q.tail; i++){
			printf("Nomor Order: %d \n", Q.items[i]);
		}
		
		return;
	}	
	
	for(i = Q.head; i <= MAX - 1; i++){
		printf("Nomor Order: %d \n", Q.items[i]);
	}
	
	for(i = 0; i <= Q.tail; i++){
		printf("Nomor Order: %d \n", Q.items[i]);
	}
}

int countQueue(Queue Q){	
	int count = 0;
	if(isEmpty(Q)){
		return count;
	}
	
	int i;
	if(Q.head <= Q.tail){
		for(i = Q.head; i <= Q.tail; i++){
			count++;
		}
		
		return count;
	}	
	
	for(i = Q.head; i <= MAX - 1; i++){
		count++;
	}
	
	for(i = 0; i <= Q.tail; i++){
		count++;
	}
	
	return count;
}

void statistikPesanan(Queue Q, Queue A, Queue B){
	printf("[Bonus - Statistik Pesanan] \n\n");
	printf("--- IsI Queue Saat ini  ---\n");
	printf("Antrian Pesanan Masuk  : %d/5\n", countQueue(Q));
	printf("Dapur A (Genap)        : %d/5\n", countQueue(A));
	printf("Dapur B (Ganjil)       : %d/5\n\n", countQueue(B));
	printf("--- Ringkasan ---\n");
	printf("Total Pesanan          : %d/5\n\n", countQueue(B) + countQueue(A) + countQueue(Q));
	printf("Menunggu diproses      : %d/5\n", countQueue(Q));
	printf("Sudah diproses         : %d/5\n", countQueue(A) + countQueue(B));
	printf("- Genap                : %d/5\n", countQueue(A));
	printf("- Ganjil               : %d/5\n", countQueue(B));
}


