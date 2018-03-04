CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

randomtestcard1.out: randomtestcard1.c dominion.c
	gcc -o randomtestcard1 randomtestcard1.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard1 > randomtestcard1.out
	gcov dominion.c -b >> randomtestcard1.out 
	cat dominion.c.gcov >> randomtestcard1.out

randomtestcard2.out: randomtestcard2.c dominion.c
	gcc -o randomtestcard2 randomtestcard2.c dominion.c rngs.c $(CFLAGS)
	./randomtestcard2 > randomtestcard2.out
	gcov dominion.c -b >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

randomtestadventurer.out: randomtestadventurer.c dominion.c
	gcc -o randomtestadventurer randomtestadventurer.c dominion.c rngs.c -g $(CFLAGS)
	./randomtestadventurer > randomtestadventurer.out
	gcov dominion.c -b >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out


unit1: unittest1.c dominion.c
	gcc -o unit1 unittest1.c dominion.c rngs.c -g $(CFLAGS)
	./unit1 > unit1.out
	gcov dominion.c -b >> unit1.out
	cat dominion.c.gcov >> unit1.out

unit2: unittest2.c dominion.c
	gcc -o unit2 unittest2.c dominion.c rngs.c -g $(CFLAGS)
	./unit2 > unit2.out
	gcov dominion.c -b >> unit2.out
	cat dominion.c.gcov >> unit2.out

unit3: unittest3.c dominion.c
	gcc -o unit3 unittest3.c dominion.c rngs.c -g $(CFLAGS)
	./unit3 > unit3.out
	gcov dominion.c -b >> unit3.out
	cat dominion.c.gcov >> unit3.out

unit4: unittest4.c dominion.c
	gcc -o unit4 unittest4.c dominion.c rngs.c -g $(CFLAGS)
	./unit4 > unit4.out
	gcov dominion.c -b >> unit4.out
	cat dominion.c.gcov >> unit4.out

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe

cleantests:
	rm -f unittestresults.out unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 *.gcda *.gcno *.gcov
