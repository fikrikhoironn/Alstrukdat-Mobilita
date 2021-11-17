// File: linkedlist.c
// Berisi implementasi dari primitif struktur list berkait 
// List dinyatakan melalui alamat elemen pertamanya 

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void CreateList(linkedList *L) {
    // KAMUS
    // ALGORITMA
    first(*L) = NULL;
}

Address newNode(infotype val) {
    // KAMUS
    Address p = (Address) malloc(sizeof(Node));
    // ALGORITMA
    if (p!=NULL) {
        info(p) = val;
        next(p) = NULL;
    }
    return p;
}

boolean isListEmpty(linkedList L) {
    // KAMUS
    // ALGORITMA
    return (first(L) == NULL);
}

infotype getElmtList(linkedList L, int idx) {
    // KAMUS
    int count;
    Address p;
    // ALGORITMA
    count = 0;
    p = first(L);
    while (count < idx) {
        p = next(p);
        count++;
    }
    return (info(p));
}

void setElmtList(linkedList *L, int idx, infotype val) {
    // KAMUS
    int count;
    Address p;
    // ALGORITMA
    count = 0;
    p = first(*L);
    while (count < idx) {
        p = next(p);
        count++;
    }
    info(p) = val;
}

int indexOfList(linkedList L, infotype val) {
    // KAMUS
    int i;
    Address p;
    boolean found;
    // ALGORITMA
    i = 0;
    p = first(L);
    found = false;
    while (p != NULL && !found) {
        if (isItemEqual(info(p), val)) {
            found = true;
        }
        else {
            i++;
            p = next(p);
        }
    }
    if (found) {
        return i;
    }
    else {
        return IDX_UNDEF;
    }
}

int lengthList(linkedList L) {
    // KAMUS
    int count;
    Address p;
    // ALGORITMA
    count = 0;
    p = first(L);
    while (p != NULL) {
        count++;
        p = next(p);
    }
    return count;
}

void insertFirstList(linkedList *L, infotype val) {
    // KAMUS
    Address p;
    // ALGORITMA
    p = newNode(val);
    if (p != NULL) {
        next(p) = first(*L);
        first(*L) = p;
    }
}

void insertAtList(linkedList *L, int idx, infotype val) {
    // KAMUS
    Address pNew, pList;
    int i;
    // ALGORITMA
    if (idx == 0) {
        insertFirstList(L, val);
    }
    else {
        pNew = newNode(val);
        if (pNew != NULL) {
            pList = first(*L);
            for (i = 0; i < idx - 1; i++) {
                pList = next(pList);
            }
            next(pNew) = next(pList);
            next(pList) = pNew;
        }
    }
}

void insertLastList(linkedList *L, infotype val) {
    // KAMUS
    Address pNew, pList;
    // ALGORITMA
    if (isListEmpty(*L)) {
        insertFirstList(L, val);
    }
    else {
        pNew = newNode(val);
        if (pNew != NULL) {
            pList = first(*L);
            while (next(pList) != NULL) {
                pList = next(pList);
            }
            next(pList) = pNew;
        }
    }
}

void deleteFirstList(linkedList *L, infotype *val) {
    // KAMUS
    Address p;
    // ALGORITMA
    p = first(*L);
    *val = info(p);
    if (next(p) == NULL) {
        first(*L) = NULL;
    }
    else {
        first(*L) = next(p);
    }
    free(p);
}

void deleteAtList(linkedList *L, int idx, infotype *val) {
    // KAMUS
    Address p, temp;
    int i;
    // ALGORITMA
    if (idx == 0) {
        deleteFirstList(L, val);
    }
    else if (idx == lengthList(*L)) {
        // tidak ada yang dihapus
    }
    else {
        p = first(*L);
        for (i = 0; i < idx - 1; i++) {
            p = next(p);
        }
        temp = next(p);
        *val = info(temp);
        next(p) = next(temp);
        free(temp);
    }
}

void deleteLastList(linkedList *L, infotype *val, int idx) {
    // KAMUS
    Address p, loc;
    // ALGORITMA
    p = first(*L);
    loc = NULL;
    while (next(p) != NULL) {
        loc = p;
        p = next(p);
    }
    if (loc == NULL) {
        first(*L) = NULL;
    }
    else {
        next(loc) = NULL;
    }
    *val = info(p);
    free(p);
}

void displayList(linkedList L) {
    // KAMUS
    Address p;
    // ALGORITMA
    if (!isListEmpty(L)) {
        p = first(L);
        while (p != NULL) {
            printf("Time in : %d\n", timeIn(info(p)) );
            printf("Pick up point : %c\n", pickUp(info(p)));
            printf("Drop off point : %c\n", dropOff(info(p)));
            printf("Item type : %c\n", typeItem(info(p)));
            p = next(p);
        }
    }
    else {
        printf("Tidak ada item.");
    }
}

linkedList concatList(linkedList L1, linkedList L2) {
    // KAMUS
    Address p1, p2;
    linkedList L3;
    // ALGORITMA
    CreateList(&L3);
    p1 = first(L1);
    p2 = first(L2);
    while (p1 != NULL) {
        insertLastList(&L3, info(p1));
        p1 = next(p1);
    }
    while (p2 != NULL) {
        insertLastList(&L3, info(p2));
        p2 = next(p2);
    }
    return L3;
}

boolean isItemEqual (item a, item b) {
    // KAMUS
    // ALGORITMA
    return ((timeIn(a)==timeIn(b)) && (pickUp(a)==pickUp(b)) && (dropOff(a)==dropOff(b)) && (typeItem(a)==typeItem(b)) && (perishableTime(a)==perishableTime(b)));
}

void insert_timeascList (linkedList *L, infotype val) {
    // KAMUS
    Address pNew, pList;
    int idx;
    // ALGORITMA
    if (isListEmpty(*L)) {
        insertFirstList(L, val);
    }
    else {   
        pNew = newNode(val);
        if (pNew != NULL) {
            idx = 0;
            pList = first(*L);
            while ((pList != NULL) && (timeIn(info(pList))<=timeIn(val))) {
                pList = next(pList);
                idx++;
            }
            insertAtList(L, idx, val);
        }
    }
}

void insert_timedescList (linkedList *L, infotype val) {
    // KAMUS
    int idx;
    Address pNew, pList;
    // ALGORITMA
    if (isListEmpty(*L)) {
        insertFirstList(L, val);
    }
    else {
        pNew = newNode(val);
        if (pNew != NULL) {
            idx = 0;
            pList = first(*L);
            while ((pList != NULL) && (timeIn(info(pList))>=timeIn(val))) {
                pList = next(pList);
                idx++;
            }
            insertAtList(L, idx, val);
        }
    }
}

Address find_by_pickup_location (linkedList L, char location) {
    // KAMUS
    Address p, retAddr;
    boolean VIPfound;
    // ALGORITMA
    p = first(L);
    while (p != NULL && (info(p)).pickUp != location) {
        p = next(p);
    }
    retAddr = p;
    p = next(p);
    // Akan diperiksa jika ada elemen berikutnya yang berada pada lokasi location dan bertipe VIP
    VIPfound = false;
    while (p != NULL && !VIPfound) {
        if ((info(p)).pickUp == location && (info(p)).typeItem == 'V') {
            // terdapat VIP item pada lokasi yang sama;
            VIPfound = true;
        }
        else {
            p = next(p);
        }
    }
    if (VIPfound) {
        // Akan dikembalikan item VIP terlebih dahulu
        retAddr = p;
    }
    return retAddr;
}

boolean isVIPin (linkedList L) {
    // KAMUS
    Address p;

    // ALGORITMA
    p = first(L);
    boolean found = false;
    while (p != NULL && (info(p)).typeItem != 'V') {
        p = next(p);
    }
    if (p == NULL) {
        return false;
    }
    else {
        return true;
    }
}

boolean isPickupLocation(linkedList L, char location) {
    // KAMUS
    Address p;
    // ALGORITMA
    p = first(L);
    boolean found  = false;
    while (p != NULL && !found) {
        if (info(p).pickUp == location){
            found = true;
        }                
        p = next(p);

    }
    return found;
}
