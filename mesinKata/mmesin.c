#include <stdio.h>
#include "mesin.h"


int main(){
    Token tt;
    startToken("tes.config");
    tt=currentToken;
    advToken();
    printToken(currentToken);
    int a=tokenToInt(currentToken);
    printf("-%d-",a);
    return 0;
}