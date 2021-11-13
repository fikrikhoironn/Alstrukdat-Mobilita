#include "item.h"

item createItem(int timeIn, char pickUp, char dropOff, char typeItem, int perishableTime){
    item Elmt;
    timeIn(Elmt) = timeIn;
    pickUp(Elmt) = pickUp;
    dropOff(Elmt) = dropOff;
    typeItem(Elmt) = typeItem;
    perishableTime(Elmt) = perishableTime;
    perishableOrigin(Elmt) = perishableTime;
    return Elmt;
    
}

boolean isNormalItem(item t){
    return typeItem(t) == 'N';
}

boolean isHeavyItem(item t){
    return typeItem(t) == 'H';
}

boolean isPerishableItem(item t){
    return typeItem(t) == 'P';
}

boolean isVipItem(item t){
    return typeItem(t) == 'V';
}

void displayItem(item t){
    printf(" %d ", t.timeIn);
    printf(" %c ", t.pickUp);
    printf(" %c ", t.dropOff);
    printf(" %c ", t.typeItem);
    printf(" %d ", t.perishableTime);
    printf(" %d\n",t.perishableOrigin);
}

void decrementPerishableTime(item *t){
    perishableTime(*t)--;
}

void resetPerishableTime(item *t){
    perishableTime(*t) = perishableOrigin(*t);
}