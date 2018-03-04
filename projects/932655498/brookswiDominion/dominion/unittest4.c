
#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Test buyCard(...)
//Reference & Citation testBuyCard.c ws used for info on how to set up a game for test
//Note my buyCard is different than the given testBuyCard
int main(int argc, char ** argv){
    printf("Unit Test 4: Beginning\n");
    
    struct gameState G;
    int i, n, r, p, deckCount, discardCount, handCount;
    int testGame, randInt = 0;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine,
        remodel, smithy, village, baron, great_hall};
    
    randInt = rand() % 10;
    //Creating a test game
    testGame = initializeGame(2, k, randInt, &G);
    assert(testGame == 0);
    
    G.coins = 10;
    G.numBuys = 0;
    int didBuyResult = 0;
    
    //test number of buys returns -1 if user have no buys
    G.numBuys = 0;
    didBuyResult = buyCard(2,&G);
    assert(didBuyResult == -1);
    printf("Unit Test 4: Passed check to see if user has > 0 numBuys\n");
    
    //test successfull buy
    G.numBuys = 1;
    didBuyResult = -1;
    didBuyResult = buyCard(2,&G);
    assert(didBuyResult == 0);
    printf("Unit Test 4: Passed check to buyCard(...)\n");
    
    printf("Unit Test 4: Ended With Success\n");
    
    return 0;
}
