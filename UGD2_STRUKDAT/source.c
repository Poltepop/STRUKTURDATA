#include "header.h"

void init(Stack *stack){
	stack->top = -1;
	stack->topGenap = -1;
	stack->topGanjil = -1;
}

void menu(){
	printf("\t [MESIN SORTIR PABRIK] \n");
	printf("[1] Tumpuk Kotak \n");
	printf("[2] Mulai Inspeksi \n");
	printf("[3] Cek Hasil sortir \n");
	printf("[4] kirim Paket \n");
	printf(">>>");
}

bool isEmpty(Stack stack){
	return stack.top == -1;
}

bool isFull(Stack stack){
	return stack.top >= MAX - 1;
}

bool isEmptyGenap(Stack stack){
	return stack.topGenap == -1;
}


bool isEmptyGanjil(Stack stack){
	return stack.topGanjil == -1;
}


void push(Stack *stack){
	if(isFull(*stack)){
		printf("[!] Mesin Penumpuk Sudah Penuh [!]\n");
		return;
	}
	
	stack->top++;
	printf("Masukan nomor seri kotak (Angka): ");
	scanf("%d", &stack->items[stack->top]);
}

void pushGenap(Stack *stack, int item){
	if(isFull(*stack)){
		printf("[!] Mesin Penumpuk Sudah Penuh [!]\n");
		return;
	}
	
	stack->topGenap++;
	stack->genap[stack->topGenap] = item;
}

void pushGanjil(Stack *stack, int item){
	if(isFull(*stack)){
		printf("[!] Mesin Penumpuk Sudah Penuh [!]\n");
		return;
	}
	
	stack->topGanjil++;
	stack->ganjil[stack->topGanjil] = item;
}


void read(Stack stack){
	if(isEmpty(stack)){
		printf("[!] Tidak Ada Kotak di mesin utama [!] \n");
		return;
	}
	
	printf("Current potition %d - %d\n", stack.items[stack.top], stack.top);
}

void pop(Stack *stack){
	if(isEmpty(*stack)){
		printf("[!] Tidak Ada Kotak di Mesin Utama Untuk Diinspeksi [!] \n");
		return;
	}
	
	int i;
	for(i = 0; i <= stack->top; i++){
		if(stack->items[i] % 2 == 0){
			printf("Mengambil Kotak %d... Masuk Ke Jalur Genap \n", stack->items[i]);
			pushGenap(stack, stack->items[i]);
		}else{
			printf("Mengambil Kotak %d... Masuk Ke Jalur Ganjil \n", stack->items[i]);
			pushGanjil(stack, stack->items[i]);
		}	
	}
	
	stack->top = -1;
	
	printf("[+] Inspeksi Selesai! Mesin Utama Sekarang Kosong [+] \n");
}

void sorting(Stack stack){
	int i;
	
	printf("[ Isi Gudang Kotak Genap ] \n");
	if(isEmptyGenap(stack)){
		printf("(Kosong) \n");
	}else{
		for(i = stack.topGenap; i > -1 ; i--){
			printf("| %d | \n", stack.genap[i]);
		}		
	}

	
	printf("[ Isi Gudang Kotak Ganjil ] \n");
	if(isEmptyGanjil(stack)){
		printf("(Kosong) \n");
	}else{
		for(i = stack.topGanjil; i > -1 ; i--){
			printf("| %d | \n", stack.ganjil[i]);
		}			
	}
}

void kirimPaket(Stack *stack){
	int i;
	for(i = stack->topGenap; i > -1; i--){
		printf("[+] Kotak Genap %d Terkirim \n", stack->genap[i]);
		stack->topGenap--;
	}
	for(i = stack->topGanjil; i > -1; i--){
		printf("[+] Kotak Ganjil %d Terkirim \n", stack->ganjil[i]);
		stack->topGanjil--;
	}
}


