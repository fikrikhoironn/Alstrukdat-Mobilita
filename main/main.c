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
#include "../command/command.h"



int main(){
    Token fileInput;
    time mobiTime;
    createTime(&mobiTime);
    int command;




    int mapheight, mapLength;
    locationCoord HQLoc;
    
    
    
    ArrayBuild arrayOfBuilding;
    
    
    Matrix adjMatrix;




    Queue daftarPesanan;


    linkedList todo;
    linkedList inprogressList;


    stack mobiBag;
    //buat todoList
    FILE *fp;
    char * test=(char *) malloc(101*sizeof(char));
    do{
        printf("Silahkan masukkan menu\n(1 // 2 // 3):\nENTER COMMAND: ");
        scanf("%d",&command);
    }while(command != 1 && command != 2 && command !=3);
    if(command==1){
            while(fp==NULL){
            currentToken.len=0;
            printf("ENTER FILENAME: ");
            startTokenStd();
            for(int i=0;i<=currentToken.len;i++){
            if(i!=currentToken.len) test[i]=currentToken.tokenArray[i];
            else test[i]='\0';
            }
            fp= fopen(test,"r");
            //printf("%s||%c||%c\n",test,test[0],currentToken.tokenArray[1]);
            advTokenStdin();
            }
            readConfigFiles(test,&mapheight,&mapLength,&HQLoc,&arrayOfBuilding,&adjMatrix,&daftarPesanan);
            //printf("%d %d\n%d %d\n",mapLength,mapheight,HQLoc.col,HQLoc.row);
            //displayArray(arrayOfBuilding);
            //displayMatrix(adjMatrix);
            //DisplayQueue(daftarPesanan);
            mobitaLocation(mobiTime) = MakePOINT((HQLoc).col,HQLoc.row);
            //printf("Selamat datang di permainan Mobilita.\n");
    }else if(command ==2){
        printf("Maaf fitur belum dapat diakses dan sedang dalam pengembangan.\n");
    }else{
        printf("Selamat Tinggal, terima kasih telah bersua.\n");
    }
    eot=true;
    endToken=true;
    adv();
    //scanf("%d",&command);
        currentToken.len=0;
    printf("ENTER COMMAND: ");
    startTokenStd();
    char * cmd;
    free(cmd);
    cmd = (char *) malloc(101*sizeof(char));

    while (!isEmptyQueue(daftarPesanan))
    {
        //printMenu();
        //printStatus();
        for(int i=0;i<=currentToken.len;i++){
        if(i!=currentToken.len) cmd[i]=currentToken.tokenArray[i];
        else cmd[i]='\0';
        }
        if(stringCompare(cmd,"MOVE")){
            MOVE(&mobiTime,arrayOfBuilding,adjMatrix);
            displayStatus(mobiTime);
            //printf("(%d,%d)",mobitaLocation(mobiTime).col,mobitaLocation(mobiTime).row);
            //printf("--move %d\n",tokenToIntStd(currentToken));
        }else if(stringCompare(cmd,"PICK_UP")){
            //masi gajelas PICK_UP belum dibenerin
            //PICK_UP(&todo,&inprogressList,&mobiBag,);
            printf("pick up\n");
        }else if(stringCompare(cmd,"DROP_OFF")){
            //ini juga ntar dibenerin
            //DROP_OFF(&todo,&inprogressList,&mobiBag,,);
            printf("drop off\n");
        }else if(stringCompare(cmd, "MAP")){
            //printf("%d %d\n%d %d\n",mapheight,mapLength,arrayOfBuilding.koor[2].row,arrayOfBuilding.koor[2].col);
            //displayArray(arrayOfBuilding);
            printMap(todo,adjMatrix,arrayOfBuilding,mapLength,mapheight,mobiTime,mobiBag);
        }else if(stringCompare(cmd,"TO_DO")){
            //TO_DO(todo);
            printf("to do\n");
        }else if(stringCompare(cmd,"IN_PROGRESS")){
            //
            printf("in progrss\n");
        }else if(stringCompare(cmd,"INVENTORY")){
            printf("inventory\n");
        }else if(stringCompare(cmd,"BUY")){
            printf("buy\n");
        }else if(stringCompare(cmd,"HELP")){
            //HELP();
            printf("help\n");
        }
        printf("ENTER COMMAND: ");
        ignoreBlankStdin();
        advTokenStdin();

    }
    
    
}