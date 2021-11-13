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

boolean isNormalItem(item t);

boolean isHeavyItem(item t);

boolean isPerishableItem(item t);

boolean isVipItem(item t);

void displayItem(item t);

void decrementPerishableTime(item *t);

#endif