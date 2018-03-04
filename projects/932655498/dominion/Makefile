CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

randa:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestadventurer.c rngs.c -o randa -lm -g

debuga:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestadventurer.c rngs.c -o debuga -lm -g
	./debuga


rand1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestcard1.c rngs.c -o rand1 -lm -g

rand2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestcard2.c rngs.c -o rand2 -lm -g

randk:
	rm -f randa rand1 rand2

mr2: randk  randa rand1 rand2 

runrand: mr2
	./randa
	rm -f randomtestadventurer.out 
	rm -f randomtestadventurer.c.gcov
	rm -f randomtestadventurer.gcda
#	rm -f randomtestadventurer.gcno
	./randa > randomtestadventurer.out 
	gcov randomtestadventurer.c >> randomtestadventurer.out 
	cat randomtestadventurer.c.gcov >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

	./rand1
	rm -f randomtestcard1.out
	rm -f randomtestcard1.c.gcov
	rm -f randomtestcard1.gcda	
	./rand1 > randomtestcard1.out	
	gcov randomtestcard1.c >> randomtestcard1.out
	cat randomtestcard1.c.gcov >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out 
	
	./rand2
	rm -f randomtestcard2.out
	rm -f randomtestcard2.c.gcov
	rm -f randomtestcard2.gcda
	./rand2 > randomtestcard2.out
	gcov randomtestcard2.c >> randomtestcard2.out 
	cat randomtestcard2.c.gcov >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out



clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randa player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so