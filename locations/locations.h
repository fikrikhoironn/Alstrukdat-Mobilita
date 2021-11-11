/* File: locations.h */
/* File to store ADT Locations */

#ifndef LOCATIONS_H
#define LOCATIONS_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

typedef int types;

typedef struct tLocations* addressLocations;
typedef struct tLocations {
    char name;
    types type;
} locations;

#define name(C) (C).name
#define type(C) (C).type

// Allocate Locations in heap
locations *allocateLocation();

// Show location status
void showLoc(locations C);

// Constructor for location type Headquarters
void makeHeadquarters(locations *C);

// Constructor for location type Mobita (current location)
void makeMobita(locations *C);

// Constructor for location type PickUp
void makePickUp(locations *C);

// Constructor for location type DropOff
void makeDropOff(locations *C);

// Constructor for location type Destination
void makeDestination(locations *C);

// Constructor for location type Neutral
void makeNeutral(locations *C);

#endif