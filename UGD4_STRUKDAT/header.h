#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char string[128];

typedef struct {
    int idChart;
    string nameChart;
    float difficultyChart;
} Chart;

void menu();
int getMaxSize();
void init(Chart *C, int maxSize);
Chart* alokasi(int maxSize);
bool isEmpty(Chart *C, int maxSize);
void insertData(Chart *C, int maxSize);
void getAll(Chart *C, int maxSize);
void updateData(Chart *C, int maxSize);
void deleteData(Chart *C, int maxSize);
void cariMaxMin(Chart *C, int maxSize);