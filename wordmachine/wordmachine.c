/* NIM/Nama     : 13520010 / Ken Kalang Al Qalyubi */
/* Tanggal      : 28 September 2021 */
/* Deskripsi    : mesin kata */

#include "wordmachine.h"
#include <stdio.h>



/* Word Engine State */
boolean endWord;
Word currentWord;

void ignoreBlank()
{
    while (currentChar==BLANK || currentChar == NEWLINE){
        adv();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void startWord(char *filename){
    start(filename);
    endWord = false;
    if (currentChar==MARK){
        endWord= true;
    }
    else{
        ignoreBlank();
        copyWord();
    }
}
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void advWord(){
    endWord = false;
    if (currentChar==MARK){
        endWord = true;
    }
    else{
        copyWord();
        ignoreBlank();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */

void copyWord(){
    int len = 0;
    while ((currentChar!=MARK) && (currentChar!=BLANK) && (len<KAPASITAS) && (currentChar != NEWLINE)){
        currentWord.contents[len]= currentChar;
        adv();
        len++;
    }
    currentWord.length= len;
}
int WordInt (Word x)
{
    int val = 0;
    int i = 0;  
    while (i <x.length){
        val = val * 10;
        switch (x.contents[i]){
        case '0' :
            val += 0;
            break;
        case '1' :
            val += 1;
            break;
        case '2' :
            val += 2;
            break;
        case '3' :
            val += 3;
            break;
        case '4' :
            val += 4;
            break;
        case '5' :
            val += 5;
            break;
        case '6' :
            val += 6;
            break;
        case '7' :
            val += 7;
            break;
        case '8' :
            val += 8;
            break;
        case '9' :
            val += 9;
            break;
        }
        i++;
    }
    return val;
}

char WordChar (Word x){
    return (x.contents[0]);
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
