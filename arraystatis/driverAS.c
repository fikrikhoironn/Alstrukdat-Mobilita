#include "arraystatis.h"
#include <stdio.h>

int main(){
    time t;
    createTime(&t);
    initCurrentMoney(&t);
    addCurrentMoney(&t, 10000);

    item i;
    i = createItem(1, 'A', 'B', 'P', 10);

    stack bag;
    createStack(&bag);

    pushBag(&bag, i);

    gadgetList g;
    createGadgetList(&g);

    buyItem(&t, &g);
    useItem(&g, &bag, &t);

    return 0;
}