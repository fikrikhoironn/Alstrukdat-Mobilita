
/* File: command.c */
/* command.h implementation */

#include "command.h"



void PICK_UP(linkedList ToDoList, linkedList *InProgressList, Stack *Bag)
/*melakukan pick up dengan mencari apakah ada item di lokasi tersebut dengan mengecek pada to do list
jika ada, pick up masukkan ke bag dan update in progress list */
{
    //KAMUS LOKAL
    boolean exist;
    item val;
    int i;

    //ALGORITMA
      //melakukan searching pada toDoList apakah terdapat item di lokasi tersebut dan memasukkan ke bag;
    for (i = 0; i < lengthList(ToDoList); i++){
        if (isItemExist(ToDoList, mobita)){
            val = getElmtList(ToDoList, i);
            pushBag(Bag, val);
        }
            
    }
    

}