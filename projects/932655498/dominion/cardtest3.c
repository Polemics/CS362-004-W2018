#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Test Feast
//Reference & Citation testBuyCard.c ws used for info on how to set up a game for test
//NOTE: My Feast has a bug from assignment 2
/*
 Feast: initialized line 1220 x = 0 instead of 1. The While loop will not trigger.
 */
int main(int argc, char ** argv){
    printf("Card Test 3: Feast: Beginning\n");
    
    struct gameState G;
    int i, n, r, p, deckCount, discardCount, handCount;
    int testGame, randInt = 0;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine,
        remodel, smithy, village, baron, great_hall};
    
    randInt = rand() % 10;
    //Creating a test game
    testGame = initializeGame(2, k, randInt, &G);
    assert(testGame == 0);
    
    //variables for testing
    int feastResult = -1; //set at any number besides 0 (0 == success)
    int currentPlayer = 0;
    int temphand[MAX_HAND];
    int choice1 = 1;
    
    feastResult = cardFeast (currentPlayer,&G, temphand,choice1);
    if (feastResult == -1) {
        printf("Card Test 3: Feast: -1 Returned, Test Failed\n");
    } else {
        printf("Card Test 3: Feast: 0 Returned, Test Passed\n");
    }
    
    
    printf("Card Test 3: Feast: Ended\n");
    return 0;
}


