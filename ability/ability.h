#ifndef ABILITY_H
#define ABILITY_H

#include "../time/time.h"
#include "../stack/stack.h"
#include "../linkedlist/linkedlist.h"
#include "../item/item.h"
#include "boolean.h"

void activateSpeedBoost(time *t); //mengaktifasi speedboost dengan menambahkan jumlah speedboost

void increaseCapactiy(stack *bag); //meningkatkan kapasitas tas

void activateReturnToSender(stack *bag, linkedList *toDoList, linkedList *inProgressList, time *t); 
//mengaktifasi return to sender

#endif