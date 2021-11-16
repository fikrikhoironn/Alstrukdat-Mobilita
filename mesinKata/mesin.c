#include <string.h>
#include <stdio.h>
#include "mesin.h"

Token currentToken;
boolean endToken; 

void ignoreBlank(){
    while(currentChar == ' ' || currentChar == '\n'){
        adv();
        //printf("ada blank ");
    }
}

void ignoreBlankStdin(){
    while(currentChar == ' ' || currentChar == '\n'){
        advStartIn();
        //printf("ada blank ");
    }
}


void startToken(char * c){
    start(c);
    ignoreBlank();
    salinToken();
}

void advToken(){
    if(currentChar==EOF) {
        endToken=true;
        printf("end");
    }
    else{
        ignoreBlank();
        salinToken();
    }
}

void salinToken(){
    int i = 0;
    currentToken.len=0;
    while(currentChar!=EOF && currentChar != BLANK && currentChar != '\n' && (i<MAX)){
        if(currentChar==' '||currentChar=='\n') ignoreBlank();
        ++i;
        currentToken.tokenArray[i]=currentChar;
        adv();
    }
    currentToken.len =i;
}

void printToken(Token t){
    int i;
    for(int i=1;i<=t.len;i++){
        printf("%c", t.tokenArray[i]);
    }
}

int tokenToInt(Token t){
    int i =1;
    int val=0;
    while(i<=t.len){
        val*=10;
        //printf("|%c|",t.tokenArray[i]);
        val += (int)t.tokenArray[i]-(int)'0';
        i++;
    }    
    return val;
}

int tokenToIntStd(Token t){
    int i =0;
    int val=0;
    while(i<t.len){
        val*=10;
        //printf("|%c|",t.tokenArray[i]);
        val += (int)t.tokenArray[i]-(int)'0';
        i++;
    }    
    return val;
}

char tokenToChar(Token t){
    return t.tokenArray[1];
}

void copyToken(Token t1, Token *t2){
    (*t2).len=t1.len;
    int i;
    for(i=1;i<=t1.len;i++){
        (*t2).tokenArray[i]=t1.tokenArray[i];
    }
}


boolean compareToken(Token basis, Token compared){
    int i=1;
    boolean test= true;
    if(basis.len!=compared.len) test=false;
    
    while (i<basis.len && test)
    {
        test = currentToken.tokenArray[i]==basis.tokenArray[i];
        i++;
    }
    
    return test;
}

void startTokenStd(){
    //printf("ENTER COMMAND: ");
    startIn();
    ignoreBlankStdin();
    salinTokenSTDIN();
}



void salinTokenSTDIN(){
    int i = 0;
    currentToken.len=0;
    while(currentChar !=' ' && currentChar!='\n' && (i<MAX)){
    currentToken.tokenArray[i]=currentChar;
    i++;
    advStartIn();
    }
    currentToken.len =i;
}


void advTokenStdin(){
    if(currentChar == eot) endToken=true;
    else{
        //printf("ENTER COMMAND: ");
        salinTokenSTDIN();
    }
}

void readConfigFiles(char* c, int *mapHeight, int * mapLength, locationCoord *HQ, ArrayBuild *arrBuild, Matrix* adjMatrix, Queue * daftarPesanan){
    startToken(c);
    *mapHeight = tokenToInt(currentToken);
    advToken();
    *mapLength=tokenToInt(currentToken);
    advToken();


    //printf("Map size is (%d,%d)\n",*mapHeight,*mapLength);
    int xHQ, yHQ;
    xHQ=tokenToInt(currentToken);
    advToken();
    yHQ = tokenToInt(currentToken);


    locations* hqLoc= allocateLocation();
    makeHeadquarters(hqLoc);
    HQ=makeLocationCoord(hqLoc,xHQ,yHQ);

    //printf("%d %d\n%d %d\n",*mapLength,*mapHeight,(*HQ).col,(*HQ).row);
    advToken();
    int m= tokenToInt(currentToken);
    advToken();
    CreateArrayBuild(arrBuild,m+1);
    IsiArray(arrBuild, '8',(*HQ).col,(*HQ).row);
    BacaArray(arrBuild,m);
    //displayArray(*arrBuild);
    int z;
    CreateMatrix(m+1,m+1,adjMatrix);
    for(z=0;z<=m;z++){
        for(int j =0;j<=m;j++){
            ELMT(*adjMatrix,z,j)=tokenToInt(currentToken);
            advToken();
        }
    }

    int mq=tokenToInt(currentToken);
    advToken();
    //printf("Banyak ipesanan %d\n",mq);
    item pesanan;
    CreateQueue(daftarPesanan);
    for(int i=0;i<mq;i++){
        int timeIn = tokenToInt(currentToken);
        advToken();
        char pickUp = tokenToChar(currentToken);
        advToken();
        char dropOff = tokenToChar(currentToken);
        advToken();
        char typeItem = tokenToChar(currentToken);
        int perishable;
        if(typeItem == 'P'){
            advToken();
            perishable = tokenToInt(currentToken);

        }else{
            perishable=-1;
        }
        pesanan=createItem(timeIn, pickUp,dropOff,typeItem,perishable);
        advToken();
        enqueue(daftarPesanan,pesanan);
    }

    currentChar =EOF;
    endToken=true;
    adv();
}
/*    Dari txt ke array */
void BacaArray (ArrayBuild* tes,int isi){
    int i,abs,ord;
    char nama_build;
    i = 1;
    while (i<=isi){
        nama_build = tokenToChar(currentToken);
        advToken();
        ord = tokenToInt(currentToken);
        advToken();
        abs = tokenToInt(currentToken);
        IsiArray(tes,nama_build,abs,ord);
        advToken();
        i++;
    }
    NEFF(*tes)=isi+1;
}

char* readStdString(){
    startTokenStd();
    char* c = &(currentToken.tokenArray[0]);
    eot=true;
    advStartIn();
    return c;
}


boolean stringCompare(char * str1, char *str2){
   int i=0;
    boolean test=str1[i]==str2[i];
   while(str1[i]!='\0' && str2[i]!='\0' && test){
       test= str1[i]==str2[i];
       i++;
   }
    eot=false;
    return str1[i]==str2[i];

}

char* tokenToString(Token test){
    char * c =&(test.tokenArray[0]);
    printf("--%c-%s-\n",test.tokenArray[0],c);
    return c;
}

/*
    int countItem= tokenToInt(currentToken);
    advToken();
    for(int i=0;i<countItem;i++){
        item items;
        items.timeIn=tokenToInt(currentToken);
        advToken();
        items.pickUp=tokenToChar(currentToken);        
        advToken();
        items.dropOff=tokenToChar(currentToken);
        advToken();
        items.typeItem=tokenToChar(currentToken);
        if(items.typeItem=='P'){
            advToken();
            items.perishableTime=tokenToInt(currentToken);
        }
        advToken();
        pushBag(bag,items);
    
    }
*/

/*

matrix tokenToMatrix(int m){
    matrix M;
    createEmptyMatrix(m,m,&M);
    nRowEff(M)=m;
    nColEff(M)=m;
    int i,j;
    for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
            locationPtr(M,i,j)=tokenToInt(currentToken);
            advToken();
        }
    }
}
*/

/*
locations tokenToLoc(int m){

}
*/

/*
graph tokenToGraph(Token t){
    graph g;
    Token token;
    
    return g;
}
*/

