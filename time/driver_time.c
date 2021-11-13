#include <stdio.h>
#include "time.h"

int main(){
    time t;
    createTime(&t);
    incrementTime(&t);
    incrementTime(&t);
    incrementTime(&t);
    incrementTime(&t);
    incrementTime(&t);
    printf("setelah bergerak 5 kali sekarang waktu: ");
    printCurrentTime(t);
    addSpeedBoost(&t);
    printf("jumlah speed boost: %d\n", speedBoost(t));
    incrementTime(&t);
    printCurrentTime(t);
    printf("setelah bergerak 1 kali dan speedBoost sekarang waktu: ");
    printCurrentTime(t);
    incrementTime(&t);
    printf("setelah bergerak 1 kali dan speedBoost sekarang waktu: ");
    printCurrentTime(t);
    printf("jumlah speed boost: %d\n", speedBoost(t));
    printf("ditambah 1 heavyItem\n");
    addHeavyItem(&t, 1);
    incrementTime(&t);
    printf("setelah bergerak 1 kali dan heavyItem sekarang waktu: ");
    printCurrentTime(t);
    incrementTime(&t);
    printf("setelah bergerak 1 kali lagi dan heavyItem sekarang waktu: ");
    printCurrentTime(t);
    printf("ditambah 3 heavy item, total ada 4 heavy item\n");
    addHeavyItem(&t, 3);
    incrementTime(&t);
    printf("setelah bergerak 1 kali dan heavyItem sekarang waktu: ");
    printCurrentTime(t);

}