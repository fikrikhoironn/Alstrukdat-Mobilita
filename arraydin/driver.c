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
	start("test.txt");
    int panjang = tokenToInt(currentToken);
    advToken();
    advToken();
    tes = BacaArray(panjang);
    displayArray(tes);

    /* Contoh akses titik lokasi bangunan */
    printf("%d",TITIK(tes,1).col);
    printf("%d", NEFF(tes));
}