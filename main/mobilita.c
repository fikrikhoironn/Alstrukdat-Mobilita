#include "mobilita.h"

void start_game();

void printMenu(){
    printf("Silahkan masukkan perintah.\n");
    printf("MOVE\n");
    printf("PICK_UP\n");
    printf("DROP_OFF\n");
    printf("MAP\n");
    printf("TO_DO\nIN_PROGRSS\nBUY\nINVENTORY\nHELP\nSAVE_GAME\nRETURN\n");
}   

void printStatus(locationCoord mobitaLoc, time mobitime){
    printf("Mobita sekarang berada di titik %c (%d,%d)!",mobitaLoc.location->name,mobitaLoc.col,mobitaLoc.row);
    printf("Waktu: ");
    printCurrentTime(mobitime);
    printf("ENTERCOMMAND: ");
}