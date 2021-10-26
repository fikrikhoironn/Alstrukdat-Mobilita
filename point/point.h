// File : point.h
// File to store ADT point 

#ifndef point_H
#define point_H

#include "boolean.h"
#include "../buildings/buildings.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    buildings building;
    int row;
    int col;
} buildingPoints;

#define row(C) (C)->row // Coordinate Y
#define col(C) (C)->col // Coordinate X
#define buildings(C) (C).building

buildingPoints makeBuilding (buildings building, int row, int col);

#endif