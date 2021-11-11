#include <stdio.h>
#include "arraydin.h"
#include "../mesinKata/mesin.h"
#include "boolean.h"
#include "../matrix/matrix.h"

#include "../item/item.h"
#include "../locations/locations.h"
#include "../point/point.h"

Token currentToken;

int main(){
    ArrayBuild tes;
	startToken("test.txt");
    int panjang = tokenToInt(currentToken);
    printf("%d\n",panjang);
    advToken();
    BacaArray(&tes,panjang);
    displayArray(tes);

    /* Contoh akses titik lokasi bangunan */
    printf("\n%d",TITIK(tes,1).col);
    printf("\n%d", NEFF(tes));
}