#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void menu();

void clean()
{
	system("CLS");
}

void startTable(char table[10][10], char mask[10][10])
{
	int line, column;
	for (line = 0; line < 10; line++)
	{
		for (column = 0; column < 10; column++)
		{
			table[line][column] = 'A';
			mask[line][column] = '~';
		}
	}
}

void showTable(char table[10][10], char mask[10][10])
{
	int cont;
	for (cont = 0; cont < 10; cont++)
	{
		if (cont == 0)
		{
			cout << "   ";
		}
		cout << cont << " ";
	}
	cout << "\n";

	int line, column;
	for (line = 0; line < 10; line++)
	{
		cout << line << " ";
		for (column = 0; column < 10; column++)
		{
			cout << " " << mask[line][column];
		}
		cout << "\n";
	}

	cout << "\n";

	for (line = 0; line < 10; line++)
	{
		for (column = 0; column < 10; column++)
		{
			cout << " " << table[line][column];
		}
		cout << "\n";
	}
}

void posShips(char table[10][10])
{
	int qtd = 10, qtdPos = 0;

	while (qtdPos < qtd)
	{
		int randomLine = rand() % 10;
		int randomColumn = rand() % 10;


		if (table[randomLine][randomColumn] == 'A')
		{
			table[randomLine][randomColumn] = 'P';
			qtdPos++;
		}
	}

	
}

void verify(char table[10][10], int line, int column, int *pts, string *msg)
{
	switch (table[line][column])
	{
	case 'P':
		*pts += 10;
		*msg = "\nSmall ship hit! (10 pts)";
		break;
	case 'A':
		*msg = "\nWater hit";
		break;
	}
}


void game(string name)
{
	char table[10][10], mask[10][10];
	int line, column;
	int state = 1;
	int pts = 0;
	string message;
	int option;
	int tries = 0, maxTries = 5;

	startTable(table, mask);

	posShips(table);

	while (tries < maxTries)
	{
		clean();

		showTable(table, mask);

		if (tries == 0)
		{
			cout << "\n\nWelcome to the battle, " << name;
		}
		else if (tries == maxTries - 1)
		{
			cout << "\n\nThis is your last move. Think wisely!";
		}
		else
		{
			cout << "\n\nMake your move.";
		}

		line = -1;
		column = -1;

		cout << "\nPoints: " << pts << "\nTries left: " << maxTries - tries;
		cout << message;

		while ( (line < 0 || column < 0) || (line > 9 || column < 9))
		{
			cout << "\nEnter a line: ";
			cin >> line;
			cout << "\nEnter a column: ";
			cin >> column;
		}

		
		verify(table, line, column, &pts, &message);

		mask[line][column] = table[line][column];

		tries++;
	}

	cout << "\nGame over";
	cout << "\n1 - Play again";
	cout << "\n2 - Return to menu";
	cout << "\n3 - Exit";
	cout << "\nEnter your option: ";
	cin >> option;

	switch (option)
	{
	case 1:
		game(name);
		break;
	case 2:
		menu();
		break;
	case 3:
		break;
	}
}


void menu()
{
	int option = 0;
	string playerName;

	while (option < 1 || option > 3)
	{
		clean();

		cout << "Welcome to the game\n";
		cout << "\n1 - Play";
		cout << "\n1 - About";
		cout << "\n1 - Exit";
		cout << "\nSelect an option: ";
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "\nEnter your name: ";
			cin >> playerName;
			game(playerName);
			break;
		case 2:

			cout << "About the game";
			break;
		case 3:

			cout << "Goodbye";
			break;
		}

	}
}


int main()
{
	srand((unsigned)time(NULL));
	menu();
	
	return 0;
}