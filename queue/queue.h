/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include <stdlib.h>
#include "../item/item.h"

/* Konstanta */
#define IDX_UNDEF -1
#define CAPACITY_QUEUE 100


/* Definisi PrioQueue */
typedef struct {
	item buffer[CAPACITY_QUEUE];
	int idxHead;
	int idxTail;
} Queue;

/* ********* AKSES (Selektor) ********* */
/* Jika pq adalah PrioQueue, maka akses elemen : */
#define IDX_HEAD(pq) (pq).idxHead
#define IDX_TAIL(pq) (pq).idxTail
#define     HEAD(pq) (pq).buffer[(pq).idxHead]
#define     TAIL(pq) (pq).buffer[(pq).idxTail]

/* *** Kreator *** */
void CreateQueue(Queue *pq);
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */

boolean isEmptyQueue(Queue pq);
/* Mengirim true jika pq kosong: lihat definisi di atas */

boolean isFullQueue(Queue pq);
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */

int lengthQueue(Queue pq);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika pq kosong. */

/*** Primitif Add/Delete ***/
void enqueue(Queue *pq, item val);
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen pq
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
void DisplayQueue (Queue pq);

void dequeue(Queue * pq, item *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd
I.S., HEAD dan IDX_HEAD "mundur"; 
        pq mungkin kosong */

#endif