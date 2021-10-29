/* File : point.c */
/* point.h implementation */

#include "point.h"

// Allocate buildingCoord
locationCoord* makeLocationCoord (locations *location, int row, int col)
{
    locationCoord *C = (locationCoord*) malloc(sizeof(locationCoord));
    row(*C) = row;
    col(*C) = col;
    locate(*C) = location;

    return C;
}

locationCoord MakePOINT (int col, int row)
{
    locationCoord C;
    col(C) = col;
    row(C) = row;

    return C;
}

// Outputs building in format : <type> (<col>,<row>)
// For e.g : Tower (1,13)
void writeBuildingCoord (locationCoord C)
{
    if (C.location->type==1){printf("Headquarters ");}
    else if ((C.location->type)==2){printf("Mobita ");}
    else if (C.location->type==3){printf("PickUp ");}
    else if (C.location->type==4){printf("DropOff ");}
    else if (C.location->type==5){printf("Destination ");}
    else if (C.location->type==6){printf("Neutral ");}

    printf("(%d,%d) ",row(C),col(C));
}