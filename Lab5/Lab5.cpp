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

void Guesses(); // This function is for the game
void GoAgain(bool& again); // This function is for going again
void Win(); // This is for win statements
void Lose(int randomNumber); // This is for lose statements
void TryAgain(); // This is for play again statements

int win = 0;
int lose = 0;

int main() // Where everything is excuted from 
{
	bool again = true;

	cout << "Welcome to the Number Guessing Game!" << endl;
	cout << "For this game you will try to guess the number that is randomly generated." << endl;
	cout << "The number is between 0 and 100. You have 20 guesses to get it right. Good Luck!" << endl;

	do
	{
		Guesses();
		GoAgain(again);
	} while (again);

	return 0;
}

void Guesses() // This function is for the game
{
	srand(time(NULL));
	int randNum = (rand() % 101);
	int tries = 20;

	for (int i = 0; i < tries; i++) // runs while i is less that tries (20)
	{
		int guess;
		cout << endl << "Try number " << i + 1 << ". What is your guess? ";
		cin >> guess;

		if (guess == randNum) // if the guess is correct
		{
			Win();
			i = tries;
			win++;
		}
		else // if the guess is incorrect
		{
			cout << "Wrong!" << endl;
			if (guess > randNum) // if the number is too high
			{
				cout << "Your guess is too high" << endl << endl;
			}
			else if (guess < randNum) // if the number is too low
			{
				cout << "Your guess is too low" << endl << endl;
			}

			if (i == tries - 1) // if the tries goes over 20
			{
				Lose(randNum);
				lose++;
			}
		}
	}
}

void GoAgain(bool& again) // This function is for going again
{
	int tryAgain;
	TryAgain();
	cin >> tryAgain;

	switch (tryAgain)
	{
	case 1:	again = true;
		break;

	case 2:	again = false;
		cout << "You won " << win << " time(s)! And you lost " << lose << " time(s)";
		break;

	default: cout << "Error. Exiting Game" << endl << endl;
		again = false;
		break;
	}
}

void Win() // This is for win statements
{
	srand(time(NULL));
	int randWin = (rand() % 10) + 1; 
	switch (randWin) // takes the random number and gives a win statement
	{
	case 1:
		cout << endl << endl << "Congrats! You guessed the number." << endl << endl;
		break;
	case 2:
		cout << endl << endl << "Great Job! You correctly guess a random number." << endl << endl;
		break;
	case 3:
		cout << endl << endl << "You finally got it right." << endl << endl;
		break;
	case 4:
		cout << endl << endl << "Wow that was too easy." << endl << endl;
		break;
	case 5:
		cout << endl << endl << "Now I need to make it more diffucult." << endl << endl;
		break;
	case 6:
		cout << endl << endl << "You make it look way too easy." << endl << endl;
		break;
	case 7:
		cout << endl << endl << "I am suprised that you actually got it." << endl << endl;
		break;
	case 8:
		cout << endl << endl << "You just aced that." << endl << endl;
		break;
	case 9:
		cout << endl << endl << "Well Done! You are a super star." << endl << endl;
		break;
	case 10:
		cout << endl << endl << "10/10" << endl << endl;
		break;
	}
}

void Lose(int randomNumber) // This is for lose statements
{
	int randNum = randomNumber;
	srand(time(NULL));
	int randLose = (rand() % 10) + 1;
	switch (randLose) // takes the random number and gives a lose statement
	{
	case 1:
		cout << "You lost. The number was: " << randNum << endl;
		break;
	case 2:
		cout << "Pssst, you should have tried " << randNum << endl;
		break;
	case 3:
		cout << "Why did you not try " << randNum << endl;
		break;
	case 4:
		cout << "The number you should have tried was " << randNum << endl;
		break;
	case 5:
		cout << "Next time I would have gone with " << randNum << endl;
		break;
	case 6:
		cout << "0/10. You needed to try " << randNum << endl;
		break;
	case 7:
		cout << "You failed that so badly. The number was " << randNum << endl;
		break;
	case 8:
		cout << "That is all you got. The actually number was " << randNum << endl;
		break;
	case 9:
		cout << "You got it correct. Sike the real number was " << randNum << endl;
		break;
	case 10:
		cout << "You are making me look bad. The number you should have say was " << randNum << endl;
		break;
	}
}

void TryAgain() // This is for play again statements
{
	srand(time(NULL));
	int randAgain = (rand() % 10) + 1;
	switch (randAgain) // takes the random number and gives a play again statement
	{
	case 1:
		cout << "Would you like to play again? Enter 1 for Yes and 2 for No: ";
		break;
	case 2:
		cout << "Do you want to play a game? Enter 1 for Yes and 2 for No: ";
		break;
	case 3:
		cout << "Do you want to stay or leave? Enter 1 for Yes and 2 for No: ";
		break;
	case 4:
		cout << "Game over. Try Again? Enter 1 for Yes and 2 for No: ";
		break;
	case 5:
		cout << "Don't give up keep going. Enter 1 for Yes and 2 for No: ";
		break;
	case 6:
		cout << "A successful person will profit from their mistakes and try again in a different way. Enter 1 for Yes and 2 for No: ";
		break;
	case 7:
		cout << "If at first you don't succeed try again. Enter 1 for Yes and 2 for No: ";
		break;
	case 8:
		cout << "Keep going you are doing great. Enter 1 for Yes and 2 for No: ";
		break;
	case 9:
		cout << "You don't have to continue unless you want to. Enter 1 for Yes and 2 for No: ";
		break;
	case 10:
		cout << "Failure is not a reason to quit. Enter 1 for Yes and 2 for No: ";
		break;
	}
}