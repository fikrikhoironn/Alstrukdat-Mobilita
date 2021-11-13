#include <stdio.h>
#include <string.h>
#include "mesin.h"


int main(){
    startTokenStd();
    char* c = tokenToString(currentToken);
    printf("%s",c);
    advTokenStdin();
    char*z = tokenToString(currentToken);
        printf("\n%s",z);
    return 0;
}