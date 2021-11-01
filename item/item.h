// File : item. h
// ADT yang berkaitan dengan item

#ifndef item_h
#define item_h

#include <stdio.h>
#include <boolean.h>

typedef struct{
    int timeIn;
    char pickUp;
    char dropOff;
    char typeItem;
    int valueItem;
    int rewardItem;
}item;

#define timeIn(I) (I).timeIn
#define pickUp(I) (I).pickUp
#define dropOff(I) (I).dropOff
#define typeItem(I) (I).typeItem
#define valueItem(I) (I).valueItem
#define rewardItem(I) (I).rewardItem

#endif