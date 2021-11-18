#include "ability.h"

void activateSpeedBoost(time *t){
    speedBoost(*t) += 10;
}

void increaseCapactiy(stack *bag){
    if (!isFullBag(*bag)){
        maxBag(*bag) += 1;
    }
}

//mengaktifasi return to sender
void activateReturnToSender1(stack *bag, linkedList *toDoList, linkedList *inProgressList, time *t){ 
    item val;
    val = getElmtList(*inProgressList, 0);
    if (typeItem(val) != 'V' &&  returnToSender(*t) > 0){
        popBag(bag, &val);
        perishableTime(val) = perishableOrigin(val);
        printf("perishable time item: %d\n", perishableTime(val));
        deleteFirstList(inProgressList, &val);
        insertLastList(toDoList, val);
        printf("Item tipe %c berhasil dikembalikan ke pick up point %c \n", typeItem(val), pickUp(val));
        decrementReturnToSender(t);

    }
    else if(returnToSender(*t) < 0){
        printf("Kamu tidak punya return to sender\n");
    }
    else if(typeItem(val) == 'V'){
        printf("INI ITEM VIP!, KAMU TIDAK BISA MELAKUKAN RETURN\n");
    }
}


