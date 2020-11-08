// MemoryLeak_20201108.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include<stdlib.h>
#include <time.h>

int cash = 100;
void Play(int bet) {
    char c1[3] = { 'J','Q','K' };
    //printf("Shuffling...\n");
    srand(time(NULL)); //seeding  random number generator
    int i;
    for ( i = 0; i < 5; i++)
    {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = c1[x];
        c1[x] = c1[y];
        c1[y] = temp; //swap characters at position x and y
    }
    int playersGuess;
    printf("What's the positon of the Queen 1, 2 or 3?");
    scanf_s("%d", &playersGuess);
    if (c1[playersGuess-1]=='Q')//because the array starts with 0
    {
        cash += 3 * bet;
        printf("You Win ! Result = \"%c %c %c\" Total cash = %d\n", c1[0], c1[1], c1[2], cash);
    }
    else
    {
        cash -= bet;
        printf("You Loose ! Result = \"%c %c %c\" Total cash = %d\n", c1[0], c1[1], c1[2], cash);
    }
}


int main()
{
    int bet;
    printf("WELLCOME TO THE VIRTUAL CASINO\n");
    printf("Total cash is $%d\n", cash);
    while (cash >0)
    {
        printf("What is your bet? $");
        scanf_s("%d", &bet);
        if (bet == 0 || bet > cash) break;
        Play(bet);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
