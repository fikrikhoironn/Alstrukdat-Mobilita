#include "ability.h"

void activateSpeedBoost(time *t){
    speedBoost(*t) += 10;
}

void increaseCapactiy(stack *bag){
    if (!sBagFull(*bag)){
            maxBag(*bag) += 1;
    }
}

void activateReturnToSender(stack *bag, linkedList *toDoList, linkedList *inProgressList, time t){
    item val;
    val = getElmtList(*inProgressList, 0);
    if (typeItem(val) != 'V' &&  returnToSender(t) > 0){
        popBag(bag, &val);
        deleteFirstList(inProgressList, &val);
        insertLastList(toDoList, val);
    }
}

