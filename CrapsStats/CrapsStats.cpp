// CrapsStats.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

int rollDice();

int _tmain(int argc, _TCHAR* argv[])
{
	enum result {WIN, LOSE, CONTINUE};
	result r;
	int diceTotal = 0;
	int point = 0;
	int rollNumWIN[21] = {0};
	int rollNumLOSE[21] = {0};
	int wins = 0;
	int losses = 0;
	int roundCount = 0;
	int roundCountOverWIN = 0;
	int roundCountOverLOSE = 0;
	int totalGames = 0;
	int roundSum = 0;

	srand((time(NULL)*12569) % rand());
	for(int i = 1; i <= 1000; i++)
	{
		roundCount = 0;
		cout << "-------------------------------Game Number " << i << "-------------------------------" << endl;
		cout << "Rolling the dice...";
		diceTotal = rollDice();
		if(2 == diceTotal || 3 == diceTotal || 12 == diceTotal)
		{
			cout << "Sorry, you lose :(" << endl;
			r = LOSE;
			++rollNumLOSE[roundCount++];
		}
		else if(7 == diceTotal || 11 == diceTotal)
		{
			cout << "Congrats! You win!" << endl;
			r = WIN;
			++rollNumWIN[roundCount++];
		}
		else
		{
			point = diceTotal;
			r = CONTINUE;
			++roundCount;
			while(r == CONTINUE)
			{
				cout << "Please roll again" << endl;
				diceTotal = rollDice();
				if(diceTotal == point)
				{
					cout << "Congrats! You win!" << endl;
					r = WIN;
				}
				else if(7 == diceTotal)
				{
					cout << "Congrats! You lose! :(" << endl;
					r = LOSE;
				}
				++roundCount;
			}
		}
		if(r == WIN){wins++; if(roundCount>20){roundCountOverWIN++;}else{rollNumWIN[roundCount]++;}}
		else if(r == LOSE){losses++; if(roundCount>20){roundCountOverLOSE++;}else{rollNumLOSE[roundCount]++;}}
		cout << "It took " << roundCount << " rounds to end the game" << endl;
		roundSum += roundCount;

		totalGames++;
	}
	cout << "-------------------------------Results-------------------------------" << endl;
	cout << "You won " << wins << " times and lost " << losses << " times" << endl;
	cout << endl;
	cout << setw(15) << "Games won in (rounds): " << endl;
	for(int i = 1; i <= 20; i++){cout << setw(7) << i << ": " << rollNumWIN[i] << endl;} 
	cout << "Over 20: " << roundCountOverWIN << endl;
	cout << endl;

	cout << setw(15) << "Games lost in (rounds): " << endl;
	for(int i = 1; i <= 20; i++){cout << setw(7) << i << ": " << rollNumLOSE[i] << endl;} 
	cout << "Over 20: " << roundCountOverLOSE << endl;
	cout << endl;

	cout << "Chance to win: " << setiosflags(ios::fixed | ios::showpoint) << setprecision(2) << 
		setw(6) << (static_cast<double>(wins)/totalGames)*100 << "%" << endl;
	cout << "Chance to lose: " << setiosflags(ios::fixed | ios::showpoint) << setprecision(2) <<
		setw(5) << (static_cast<double>(losses)/totalGames)*100 << "%" << endl;

	cout << "Total rounds: " << roundSum << endl;
	cout << "Total Games: " << totalGames << endl;
	cout << "Average length of a game of craps: " << (static_cast<double>(roundSum) / totalGames) << endl;


	return 0;
}

int rollDice()
{
	int di1 = 1 + rand() % 6;
	int di2 = 1 + rand() % 6;

	cout << "You rolled " << di1 << " and " << di2 << " for a total of "
		 << di1 + di2 << "." << endl;

	return di1+di2;
}

