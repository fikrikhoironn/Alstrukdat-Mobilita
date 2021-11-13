// File : stack.c
// stack.h implementation

#include "stack.h"

//Creates empty stack
void createStack(stack *bag){
    IDX_TOP(*bag) = IDX_UNDEF_STACK;
    maxBag(*bag) = 3;
}

boolean isEmptyBag(stack bag)
/* Mengirim true jika bag kosong */
{
    return IDX_TOP(bag) == IDX_UNDEF_STACK;
}

boolean isFullBag(stack bag)
/* Mengirim true jika tabel penampung nilai bag stack penuh */
{
    return (IDX_TOP(bag) == maxBag(bag)-1 || IDX_TOP(bag) == (CAPACITY_STACK - 1));
}

void pushBag(stack *bag, item val)
/* Menambahkan val sebagai elemen Stack bag */
/* I.S. s mungkin kosong, tabel penampung elemen stack mungkin penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */
{   
    if (!isFullBag(*bag)){
        IDX_TOP(*bag)++;
        TOP(*bag) = val;
    }
    else{
        printf("Bag penuh\n");
    }
        
}

void popBag(stack *bag, item *val)
/* Menghapus val dari Stack bag */
/* I.S. bag  mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */
{
    if (!isEmptyBag(*bag)){
        *val = TOP(*bag);
        IDX_TOP(*bag)--;
    }
    else{
        printf("Bag kosong\n");
    }
    
}

void displayBag(stack bag){
    int i;
    for (i=IDX_TOP(bag); i>=0; i--){
        printf(" %d ", bag.buffer[i].timeIn);
        printf(" %c ", bag.buffer[i].pickUp);
        printf(" %c ", bag.buffer[i].dropOff);
        printf(" %c ", bag.buffer[i].typeItem);
        printf(" %d ", bag.buffer[i].perishableTime);
        printf(" %d\n", bag.buffer[i].perishableOrigin);
    }
}

