
/* File: command.c */
/* command.h implementation */

#include "command.h"

void MOVE(locationCoord *mobitaLoc, ArrayBuild arrayOfBuilding, Matrix adjMatrix){
    printf("Posisi yang dapat dicapai:\n");
    int k=1;
    int locMob;
    ArrayBuild tmpBuild;
    CreateArrayBuild(&tmpBuild,arrayOfBuilding.capacity);
    for(int i=0;i<=NEFF(arrayOfBuilding);i++){
        if((*mobitaLoc).col==arrayOfBuilding.koor[i].col && (*mobitaLoc).row==arrayOfBuilding.koor[i].row){
            locMob=i;
        }
    }
    for(int i=0;i<NEFF(arrayOfBuilding);i++){
        if(isLocationConnected(adjMatrix,locMob,i)){
            printf("%d. %c (%d,%d)\n",k,arrayOfBuilding.nama[i],arrayOfBuilding.koor[i].col,arrayOfBuilding.koor[i].row);
            IsiArray(&tmpBuild,arrayOfBuilding.nama[i],arrayOfBuilding.koor[i].col,arrayOfBuilding.koor[i].row);
        }
    }
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n\n");
    printf("ENTER COMMAND: ");
    int comd = tokenToInt(currentToken);
    if(comd!=0){
        (*mobitaLoc).col=tmpBuild.koor[comd-1].col;
        (*mobitaLoc).row=tmpBuild.koor[comd-1].row;
        makeNeutral(&((*mobitaLoc).location));
        makeMobita(tmpBuild.koor[comd-1].location);
    }

}


void TO_DO (linkedList todo) {
    // KAMUS
    Address p;
    int i;

    // ALGORITMA
    if (!isListEmpty(todo)) {
        p = first(todo);
        i = 1;

        printf("Pesanan pada To Do List:\n");
        while (p != NULL) {
            printf("%d. %c -> %c ", i, pickUp(info(p)), dropOff(info(p)));
            if (typeItem(info(p)) == 'N') {
                printf("(Normal Item)\n");
            }
            else if (typeItem(info(p)) == 'P') {
                printf("(Perishable Item)\n");
            }
            else if (typeItem(info(p)) == 'H') {
                printf("(Heavy Item)\n");
            }
            else if (typeItem(info(p)) == 'V') {
                printf("(VIP Item)\n");
            }
            
            p = next(p);
            i++;
        }
    }
    else {
        printf("To Do List kosong.\n");
    }
}

void IN_PROGRESS (linkedList inprogress) {
    // KAMUS
    Address p;
    int i;

    // ALGORITMA
    if (!isListEmpty(inprogress)) {
        p = first(inprogress);
        i = 1;

        printf("Pesanan yang sedang diantarkan:\n");
        while (p != NULL) {
            printf("%d. ");
            if (typeItem(info(p)) == 'N') {
                printf("Normal Item ");
            }
            else if (typeItem(info(p)) == 'P') {
                printf("Perishable Item ");
            }
            else if (typeItem(info(p)) == 'H') {
                printf("Heavy Item ");
            }
            else if (typeItem(info(p)) == 'V') {
                printf("VIP Item ");
            }
            printf("(Tujuan: %c)\n", dropOff(info(p)));

            p = next(p);
            i++;
        }
    }
}

void DROP_OFF (linkedList *todo, linkedList *inprogress, stack *tas, time *t, map *map) {
    // KAMUS
    item delVal;

    // ALGORITMA
    if (!isEmptyBag(*tas)) {
        if (TOP(*tas).dropOff == *mobita.location) {
            // Diasumsikan adt mobita memiliki komponen location
            // Lokasi drop off pada top dari stack tas sama dengan lokasi mobita saat ini
            deleteAtList(inprogress, (indexOfList(*inprogress, TOP(*tas))), &delVal);
            popBag(tas, &delVal);
            if (isNormalItem(delVal)) {
                addCurrentMoney(t, 200);
                printf("Pesanan Normal Item berhasil diantarkan\n");
                printf("Uang yang didapatkan : 200 Yen\n");
            }
            else if (isHeavyItem(delVal)) {
                addCurrentMoney(t, 400);
                activateSpeedBoost(t);
                subtractHeavyItem(t, 1);
                printf("Pesanan Heavy Item berhasil diantarkan\n");
                printf("Uang yang didapatkan : 400 Yen\n");
                printf("Anda memperoleh ability Speed Boost\n");
            }
            else if (isPerishableItem(delVal)) {
                // Waktu hangus dari perishable item < waktu mobita
                addCurrentMoney(t, 400);
                increaseCapactiy(tas);
                printf("Pesanan Perishable Item berhasil diantarkan\n");
                printf("Uang yang didapatkan : 400 Yen\n");
                printf("Anda memperoleh ability Increase Capacity\n");
            }
            else if (isVIPItem(delVal)) {
                *mobita.money += 600;
                activateReturnToSender(tas, todo, inprogress, *t); 
                printf("Pesanan VIP Item berhasil diantarkan\n");
                printf("Uang yang didapatkan : 600 Yen\n");
                printf("Anda memperoleh ability Return To Sender\n");
            }
            // Mengubah tampilan warna pada map
            updateMap(map, *mobita.location);
            // Fungsi updateMap diasumsikan ada
        }
        else {
            printf("Lokasi pengantaran tidak sesuai!\n");
        }
    }
    else {
        printf("Tidak terdapat pesanan yang dapat diantarkan!\n");
    }
}

void PICK_UP (linkedList *todo, linkedList *inprogress, stack *tas, person *mobita) {
    // KAMUS
    Address pickedUp;
    item delVal;

    // ALGORITMA
    pickedUp = find_by_pickup_location(*todo, *mobita.location);
    if (pickedUp != NULL) {
        if (!isFullBag(*tas)) {
            if (isVIPin(*todo) && info(pickedUp).typeItem != 'V') {
                printf("Pick up VIP Item terlebih dahulu!\n");
            }
            else {
                // Kondisi normal, item berhasil di pick up
                deleteAtList(*todo, (indexOfList(todo, info(pickedUp))), &delVal);
                insert_timedescList(inprogress, delVal);
                pushBag(tas, delVal);
                // Ganti warna map
            }
        }
        else {
            printf("Tas penuh!\n");
        }
    }
    else {
        printf("Tidak ada item untuk di-pick up!\n");
    }
}

void HELP(){
    printf("1.\tMOVE -> Untuk berpindah ke lokasi selanjutnya.\n");
    printf("2.\tPICL_UP -> Untuk mengamvil item di lokasi saat ini.\n");
    printf("3.\tDROP_OFF -> Untuk mengantarkan item ke lokasi jika item di tumpukan teratas sesuai dengan pesanan.\n");
    printf("4.\tMAP -> untuk menampilkan peta saat ini.\n");
    printf("5.\tTO_DO -> Untuk menampilkan pesanan yang masuk ke To Do List.\n");
    
}