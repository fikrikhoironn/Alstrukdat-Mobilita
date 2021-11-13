/* File: command.h */
/* File for storing commands */

#ifndef command_H
#define command_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "../stack/stack.h"
#include "../linkedlist/linkedlist.h"
#include "../ability/ability.h"



void TO_DO (linkedList todo);

void IN_PROGRESS (linkedList inprogress);

void DROP_OFF (linkedList *todo, linkedList *inprogress, stack *tas, person *mobita, time *t, map *map);
// Diasumsikan terdapat adt person bernama mobita yang memiliki komponen money
// Diasumsikan terdapat adt map
// Memindahkan item dari in progress list dan melakukan pop item dari tas


#endif /* command_H */

