#include "arraystatis.h"
#include <stdio.h>
#include <stdlib.h>

// Mengisi gadgetList dengan VAL_UNDEF
void createGadgetList(gadgetList *g){
    int i;
    for (i = 0; i < MAX_CAPACITY; i++){
        ELEMENT(*g, i) = VAL_UNDEF;
    }
}

// Return true jika gadgetList penuh
boolean isFull(gadgetList g){
    int i;
    for (i = 0; i < MAX_CAPACITY; i++){
        if (ELEMENT(g,i) == VAL_UNDEF){
            return false;
        }
    }
    return true;
}

// Return true jika gadgetList kosong
boolean isEmpty(gadgetList g){
    int i;
    for (i = 0; i < MAX_CAPACITY; i++){
        if (ELEMENT(g, i) != VAL_UNDEF){
            return false;
        }
    }
    return true;
}

// Prosedur BUY
void BUY(time *money, gadgetList *g, ArrayBuild arrBuild){

    // Mengecek lokasi Mobita (harus di HQ)
    int z=0;
    while(z<NEFF(arrBuild)&& (TITIK(arrBuild,z).row!=mobitaLocation(*money).row || TITIK(arrBuild,z).col !=mobitaLocation(*money).col)){
      z++;
    }

    if (arrBuild.nama[z] == '8'){
        int command;

        if (!isFull(*g)){ // cek inventory awal
            do {
                printf("Uang Anda sekarang: %d Yen\n", currentMoney(*money));
                printf("Gadget yang tersedia:\n");
                printf("1. Kain Pembungkus Waktu (800 Yen)\n");
                printf("2. Senter Pembesar (1200 Yen)\n");
                printf("3. Pintu Kemana Saja (1500 Yen)\n");
                printf("4. Mesin Waktu (3000 Yen)\n");
                printf("5. Senter Pengecil (800 Yen)\n");
                printf("Gadget mana yang ingin kau beli? (ketik 0 jika ingin kembali)\n");

                getCommand(&command, 0, 5);

                // command yang dimasukkan pasti valid (0..5)
                if (command != 0){
                    if (isMoneySufficient(*money, command)){
                        addGadget(g, command);
                        subtractCurrentMoney(money, gadgetPrice(command));
                        displayBuySuccess(command);
                        printf("Uang Anda sekarang: %d Yen\n", currentMoney(*money));
                    } else {
                        printf("Uang tidak cukup untuk membeli gadget!\n");
                    }
                    printf("\nLanjut membeli?\n");
                    printf("1. Ya\n");
                    printf("2. Tidak\n");

                    getCommand(&command, 1, 2);
                    printf("\n");

                    command -= 2; 
                }
            } while (command != 0 && !isFull(*g));
            if (isFull(*g)){
                printf("Inventory sudah penuh. Kembali...\n"); 
            } else {
                printf("Kembali...\n"); 
            }
        } else {
            printf("Inventory sudah penuh. Kembali...\n");
        }
    } else {
        printf("Tidak dapat membeli di luar Headquarter!\n");
    }

    
    
}

// Pesan kalau buy berhasil
void displayBuySuccess(int gadgetType){
    if (gadgetType == 1){
        printf("Kain Pembungkus Waktu berhasil dibeli!\n");
    } else if (gadgetType == 2){
        printf("Senter Pembesar berhasil dibeli!\n");
    } else if (gadgetType == 3){
        printf("Pintu Kemana Saja berhasil dibeli!\n");
    } else if (gadgetType == 4){
        printf("Mesin Waktu berhasil dibeli!\n");
    } else {
        printf("Senter Pengecil berhasil dibeli!\n");
    }
}

// Prosedur INVENTORY
void INVENTORY(gadgetList *g, stack *bag, time *t, linkedList toDoList, Matrix m, ArrayBuild arrBuild, int x , int y){

    int command;
    if (! isEmpty(*g)){ // Cek inventory kosong
        do {
            displayGadgetList(*g);
            printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");

            getCommand(&command, 0, 5);

            // command pasti valid (0..5)
            if (command != 0){
                int gadgetType;
                removeGadget(g, command - 1, &gadgetType); // command == index + 1
                if (gadgetType != VAL_UNDEF){
                    useGadget(gadgetType, bag, t, toDoList, m, arrBuild, x , y);
                }
                if (! isEmpty(*g)){
                    printf("\nLanjut memakai?\n");
                    printf("1. Ya\n");
                    printf("2. Tidak\n");

                    getCommand(&command, 1, 2);
                    printf("\n");

                    command -= 2; 
                }
            } 
        } while (command != 0 && ! isEmpty(*g));
        if (isEmpty(*g)){
            printf("Inventory kosong. Kembali...\n");
        } else{
            printf("Kembali...\n");
        }
    } else {
        printf("Inventory kosong. Kembali...\n");
    }
    
    
}

// Print isi gadgetList
void displayGadgetList(gadgetList g){
    int i;
    for(i = 0; i < MAX_CAPACITY; i++){
        printf("%d. ", i + 1);
        if (ELEMENT(g, i) == VAL_UNDEF){
            printf("-\n");
        } else {
            if (ELEMENT(g, i) == 1){
                printf("Kain Pembungkus Waktu\n");
            } else if (ELEMENT(g, i) == 2){
                printf("Senter Pembesar\n");
            } else if (ELEMENT(g, i) == 3){
                printf("Pintu Kemana Saja\n");
            } else if (ELEMENT(g,i) == 4){
                printf("Mesin Waktu\n");
            } else { // ELEMENT(g,i) == 5
                printf("Senter Pengecil\n");
            }
        }
    }
}

// Memasukkan gadget ke dalam INVENTORY
void addGadget(gadgetList *g, int gadgetType){
    boolean find = false;
    int i = 0;

    while (i < MAX_CAPACITY && ! find){
        if (ELEMENT(*g, i) == VAL_UNDEF){
            find = true;
            ELEMENT(*g, i) = gadgetType;
        } else {
            i++;
        }
    }
}

// Menghapus gadget sesuai index
void removeGadget(gadgetList *g, int index, int *gadgetType){
    if (ELEMENT(*g, index) != VAL_UNDEF){
        *gadgetType = ELEMENT(*g, index);
        ELEMENT(*g, index) = VAL_UNDEF;
    } else {
        printf("Tidak ada Gadget yang dapat digunakan!\n");
        *gadgetType = VAL_UNDEF;
    }
}

// Return harga gadget
int gadgetPrice(int gadgetType){
    if (gadgetType == 1){
        return 800;
    } else if (gadgetType == 2){
        return 1200;
    } else if (gadgetType == 3){
        return 1500;
    } else if (gadgetType == 4){ 
        return 3000;
    } else { // gadgetType == 5
        return 800;
    }
}

// Return true jika uang cukup
boolean isMoneySufficient(time money, int gadgetType){
    return currentMoney(money) >= gadgetPrice(gadgetType);
}

// Better input selector
void getCommand(int *a, int lower_border, int upper_border){
    char b;
    printf("\nENTER COMMAND: ");
    if (scanf("%d%c", a,&b) == 2 && b == '\n' && (*a <= upper_border) && (*a >= lower_border)){
        
    } else {
        printf("Command salah, Ulangi!\n");
        fflush(stdin);
        getCommand(a, lower_border, upper_border);
    }
}

// Prosedur pemakaian gadget
void useGadget(int gadgetType, stack *bag, time *t, linkedList toDoList, Matrix m, ArrayBuild arrBuild, int x , int y){
    if (gadgetType == 1){
        if (isPerishableItem(TOP(*bag))) {
            perishableTime(TOP(*bag)) = perishableOrigin(TOP(*bag));
        } // else do nothing
        printf("Kain Pembungkus Waktu berhasil digunakan!\n");
    } else if (gadgetType == 2){
        maxBag(*bag) *= 2;
        if (maxBag(*bag) > CAPACITY_STACK){
            maxBag(*bag) = CAPACITY_STACK;
        }
        printf("                      _.----.\n");
        printf("    .----------------\" /  /  \\ \n");
        printf("   (     BIG LASER   | |  |)  |\n");
        printf("    `----------------._\\  \\  /\n");
        printf("                       \"----'\n");
        printf("Senter Pembesar berhasil digunakan!\n");
    } else if (gadgetType == 3){
        printMap(toDoList, m, arrBuild, x, y, *t, *bag);
        printf("Ingin pindah kemana?\n");
        
        int k=1;
        int locMob;
        ArrayBuild tmpBuild;
        CreateArrayBuild(&tmpBuild,arrBuild.capacity);
        int z = indexOfBuildMobita(*t,arrBuild);
        int i;
        for( i=0;i<NEFF(arrBuild);i++){
            printf("%d. %c (%d,%d)\n",k,arrBuild.nama[i],arrBuild.koor[i].col,arrBuild.koor[i].row);
            IsiArray(&tmpBuild,arrBuild.nama[i],arrBuild.koor[i].col,arrBuild.koor[i].row);
            k++;
        }

        printf("Posisi yang dipilih?\n"); // bisa teleport ke lokasi awal / terbuang sia - sia
        int comd;
        getCommand(&comd, 1, k - 1);
        
        mobitaLocation(*t).location=arrBuild.koor[z].location;
        mobitaLocation(*t).col=tmpBuild.koor[comd-1].col;
        mobitaLocation(*t).row=tmpBuild.koor[comd-1].row;

        printf("Pintu Kemana Saja berhasil digunakan!\n");
    } else if (gadgetType == 4){ 
        subtractTime(t, 50);
        if (currentTime(*t) < 0) {
            currentTime(*t) = 0;
        } 
        printf("Mesin Waktu berhasil digunakan!\n");
    } else { // gadgetType == 5
        if (isHeavyItem(TOP(*bag))) {
            subtractHeavyItem(t, 1);
            incrementSenterPengecil(t);
        } 
        if (heavyItem(*t) < 0){
            heavyItem(*t) = 0;
        }
        printf("                      _.----.\n");
        printf("    .----------------\" /  /  \\ \n");
        printf("   (    smol laser   | |  |)  |\n");
        printf("    `----------------._\\  \\  /\n");
        printf("                       \"----'\n");
        printf("Senter Pengecil berhasil digunakan!\n");
    }
}