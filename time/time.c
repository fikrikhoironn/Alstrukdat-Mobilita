#include "time.h"

void createTime(time *t){
    currentTime(*t) = 0;
    speedBoost(*t) = 0;
    heavyItem(*t) = 0;
    moveCount(*t) = 0;
}

void incrementTime(time *t){
    if(heavyItem(*t) > 0){ // 
        currentTime(*t) += heavyItem(*t) +1;
        speedBoost(*t) = 0;
    }
    else if(speedBoost(*t) > 0 && heavyItem(*t) == 0){
        speedBoost(*t) -= 1;
        if (moveCount(*t) == 2 && speedBoost(*t) > 0){
            currentTime(*t) += 1;
            moveCount(*t) = 0;
        }
    }
    else{
        currentTime(*t) += 1;
    }
}
void addHeavyItem(time *t){
    heavyItem(*t) += 1;
}

void resetHeavyItem(time *t){
    heavyItem(*t) = 0;
}

void initMoveCount(time *t){
    moveCount(*t) = 0;
}


