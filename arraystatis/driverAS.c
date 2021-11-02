#include "arraystatis.h"
#include <stdio.h>

int main(){
    int money = 10000; // Asumsi money awal

    gadgetList g;
    createGadgetList(&g);

    buyItem(&money, &g);
    useItem(&g);

    return 0;
}