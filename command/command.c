
/* File: command.c */
/* command.h implementation */

#include "command.h"




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

void DROP_OFF (linkedList *inprogress, stack *tas, time *t, map *map) {
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
                addCurrentMoney(t, 600);
                activateReturnToSender(); // Diasumsikan ada
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