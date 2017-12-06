#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "game.h"
#include "manu.h"
#include<conio.h>
#include<time.h>


using namespace std;

/*=============== all the functions ===============*/
HANDLE hout;


Game::Game()
{
	player = 1;
	position.X = 4;
	position.Y = 4;
	locationx = 1;
	locationy = 1;
	arrayxo[0][0] = 'x';
}



void Game::drawPlay()
{
	drawFrame(1, 1, 61, 31, '-', '|');
	for (int i = 3; i <= 59; i = i + 2)
	{
		drawCol(i, 2, 30, '|');
	}
	for (int i = 3; i < 30; i = i + 2)
	{
		drawRow(i, 2, 60, '-');
	}
	SetPos(2, 2);
}
//X 2 - 60, Y 2 - 30, all "X" and "O" location must be even



void Game::cursormove(char x)
{
	/*COORD coord; //cursor location
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	
	coord.X = 10;
	coord.Y = 10;


	GetConsoleScreenBufferInfo(hout, &csbi);
	coord.X = csbi.dwCursorPosition.X; //get X
	coord.Y = csbi.dwCursorPosition.Y; //get Y 
	*/

			if (x == 'a') //left
				if (position.X != 2)
				{
					position.X -= 2;
					SetPos(position.X, position.Y);
				}

			if (x == 's') //down
				if (position.Y != 30)
				{
					position.Y += 2;
					SetPos(position.X, position.Y);
				}


			if (x == 'd')//right
				if (position.X != 60)
				{
					position.X += 2;
					SetPos(position.X, position.Y);
				}

			if (x == 'w')//UP
				if (position.Y != 2)
				{
					position.Y -= 2;
					SetPos(position.X, position.Y);
				} 
			
	
		}
	



/*void Game::playing()
{
	char x = 'X', o = 'O';
	int P;
	while (1)
	{
		cursormove(x);
		//Jug(P=1);
		cursormove(o);
		//Jug(P=2);
	}
}*/

void Game::playing()
{
	
	drawPlay();
	while (1)
	{
	if (_kbhit())
{
	char x = _getch();
	if ('a' == x || 's' == x || 'd' == x || 'w' == x)
	cursormove(x);
	else
	if ('k' == x)
	{
		Add();
		Jug();
}
	else
	if ('q' == x)
	exit(0); //FIX
		}
	}

} 

void Game::gameover()
{
	system("cls");
	COORD p1 = { 28,9 };
	COORD p2 = { 53,15 };
	drawFrame(p1, p2, '=', '|');
	SetPos(36, 12);
	if (player == 1)
		cout << "Player 2  Wins";
	if (player == 2)
		cout << "Player 1  Wins";
	Sleep(1000);
	system("cls");
	SetPos(36, 12);
	cout << " Player again hit Y, no hit N";
	as:
	char x = _getch();
	if (x == 'n')
		exit(0);
	else if (x == 'y')
	{
		system("cls");
		Game game;
		game.drawPlay();
		game.playing();
	}
	else goto as;
}






void Game::Add()
{
	if (player == 1)
	{
		if (arrayxo[position.X / 2][position.Y / 2] != 'O')
		{
			locationx = position.X;
			locationy = position.Y;
			arrayxo[locationx / 2][locationy / 2] = 'X';
			//SetPos(100, 100);
			//cout << arrayxo[0][0];
			SetPos(position.X, position.Y);
			player = 2;
			cout << "X";
		}
	}
	else
	{
		if (arrayxo[position.X / 2][position.Y / 2] != 'X')
		{
			locationx = position.X;
			locationy = position.Y;
			arrayxo[locationx / 2][locationy / 2] = 'O';
			//SetPos(100, 100);
			//cout << arrayxo[locationx / 2][locationy / 2];
			SetPos(position.X, position.Y);
			player = 1;
			cout << "O";
		}
	}
}


/*=============== all the Jug functions ===============*/

void Game::Jug()
{
	char x;
	if (player == 2)
		x = 'X';
	else
		x = 'O';
	BackSlash(x);
	SlashForX(x);
	YInTheLine(x);
	XInTheLine(x);

}
void Game::XInTheLine(char XorO)
{
	// 1 2 3 4 5 6 7 8 9
	int i, c = 1;
	int x = locationx/2, y = locationy/2;
	
	for (i = 1; i <= 4; i++)
	{
		if (arrayxo[x + i][y] == XorO)
			c++;
		else
			break;
	}
	if (c == 5)
		gameover();
	else
	{
		c = 1;
		for (i = 1; i <= 4; i++)
		{
			if (arrayxo[x - i][y] == XorO)
				c++;
			else
				break;
		}
		if (c == 5)
			gameover();
	}
}

void Game::YInTheLine(char XorO)
{											// 3
											// 4
	int i, c = 1;							// 5
	int x = locationx / 2, y = locationy / 2;

	for (i = 1; i <= 4; i++)
	{
		if (arrayxo[x][y + i] == XorO)
			c++;
		else
			break;
	}
	if (c == 5)
		gameover();
	else
	{
		c = 1;
		for (i = 1; i <= 4; i++)
		{
			if (arrayxo[x][y - i] == XorO)
				c++;
			else
				break;
		}
		if (c == 5)
			gameover();
	}

}

void Game::SlashForX(char XorO)
{                                      // X
	char Jug[9]; // Jug[4] is the center of X  
	int i, c = 1;						   // X
	int x = locationx / 2, y = locationy / 2;

	for (i = 1; i <= 4; i++)
	{
		if (arrayxo[x + i][y + i] == XorO)
			c++;
		else
			break;
	}
	if (c == 5)
		gameover();
	else
	{
		c = 1;
		for (i = 1; i <= 4; i++)
		{
			if (arrayxo[x - i][y - i] == XorO)
				c++;
			else
				break;
		}
		if (c == 5)
			gameover();
	}
}
void Game::BackSlash(char XorO)
{										   // X
	char Jug[9]; // Jug[4] is the center of X  
	int i, c = 1;					   // X
	int x = locationx / 2, y = locationy / 2;

	for (i = 1; i <= 4; i++)
	{
		if (arrayxo[x - i][y + i] == XorO)
			c++;
		else
			break;
	}
	if (c == 5)
		gameover();
	else
	{
		c = 1;
		for (i = 1; i <= 4; i++)
		{
			if (arrayxo[x + i][y - i] == XorO)
				c++;
			else
				break;
		}
		if (c == 5)
			gameover();
	}
}
