#include "item.h"

item makeItem(int timeIn, char pickUp, char dropOff, char typeItem, int perishableTime){
    item Elmt;
    timeIn(Elmt) = timeIn;
    pickUp(Elmt) = pickUp;
    dropOff(Elmt) = dropOff;
    typeItem(Elmt) = typeItem;
    perishableTime(Elmt) = perishableTime;
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