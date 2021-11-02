/* File: command.h */
/* File for storing commands */

#ifndef command_H
#define command_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "../stack/stack.h"
#include "../linkedlist/linkedlist.h"

void PICK_UP(List ToDoList, List *InProgressList, Stack *Bag);
/*melakukan pick up dengan mencari apakah ada item di lokasi tersebut dengan mengecek pada to do list
jika ada, pick up masukkan ke bag dan update in progress list */

#endif /* command_H */