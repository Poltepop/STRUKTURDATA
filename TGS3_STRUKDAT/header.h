#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 5

typedef char string[128];

typedef struct {
	int items[MAX];
	int head;
	int tail;
} Queue;

void init(Queue *Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
bool isOneElement(Queue Q);
void enqueue(Queue *Q, int value);
void dequeue(Queue *Q);
void mulaiProsesPesanan(Queue *Q, Queue *A, Queue *B);
void cekStatusDapur(Queue Q, char status);
int countQueue(Queue Q);
void statistikPesanan(Queue Q, Queue A, Queue B);
void menu();



