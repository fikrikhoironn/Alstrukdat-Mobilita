#include "time.h"

void incrementTime(time *t){
    if(heavyDuration(*t) > 0){
        currentTime(*t) += heavyDuration(*t) +1;
        speedBoost(*t) = 0;
    }
    else if(speedBoost(*t) > 0 && heavyDuration(*t) == 0){
        speedBoost(*t) -= 1;
        currentTime(*t) += 0.5;
    }
    else{
        currentTime(*t) += 1;
    }
}