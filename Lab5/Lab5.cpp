/*
	Dalton Hammel
	C++ Fall 2021
	Due: 10/27/2021
	Lab 5 Number Guessing Game

	Write a number-guessing game in which the computer selects a random number in the range of 0 to 100, and users get a maximum 
	of 20 attempts to guess it. At the end of each game, users should be told whether they won or lost, and then be asked 
	whether they want to play again. When the user quits, the program should output the total number of wins and losses. To make 
	the game more interesting, the program should vary the wording of the messages that it outputs for winning, for losing, and for 
	asking for another game. Create 10 different messages for each of these cases, and use random numbers to choose among them. 
	This application should use at least one Do-While loop and at least one Switch statement. Write your C++ code using good style and
	documenting comments. You should use functions in your code as well. Your source code file should be called Lab5.cpp.
*/

#include <iostream> // Allows the ability to input and output 
#include <iomanip> // Allows to use the setw() function
#include <cmath>
#include <stdlib.h>
#include <ctime>

using namespace std;

void Guesses();
void GoAgain(bool& again);

int win = 0;
int lose = 0;

int main()
{
	bool again = true;

	cout << "Welcome to the Number Guessing Game!" << endl;
	cout << "For this game you will try to guess the number that is randomly generated." << endl;

	do
	{
		Guesses();
		GoAgain(again);
	} while (again);

	return 0;
}

void Guesses()
{
	srand(time(NULL));
	int rand_num = (rand() % 100) + 1;
	int tries = 20;

	for (int i = 0; i < tries; i++)
	{
		int guess;
		cout << endl << "Guess number " << i + 1 << ". What is your guess? ";
		cin >> guess;

		if (guess == rand_num)
		{
			cout << endl << endl << "Congrats! You guessed the number." << endl << endl;
			i = tries;
			win++;
		}
		else
		{
			cout << "Wrong!" << endl;
			if (guess > rand_num)
			{
				cout << "Your guess is too high" << endl << endl;
			}
			else if (guess < rand_num)
			{
				cout << "Your guess is too low" << endl << endl;
			}

			if (i == tries - 1)
			{
				cout << "The number is: " << rand_num << endl;
				lose++;
			}
		}
	}
}

void GoAgain(bool& again)
{
	int again_input;
	cout << "Would you like to play again? Enter 1 for Yes and 2 for No: ";
	cin >> again_input;

	switch (again_input)
	{
	case 1:	again = true;
		break;

	case 2:	again = false;
		cout << "You won " << win << " time(s)! And you lost " << lose << " time(s)";
		break;

	default: cout << "Input error! Exiting program." << endl << endl;
		again = false;
		break;
	}
}