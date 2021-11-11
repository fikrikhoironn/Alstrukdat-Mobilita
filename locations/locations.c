#include"locations.h"
#include <stdlib.h>
#include <stdio.h>


locations *allocateLocation(){
    addressLocations a = (addressLocations) malloc(sizeof(locations));
    return a;
}


void showLoc(locations C){
    if (C.type==1){printf("Headquarters ");}
    else if ((C.type)==2){printf("Mobita ");}
    else if (C.type==3){printf("PickUp ");}
    else if (C.type==4){printf("DropOff ");}
    else if (C.type==5){printf("Destination ");}
    else if (C.type==6){printf("Neutral ");}
}

void makeHeadquarters(locations *C){
(*C).type=1;
}

void makeMobita(locations *C){
(*C).type=2;
}

void makePickUp(locations *C){
(*C).type=3;
}

void makeDropOff(locations *C){
(*C).type=4;
}

void makeDestination(locations *C){
(*C).type=5;
}

void makeNeutral(locations *C){
(*C).type=6;
} 