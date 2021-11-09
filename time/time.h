#include "../matrix/matrix.h"
#include "../stack/stack.h"
#include "../linkedlist/linkedlist.h"
#include "../locations/locations.h"
#include "../arraydin/arraydin.h"
#include "../arraystatis/arraystatis.h"
#include "../item/item.h"

typedef struct{
    float currentTime;
    float speedBoost;
    int heavyDuration;
}time;

#define currentTime(t) (t).currentTime
#define speedBoost(t) (t).speedBoost
#define heavyDuration(t) (t).heavyDuration



// typedef struct{
//     Stack bag;
//     linkedList toDoList;
//     linkedList inProgressList;
//     gadgetList inventory;
//     //ability
// }person;

