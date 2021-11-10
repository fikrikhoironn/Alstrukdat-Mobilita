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
        speedBoost(*t) = 0; //reset speedBoost
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

void addTime(time *t, int amount){
    currentTime(*t) += amount;
}

void subtractTime(time *t, int amount){
    currentTime(*t) -= amount;
}

void addHeavyItem(time *t){
    heavyItem(*t) += 1;
}

void decrementHeavyItem(time *t){
    heavyItem(*t) -= 1;
}

void resetHeavyItem(time *t){
    heavyItem(*t) = 0;
}

void initMoveCount(time *t){
    moveCount(*t) = 0;
}

void initCurrentMoney(time *t){
    currentMoney(*t) = 0;
}

void addCurrentMoney(time *t, int reward){
    currentMoney(*t) += reward;
}

void subtractCurrentMoney(time *t, int cost){
    currentMoney(*t) -= cost;
}

void initReturnToSender(time *t){
    returnToSender(*t) = 0;
}

void incrementReturnToSender(time *t){
    returnToSender(*t)++;
}


