<<<<<<< HEAD
/* File : point.h */
/* File to store ADT point */

#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "../locations/locations.h"

typedef struct {
    locations *location;
	int row;
	int col;
} locationCoord;

#define row(C) (C).row //Y pos
#define col(C) (C).col //X pos
#define locate(C) (C).location

// Allocate location coord
locationCoord* makeLocationCoord (locations *location, int row, int col);

// Outputs location in format : <type> (<col>,<row>)
// For e.g : Headquarters (1,1)
void writeLocationCoord (locationCoord C);
=======
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
>>>>>>> 157ed4a510b95e81e76873547bc7dc17c72d6a06

#endif