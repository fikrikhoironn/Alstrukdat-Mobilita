// File: linkedlist.h 
// Berisi definisi dan primitif struktur list berkait 
// List dinyatakan melalui alamat elemen pertamanya 

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "boolean.h"
#include "../item/item.h"
#include <stdio.h>

// DEKLARASI TIPE   
typedef item infotype;
typedef struct tnode* Address;
typedef struct tnode {
    infotype info;
    Address next;
} Node;
typedef Address linkedList;

// KAMUS UMUM
#define IDX_UNDEF -1 // Indeks tidak terdefinisi

// SELEKTOR 
#define info(L) (L)->info
#define next(L) (L)->next
#define first(L) (L)

// KONSTRUKTOR 
void CreateList(linkedList *L);
// I.S. L sembarang 
// F.S. L terdefinisi sebagai list kosong, L = NULL 

Address newNode(infotype val);
// Mengalokasikan val sebagai info dari node baru dan mengembalikan alamatnya

// OPERASI PADA LIST 
boolean isEmpty(linkedList L);
// Mengirimkan true jika L kosong, false jika tidak

infotype getElmt(linkedList L, int idx);
// Mengirimkan nilai elemen L pada indeks ke-idx

void setElmt(linkedList *L, int idx, infotype val);
// I.S. L terdefinisi, idx adalah indeks yang terdefinisi pada L
// F.S. Nilai elemen L pada indeks ke-idx adalah 

int indexOf(linkedList L, infotype val);
// Mencari letak val dalam list dan mengirimkan indeksnya 

int length(linkedList L);
// Mengirimkan panjang/banyak elemen list L 

void insertFirst(linkedList *L, infotype val);
// I.S. List L terdefinisi 
// F.S. val adalah elemen pertama list yang baru; 
// list L dinyatakan sebagai address dari val
// jumlah elemen list L bertambah satu 

void insertAt(linkedList *L, int idx, infotype val);
// I.S. List L terdefinisi 
// F.S. val adalah elemen list pada indeks ke-idx  yang baru; 
// jumlah elemen list L bertambah satu

void insertLast(linkedList *L, infotype val);
// I.S. List L terdefinisi 
// F.S. val adalah elemen terakhir list yang baru; 
// jumlah elemen list L bertambah satu

void deleteFirst(linkedList *L, infotype *val);
// I.S. List L terdefinisi dan tidak kosong 
// F.S. Elemen pada indeks pertama list dihapus,
// val adalah nilai yang dihapus dari list 

void deleteAt(linkedList *L, int idx, infotype *val);
// I.S. List L terdefinisi dan tidak kosong 
// F.S. Elemen pada indeks ke-idx list dihapus,
// val adalah nilai yang dihapus dari list 

void deleteLast(linkedList *L, infotype *val, int idx);
// I.S. List L terdefinisi dan tidak kosong 
// F.S. Elemen pada indeks terakhir list dihapus,
// val adalah nilai yang dihapus dari list 

void displayList(linkedList L);
// I.S. List L terdefinisi, bisa kosong
// F.S. Elemen list ditampilkan dengan format [e1,e2,...,en]

linkedList concat(linkedList L1, linkedList L2);
// I.S. List L1 dan L2 terdefinisi 
// F.S. LOUt terdefinisi sebagai list hasil penempelan L1 dengan L2 

boolean isItemEqual(item a, item b);
// mengembalikan true jika item a sama dengan item b
// To do list terurut dengan waktu masuk terurut membesar
// In progress list terurut dengan waktu masuk terurut mengecil

void insert_timeasc (linkedList *L, infotype val);
// Memasukkan element val ke dalam list L, terurut membesar

void insert_timedesc (linkedList *L, infotype val);
// Memasukkan element val ke dalam list L, terurut mengecil

#endif