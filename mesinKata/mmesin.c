#include <stdio.h>
#include <string.h>
#include "mesin.h"


int main(){
    char* c = "tes.config";
    int mapHeight, mapLength;
    locationCoord HQ;
    ArrayBuild arrBuild;
    Matrix adjMatrix;
    Queue daftarPesanan;
    readConfigFiles(c,&mapHeight,&mapLength,&HQ,&arrBuild,&adjMatrix, &daftarPesanan);
    displayMatrix(adjMatrix);
    printf("\nMap size is(%d,%d)\n",mapLength,mapHeight);
    printf("HQ ada di (%d,%d)\n",HQ.col,HQ.row);
    displayArray(arrBuild);
    DisplayQueue(daftarPesanan);
    return 0;
}