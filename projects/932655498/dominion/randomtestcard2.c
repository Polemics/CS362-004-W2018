//Dustin Pack
//15 FEB 2018
//Random Test Smithy

//Note look for "//soft assert" to see where im actually performing a logical test
//This code does not include a hard assert that crashes the program
//Reference & Citation testBuyCard.c was used for info on how to set up a game for test
//Citation for Generating Random Game State https://piazza.com/class/jbk4lmzexg4ce?cid=169
//Citation for random test coverage https://piazza.com/class/jbk4lmzexg4ce?cid=164
//Citation for gcov branch coverage https://piazza.com/class/jbk4lmzexg4ce?cid=158
//Citation or makefile help https://piazza.com/class/jbk4lmzexg4ce?cid=130
//Citation for c rand() https://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
//Citation for c passing a struct https://stackoverflow.com/questions/10370047/passing-struct-to-function


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "dominion.h"

int main () {
    srand(time(NULL));
    
    int k[10] = {adventurer, council_room, feast, gardens, mine,
        remodel, smithy, duchy, baron, great_hall};
    
    struct gameState unchangedGameState;
    struct gameState testGameState;
    
    int smithy_effect_fail_counter = 0;
    int num_tests = 500;
    int num_tests_performed = 0;
    int test_counter = 0;
    
    printf("Begin Random Smithy Test\n");
    // randomly initialized the game state
    for (test_counter = 0; test_counter < num_tests; test_counter++) {
        
        //set up the game variables
        int players, player;
        players = (rand() % 3) + 2; //2-3 players
        player = rand() % players;
        int randGameSeed = rand();
        //soft assert
        if (!(initializeGame(players, k, randGameSeed, &unchangedGameState) == 0)){
            printf("Failed to initalize during test %d\n", test_counter);
            break;
        }
        
        //randomly set up the player variables
        unchangedGameState.deckCount[player] = (rand() % (MAX_DECK - 1)) + 1;
        unchangedGameState.discardCount[player] = (rand() % (MAX_DECK - 1)) + 1;
        unchangedGameState.handCount[player] = (rand() % (MAX_HAND - 1)) + 1;
        unchangedGameState.whoseTurn = player;
        
        //Begin Testing
        
        //The game is now set up; copy the state as 'unchangedGameState'
        //This is used later in the program to test if the game state actually changed
        testGameState = unchangedGameState;
        int bonus = 0;
        
        //call smithy card and make sure it returnes a 0
        //NOTE My Smithy Card always returns a -1, this will always fail
        //NOTE 2 I supressed the printf so as to not spam the console with fails
        //and instead added a fail counter to be reported at the end
        int smithyReturnValue;
        smithyReturnValue = cardEffect(smithy,0,0,0,&unchangedGameState,0,&bonus);
        if (smithyReturnValue == -1) {
            //printf("Smithy Card Effect test failed during %d", test_counter);
            smithy_effect_fail_counter++;
        }
        
        
        //call draw card 3 times and see if it fails
        int draw1, draw2, draw3;
        draw1 = drawCard(player,&testGameState);
        if (draw1 == -1) { //soft assert
            printf("First Draw Card test failed during %d\n", test_counter);
        }
        draw2 = drawCard(player,&testGameState);
        if (draw2 == -1) { //soft assert
            printf("Second Draw Card test failed during %d\n", test_counter);
        }
        draw3 = drawCard(player,&testGameState);
        if (draw3 == -1) { //soft assert
            printf("Third Draw Card test failed during %d\n", test_counter);
        }
        //check to see if the draw card failed and if the deck counter was > 0
        //cant draw from an empty deck
        if ((draw1 == -1 || draw2 == -1 || draw3 == -1) && testGameState.deckCount[player] > 0) { //soft assert
            printf("Deck Count test failed while drawing card during %d\n", test_counter);
        }
        
        
        //call discardCard and check its return value
        int discardReturnValue;
        discardReturnValue = discardCard(0, player, &testGameState, 0);
        if (discardReturnValue == -1) { //soft assert
            printf("Card Effect test failed during %d\n", test_counter);
        }
        
        //check if the hand count is the same
        if (!(unchangedGameState.handCount[player] == testGameState.handCount[player])) { //soft assert
            printf("Hand Count test failed during %d\n", test_counter);
        }
        
        //check if the deck count is the same
        if (!(unchangedGameState.deckCount[player] == testGameState.deckCount[player])) { //soft assert
            printf("Deck Count test failed during %d\n", test_counter);
        }
        num_tests_performed++;
        
    }
    if (smithy_effect_fail_counter > 0) { //soft assert
        printf("Smithy card effect failed: %d times\n",smithy_effect_fail_counter);
    }
    printf("Number of Tests Completed: %d\n", num_tests_performed);
    printf("End Smithy Test\n");
    
    return 0;
}

