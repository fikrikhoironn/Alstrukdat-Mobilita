#ifndef ARRAYSTATIS_H
#define ARRAYSTATIS_H

#include "boolean.h"
#include "../time/time.h"
#include "../stack/stack.h"

#define VAL_UNDEF -1
#define MAX_CAPACITY 5

#define ELEMENT(l, i) (l).gadgetType[i]

typedef struct {
    int gadgetType[MAX_CAPACITY];
} gadgetList;

// Konstruktor

void createGadgetList(gadgetList *g);
// I.S sembarang
// F.S mengisi gadgetList dengan VAL_UNDEF

// Fungsi/Prosedur

boolean isFull(gadgetList g);

boolean isEmpty(gadgetList g);

void buyItem(time *money, gadgetList *g);
// I.S money dan gadgetList terdefinisi
// F.S jika money cukup && gadgetList belum penuh -> item dimasukkan ke dalam gadgetList
//     else -> I.S

void useItem(gadgetList *g, stack *bag, time *t);
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

boolean isMoneySufficient(time money, int gadgetType);
// return true, if money > price of Gadget

// Better input selector
void getCommand(int *a, int lower_border, int upper_border);

void useGadget(int gadgetType, stack *bag, time *t);
// menggunakan gadget

#endif