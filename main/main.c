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
    char bcom;
    int command;
    gadgetList listGadget;
    createGadgetList(&listGadget);
    int mapheight, mapLength;
    locationCoord HQLoc;
    ArrayBuild arrayOfBuilding;
    Matrix adjMatrix;
    Queue daftarPesanan;
    CreateQueue(&daftarPesanan);
    linkedList todo;
    CreateList(&todo);
    linkedList inprogressList;
    CreateList(&inprogressList);

    stack mobiBag;
    createStack(&mobiBag);
    //buat todoList
    FILE *fp = NULL;
    char * test=(char *) malloc(101*sizeof(char));
    int i;
    int j;
    printf("%s",YELLOW);
    printf("#     # ####### ######  ### #######    #       #       #######  #####  ####### #     # ######\n");  
    printf("##   ## #     # #     #  #     #      # #      #       #       #     # #       ##    # #     # \n");
    printf("# # # # #     # #     #  #     #     #   #     #       #       #       #       # #   # #     # \n");
    printf("#  #  # #     # ######   #     #    #     #    #       #####   #  #### #####   #  #  # #     # \n");
    printf("#     # #     # #     #  #     #    #######    #       #       #     # #       #   # # #     #\n");
    printf("#     # #     # #     #  #     #    #     #    #       #       #     # #       #    ## #     #\n"); 
    printf("#     # ####### ######  ###    #    #     #    ####### #######  #####  ####### #     # ######  \n");
    printf("%s",NORMAL);
    printf("\nSilahkan masukkan menu\n(1| Start Game\n(2| Load Game \n(3| New Game\nMasukkan nomor perintah!\n\nENTER COMMAND: ");
    startTokenStd();    
    do{
        while(currentToken.len!=1){
            printf("\n\nSilahkan masukkan menu\n(1| Start Game\n(2| Load Game \n(3| New Game\nMasukkan nomor perintah!\n\nENTER COMMAND: ");   
            advTokenStdin();
        }
    command = (int)(currentToken).tokenArray[0]-'0';
    }while(!(command == 1 || command == 2 || command ==3));
    if(command==1){
            printf("\n==================================");
            printf("\n||  ENTER FILENAME: ");
            advTokenStdin();
            printf("==================================");

            boolean isFileValid=false;
            while(fp==NULL){
                for(i=0;i<=currentToken.len;i++){
                    if(i!=currentToken.len) test[i]=currentToken.tokenArray[i];
                    else test[i]='\0';

                    if(currentToken.tokenArray[i]=='.') isFileValid=true;
                }
                if(isFileValid){ 
                fp= fopen(test,"r");
                }
                if(fp==NULL) {
                    printf("\n==================================");
                    printf("\n||  ENTER FILENAME: ");
                    advTokenStdin(); 
                    printf("==================================");
                }
            }
            readConfigFiles(test,&mapheight,&mapLength,&HQLoc,&arrayOfBuilding,&adjMatrix,&daftarPesanan);
            mobitaLocation(mobiTime) = HQLoc;
            createTime(&mobiTime,HQLoc);
    }else if(command ==2){
        printf("Maaf fitur belum dapat diakses dan sedang dalam pengembangan.\n");
    }else{
        printf("Selamat Tinggal, terima kasih telah bersua.\n");
    }

    if(command==1){
        printf("\n\n==================================");
        printf("\n||  %s%s", BLUE, "Welcome");
        printf("%s", NORMAL);
        printf(" to Mobita");
        printStringColor(RED," vs ");
        printf("PPKM");
        printf("\t||\n==================================");
        eot=true;
        endToken=true;
        adv();
        currentToken.len=0;
        printf("\n\nENTER COMMAND: ");
        startTokenStd();
        char * cmd;
        cmd = (char *) malloc(101*sizeof(char));
        while (!isEmptyQueue(daftarPesanan) || !isListEmpty(todo) || !isListEmpty(inprogressList) || !(mobitaLocation(mobiTime).col==HQLoc.col && mobitaLocation(mobiTime).row== HQLoc.row))
        {
            for(i=0;i<=currentToken.len;i++){
            if(i!=currentToken.len) cmd[i]=currentToken.tokenArray[i];
            else cmd[i]='\0';
            }
            if(stringCompare(cmd,"MOVE")){
                MOVE(&mobiTime,arrayOfBuilding,adjMatrix);
                updateToDoAndPerishable(&mobiTime,&todo,&inprogressList,&daftarPesanan,&mobiBag);

            }else if(stringCompare(cmd,"PICK_UP")){
                PICK_UP(&todo,&inprogressList,&mobiBag,&mobiTime,arrayOfBuilding);
            }else if(stringCompare(cmd,"DROP_OFF")){
                DROP_OFF(&todo,&inprogressList,&mobiBag,&mobiTime, arrayOfBuilding);
            }else if(stringCompare(cmd, "MAP")){

                printMap(todo,adjMatrix,arrayOfBuilding,mapLength,mapheight,mobiTime,mobiBag);
            }else if(stringCompare(cmd,"TO_DO")){
                TO_DO(todo);
            }else if(stringCompare(cmd,"IN_PROGRESS")){
                IN_PROGRESS(inprogressList);
                //printf("progrlist");
            }else if(stringCompare(cmd,"INVENTORY")){
                INVENTORY(&listGadget,&mobiBag,&mobiTime,todo,adjMatrix,arrayOfBuilding,mapLength,mapheight);
                //printf("inventory\n");
            }else if(stringCompare(cmd,"BUY")){
                BUY(&mobiTime,&listGadget, arrayOfBuilding);

            }else if(stringCompare(cmd,"HELP")){
                HELP();

            }else if(stringCompare(cmd,"RETURN")){
                activateReturnToSender1(&mobiBag, &todo, &inprogressList, &mobiTime);
            }else if(stringCompare(cmd,"STATUS")){
                printf("HEAVY ITEM YANG DIBAWA: %d\n", heavyItem(mobiTime));
                printf("JUMLAH SPEEDBOOST SEKARANG: %d\n", speedBoost(mobiTime));
                printf("JUMLAH RETURN TO SENDER SEKARANG: %d\n", returnToSender(mobiTime));
                
            }else{
                printf("PERINTAH TIDAK SESUAI.");
            }
            displayStatus(mobiTime,arrayOfBuilding); 

            printf("ENTER COMMAND: ");
            ignoreBlankStdin();
            advTokenStdin();

        } 
    }

    printf("PERMAINAN SELESAI SELAMAT");
    
}