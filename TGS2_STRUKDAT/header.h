#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 3

typedef char string[128];

typedef struct {
    int top;
    int items[MAX];
} Hanoi;

void menu();
void init(Hanoi stack[]);
bool isEmpty(Hanoi stack[], int indexTower);
bool isFull(Hanoi stack[], int indexTower);
void push(Hanoi stack[], int indexTower, int value);
void pop(Hanoi stack[], int indexTower);
void read(Hanoi stack[], int indexTower);
void readTower(Hanoi stack[], int langkah);
void towerHanoi(Hanoi stack[], int *langkah);
void TampilkanJumlahLangkah(int langkah);