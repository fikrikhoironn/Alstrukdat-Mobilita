#include "../matrix/matrix.h"
#include "../stack/stack.h"
#include "../linkedlist/linkedlist.h"
#include "../locations/locations.h"
#include "../arraydin/arraydin.h"
#include "../arraystatis/arraystatis.h"
#include "../item/item.h"

typedef struct{
    int currentTime;
    int speedBoost;
    int heavyItem;
    int moveCount;
}time;

#define currentTime(t) (t).currentTime
#define speedBoost(t) (t).speedBoost
#define heavyItem(t) (t).heavyItem
#define moveCount(t) (t).moveCount

void createTime(time *t);

void incrementTime(time *t);

void resetHeavyItem(time *t);

void initMoveCount(time *t);

void addHeavyItem(time *t);


// typedef struct{
//     Stack bag;
//     linkedList toDoList;
//     linkedList inProgressList;
//     gadgetList inventory;
//     //ability
// }person;

