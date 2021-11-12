#include <stdio.h>
#include "stack.h"
#include "./item/item.h"

int main(){
    item elmt1, elmt2, elmt3, elmt4;
    elmt1 = createItem(1,'G','N','N', -1);
    elmt2 = createItem(2,'G','N','H', -1);
    elmt3 = createItem(3,'G','B','P','20');
    elmt4 = createItem(5,'C', 'D', 'N', 10);

    stack bag;
    createStack(&bag);
    pushBag(&bag, elmt1);
    pushBag(&bag, elmt2);
    pushBag(&bag, elmt3);
    pushBag(&bag, elmt4);

    displayBag(bag);
}