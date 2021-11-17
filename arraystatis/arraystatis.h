#ifndef ARRAYSTATIS_H
#define ARRAYSTATIS_H

#include "boolean.h"
#include "../time/time.h"
#include "../stack/stack.h"
#include "../matrix/matrix.h"

#define VAL_UNDEF -1
#define MAX_CAPACITY 5

#define ELEMENT(l, i) (l).gadgetType[i]

typedef struct {
    int gadgetType[MAX_CAPACITY];
} gadgetList;

// Mengisi gadgetList dengan VAL_UNDEF
void createGadgetList(gadgetList *g);

// Return true jika gadgetList penuh
boolean isFull(gadgetList g);

// Return true jika gadgetList kosong
boolean isEmpty(gadgetList g);

// Prosedur BUY
void BUY(time *money, gadgetList *g, ArrayBuild arrBuild);

// Prosedur INVENTORY
void INVENTORY(gadgetList *g, stack *bag, time *t, linkedList toDoList, Matrix m, ArrayBuild arrBuild, int x , int y);

// Pesan kalau buy berhasil
void displayBuySuccess(int gadgetType);

// Print isi gadgetList
void displayGadgetList(gadgetList g);

// Memasukkan gadget ke dalam INVENTORY
void addGadget(gadgetList *g, int gadgetType);

// Menghapus gadget sesuai index
void removeGadget(gadgetList *g, int index, int *gadgetType);

// Return harga gadget
int gadgetPrice(int gadgetType);

// Return true jika uang cukup
boolean isMoneySufficient(time money, int gadgetType);

// Better input selector
void getCommand(int *a, int lower_border, int upper_border);

// Prosedur pemakaian gadget
void useGadget(int gadgetType, stack *bag, time *t, linkedList toDoList, Matrix m, ArrayBuild arrBuild, int x , int y);

#endif