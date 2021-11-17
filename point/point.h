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


// isi koordinat lokasi
locationCoord MakePOINT (int col, int row);
// Outputs location in format : <type> (<col>,<row>)
// For e.g : Headquarters (1,1)
void writeLocationCoord (locationCoord C);

#endif