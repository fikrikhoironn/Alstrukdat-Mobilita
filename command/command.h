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
#include "../arraydin/arraydin.h"
#include "../matrix/matrix.h"
#include "../point/point.h"
#include "../mesinKata/mesin.h"

void MOVE(time *mobiTime, ArrayBuild arrayOfBuilding, Matrix adjMatrix);
/*
void TO_DO (linkedList todo);

void IN_PROGRESS (linkedList inprogress);

void DROP_OFF (linkedList *todo, linkedList *inprogress, stack *tas, time *t);
// Diasumsikan terdapat adt person bernama mobita yang memiliki komponen money
// Diasumsikan terdapat adt map
// Memindahkan item dari in progress list dan melakukan pop item dari tas

void PICK_UP (linkedList *todo, linkedList *inprogress, stack *tas, time t);
// Memindahkan item dari to do list ke in progress list dan melakukan push item ke dalam tas

void HELP();
*/

#endif /* command_H */

