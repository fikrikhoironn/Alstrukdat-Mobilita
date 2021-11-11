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


void startTokenStd(){
    startIn();
    salinTokenSTDIN();
}

void salinTokenSTDIN(){
    int i = 0;
    currentToken.len=0;
    while(currentChar !=' ' && currentChar!='\n' && (i<MAX)){
        ++i;
        currentToken.tokenArray[i]=currentChar;
        advStartIn();
    }
    currentToken.len =i;
}


void advTokenStdin(){
    if(currentChar == ' ' || currentChar =='\n') endToken=true;
    else{
        ignoreBlank();
        salinTokenSTDIN();
    }
}

void readConfigFiles(char* c, int *mapHeight, int * mapLength, locationCoord *HQ, ArrayBuild *arrBuild, Matrix* adjMatrix){
    startToken(c);
    *mapHeight = tokenToInt(currentToken);
    advToken();
    *mapLength=tokenToInt(currentToken);
    advToken();


    printf("Map size is (%d,%d)\n",*mapHeight,*mapLength);
    int xHQ, yHQ;
    xHQ=tokenToInt(currentToken);
    advToken();
    yHQ = tokenToInt(currentToken);


    locations* hqLoc= allocateLocation();
    makeHeadquarters(hqLoc);
    *HQ=MakePOINT(xHQ,yHQ);
    (*HQ).location=hqLoc;


    advToken();
    int m= tokenToInt(currentToken);
    printf("\n---%d---\n",m);
    int i;


    advToken();
    BacaArray(arrBuild,m);
 

    CreateMatrix(m+1,m+1,adjMatrix);
    for(i=0;i<=m;i++){
        for(int j =0;j<=m;j++){
            ELMT(*adjMatrix,i,j)=tokenToInt(currentToken);
            advToken();
        }
    }
    currentChar =EOF;
    endToken=true;
    adv();
}
/*    Dari txt ke array */
void BacaArray (ArrayBuild* tes,int isi){
    ArrayBuild array;
    CreateArrayBuild(&array,isi);
    int i,abs,ord;
    char nama_build;
    i = 0;
    while (i<isi){
        nama_build = tokenToChar(currentToken);
        advToken();
        abs = tokenToInt(currentToken);
        advToken();
        ord = tokenToInt(currentToken);
        IsiArray(&array,nama_build,abs,ord);
        advToken();
        i++;
    }
    NEFF(array)=isi;
    *tes=array;
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

