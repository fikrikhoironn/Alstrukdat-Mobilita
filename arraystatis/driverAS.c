#include "arraystatis.h"
#include <stdio.h>

int main(){
    time t;
    createTime(&t);
    initCurrentMoney(&t);
    addCurrentMoney(&t, 10000);

    gadgetList g;
    createGadgetList(&g);

    buyItem(&t, &g);
    useItem(&g);

    return 0;
}