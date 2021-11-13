/* File : stack.h */
/* Definisi ADT Stack dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */

#ifndef STACK_H
#define STACK_H

#include "boolean.h"
#include "../item/item.h"

#define IDX_UNDEF_STACK -1
#define CAPACITY_STACK 100

typedef struct {
  item buffer[CAPACITY_STACK]; /* tabel penyimpan elemen */
  int idxTop;              /* alamat TOP: elemen puncak */
  int maxBag;
} stack;

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah Stack, maka akses elemen : */
#define IDX_TOP(s) (s).idxTop
#define     TOP(s) (s).buffer[(s).idxTop]
#define  maxBag(s) (s).maxBag

/* *** Konstruktor/Kreator *** */
void createStack(stack *bag);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */

/* ************ Prototype ************ */
boolean isEmptyBag(stack bag);
/* Mengirim true jika s kosong: lihat definisi di atas */
boolean isFullBag(stack bag);
/* Mengirim true jika tabel penampung nilai s stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void pushBag(stack *bag, item val);
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void popBag(stack *bag, item *val);
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */

void displayBag(stack bag);

#endif