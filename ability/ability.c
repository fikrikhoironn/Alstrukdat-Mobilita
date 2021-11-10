#include "ability.h"

void activateSpeedBoost(time *t){
    speedBoost(*t) += 10;
}

void increaseCapactiy(stack *bag){
    if (!sBagFull(*bag)){
            maxBag(*bag) += 1;
    }
}

