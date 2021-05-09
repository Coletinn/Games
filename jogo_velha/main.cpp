#include <iostream>
#include <string>

using namespace std;

void clean();
void menu();
void game(string player1, string player2, int score1, int score2);
int verifyWinner(char table[3][3]);
void startTable(char table[3][3]);
void printTable(char table[3][3]);
void printInstructions();



int main()
{
	menu();
	return 0;
}


void menu()
{
	int option = 0;

	string player1, player2;

	while (option < 1 || option > 3)
	{
		cout << "\n\nWelcome to the game";
		cout << "\n1 - Play";
		cout << "\n2 - About";
		cout << "\n3 - Exit";
		cout << "\nSelect an option: ";
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "\nGame started";
			cout << "\nEnter player 1 name: ";
			cin >> player1;
			cout << "\nEnter player 2 name: ";
			cin >> player2;
			game(player1, player2,0,0);
			break;
		case 2:
			cout << "\nAbout the game";
		case 3:
			cout << "\nThanks for playing!";
			break;
		}

	}
}


void game(string player1, string player2, int score1, int score2)
{
	char table[3][3];

	int lin, col, position, gameLoop = 1, round = 1, playerTurn = 1, option = 0;
	string playerNow;
	bool playPosition;

	startTable(table);

	while (round <= 9 && gameLoop == 1)
	{
		clean();

		cout << player1 << ": " << score1 << " --- " << player2 << ": " << score2;
		
		printTable(table);

		printInstructions();

		cout << "\n\nRound " << round << endl;
		

		if (playerTurn == 1)
		{
			playerNow = player1;
		}
		else
		{
			playerNow = player2;
		}

		playPosition = false;

		int positions[9][2] = { {2,0},{2,1},{2,2},{1,0},{1,1},{1,2},{0,0},{0,1},{0,2} };

		while (playPosition == false)
		{
			cout << "\nIt's " << playerNow << "'s turn.\nEnter a position: ";
			cin >> position;

			lin = positions[position-1][0];
			col = positions[position-1][1];

			if (table[lin][col] == '-')
			{
				playPosition = true;
				if (playerTurn == 1)
				{
					table[lin][col] = 'X';
					playerTurn = 2;
				}
				else
				{
					table[lin][col] = 'O';
					playerTurn = 1;
				}
			}
		}



		if (verifyWinner(table) == 1)
		{
			cout << "\nPlayer X has won!";
			score1++;
			gameLoop = 0;
		}
		else if (verifyWinner(table) == 2)
		{
			cout << "\nPlayer O has won!";
			score2++;
			gameLoop = 0;
		}

		round++;
	}

	printTable(table);
	cout << "\n\nGame over!\nWhat do you wish to do now?\n1 - Play again\n2 - Main menu\n3 - Exit\nSelect your option: ";
	cin >> option;
	clean();
	switch (option)
	{
	case 1:
		game(player1, player2, score1, score2);
		break;
	case 2:
		menu();
		break;
	case 3:
		cout << "\nThanks for playing!";
		break;
	}

}


int verifyWinner(char table[3][3])
{
	int lin, col;

	for (lin = 0; lin < 3; lin++)
	{
		if (table[lin][0] == 'X' && table[lin][0] == table[lin][1] && table[lin][1] == table[lin][2])
		{
			return 1;
		}
		else if (table[lin][0] == 'O' && table[lin][0] == table[lin][1] && table[lin][1] == table[lin][2])
		{
			return 2;
		}
	}


	for (col = 0; col < 3; col++)
	{
		if (table[0][col] == 'X' && table[0][col] == table[1][col] && table[1][col] == table[2][col])
		{
			return 1;
		}
		else if (table[0][col] == 'O' && table[0][col] == table[1][col] && table[1][col] == table[2][col])
		{
			return 2;
		}
	}

	if (table[0][0] != '-' && table[0][0] == table[1][1] && table[1][1] == table[2][2])
	{
		if (table[0][0] == 'X')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}


	if (table[0][2] != '-' && table[0][2] == table[1][1] && table[1][1] == table[2][0])
	{
		if (table[0][0] == 'X')
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
}


void startTable(char table[3][3])
{
	int lin, col;
	for (lin = 0; lin < 3; lin++)
	{
		for (col = 0; col < 3; col++)
		{
			table[lin][col] = '-';
		}
	}
}


void printTable(char table[3][3])
{
	int lin, col;
	for (lin = 0; lin < 3; lin++)
	{
		cout << "\n";
		for (col = 0; col < 3; col++)
		{
			cout << table[lin][col];
		}
	}
}


void printInstructions()
{
	cout << "\nPositions map:";
	cout << "\n 7 | 8 | 9\n 4 | 5 | 6\n 1 | 2 | 3";
}


void clean()
{
	system("CLS");
}




