#ifndef ARRAYSTATIS_H
#define ARRAYSTATIS_H

#include "boolean.h"

#define VAL_UNDEF -1
#define CAPACITY 5

#define ELMT(l, i) (l).gadgetType[i]

typedef struct {
    int gadgetType[CAPACITY];
} gadgetList;

// Konstruktor

void createGadgetList(gadgetList *g);
// I.S sembarang
// F.S mengisi gadgetList dengan VAL_UNDEF

// Fungsi/Prosedur

boolean isFullInventory(gadgetList g);

boolean isEmptyInventory(gadgetList g);

void buyItem(int *money, gadgetList *g);
// I.S money dan gadgetList terdefinisi
// F.S jika money cukup && gadgetList belum penuh -> item dimasukkan ke dalam gadgetList
//     else -> I.S

void useItem(gadgetList *g);
// I.S gadgetList terdefinisi
// F.S gadgetList berkurang (jika instruksi benar)

void displayGadgetList(gadgetList g);
// Menampilkan gadget yang disimpan dalam gadgetList

void addGadget(gadgetList *g, int gadgetType);
// I.S sembarang
// F.S gadget (berupa int) ditambahkan di VAL_UNDEF pertama

void removeGadget(gadgetList *g, int index, int *gadgetType);
// I.S gadgetList terdefinisi
// F.S gadget di index dihapus

int gadgetPrice(int gadgetType);
// Menampilkan harga gadget

boolean isMoneySufficient(int money, int gadgetType);
// return true, if money > price of Gadget

void useGadget(int gadgetType);
// menggunakan gadget

#endif