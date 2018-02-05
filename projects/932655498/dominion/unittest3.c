#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//Test the isGameOver(...) function
//Game is over when isGameOver returns 1 instead of 0
//Reference & Citation testBuyCard.c ws used for info on how to set up a game for test
int main(int argc, char ** argv){
    printf("Unit Test 3: Beginning\n");
    
    struct gameState G;
    int i, n, r, p, deckCount, discardCount, handCount;
    int testGame, randInt = 0;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine,
        remodel, smithy, village, baron, great_hall};
    
    randInt = rand() % 10;
    //Creating a test game
    testGame = initializeGame(2, k, randInt, &G);
    assert(testGame == 0);
    
    //Bring Providence Cards to 0 and see if the game ends
    int cardCount = 0;
    int gameIsOverBool = 0;
    
    for(cardCount = 3; cardCount >=0; cardCount--){
        G.supplyCount[province] = cardCount;
        gameIsOverBool = isGameOver(&G);
        printf("Unit Test 3: Providence card count: %d gameIsOverBool: %d\n",cardCount,gameIsOverBool);
    }
    assert(gameIsOverBool == 1);
    
    
    //Bring 3 supply piles to 0 and see if the game ends
    G.supplyCount[province] = 1; //set province count above 0 for next test
    gameIsOverBool = 1; //set game back to not over
    int j = 1;
    for(cardCount = 3; cardCount>=0; cardCount--){
        G.supplyCount[j] = cardCount;
        G.supplyCount[j+1] = cardCount;
        G.supplyCount[j+2] = cardCount;
        gameIsOverBool = isGameOver(&G);
        printf("Unit Test 3: Supply card count: %d gameIsOverBool: %d\n",cardCount,gameIsOverBool);
    }
    assert(gameIsOverBool == 1);
    printf("Unit Test 3: Ended With Success\n");
    
    return 0;
}
