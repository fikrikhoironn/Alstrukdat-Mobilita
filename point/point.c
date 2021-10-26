/* File : point.c */
/* point.h implementation */

#include "point.h"

buildingPoints makeBuilding (buildings building, int row, int col){
    buildingPoints C;
    building(C) = building;
    row(C) = row;
    col(C) = col;
}