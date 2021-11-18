/* File: mesin.h */
/* Definisi Mesin pemrosesan Input */


#ifndef _ENGINE_H
#define _ENGINE_H

#include "../arraydin/arraydin.h"
#include "boolean.h"
#include "charmachine.h"
#include "../matrix/matrix.h"

#include "../item/item.h"
#include "../locations/locations.h"
#include "../point/point.h"
#include "../stack/stack.h"
#include "../queue/queue.h"
//#include "../graph/graph.h"
#include <stdio.h>
#include <string.h> 

#define MAX 100
#define BLANK ' '
#define NEWLINE '\n'
#define NIL NULL


typedef struct{
    char tokenArray[MAX+1];
    int len;
} Token;

extern Token currentToken;
extern boolean endToken;

void ignoreBlankStdin();
/* 
IS Sembarang
FS Mengabaikan karakter satu atau lebih BLANK yakni New Line maupun Spasi
*/

void ignoreBlank();
/* 
IS Sembarang
FS Mengabaikan karakter satu atau lebih BLANK yakni New Line maupun Spasi
*/


void startToken(char * c);
/*
IS. adalah karakter pertama yang akan diakusisi, bisa BLANK maupun bukan
FS. Memulai pembacaan pada sebuah mesin kata dari sebuah fule
*/

void advToken();
/*
IS Pita sembanrang
FS Melanjutkan pembacaan sebuah token atau masukan, yang artinya membaca token berikutnya
*/

void salinToken();
/* Menyalin sebuah token dan memasukkannya kedalam sebuah ADT token
I.S.
F.S. persimpan sebuah token yang isinya sebuah value non spasi, new line dan panjangangnya < MAX dan memasukkannya ke dalam token
di mana terbentuk token
*/

void printToken();
/* 
I.S. sembarang
F.S. mencetak token
*/

int tokenToInt(Token t);
/*
I.S. Token tedeifnisi
F.S. Mengubah token menjadi int 
*/

int tokenToIntStd(Token t);
/*
I.S. Token tedefinisi
F.S. Mengubah token menjadi int 
*/

char tokenToChar(Token t);
/* 
I.S. Token terdeifinisi
F.S. Mengubah sebuah token dengan len=1 menjadi char
*/



void copyToken(Token t1, Token *t2);
/* Copy sebuah token ke token lainnya
I.S. t1 terdefinisi
F.S. t2 memiliki isi yang identik dengan t1
*/

boolean compareToken(Token basis, Token compared);
/* Membandungkan dua buah token apakah senilai
I.S. Basis merupakan token yang sudah diset dari commadn-command yang ada pada spek
dan compared adalah masukan dari STDIN yang ingin kita compare dengan command
F.S. Jika isinya sama "MOVE"=="MOVE"  misalnya maka hasilnya akan true, jika isi berbeda maka false
*/



void startTokenStd();
/*
I.S. Sembarang
F.S. Menjalankan program mesin kata standar dari user
*/

void salinTokenSTDIN();
//ini buat opsi kalo graph kita gagal'
//void tokenToMatrix(int m[][] );
/*
Menyimpan matrix relasi dari masukan (config) menjadi matrix biasa di mana ukurannya jumlah bangunan+1;
I.S. m adalah total lokasi yang ada ditambah hq
F.S. Matrix relasi dari config file dimasukkan ke dalam matrix,
Untuk setiap pergerakan, lakukan perulangan untuk mengecek relasi dari suatu titik pada matrix.
*/
void advTokenStdin();

void readConfigFiles(char* c, int *mapHeight, int * mapLength, locationCoord *HQ, ArrayBuild *arrBuild, Matrix* adjMatrix,Queue * daftarPesanan);
/*
I.S. File terdefinisi dengan nama file c, 
F.S.Membaca file configurasi, ketika melakukan newgame
*/
void BacaArray (ArrayBuild* tes,int isi);

char* readStdString();
/* membaca secara standar masukan user dan disimpan dalam pointer of char*/

boolean stringCompare(char * str1, char *str2);
/* 
I.F. kedua char of pointer terdefinisi
F.S. Mengembalikan nilai true jika keduanya berisi kalimat atau string yang sama*/

char* tokenToString(Token test);
/*
I.S. Token terdefinisi
F.S. mengembalikan nilai char of pointer (string)
*/
#endif