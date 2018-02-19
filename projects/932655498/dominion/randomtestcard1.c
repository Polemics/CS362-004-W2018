//Dustin Pack
//15 FEB 2018
//Random Test Village

//Note look for "//soft assert" to see where im actually performing a logical test
//This code does not include a hard assert that crashes the program
//Reference & Citation testBuyCard.c was used for info on how to set up a game for test
//Citation for Generating Random Game State https://piazza.com/class/jbk4lmzexg4ce?cid=169
//Citation for random test coverage https://piazza.com/class/jbk4lmzexg4ce?cid=164
//Citation for gcov branch coverage https://piazza.com/class/jbk4lmzexg4ce?cid=158
//Citation or makefile help https://piazza.com/class/jbk4lmzexg4ce?cid=130
//Citation for c rand() https://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
//Citation for c passing a struct https://stackoverflow.com/questions/10370047/passing-struct-to-function
#include "dominion.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    //Village is not in the supply deck, we will add village later
    int k[10] = {adventurer, council_room, feast, gardens, mine,
        remodel, smithy, duchy, baron, great_hall};

    struct gameState testGameState;
    struct gameState unchangedGameState;
    
    //where the village card on hand position
    printf("Begin Random Village Test\n");
    //loop will run until num_tests has been reached
    //this method was picked so NUM_TESTS could be dialed up or down to meet desired
    int num_tests = 50;
    int num_tests_performed = 0;
    int test_counter;
    int idx; //for loop counters
    for (test_counter = 0; test_counter < num_tests; test_counter++) {
        
        //set up the game variables
        int randGameSeed = rand();
        int players, player;
        players = (rand() % 3) + 2; //2-3 players
        player = rand() % players;

        //setup the game and make a copy for later comparisons
        if (!(initializeGame(players, k, randGameSeed, &testGameState) == 0)){
            printf("Failed to initalize during test %d\n", test_counter);
            break;
        }
        
        //set the player's turn
        testGameState.whoseTurn = player;
        
        //set hand for player
        testGameState.handCount[player] = (rand() % (MAX_HAND - 1)) + 1;
        for (idx = 0; idx < testGameState.handCount[player]; idx++) {
            testGameState.hand[player][idx] = k[rand() % 10];
        }
        
        //replace a card in the hand with a village card
        int villageHandPosition;
        villageHandPosition = rand() % testGameState.handCount[player];
        testGameState.hand[player][villageHandPosition] = village;
        
        //set deck for player
        testGameState.deckCount[player] = (rand() % (MAX_DECK - 1)) + 1;
        for (idx = 0; idx < testGameState.deckCount[player]; idx++) {
            testGameState.deck[player][idx] = k[rand() % 10];
        }
        
        //set discard count to be less than the player's hand count
        testGameState.discardCount[player] = (rand() % (MAX_DECK - 1)) + 1;
        while (testGameState.discardCount[player] >= testGameState.handCount[player]){
            testGameState.discardCount[player] --;
        }
        
        for (idx = 0; idx < testGameState.discardCount[player]; idx++) {
            testGameState.discard[player][idx] = k[rand() % 10];
        }
        
        //The game is now set up; copy the state as 'unchangedGameState'
        //This is used later in the program to test if the game state actually changed
        unchangedGameState = testGameState;
        
        //Call the village card effect
        if (!(cardEffect(village, 0, 0, 0, &unchangedGameState, villageHandPosition, 0) == 0)){
            printf("Card effect failed to during test %d\n", test_counter);
            break;
        }
        
        //check if no card called village
        for (idx = 0; idx < unchangedGameState.handCount[player]; idx++){
            if (unchangedGameState.hand[player][idx] == 14){
                printf("Village card is still in the hand %d\n", test_counter);
                break;
            }
        }
        
        //from the card effect called above check that we have 2 more actions to perform now
        if (!(unchangedGameState.numActions == testGameState.numActions + 2)){
            printf("Player failed to have +2 actions %d\n", test_counter);
            break;
        }
        
        //from the card effect caled above check that the player's hand count is still the same
        //this is due to drawing 1 card and discarding 1 card
        if (!(unchangedGameState.handCount[player] == testGameState.handCount[player])){
            printf("Player's hand failed to discard a card on test %d\n", test_counter);
            break;
        }
        num_tests_performed++;
    }
    printf("Number of Tests Completed: %d\n", num_tests_performed);
    printf("End Village Test\n");
    
    return 0;
}
