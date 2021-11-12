#include "../matrix/matrix.h"
#include "../stack/stack.h"
#include "../linkedlist/linkedlist.h"
#include "../locations/locations.h"
#include "../arraydin/arraydin.h"
#include "../arraystatis/arraystatis.h"
#include "../item/item.h"
#include "boolean.h"

typedef struct{
    int currentTime;
    int speedBoost;
    int heavyItem;
    int moveCount;
    int currentMoney;
    int returnToSender;
}time;

#define currentTime(t) (t).currentTime
#define speedBoost(t) (t).speedBoost
#define heavyItem(t) (t).heavyItem
#define moveCount(t) (t).moveCount
#define currentMoney(t) (t).currentMoney
#define returnToSender(t) (t).returnToSender

void createTime(time *t);

void addTime(time *t, int amount); //menambah waktu sesuai amount atau masukan

void subtractTime(time *t, int amount); //mengurang waktu sesuai amount atau masukan

void decrementHeavyItem(time *t);

void incrementTime(time *t);

void resetHeavyItem(time *t);

void initMoveCount(time *t);

void initReturnToSender(time *t);

void incrementReturnToSender(time *t);

void addHeavyItem(time *t);

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

