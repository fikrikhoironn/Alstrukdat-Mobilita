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
}item;

#define timeIn(I) (I).timeIn
#define pickUp(I) (I).pickUp
#define dropOff(I) (I).dropOff
#define typeItem(I) (I).typeItem
#define perishableTime(I) (I).perishableTime



#endif