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


void startTokenStd(char *c){
    startIn(c);
    salinTokenSTDIN();
}

void salinTokenSTDIN(){
    int i = 0;
    currentToken.len=0;
    while(currentChar!=MARK && currentChar !=' ' && currentChar!='\n' && (i<MAX)){
        i++;
        currentToken.tokenArray[i]=currentChar;
        advStartIn();
    }
    currentToken.len =i;
}


void advTokenStdin(){
    if(currentChar==MARK || currentChar == ' ' || currentChar =='\n') endToken=true;
    else{

        ignoreBlank();
        salinToken();
        adv();
    }
}

/*
matrix tokenToMatrix(int m){
    matrix M;
    createEmptyMatrix(m,m,&M);
    nRowEff(M)=m;
    nColEff(M)=m;
    int i,j;
    for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
            locationPtr(M,i,j)=tokenToInt(token);
            advToken();
        }
    }
}

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

