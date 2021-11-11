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
    printf("Map size is(%d,%d)\n",mapLength,mapHeight);
    printf("HQ ada di (%d,%d)",HQ.col,HQ.row);
    displayArray(arrBuild);
    return 0;
}