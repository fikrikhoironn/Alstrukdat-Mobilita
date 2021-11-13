#include "time.h"
#include <math.h>
#include <stdio.h>

void createTime(time *t){
    currentTime(*t) = 0;
    speedBoost(*t) = 0;
    heavyItem(*t) = 0;
    currentMoney(*t) = 0;
    returnToSender(*t) = 0;
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
    float currentTimeFloat = floor(currentTime(t));
    int my_var = (int)currentTimeFloat;
    printf("WAKTU SEKARANG: %d\n", my_var);
    // printf("%f\n", currentTimeFloat);
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

void updateToDoAndPerishable(time *t, linkedList *toDoList, linkedList *inProgressList,  Queue *daftarPesanan, stack *bag) //mengupdateToDoList dan perishableTime sesuai waktu sekarang
{
    int i;
    //untuk memasukkan daftar pesanan ke toDoList jika sesuai waktu
    for (i = IDX_HEAD (*daftarPesanan); i <= IDX_TAIL(*daftarPesanan); i++)
    {
        /* code */
        item val;
        val = daftarPesanan->buffer[i];
        if (timeIn(val) >= currentTime(*t)){
            insert_timeascList(toDoList, val);
        }
    }
    //menghapus perishable item jika waktunya sudah hangus dan mengurangi sisa waktu perishable item
    if (!isListEmpty(inProgressList)){
        Address p = first(inProgressList);
        int idx = 0;
        while (p != NULL){
            item val;
            if (typeItem(info(p)) == 'P'){
                decrementPerishableTime(&info(p));
            }
            if (typeItem(info(p)) == 'P' && perishableTime(info(p)) <= 0){
                deleteAtList(inProgressList, idx, &val);

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
            pushBag(&temp, val);
        }
        else if((typeItem(val) != 'P')){
            pushBag(&temp, val);
        }
    }
    while(!isEmptyBag(temp)){ //memindahkan dari stack sementara ke bag awal
        item val2;
        popBag(&temp, &val2);
        pushBag(bag, val2);
    }
    

}

