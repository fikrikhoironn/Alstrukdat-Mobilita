
/* File: command.c */
/* command.h implementation */

#include "command.h"

void MOVE(time *mobiTime, ArrayBuild arrayOfBuilding, Matrix adjMatrix){
    printf("Posisi yang dapat dicapai:\n");
    int comd;
    char bcomd;
    int k=1;
    int locMob;
    ArrayBuild tmpBuild;
    CreateArrayBuild(&tmpBuild,arrayOfBuilding.capacity);
    int z = indexOfBuildMobita(*mobiTime,arrayOfBuilding);
    int i;
    for( i=0;i<NEFF(arrayOfBuilding);i++){
        if(isLocationConnected(adjMatrix,z,i)){
            printf("%d. %c (%d,%d)\n",k,arrayOfBuilding.nama[i],arrayOfBuilding.koor[i].col,arrayOfBuilding.koor[i].row);
            IsiArray(&tmpBuild,arrayOfBuilding.nama[i],arrayOfBuilding.koor[i].col,arrayOfBuilding.koor[i].row);
            k++;
        }
    }

    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n\n");
    printf("ENTER COMMAND: ");
        //ignoreBlank();
    advTokenStdin();
    //printf("---%d--\n",tokenToIntStd(currentToken));
    bcomd=currentToken.tokenArray[0];
    comd = (int) bcomd-'0';
    while ( !(0<=comd && comd<k) )
    {
        printf("\nLokasi Tak Tersediia\nENTER COMMAND: ");
        advTokenStdin();
        comd = tokenToIntStd(currentToken);
    }
    
    //printf("%d %d\n",k,comd);
    
    if(comd>0 && comd<k){
        //makeNeutral((mobitaLocation(*mobiTime).location));
        mobitaLocation(*mobiTime).location=arrayOfBuilding.koor[z].location;
        mobitaLocation(*mobiTime).col=tmpBuild.koor[comd-1].col;
        mobitaLocation(*mobiTime).row=tmpBuild.koor[comd-1].row;
        incrementTime(mobiTime);
        //makeMobita(tmpBuild.koor[comd-1].location);
    }else if(comd!=0) printf("Lokasi tidak ada...\n");

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
            printf("%d. ",i);
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
    }else{
        printf("TIDAK ADA PESANAN BERJALAN\n");
    }
}

void DROP_OFF (linkedList *todo, linkedList *inprogress, stack *tas, time *t, ArrayBuild arrBuild) {
    // KAMUS
    item delVal;

    // ALGORITMA
    if (!isEmptyBag(*tas)) {
        int z = indexOfBuildMobita(*t,arrBuild);
        if (TOP(*tas).dropOff == arrBuild.nama[z]) {
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
            else if (isVipItem(delVal)) {
                addCurrentMoney(t, 600);
                incrementReturnToSender(t); 
                printf("Pesanan VIP Item berhasil diantarkan\n");
                printf("Uang yang didapatkan : 600 Yen\n");
                printf("Anda memperoleh ability Return To Sender\n");
            }
            // Mengubah tampilan warna pada map
            //updateMap(map, *mobita.location);
            // Fungsi updateMap diasumsikan ada

            if (senterPengecil(*t)){ // senterPengecil!= 0
                if (! isHeavyItem(delVal)){
                    addHeavyItem(t, 1);
                }
                decrementSenterPengecil(t);
            } 
        }
        else {
            printf("Lokasi pengantaran tidak sesuai!\n");
        }
    }
    else {
        printf("Tidak terdapat pesanan yang dapat diantarkan!\n");
    }
}

void PICK_UP (linkedList *todo, linkedList *inprogress, stack *tas, time *t,ArrayBuild arrBuild) {
    // KAMUS
    Address pickedUp,checkVip;
    item delVal;
    boolean isLocOfVip;
    int i,z;
    // ALGORITMA
    
    isLocOfVip=false;
     z = indexOfBuildMobita(*t,arrBuild);
    /*
    checkVip =first(*todo);
    while((checkVip)!=NULL && !isLocOfVip){
        if(info(checkVip).typeItem=='V'){
            isLocOfVip=true;
            pickedUp =checkVip;
        }else{
            checkVip=next(checkVip);
        }
    }
    if(!isLocOfVip){
    pickedUp = find_by_pickup_location(*todo, arrBuild.nama[z]);
    }
    */
   pickedUp = find_by_pickup_location(*todo, arrBuild.nama[z]);

    if (pickedUp != NULL) {
        if (!isFullBag(*tas)) {
            if ((isVIPin(*todo) || isVIPin(*inprogress)) && info(pickedUp).typeItem!='V') {
                printf("Antar VIP Item terlebih dahulu!\n");
            }
            else {
                // Kondisi normal, item berhasil di pick up
                deleteAtList(todo, (indexOfList(*todo, info(pickedUp))), &delVal);
                perishableTime(delVal) = perishableOrigin(delVal);
                insert_timedescList(inprogress, delVal);
                pushBag(tas, delVal);
                printf("Pesanan berupa ");
                if (delVal.typeItem == 'N') {
                    printf("Normal ");
                }
                else if (delVal.typeItem == 'H') {
                    printf("Heavy ");
                    addHeavyItem(t, 1);
                }
                else if (delVal.typeItem == 'P') {
                    printf("Perishable ");
                }
                else if (delVal.typeItem == 'V') {
                    printf("VIP ");
                }
                printf("Item berhasil diambil!\n");
                printf("Tujuan Pesanan : %c\n", delVal.dropOff);
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
    printf("\n\b==================================================================================================================\n");
    printf("|| 1. MOVE         -> Untuk berpindah ke lokasi selanjutnya\t\t\t\t\t\t\t||\n");
    printf("|| 2. PICK_UP      -> Untuk mengambil item dilokasi saat ini\t\t\t\t\t\t\t||\n");
    printf("|| 3. DROP_OFF     -> Untuk mengantarkan item ke lokasi sesuai pesanan\t\t\t\t\t\t||\n");
    printf("|| 4. MAP          -> Untuk memunculkan peta\t\t\t\t\t\t\t\t\t||\n");
    printf("|| 5. TO_DO        -> Untuk menampilkan pesanan pada To Do List\t\t\t\t\t\t\t||\n");
    printf("|| 6. IN_PROGRESS  -> Untuk menampilkan pesanan yang sedang dikerjakan\t\t\t\t\t\t||\n");
    printf("|| 7. BUY          -> Untuk menampilkan gadget yang dapat dibeli lalu membelinya (Hanya pada headquarters)\t||\n");
    printf("|| 8. INVENTORY    -> Untuk melihat gadget yang dimiliki dan menggunakannya\t\t\t\t\t||\n");
    printf("|| 9. HELP         -> Untuk mengeluarkan list command dan kegunaannya\t\t\t\t\t\t||\n");
    printf("||10. EXIT         -> Untuk keluar dari permainan ketika permainan selesai                                      ||\n");
    printf("==================================================================================================================\n\n");
}

boolean EXIT(linkedList todo, linkedList inPorgress, time t,locationCoord hq)
// Mengembalikan true jika permainan selesai dan pemain bisa menang;
{
    if(!(isListEmpty(todo) || isListEmpty(inPorgress))){
        printf("HABISKAN PESANAN TERLEBIH DAHULU\n");
    }else if(!(mobitaLocation(t).col==hq.col && mobitaLocation(t).row==hq.row)){
        printf("PERGI KE HQ TERLEBIH DAHULU\n");
    }
    return isListEmpty(todo) && isListEmpty(inPorgress) && mobitaLocation(t).col==hq.col && mobitaLocation(t).row==hq.row;
}
