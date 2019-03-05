#include <iostream>
#include <string>
#include "tictacPlayer.h"
#include <windows.h>
using namespace std;

	void print(char Script[6][81])
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 81; j++)
			{
				cout << Script[i][j];
			}
			cout << endl;
		}
	}
	void print2(char Script[4][90])
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 90; j++)
			{
				cout << Script[i][j];
			}
			cout << endl;
		}
	}

void Win(char Youwin[4][90])
{
	for (int H = 0; H < 4; H++)
	{
		for (int N = 0; N < 90; N++)
		{
			cout << Youwin[H][N];
		}
		cout << endl;
	}

}
char Youwin[4][90] =
{

"  __ __                  _     ",
" |  |  |___ _ _    _ _ _|_|___ ",
" |_   _| . | | |  | | | | |   |",
"   |_| |___|___|  |_____|_|_|_|"

};

void Title(char TitleScreen[6][81])
{
	for (int J = 0; J < 6; J++)
	{
		for (int N = 0; N < 81; N++)
		{
		  cout << TitleScreen[J][N];
		}
		cout << endl;
	}

}
char TitleScreen[6][81] =
{
		"  _____   _   _____        _____     ___   _____        _____   _____   _____ ",
		" |_   _| | | /  ___|      |_   _|   /   | /  ___|      |_   _| /  _  \\ | ____|",
		"   | |   | | | |            | |    / /| | | |            | |   | | | | | |__  ",
		"   | |   | | | |            | |   / / | | | |            | |   | | | | |  __| ",
		"   | |   | | | |___         | |  / /  | | | |___         | |   | |_| | | |___ ",
		"   |_|   |_| \\_____|        |_| /_/   |_| \\_____|        |_|   \\_____/ |_____|"
};

char tic[3][3] =
{
	{ '0', '1', '2' },
	{ '3', '4', '5' },
	{ '6', '7', '8' }
};

char Check[3][3] =
{
	{ '0', '1', '2' },
	{ '3', '4', '5' },
	{ '6', '7', '8' }
};
bool Gamereset = true;
int main()
{


	while (Gamereset)
	{

		print(TitleScreen);
		cout << "Type `Start` to begin the Game.\n";
		string input;
		cin >> input;
		if ((input == "Start") || (input == "start"))
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail());
				continue;
			}
			//initialise the symbols
			Player playerArr[2];
			playerArr[0].initialise('X');
			playerArr[1].initialise('O');
			int changePlay = 0;

			//                /\
			//first number is | while second number is <-->
			//tic[1][0] = 'X';
			//for (int k = 0; k < 9; ++k)
			{
				int turnCount = 1;
				while (true)
				{
					system("cls");

					cout << "	-------------------------------------" << endl;
					//repeat
					for (int i = 0; i < 3; ++i)
					{
						cout << "	|           |           |           |" << endl;
						cout << "	|";
						//Print row
						for (int j = 0; j < 3; ++j)
						{
							cout << "     " << tic[i][j] << "     |";
						}
						cout << endl;
						cout << "	|           |           |           |" << endl;
						cout << "	-------------------------------------" << endl;
					}


					while (true)
					{
						cout << "Choose the row you wish to choose. \n";
						int input;
						cin >> input;

						if (cin.fail())
						{
							cin.clear();
							cin.ignore(cin.rdbuf()->in_avail());
							continue;
						}

						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());


						cout << "Choose the column you wish to choose.\n";
						int input2;
						cin >> input2;

						if (cin.fail())
						{
							cin.clear();
							cin.ignore(cin.rdbuf()->in_avail());
							continue;
						}


						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());

						if (Check[input][input2] == tic[input][input2])
						{
							tic[input][input2] = playerArr[changePlay].GetSymbol();
							++turnCount;
							if (changePlay == 1)
							{
								changePlay = 0;
							}
							else
							{
								changePlay = 1;
							}
							break;
						}

					}

					//Row 0
					if (tic[0][0] == tic[0][1] && tic[0][0] == tic[0][2])
					{
						print2(Youwin);
						cout << "You know who won." << endl;
						
						cout << "You know who lost." << endl;
						system("pause");
					}
					//row 1
					else if (tic[1][0] == tic[1][1] && tic[1][0] == tic[1][2])
					{
						print2(Youwin);
						cout << "You know who won." << endl;

						cout << "You know who lost." << endl;
						system("pause");
					}
					//row 2
					else if (tic[2][0] == tic[2][1] && tic[2][0] == tic[2][2])
					{
						print2(Youwin);
						cout << "You know who won." << endl;

						cout << "You know who lost." << endl;
						system("pause");
					}
					//Diagnal 1
					else if (tic[0][0] == tic[1][1] && tic[0][0] == tic[2][2])
					{
						print2(Youwin);
						cout << "You know who won." << endl;

						cout << "You know who lost." << endl;
						system("pause");
					}
					//Diagnal 2
					else if (tic[0][2] == tic[1][1] && tic[0][2] == tic[2][0])
					{
						print2(Youwin);
						cout << "You know who won." << endl;

						cout << "You know who lost." << endl;
						system("pause");
					}
					//column 0
					else if (tic[0][0] == tic[1][0] && tic[0][0] == tic[2][0])
					{
						print2(Youwin);
						cout << "You know who won." << endl;

						cout << "You know who lost." << endl;
						system("pause");
					}
					//column 1
					else if (tic[0][1] == tic[1][1] && tic[0][1] == tic[2][1])
					{
						print2(Youwin);
						cout << "You know who won." << endl;
						cout << "You know who lost." << endl;
						system("pause");
					}
					//column 2
					else if (tic[0][2] == tic[1][2] && tic[0][2] == tic[2][2])
					{
						print2(Youwin);
						cout << "You know who won." << endl;
						cout << "You know who lost." << endl;
						system("pause");
					}
					else if(turnCount > 9)
					{
						cout << "Draw." << endl;
						system("pause");
						if ((input == "Reset") || (input == "reset"));
						{
							cin >> input;
						}
					}
				}
			}
		}
	}	
system("pause");
return 0;
}			
