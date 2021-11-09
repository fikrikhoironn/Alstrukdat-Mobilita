/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */


#include <stdio.h>
#include "boolean.h"
#include "arraydin.h"
#include <stdlib.h>

/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ArrayBuild, cara deklarasi dan akses: */
/* Deklarasi : l : ArrayBuild */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.nEff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateArrayBuild(ArrayBuild *l, int isi)
{
    NAMA(*l)=(char *) malloc(isi * sizeof(char));
    KOOR(*l)=(locationCoord *) malloc (isi * sizeof(locationCoord));
    CAPACITY(*l) = isi;
    NEFF(*l)=0;
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ArrayBuild l)
{
    return NEFF(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ArrayBuild l)
{
    return (NEFF(l)-1);
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */

/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */




/*    Isi elemen array ke dalam NEFF */
void IsiArray (ArrayBuild *l,char bangun, int xx, int yy){
    locationCoord lokasi = MakePOINT(xx,yy);
    ELMT(*l,NEFF(*l)) = bangun;
    TITIK(*l,NEFF(*l)) = lokasi;
    NEFF(*l)++;
}

/*    Dari txt ke array */
ArrayBuild BacaArray (int isi){
    ArrayBuild array;
    CreateArrayBuild(&array,isi);
    int i,abs,ord;
    char nama_build;
    i = 0;
    while (i<isi){
        nama_build = tokenToChar(currentChar);
        advToken();
        abs = tokenToInt(currentToken);
        advToken();
        ord = tokenToInt(currentToken);
        IsiArray(&array,nama_build,abs,ord);
        advToken();
        i++;
    }
    return array;
}
/* ********** SEARCHING ********** */


/*    Ngeluarin koordinat atau titik dari bangunan yang diinginkan */
locationCoord Pointof(ArrayBuild l, char bangunan)
{
    int i;
    boolean cek = false;
    i = 0;
    while (i<length(l) && !cek){
        if (ELMT(l,i)==bangunan){
            cek = true;
        }
        else i++;
    }
    return TITIK(l,i);
}

/*    Display array */
void displayList(ArrayBuild l)
{
    int i;
    for(i=0;i<NEFF(l);i++){
        printf("%c (%d %d)\n",ELMT(l,i),TITIK(l,i).col,TITIK(l,i).row);
    }
}
