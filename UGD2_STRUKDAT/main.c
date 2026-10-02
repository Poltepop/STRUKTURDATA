#include "header.h"

int main(){
    Stack stack;
	init(&stack);
	int pilihan;
	do{
		system("cls");
		menu();
		scanf("%d", &pilihan);
		switch(pilihan){
			case 1:
				system("cls");
				push(&stack);
			break;
			case 2:
				system("cls");
				pop(&stack);
			break;
			case 3:
				system("cls");
				sorting(stack);
			break;
			case 4:
				system("cls");
				kirimPaket(&stack);
			break;
			case 0:
				system("cls");
				printf("[~] Mematikan Mesin Pabrik [~] \n");
				printf("[~] I Dewa Putu Adhitya Wiraguna - 250713478 - C \n");
			break;
		}
		
		getch();
	}while(pilihan != 0);

    return 0;
}