#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define baris 6 
#define kolom 4 
#define barisPesanan 2
#define kolomPesanan 2

typedef char string[128];

typedef struct {
    int kodeMeja;
    string idReservasi;
    string namaPemesan;
    string jenisAcara;
    string menuPesanan[barisPesanan][kolomPesanan];
} Reservasi;

void menu();
void initReservasi(Reservasi reservasi[baris][kolom]);
void pesanMenu(Reservasi reservasi[baris][kolom], int getBaris, int getKolom);
void pesanMejaResto(Reservasi reservasi[baris][kolom]);
void getAll(Reservasi reservasi[baris][kolom]);
void pesanMejaResto(Reservasi reservasi[baris][kolom]);
void getDetail(Reservasi reservasi[baris][kolom]);
void updateReservasi(Reservasi reservasi[baris][kolom]);
void batalkanReservasi(Reservasi reservasi[baris][kolom]);