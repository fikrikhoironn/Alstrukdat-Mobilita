// File : stack.c
// stack.h implementation

#include "stack.h"

//Creates empty stack
void CreateStack(Stack *bag){
    IDX_TOP(*bag) = IDX_UNDEF;
    maxBag(*bag) = 3;
}

boolean isBagEmpty(Stack bag)
/* Mengirim true jika bag kosong */
{
    return IDX_TOP(bag) == IDX_UNDEF;
}

boolean isBagFull(Stack bag)
/* Mengirim true jika tabel penampung nilai bag stack penuh */
{
    return (IDX_TOP(bag) == maxBag(bag) || IDX_TOP(bag) == (CAPACITY - 1));
}

void pushBag(Stack *bag, item val)
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

void popBag(Stack *bag, item *val)
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
