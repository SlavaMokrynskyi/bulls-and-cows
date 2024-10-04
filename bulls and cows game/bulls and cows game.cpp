#include <iostream>
#include <stdlib.h>
#define SIZE 4
using namespace std;




int isUserFind(int computer_num[SIZE], int player_num[SIZE], int score)
{
	int bulls = 0, cows = 0;

	for (int i = 0; i < SIZE; i++) {
		if (player_num[i] == computer_num[i]) {
			cows++;
		}
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (player_num[j] == computer_num[i] && i != j) {
				bulls++;
			}
		}
	}

	if (cows == 4) {
		cout << "Congratulations! You win! You tried " << score << " times." << endl;
		return true;
	}
	else {
		cout << "Bulls: " << bulls << ", Cows: " << cows << endl;
		return false;
	}
}

void GetNum(int computer_num[SIZE], int score)
{
	int num, players_num[SIZE];
	
	cout << "Enter a four-digit number (each num must be unique) --> ";
	cin >> num;
	if (num > 9999 || num < 1000) {
		GetNum(computer_num, score);
		return;
	}
	for (int i = 1; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int x = 0; x < 9; x++)
			{
				for (int y = 0; y < 9; y++)
				{
					if (i * 1000 + j * 100 + x * 10 + y == num) {
						players_num[0] = i;
						players_num[1] = j;
						players_num[2] = x;
						players_num[3] = y;
					}
				}
			}
		}
	}
	if (isUserFind(computer_num, players_num, score) == false) {
		score++;
		GetNum(computer_num, score);
	}
}

int main()
{
	srand(time(NULL));
	int computer_num[SIZE], score = 0, players_num[SIZE], num, choice = 0;
	bool used[10] = { false };
	
	do {
		cout << "\tBulls and Cows" << endl;
		cout << endl;
		cout << "1) Start a game\n2) Rules\n3) Exit\nEnter your choice -> ";
		cin >> choice;
		if (choice == 1) {
			int digit;
			for (int i = 0; i < SIZE; i++)
			{
				do {
					digit = rand() % 10;
				} while (used[digit] || (i == 0 && digit == 0));
				
				used[digit] = true;
				computer_num[i] = digit;
			}
			GetNum(computer_num, score);
		}
		
		else if (choice == 2) {
			system("cls");
			cout << "\tBULLS AND COWS" << endl;
			cout << endl;
			cout << "Gameplay:"<< endl;
			cout << endl;
			cout << "1) The computer generates a secret four - digit number with unique digits." << endl;
			cout << endl;
			cout << "2) You guess a four - digit number." << endl;
			cout << endl;
			cout << "3) The computer tells you how many bulls(correct digits in the correct positions) and cows(correct digits in the wrong positions)." << endl;
			cout << endl;
			cout << "4) Keep guessing until you get 4 bulls(all digits correct in the right positions) to win." << endl;

		}
		else {
			return 0;
		}
	} while (choice != 1 || choice != 3);
}