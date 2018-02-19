//Dustin Pack
//15 FEB 2018
//Random Test Adventurer

//Note look for "//soft assert" to see where im actually performing a logical test
//This code does not include a hard assert that crashes the program
//Reference & Citation testBuyCard.c was used for info on how to set up a game for test
//Citation for Generating Random Game State https://piazza.com/class/jbk4lmzexg4ce?cid=169
//Citation for random test coverage https://piazza.com/class/jbk4lmzexg4ce?cid=164
//Citation for gcov branch coverage https://piazza.com/class/jbk4lmzexg4ce?cid=158
//Citation or makefile help https://piazza.com/class/jbk4lmzexg4ce?cid=130
//Citation for c rand() https://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
//Citation for c passing a struct https://stackoverflow.com/questions/10370047/passing-struct-to-function
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"

int main() {
    srand(time(NULL));
    int k[10] = {adventurer, council_room, feast, gardens, mine,
        remodel, smithy, duchy, baron, great_hall};
    int coin_counter1 = 0;
    int coin_counter2 = 0;
    int test_counter = 0;
    int idx;
    int jdx;
    struct gameState testGameState;
    
    printf("Begin Random Adventurer Test\n");
    
    //loop will run until num_tests has been reached
    //This method was picked so NUM_TESTS could be dialed up or down to meet desired 
    int num_tests = 50;
    int num_tests_performed = 0;
    for (test_counter = 0; test_counter < num_tests; test_counter++) {
        //This line was supressed in order to not spam the terminal
        //printf("Running Test%d\n", test_counter);
        
        //set up the game variables
        int randGameSeed = rand();
        int players, player;
        players = (rand() % 3) + 2; //2-3 players
        player = rand() % players; //set a random player
        
        //setup the game
        if (!(initializeGame(players, k, randGameSeed, &testGameState) == 0)){
            printf("Failed to initalize during test %d", test_counter);
            break;
        }
        
        //set the player's turn
        testGameState.whoseTurn = player;
        
        //set hand for player
        testGameState.handCount[player] = (rand() % (MAX_HAND - 1)) + 1;
        for (idx = 0; idx < testGameState.handCount[player]; idx++) {
            testGameState.hand[player][idx] = rand() % treasure_map;
        }
        
        //set deck for player
        testGameState.deckCount[player] = (rand() % (MAX_DECK - 1)) + 1;
        for (idx = 0; idx < testGameState.deckCount[player]; idx++) {
            testGameState.deck[player][idx] = rand() % treasure_map;
        }
        
        //set discard count to be less than the player's hand count
        testGameState.discardCount[player] = (rand() % (MAX_DECK - 1)) + 1;
        while (testGameState.discardCount[player] >= testGameState.handCount[player]){
            testGameState.discardCount[player] --;
        }
        
        for (idx = 0; idx < testGameState.discardCount[player]; idx++) {
            testGameState.discard[player][idx] = rand() % treasure_map;
        }
        
        //test using a gold piece
        if (testGameState.deckCount[player] != 0){
            coin_counter1 = 0;
            jdx = rand() % testGameState.deckCount[player];
            testGameState.deck[player][jdx] = gold;
            testGameState.deck[player][jdx+1] = gold;
            for (idx = 0; idx < testGameState.handCount[player]; idx++){
                if (testGameState.hand[player][idx] == 6 || testGameState.hand[player][idx] == 5 || testGameState.hand[player][idx] == 4){
                    coin_counter1++;
                }
            }
            //soft assert to make sure the card effect triggered
            if (!(cardEffect(adventurer, 0, 0, 0, &testGameState, 0, 0) == 0)){
                printf("Failed to trigger the card effect on test %d ", test_counter);
                
            }
            //make sure treasure is in the hand
            coin_counter2 = 0;
            for (idx = 0; idx < testGameState.handCount[player]; idx++){
                if (testGameState.hand[player][idx] == 6|| testGameState.hand[player][idx] == 5 || testGameState.hand[player][idx] == 4){
                    coin_counter2++;
                }
            }
            //soft assrt to make sure the counts of teasures line up
            //note this SHOULD fail some times since I introduced a bug in assignment 2
            if (!(coin_counter2 == (coin_counter1+2))){
                printf("Failed count of the treasure on test %d ", test_counter);
                printf("Treasure should be 2 but treasure is %d\n", coin_counter2);
            }
        }
        num_tests_performed++;
    }
    
    printf("Number of Tests Completed: %d\n", num_tests_performed);
    printf("End Random Adventurer Test\n");
    
    return 0;
}
