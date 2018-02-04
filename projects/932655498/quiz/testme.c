//Dustin W. Pack
//CS 362
//Quiz
//3 FEB 2018

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//inputChar() creates an integer assignable to char that represents an ASCII value
//acceptable range on the ASCII table is from 32 to 127
char inputChar()
{
    char randChar;
    randChar = (rand() % 95) + 32;
    return randChar;
}

//inputString() creates a string based on random characters
//acceptable characters come from the ASCII range of 97 - 122.
//To test testme() we need a string length of 6 to account for 5 characters and 1 \0
char *inputString()
{
    //variables and constants to operate with
    const int stringLength = 6;
    int idx; //index for outer for loops
    int jdx; //index for inner for loops
    static char randomString[6];
    
    //conditional branch gives a 1 in 2 chance of attempting to make a string
    //using only characters 'r' 'e' 's' 't' in order do make the string 'reset'
    //this was opted for since a true random string ws taking millions of iterations
    //to get to 'reset' randomly
    if((rand() % 2) == 0)
    {
        for(idx = 0; idx < (stringLength -1); idx++)
        {
            jdx = (rand() % 4);
            switch (jdx){
                case 1:
                    randomString[idx] = 'r';
                    break;
                case 2:
                    randomString[idx] = 'e';
                    break;
                case 3:
                    randomString[idx] = 's';
                    break;
                default:
                    randomString[idx] = 't';
                    break;
            }
        }
    }
    //create a random string from the 97-122 ASCII range
    //note previous iterations of this test used the full ascii range but
    //it was paired down to just this range in order to eliminate odd outputs
    //and reduce loop time down to the thousands.
    else
    {
        for(idx = 0; idx < (stringLength -1); idx++)
        {
            randomString[idx] = (rand() % 25) + 97;
        }
    }
    randomString[stringLength -1] = '\0';
    return randomString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
