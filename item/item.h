// File : item. h
// ADT yang berkaitan dengan item

#ifndef item_h
#define item_h

#include <stdio.h>
#include "boolean.h"

typedef struct{
    int timeIn;
    char pickUp;
    char dropOff;
    char typeItem;
    int perishableTime; 
    int perishableOrigin;
}item;

#define timeIn(I) (I).timeIn
#define pickUp(I) (I).pickUp
#define dropOff(I) (I).dropOff
#define typeItem(I) (I).typeItem
#define perishableTime(I) (I).perishableTime
#define perishableOrigin(I) (I).perishableOrigin

item createItem(int timeIn, char pickUp, char dropOff, char typeItem, int perishableTime);

boolean isNormalItem(item t); //mengecek apakah item ini normal item

boolean isHeavyItem(item t); //mengecek apakah item ini heavy item 

boolean isPerishableItem(item t); //mengecek apakah item ini perishable item

boolean isVipItem(item t); //mengecek apakah item ini VIP item

void displayItem(item t); //menampilkan atribut item

void decrementPerishableTime(item *t); //mengurangi waktu perishable time

void resetPerishableTime(item *t); //mengembalikan waktu perishable time ke nilai awal sebelum di pick up

#endif