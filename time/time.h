#ifndef TIME_H
#define TIME_H

#include "boolean.h"
#include <math.h>
#include "../linkedlist/linkedlist.h"
#include "../queue/queue.h"
#include "../stack/stack.h"
#include "../point/point.h"

typedef struct{
    float currentTime;
    int speedBoost;
    int heavyItem;
    int currentMoney;
    int returnToSender;
    int senterPengecil; 
    locationCoord currentLocation;
}time;

#define currentTime(t) (t).currentTime
#define speedBoost(t) (t).speedBoost
#define heavyItem(t) (t).heavyItem
#define currentMoney(t) (t).currentMoney
#define returnToSender(t) (t).returnToSender
#define senterPengecil(t) (t).senterPengecil
#define mobitaLocation(t) (t).currentLocation

void displayStatus(time t);

void createTime(time *t); //membuat state waktu sesuai amount atau masukan

void addTime(time *t, int amount); //menambah waktu sesuai amount atau masukan

void printCurrentTime(time t); //menampilkan state sekarang

void subtractTime(time *t, int amount); //mengurang waktu sesuai amount atau masukan

void subtractHeavyItem(time *, int amount); //mengurangi heavy item sesuai masukan berupa heavy item yang di drop

void incrementTime(time *t); //melakukan increment waktu sesuai spek

void resetHeavyItem(time *t); 

void addSpeedBoost(time *t); //menambah speedboost 10 unit

void initReturnToSender(time *t); 

void incrementReturnToSender(time *t); //menambah waktu returnToSender sejumlah 1

void decrementReturnToSender(time *t); //mengurangi returnToSender sejumlah 1

void addHeavyItem(time *t, int amount); //menambah heavy item sesuai masukan berupa jumlah heavy item yang dipick

void initCurrentMoney(time *t);

void addCurrentMoney(time *t, int reward); //menambah jumlah uang sesuai reward

void subtractCurrentMoney(time *t, int reward); //mengurangi jumlah uang sesuai pengeluaran pembelian gadget

void incrementSenterPengecil(time *t); // menambah senterPengecil sebanyak 1

void decrementSenterPengecil(time *t); // mengurangi senterPengecil sebanyak 1

void updateToDoAndPerishable(time *t, linkedList *toDoList, linkedList *inProgressList, Queue *daftarPesanan, stack *bag); //mengupdateToDoList sesuai waktu sekarang


#endif

