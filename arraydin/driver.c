#include <stdio.h>
#include "arraydin.h"
#include "../wordmachine/wordmachine.h"
#include "../charmachine/charmachine.h"
#include "../point/point.h"

int main(){
    ArrayBuild tes;
	startWord("test.txt");
    int panjang = WordInt(currentWord);
    advWord();
    advWord();
    tes = BacaArray(panjang);
    displayList(tes);

    /* Contoh akses titik lokasi bangunan */
    printf("%d",TITIK(tes,1).col);
}