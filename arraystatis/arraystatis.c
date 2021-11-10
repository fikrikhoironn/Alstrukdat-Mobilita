#include "arraystatis.h"
#include <stdio.h>
#include <stdlib.h>

// Konstruktor
void createGadgetList(gadgetList *g){
    int i;
    for (i = 0; i < CAPACITY; i++){
        ELMT(*g, i) = VAL_UNDEF;
    }
}
// I.S sembarang
// F.S mengisi gadgetList dengan VAL_UNDEF

boolean isFullInventory(gadgetList g){
    int i;
    for (i = 0; i < CAPACITY; i++){
        if (ELMT(g,i) == VAL_UNDEF){
            return false;
        }
    }
    return true;
}

boolean isEmptyInventory(gadgetList g){
    int i;
    for (i = 0; i < CAPACITY; i++){
        if (ELMT(g, i) != VAL_UNDEF){
            return false;
        }
    }
    return true;
}

// Fungsi/Prosedur

void buyItem(int *money, gadgetList *g){

    int command;

    if (!isFull(*g)){ // cek inventory awal
        do {
            printf("Uang Anda sekarang: %d Yen\n", *money);
            printf("Gadget yang tersedia:\n");
            printf("1. Kain Pembungkus Waktu (800 Yen)\n");
            printf("2. Senter Pembesar (1200 Yen)\n");
            printf("3. Pintu Kemana Saja (1500 Yen)\n");
            printf("4. Mesin Waktu (3000 Yen)\n");
            printf("Gadget mana yang ingin kau beli? (ketik 0 jika ingin kembali)\n");

            printf("\nENTER COMMAND: ");

            scanf("%d", &command);

            while (command > 4 || command < 0){ // command tidak valid
                printf("Command salah, ulangi!\n");
                printf("\nENTER COMMAND: ");
                scanf("%d", &command);
            }

            // command yang dimasukkan pasti valid (0..4)
            if (command != 0){
                if (isMoneySufficient(*money, command)){
                    addGadget(g, command);
                    *money -= gadgetPrice(command);
                    printf("Uang Anda sekarang: %d Yen\n", *money);
                } else {
                    printf("Uang tidak cukup untuk membeli gadget!\n");
                }
                printf("Lanjut membeli?(ketik 0 untuk kembali ke main menu/ketik angka bebas untuk lanjut)\n");

                printf("\nENTER COMMAND: ");
                scanf("%d", &command);
            }
        } while (command != 0 && !isFull(*g));
        if (isFull(*g)){
            printf("Inventory sudah penuh. Kembali ke main menu!\n"); 
        } else {
            printf("Kembali ke main menu!\n"); // Pengganti sementara fungsi ke main menu
        }
    } else {
        printf("Inventory sudah penuh. Kembali ke main menu!\n");
    }
    
}
// Prekondisi gadgetList tidak penuh
// I.S money dan gadgetList terdefinisi
// F.S jika money cukup -> item dimasukkan ke dalam gadgetList
//     else -> I.S
// panggil untuk membeli gadget *satu kali*

void useItem(gadgetList *g){

    int command;
    if (! isEmpty(*g)){
        do {
            displayGadgetList(*g);
            printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");

            printf("\nENTER COMMAND: ");
            
            scanf("%d", &command);

            while (command > 5 || command < 1){ // command tidak valid
                printf("Command salah, ulangi!\n");
                printf("\nENTER COMMAND: ");
                scanf("%d", &command);
            }

            // command pasti valid (1..5)
            if (command != 0){
                int gadgetType;
                removeGadget(g, command - 1, &gadgetType); // command == index + 1
                if (gadgetType != VAL_UNDEF){
                    useGadget(gadgetType);
                }

                printf("Lanjut membeli?(ketik 0 untuk kembali ke main menu/ketik angka bebas untuk lanjut)\n");

                printf("\nENTER COMMAND: ");
                scanf("%d", &command);

            } 
        } while (command != 0 && ! isEmpty(*g));
        if (isEmpty(*g)){
            printf("Inventory kosong. Kembali ke main menu!\n");
        } else{
            printf("Kembali ke main manu!\n"); // Pengganti sementara fungsi ke main menu
        }
    } else {
        printf("Inventory kosong. Kembali ke main menu!\n");
    }
    
    
}
// I.S gadgetList terdefinisi
// F.S gadgetList berkurang (jika instruksi benar)

void displayGadgetList(gadgetList g){
    int i;
    for(i = 0; i < CAPACITY; i++){
        printf("%d. ", i + 1);
        if (ELMT(g, i) == VAL_UNDEF){
            printf("-\n");
        } else {
            if (ELMT(g, i) == 1){
                printf("Kain Pembungkus Waktu\n");
            } else if (ELMT(g, i) == 2){
                printf("Senter Pembesar\n");
            } else if (ELMT(g, i) == 3){
                printf("Pintu Kemana Saja\n");
            } else {
                printf("Mesin Waktu\n");
            }
        }
    }
}
// Menampilkan gadget yang disimpan dalam gadgetList

void addGadget(gadgetList *g, int gadgetType){
    boolean find = false;
    int i = 0;

    while (i < CAPACITY && ! find){
        if (ELMT(*g, i) == VAL_UNDEF){
            find = true;
            ELMT(*g, i) = gadgetType;
        } else {
            i++;
        }
    }
}
// I.S sembarang
// F.S gadget (berupa int) ditambahkan di VAL_UNDEF pertama

void removeGadget(gadgetList *g, int index, int *gadgetType){
    if (ELMT(*g, index) != VAL_UNDEF){
        *gadgetType = ELMT(*g, index);
        ELMT(*g, index) = VAL_UNDEF;
    } else {
        printf("Tidak ada Gadget yang dapat digunakan!\n");
        *gadgetType = VAL_UNDEF;
    }
}
// I.S gadgetList terdefinisi
// F.S gadget di index dihapus

int gadgetPrice(int gadgetType){
    if (gadgetType == 1){
        return 800;
    } else if (gadgetType == 2){
        return 1200;
    } else if (gadgetType == 3){
        return 1500;
    } else { // gadgetType == 4
        return 3000;
    }
}
// Menampilkan harga gadget

boolean isMoneySufficient(int money, int gadgetType){
    return money > gadgetPrice(gadgetType);
}
// return true, if money > price of Gadget

void useGadget(int gadgetType){ // belum selesai
    if (gadgetType == 1){
        printf("Kain Pembungkus Waktu berhasil digunakan!\n");
    } else if (gadgetType == 2){
        printf("Senter Pembesar berhasil digunakan!\n");
    } else if (gadgetType == 3){
        printf("Pintu Kemana Saja berhasil digunakan!\n");
    } else { // gadgetType == 4
        printf("Mesin Waktu berhasil digunakan!\n");
    }
}