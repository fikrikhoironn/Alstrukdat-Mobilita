#include "arraystatis.h"
#include <stdio.h>

int main(){
    time t;
    createTime(&t);
    addTime(&t, 100);
    initCurrentMoney(&t);
    addCurrentMoney(&t, 10000);
    addHeavyItem(&t, 20);

    item i;
    i = createItem(1, 'A', 'B', 'P', 10);
    perishableOrigin(i) = 20;

    item h;
    h = createItem(1, 'A', 'B', 'H', 0);

    stack bag;
    createStack(&bag);

    pushBag(&bag, i);
    pushBag(&bag, h);

    gadgetList g;
    createGadgetList(&g);

    BUY(&t, &g);
    INVENTORY(&g, &bag, &t);

    return 0;
}