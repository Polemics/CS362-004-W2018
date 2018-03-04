#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Test Smithy
//Reference & Citation testBuyCard.c ws used for info on how to set up a game for test
//NOTE: My Smithy has a bug from assignment 2, it returns -1 instead of 0
int main(int argc, char ** argv){
    printf("Card Test 1: Smithy: Beginning\n");
    
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
    int smithyResult = 2; //set at any number besides -1 or 0
    int currentPlayer = 0;
    int handPos = 4;
    
    smithyResult = cardSmithy(currentPlayer, &G, handPos);
    if (smithyResult == -1) {
        printf("Card Test 1: Smithy: -1 Returned, Test Failed\n");
    }
    if (smithyResult == 0)
    {
        printf("Card Test 1: Smithy: 0 Returned, Test Passed\n");
    }
    
    
    printf("Card Test 1: Smithy: Ended\n");
    return 0;
}

