#include "time.h"
#include <math.h>
#include <stdio.h>

void createTime(time *t){
    currentTime(*t) = 0;
    speedBoost(*t) = 0;
    heavyItem(*t) = 0;
    currentMoney(*t) = 0;
    returnToSender(*t) = 0;
}

void incrementTime(time *t){
    if(speedBoost(*t) > 0 && heavyItem(*t) == 0){
        speedBoost(*t) -= 1;
        currentTime(*t) += 0.5;
    }
    else if(heavyItem(*t) > 0){ // 
        currentTime(*t) += heavyItem(*t) +1;
        speedBoost(*t) = 0; //reset speedBoost
    }
    
    else{
        currentTime(*t) += 1;
        
    }
}

void printCurrentTime(time t){
    float currentTimeFloat = floor(currentTime(t));
    int my_var = (int)currentTimeFloat;
    printf("%d\n", my_var);
    // printf("%f\n", currentTimeFloat);
}

void addTime(time *t, int amount){
    currentTime(*t) += amount;
}

void subtractTime(time *t, int amount){
    currentTime(*t) -= amount;
}

void addSpeedBoost(time *t){
    speedBoost(*t) += 10;
}

void addHeavyItem(time *t, int amount){
    heavyItem(*t) += amount;
}

void subtractHeavyItem(time *t, int amount){
    heavyItem(*t) -= amount;
}

void resetHeavyItem(time *t){
    heavyItem(*t) = 0;
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


