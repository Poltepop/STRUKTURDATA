#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

typedef struct{
	int top;
	int topGanjil;
	int topGenap;
	int items[MAX];
	int genap[MAX];
	int ganjil[MAX];
}Stack;

void menu();
void init(Stack *stack);
bool isEmpty(Stack stack);
bool isFull(Stack stack);
void push(Stack *stack);
void read(Stack stack);
void pop(Stack *stack);
void sorting(Stack stack);
void kirimPaket(Stack *stack);
