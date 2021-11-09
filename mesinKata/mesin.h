/* File: mesin.h */
/* Definisi Mesin pemrosesan Input */


#ifndef _ENGINE_H
#define _ENGINE_H

#include "boolean.h"
#include "charmachine.h"
#include "../matrix/matrix.h"
#include "../arraydin/arraydin.h"
#include "../item/item.h"
#include "../stack/stack.h"
#include "../locations/locations.h"
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


void ignoreBlank();
/* Mengabaikan karakter satu atau lebih BLANK yakni New Line maupun Spasi
IS
FS
*/


void startToken(char * c);
/*Memulai pembacaan pada sebuah mesin kata berakhiran . (MARK)
IS. adalah karakter pertama yang akan diakusisi, bisa BLANK maupun bukan
FS. 
*/

void advToken();
/*Melanjutkan pembacaan sebuah token atau masukan, yang artinya membaca token berikutnya
IS Pita sembanrang
FS T
*/

void salinToken();
/* Menyalin sebuah token dan memasukkannya kedalam sebuah ADT token
I.S.
F.S. persimpan sebuah token yang isinya sebuah value non spasi, new line dan panjangangnya < MAX dan memasukkannya ke dalam token
di mana terbentuk token
*/

void printToken();
/* 
I.S.
F.S.
*/

int tokenToInt(Token t);
/* Mengubah token menjadi int 
I.S. 
F.S.
*/

char tokenToChar(Token t);
/* Mengubah sebuah token dengan len=1 menjadi char
I.S.
F.S.
*/



void copyToken(Token t1, Token *t2);
/* Copy sebuah token ke token lainnya
I.S. t1 terdefinisi
F.S. t2 memiliki isi yang identik dengan t1
*/


void startTokenStd();


void salinTokenSTDIN();

//ini buat opsi kalo graph kita gagal'
void tokenToMatrix(int m[][] );
/*
Menyimpan matrix relasi dari masukan (config) menjadi matrix biasa di mana ukurannya jumlah bangunan+1;
I.S. m adalah total lokasi yang ada ditambah hq
F.S. Matrix relasi dari config file dimasukkan ke dalam matrix,
Untuk setiap pergerakan, lakukan perulangan untuk mengecek relasi dari suatu titik pada matrix.
*/
void advTokenStdin();

void readConfigFile(const char * c);
/*
Membaca file configurasi, ketika melakukan newgame

*/

#endif