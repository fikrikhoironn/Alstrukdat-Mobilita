#ifndef TIME_H
#define TIME_H

#include "boolean.h"

typedef struct{
    float currentTime;
    int speedBoost;
    int heavyItem;
    int currentMoney;
    int returnToSender;
}time;

#define currentTime(t) (t).currentTime
#define speedBoost(t) (t).speedBoost
#define heavyItem(t) (t).heavyItem
#define currentMoney(t) (t).currentMoney
#define returnToSender(t) (t).returnToSender

void createTime(time *t);

void addTime(time *t, int amount); //menambah waktu sesuai amount atau masukan

void printCurrentTime(time t);

void subtractTime(time *t, int amount); //mengurang waktu sesuai amount atau masukan

void subtractHeavyItem(time *, int amount);

void incrementTime(time *t);

void resetHeavyItem(time *t);

void addSpeedBoost(time *t);

void initReturnToSender(time *t);

void incrementReturnToSender(time *t);

void addHeavyItem(time *t, int amount);

void initCurrentMoney(time *t);

void addCurrentMoney(time *t, int reward);

void subtractCurrentMoney(time *t, int reward);


// typedef struct{
//     Stack bag;
//     linkedList toDoList;
//     linkedList inProgressList;
//     gadgetList inventory;
//     //ability
// }person;

#endif

