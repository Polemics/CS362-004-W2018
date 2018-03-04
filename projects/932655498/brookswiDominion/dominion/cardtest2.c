#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Test Adventurer
//Reference & Citation testBuyCard.c ws used for info on how to set up a game for test
//NOTE: My Adventurer has a bug from assignment 2, it returns -1 instead of 0
/*
 Adventurer: line 1182 changed second || operator to an && operator. This will cause the treasure counter to not increment unless the player draws a silver AND a gold... which isn’t possible while drawing 1 card.
 */
int main(int argc, char ** argv){
    printf("Card Test 2: Adventurer: Beginning\n");
    
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
    int adventurerResult = 2; //set at any number besides -1 or 0
    int currentPlayer = 0;
    int temphand[MAX_HAND];
    int z = 0; //counter for temp hand
    int drawntreasure = 0;
    int cardDrawn;
    
    adventurerResult = cardAdventurer(currentPlayer,temphand, z,&G,drawntreasure,cardDrawn);
    
    //printf("adventurerResult Is: %d\n", adventurerResult);
    if (adventurerResult == -1) {
        printf("Card Test 2: Adventurer: -1 Returned, Test Failed\n");
    } else {
        printf("Card Test 2: Adventurer: 0 Returned, Test Passed\n");
    }
    
    
    printf("Card Test 2: Adventurer: Ended\n");
    return 0;
}


