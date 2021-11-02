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

boolean isEmpty(linkedList L) {
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

void setElmt(linkedList *L, int idx, infotype val) {
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

int indexOf(linkedList L, infotype val) {
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

void insertFirst(linkedList *L, infotype val) {
    // KAMUS
    Address p;
    // ALGORITMA
    p = newNode(val);
    if (p != NULL) {
        next(p) = first(*L);
        first(*L) = p;
    }
}

void insertAt(linkedList *L, int idx, infotype val) {
    // KAMUS
    Address pNew, pList;
    int i;
    // ALGORITMA
    if (idx == 0) {
        insertFirst(L, val);
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

void insertLast(linkedList *L, infotype val) {
    // KAMUS
    Address pNew, pList;
    // ALGORITMA
    if (isEmpty(*L)) {
        insertFirst(L, val);
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

void deleteFirst(linkedList *L, infotype *val) {
    // KAMUS
    Address p;
    // ALGORITMA
    p = first(*L);
    *val = info(p);
    if (next(p) == NULL) {
        first(*L) = NULL;
    }
    else {
        first(*L) = next(*L);
    }
    free(p);
}

void deleteAt(linkedList *L, int idx, infotype *val) {
    // KAMUS
    Address p, temp;
    int i;
    // ALGORITMA
    if (idx == 0) {
        deleteFirst(L, val);
    }
    else if (idx == length(*L)) {
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

void deleteLast(linkedList *L, infotype *val, int idx) {
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
    if (!isEmpty(L)) {
        p = first(L);
        while (p != NULL) {
            printf("Time in : %d\n", timeIn(info(p)) );
            printf("Pick up point : %c\n", pickUp(info(p)));
            printf("Drop off point : %c\n", dropOff(info(p)));
            printf("Item type : %c\n", typeItem(info(p)));
            printf("Item value : %d\n", valueItem(info(p)));
            printf("Reward number : %d\n\n", rewardItem(info(p)));
            p = next(p);
        }
    }
    else {
        printf("Tidak ada item.");
    }
}

linkedList concat(linkedList L1, linkedList L2) {
    // KAMUS
    Address p1, p2;
    linkedList L3;
    // ALGORITMA
    CreateList(&L3);
    p1 = first(L1);
    p2 = first(L2);
    while (p1 != NULL) {
        insertLast(&L3, info(p1));
        p1 = next(p1);
    }
    while (p2 != NULL) {
        insertLast(&L3, info(p2));
        p2 = next(p2);
    }
    return L3;
}

boolean isItemEqual (item a, item b) {
    // KAMUS
    // ALGORITMA
    return ((timeIn(a)==timeIn(b)) && (pickUp(a)==pickUp(b)) && (dropOff(a)==dropOff(b)) && (typeItem(a)==typeItem(b)) && (valueItem(a)==valueItem(b)) && (rewardItem(a)==rewardItem(b)));
}

void insert_timeasc (linkedList *L, infotype val) {
    // KAMUS
    Address pNew, pList;
    int idx;
    // ALGORITMA
    if (isEmpty(*L)) {
        insertFirst(L, val);
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
            insertAt(L, idx, val);
        }
    }
}

void insert_timedesc (linkedList *L, infotype val) {
    // KAMUS
    int idx;
    Address pNew, pList;
    // ALGORITMA
    if (isEmpty(*L)) {
        insertFirst(L, val);
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
            insertAt(L, idx, val);
        }
    }
}