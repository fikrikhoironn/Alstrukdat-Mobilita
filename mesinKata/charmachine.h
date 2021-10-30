/* File: charmachine.h */
/* Definisi Character Engine */

#ifndef CHAR_ENGINE_H
#define CHAR_ENGINE_H

#include "boolean.h"
#include <string.h>
#include <stdio.h>

#define MARK '.'
/* Char Engine State */
extern char currentChar;
extern boolean eot;

void start(const char* fileName);
/* Mesin siap dioperasikan. Mesin membaca pita dari sebuah file dari masukan user.
   I.S. : nama    sebuha file yang pasti ada pada direktori
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void adv();
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

void startIn(const char* fileName);
/* Mesin karakter untuk membaca secara standar sebuha input dari pengguna*/

void advStartIn();
/*Advances dari mesin staretIn di mana untuk melanjutkan program hingga eot*/


#endif