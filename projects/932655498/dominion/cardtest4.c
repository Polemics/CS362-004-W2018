#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Test Village
//Reference & Citation testBuyCard.c ws used for info on how to set up a game for test
//NOTE: This test is not a card from assignment 2, should have no bugs and is implemented int he case statement and not in its own function
int main(int argc, char ** argv){
    printf("Card Test 4: Village: Beginning\n");
    
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
    int villageResult = 2; //set at any number besides -1 or 0
    int currentPlayer = 0;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 4;
    int bonus = 0;
    
    villageResult = cardEffect(village, choice1, choice2, choice3, &G, handPos, bonus);
    //printf("Card Test 4: Village: villageResult %d\n",villageResult);
    if (villageResult == -1) {
        printf("Card Test 4: Village: -1 Returned, Test Failed\n");
    } else {
        printf("Card Test 4: Village: 0 Returned, Test Passed\n");
    }
    
    
    printf("Card Test 4: Village: Ended\n");
    return 0;
}


