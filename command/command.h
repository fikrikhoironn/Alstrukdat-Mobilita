/* File: command.h */
/* File for storing commands */

#ifndef command_H
#define command_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "../stack/stack.h"
#include "../linkedlist/linkedlist.h"

void MOVE();

void PICK_UP(linkedList ToDoList, linkedList *InProgressList, stack *Bag);
/*melakukan pick up dengan mencari apakah ada item di lokasi tersebut dengan mengecek pada to do list
jika ada, pick up masukkan ke bag dan update in progress list */

void TO_DO (linkedList todo);

void IN_PROGRESS (linkedList inprogress);


#endif /* command_H */

