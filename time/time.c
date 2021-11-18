#include "time.h"
#include <math.h>
#include <stdio.h>

void displayStatus(time t, ArrayBuild arrBuild){
    int z=0;
    while(z<NEFF(arrBuild)&& (TITIK(arrBuild,z).row!=mobitaLocation(t).row || TITIK(arrBuild,z).col !=mobitaLocation(t).col)){
      z++;
    }
    printf("\nMobita sekarang berada di titik %s%c%s (%d,%d)%s!\n",YELLOW,arrBuild.nama[z],MAGENTA,mobitaLocation(t).col,mobitaLocation(t).row,NORMAL);
    printf("%s",GREEN);
    printCurrentTime(t);
    printf("%s",RED);
    printf("JUMLAH UANG: %d\n", currentMoney(t));
    printf("%s",NORMAL);
    printf("HEAVY ITEM: %d || SPEEDBOOST: %d || RETURN TO SENDER: %d || SENTER PENGECIL: %d\n\n", heavyItem(t), speedBoost(t), returnToSender(t), senterPengecil(t));
}


void createTime(time *t,locationCoord base){
    currentTime(*t) = 0;
    speedBoost(*t) = 0;
    heavyItem(*t) = 0;
    currentMoney(*t) = 0;
    returnToSender(*t) = 0;
    senterPengecil(*t) = 0;
    mobitaLocation(*t)=base;
}

void incrementTime(time *t){
    if(speedBoost(*t) > 0 && heavyItem(*t) == 0){
        speedBoost(*t) -= 1;
        currentTime(*t) += 0.5;
    }
    else if(heavyItem(*t) > 0){ // 
        currentTime(*t) += heavyItem(*t) +1;
        speedBoost(*t) = 0; //reset speedBoost
    }
    
    else{
        currentTime(*t) += 1;
        
    }
    
}

void printCurrentTime(time t){
    int my_var = (int) floor(currentTime(t));
    printf("WAKTU SEKARANG: %d\n", my_var);
}

void addTime(time *t, int amount){
    currentTime(*t) += amount;
}

void subtractTime(time *t, int amount){
    currentTime(*t) -= amount;
}

void addSpeedBoost(time *t){
    speedBoost(*t) += 10;
}

void addHeavyItem(time *t, int amount){
    heavyItem(*t) += amount;
}

void subtractHeavyItem(time *t, int amount){
    heavyItem(*t) -= amount;
}

void resetHeavyItem(time *t){
    heavyItem(*t) = 0;
}

void initCurrentMoney(time *t){
    currentMoney(*t) = 0;
}

void addCurrentMoney(time *t, int reward){
    currentMoney(*t) += reward;
}

void subtractCurrentMoney(time *t, int cost){
    currentMoney(*t) -= cost;
}

void initReturnToSender(time *t){
    returnToSender(*t) = 0;
}

void incrementReturnToSender(time *t){
    returnToSender(*t)++;
}

void decrementReturnToSender(time *t){
    returnToSender(*t)--;
}

void incrementSenterPengecil(time *t){
    senterPengecil(*t)++;
}

void decrementSenterPengecil(time *t){
    senterPengecil(*t)--;
}

void updateToDoAndPerishable(time *t, linkedList *toDoList, linkedList *inProgressList,  Queue *daftarPesanan, stack *bag) //mengupdateToDoList dan perishableTime sesuai waktu sekarang
{
    int i;
    

    int my_var = (int) floor(currentTime(*t));
    while(timeIn(HEAD(*daftarPesanan)) <= my_var && !isOneElmtQueue(*daftarPesanan) && !isEmptyQueue(*daftarPesanan)){
        item val;
        dequeue(daftarPesanan, &val);
        insert_timeascList(toDoList, val); 
    }

    if(!isEmptyQueue(*daftarPesanan)){
        if(timeIn(HEAD(*daftarPesanan))<=my_var){
        item val;
        dequeue(daftarPesanan,&val);
        insert_timeascList(toDoList,val);
        }
    }

    //menghapus perishable item jika waktunya sudah hangus dan mengurangi sisa waktu perishable item
    if (!isListEmpty(*inProgressList)){
        Address p = first(*inProgressList);
        int idx = 0;
        while (p != NULL){
            item val;
            if (typeItem(info(p)) == 'P'){
                perishableTime(info(p)) = perishableTime(info(p)) - heavyItem(*t) - 1;

            }
            if (typeItem(info(p)) == 'P' && perishableTime(info(p)) <= 0){
                deleteAtList(inProgressList, idx, &val);
                printf("Perishable item tujuan dropOff %c telah hangus\n", dropOff(info(p)));

            }
            p = next(p);
            idx++;
        }
    }
    //update bag, menghapus perishable item jika sudah hangus dari bag
    stack temp;
    createStack(&temp);
    while (!isEmptyBag(*bag)){ //menfilter perishable item
        item val;
        popBag(bag, &val); //menyimpan yang lolos filter ke stack sementara
        if ((typeItem(val) == 'P') && perishableTime(val) > 0){
            decrementPerishableTime(&val);
            if (perishableTime(val) > 0){
                pushBag(&temp, val);
            }
        }
        else if((typeItem(val) != 'P')){
            pushBag(&temp, val);
        }
        if ((typeItem(val) == 'P') && perishableTime(val) <= 0){
            printf("Perishable item tujuan %c telah dihapus\n", dropOff(val));
        }

    }
    while(!isEmptyBag(temp)){ //memindahkan dari stack sementara ke bag awal
        item val2;
        popBag(&temp, &val2);
        pushBag(bag, val2);
    }
    

}

int indexOfBuildMobita(time t, ArrayBuild arrBuild){
    int z=0;
    while(z<NEFF(arrBuild)&& (TITIK(arrBuild,z).row!=mobitaLocation(t).row || TITIK(arrBuild,z).col !=mobitaLocation(t).col)){
      z++;
    }
    return z;
}
