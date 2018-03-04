#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Test the Cost of a Card Function
int main(int argc, char ** argv){
    int x;
    x = getCost(0);
    printf("%d\n",x);
    
    if (x >= 0) {
        printf("Unit Test 1: getCost() Passed.\n");
    } else {
        printf("Unit Test 1: getCost() Failed Cost is not a positive int.\n");
    }
    
    printf("Unit Test 1: Ended With Success\n");
    return 0;
}
