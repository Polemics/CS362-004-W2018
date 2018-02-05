#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Test updated Coins function (line 1301 in dominion.c)
//Reference & Citation testBuyCard.c ws used for info on how to set up a game for test
int main(int argc, char ** argv){
    printf("Unit Test 2: Beginning\n");
    
    struct gameState G;
    int i, n, r, p, deckCount, discardCount, handCount;
    int testGame, randInt = 0;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine,
        remodel, smithy, village, baron, great_hall};
    
    randInt = rand() % 10;
    //Creating a test game
    testGame = initializeGame(2, k, randInt, &G);
    assert(testGame == 0);
    
    if (G.coins = 4){
        //printf("\nInitial Coins = %d\n", G.coins);
        //printf("Updating Coins by 1 using bonus parameter\n");
        updateCoins(0, &G, 1);
        assert(G.coins == 5);
        //printf("Updated Coins = %d\n", G.coins);
        //printf("Updating Coins by swapping card 0 with a gold\n");
        G.hand[0][0] = gold;
        updateCoins(0,&G,0);
        assert(G.coins == 7);
        //printf("Updating Coins by swapping card 1 with a silver\n");
        G.hand[0][1] = silver;
        updateCoins(0,&G,0);
        assert(G.coins == 8);
        //printf("Coins = %d\n", G.coins);
    }
    if (G.coins = 8) {
        printf("Unit Test 2: Passed updatedCoins()\n");
    }
    printf("Unit Test 2: Ended With Success\n");
    return 0;
}
