#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char string[128];

typedef struct Node *address;
typedef struct Node{
	string nama;
	int umur;
	string kategori;
	address next;
} tNode;

bool isEmpty(address first);
bool isHaveOneElement(address first);
void init(address *first);
address memoryAllocation(string nama, int umur, string kategori);
void insertFirst(address *first, string nama, int umur, string kategori);
void insertLast(address *first, string nama, int umur, string kategori);
void deleteFirst(address *first);
void deleteLast(address *first);
void printData(address first);
void mean(address first);
void searchByName(address first, string getName);
void menu();
void hasilPenjualan(address first);