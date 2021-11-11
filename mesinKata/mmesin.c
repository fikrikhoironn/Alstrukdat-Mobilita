#include <stdio.h>
#include <string.h>
#include "mesin.h"


int main(){
    char* c = "tes.config";
    int mapHeight, mapLength;
    locationCoord HQ;
    ArrayBuild arrBuild;
    Matrix adjMatrix;
    readConfigFiles(c,&mapHeight,&mapLength,&HQ,&arrBuild,&adjMatrix);
    displayMatrix(adjMatrix);
    printf("\nMap size is(%d,%d)\n",mapLength,mapHeight);
    printf("HQ ada di (%d,%d)\n",HQ.col,HQ.row);
    displayArray(arrBuild);
    return 0;
}