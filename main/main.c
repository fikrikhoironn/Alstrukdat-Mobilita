#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../mesinKata/mesin.h"

#include "../queue/queue.h"
#include "../arraydin/arraydin.h"
#include "../time/time.h"
#include "../stack/stack.h"
#include "../point/point.h"
#include "../matrix/matrix.h"
#include "../locations/locations.h"
#include "../linkedlist/linkedlist.h"
#include "../item/item.h"
#include "../arraystatis/arraystatis.h"
#include "../ability/ability.h"

int main(){
    Token fileInput;
    time mobitime;
    createTime(&mobitime);
    int command;




    int mapheight, mapLength;
    locationCoord HQLoc;
    locationCoord mobitaLoc;
    
    
    
    ArrayBuild arrayOfBuilding;
    
    
    Matrix adjMatrix;




    Queue daftartPesanan;


    linkedList todo;
    linkedList inprogressList;


    stack mobiBag;
    //buat todoList
    FILE *fp;
    do{
        printf("Silahkan masukkan menu\n(1//2//3):\nENTER COMMAND: ");
        scanf("%d",&command);
    }while(command != 1 || command != 2 || command !=3);
    if(command==1){
            do{
            startIn();
            fp= fopen(tokenToString(currentToken),"r");
            advTokenStdin();
            }while(fp==NULL);
            readConfigFiles(tokenToString(currentToken),&mapheight,&mapLength,&HQLoc,&arrayOfBuilding,&adjMatrix,&daftartPesanan);
            mobitaLoc = MakePOINT((HQLoc).col,HQLoc.row);
            printf("Selamat datang di permainan Mobilita.");
    }else if(command ==2){
        printf("Maaf fitur belum dapat diakses dan sedang dalam pengembangan.\n");
    }else{
        printf("Selamat Tinggal, terima kasih telah bersua.\n");
    }

    while (!isEmptyQueue(daftartPesanan))
    {
        //printMenu();
        //printStatus();
        advTokenStdin();
        char * cmd = tokenToString(currentToken);
        if(stringCompare(cmd,"MOVE")){
            //MOVE(&mobitaLoc,arrayOfBuilding,adjMatrix);
            printf("move\n");
        }else if(stringCompare(cmd,"PICK_UP")){
            //masi gajelas PICK_UP belum dibenerin
            //PICK_UP(&todo,&inprogressList,&mobiBag,);
            printf("pick up\n");
        }else if(stringCompare(cmd,"DROP_OFF")){
            //ini juga ntar dibenerin
            //DROP_OFF(&todo,&inprogressList,&mobiBag,,);
            printf("drop off\n");
        }else if(stringCompare(cmd, "MAP")){
            //MAP();
            printf("map\n");
        }else if(stringCompare(cmd,"TO_DO")){
            //TO_DO(todo);
            printf("to do\n");
        }else if(stringCompare(cmd,"IN_PROGRESS")){
            //
            printf("in progrss\n");
        }else if(stringCompare(cmd,"INVENTORY")){
            printf("inventory\n");
        }else if(stringCompare(cmd,"BUY")){

        }else if(stringCompare(cmd,"HELP")){
            //HELP();
            printf("help\n");
        }
    }
    
}