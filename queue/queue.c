/* File : prioqueue.h */
/* Representasi priority queue dengan array eksplisit dan alokasi stastik */
/* Queue terurut mengecil berdasarkan elemen score (nilai Daspro) */
/* Jika score sama, diurutkan membesar berdasarkan tKedatangan (waktu kedatangan) */
#include <stdio.h>
#include "queue.h"
#include "boolean.h"


/* Konstanta */

/* Deklarasi ElType */

/* Definisi PrioQueue */

/* ********* AKSES (Selektor) ********* */
/* Jika pq adalah PrioQueue, maka akses elemen : */
/* *** Kreator *** */
void CreateQueue(Queue *pq){
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */

boolean isEmptyQueue(Queue pq){
    return ((IDX_HEAD(pq) == IDX_UNDEF ) && (IDX_TAIL(pq) == IDX_UNDEF));
}
/* Mengirim true jika pq kosong: lihat definisi di atas */

boolean isFullQueue(Queue pq){
    return ((IDX_TAIL(pq)==CAPACITY_QUEUE-1)&&(IDX_HEAD(pq)==0));
}
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */

int lengthQueue(Queue pq){
    if (isEmptyQueue(pq))
        return 0;
    else
        return (IDX_TAIL(pq)-IDX_HEAD(pq)+1);
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika pq kosong. */

/*** Primitif Add/Delete ***/
void enqueue(Queue *pq, item val)
{
    int i,j;
    if(isEmptyQueue(*pq)){
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
    }   
    else { 
        if(IDX_TAIL(*pq) ==  (CAPACITY_QUEUE-1)) {
            for(i= IDX_HEAD (*pq); i <=IDX_TAIL(*pq); i ++){
                (*pq).buffer[i-IDX_HEAD(*pq)] = (*pq).buffer[i];
            }
            IDX_TAIL(*pq) -= IDX_HEAD(*pq);
            IDX_HEAD(*pq) = 0;
        }
        IDX_TAIL(*pq)++;
    }
    TAIL(*pq)=val;
    item temp;
    i = IDX_TAIL(*pq);
    while ((i > 0) && ((*pq).buffer[i - 1].timeIn > ((*pq).buffer[i].timeIn))) {
        temp = (*pq).buffer[i - 1];
        (*pq).buffer[i - 1] = (*pq).buffer[i];
        (*pq).buffer[i] = temp;
        i--;
    }
}
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen pq
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */



void DisplayQueue (Queue pq)
{
    item Element;
    int i = 1;
    while(!isEmptyQueue(pq)){
        printf("%d. %c -> %c", i, HEAD(pq).pickUp , HEAD(pq).dropOff);
        if (HEAD(pq).typeItem == 'N')
            printf(" (Normal Item)\n");
        else if (HEAD(pq).typeItem == 'H')
            printf(" (Heavy Item)\n");
        else if (HEAD(pq).typeItem == 'P')
            printf(" (Perishable Item, sisa waktu %d)\n", HEAD(pq).perishableTime);   
        else if (HEAD(pq).typeItem == 'V')
            printf(" (VIP Item)\n"); 
        dequeue(&pq, &Element);
        i++;
    }
}

void dequeue(Queue * pq, item *val)
{
    *val = HEAD(*pq);
    if(IDX_HEAD(*pq)==IDX_TAIL(*pq)){
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    }
    else
        IDX_HEAD(*pq)++;
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd
I.S., HEAD dan IDX_HEAD "mundur"; 
        pq mungkin kosong */

boolean isOneElmtQueue(Queue pq){
    return IDX_TAIL(pq)==IDX_HEAD(pq);
}