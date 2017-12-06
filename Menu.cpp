#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "manu.h"
#include<conio.h>
#include<time.h>

using namespace std;



manu::manu() {
	//nothing here
}


void manu::drawManu()
{
	drawFrame(3, 3, 60, 30, '-', '|');
	//drawCol(40, 4, 23, '|');
	//drawRow(23, 40, 59, '-');
	SetPos(10, 5);
	cout << "Press any key to start";
	SetPos(10, 10);
	cout << " W up, A left, S down, D right";
	SetPos(10, 11);
	cout << " K to enter the X or O, Q quit game";
	SetPos(6, 21);
	cout << "Ruls: Who made 5 'o'or 'x' connected Who wins";
	SetPos(10, 10);
	while (1)
	{
		if (_kbhit())
		{
			char x = _getch();
			if (x = 'k')
				break;
		}
	}
	
}

void manu::SetPos(COORD a)// set cursor 
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(out, a);
}

void manu::SetPos(int i, int j)// set cursor
{
	COORD pos = { i, j };
	SetPos(pos);
}

/*void HideCursor()
{
CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}*/

void manu::drawRow(int y, int x1, int x2, char ch)
{
	SetPos(x1, y);
	for (int i = 0; i <= (x2 - x1); i++)
		cout << ch;
}


void manu::drawRow(COORD a, COORD b, char ch)
{
	if (a.Y == b.Y)
		drawRow(a.Y, a.X, b.X, ch);
	else
	{
		SetPos(0, 25);
		cout << "error code 01";
		system("pause");
	}
}
void manu::drawCol(int x, int y1, int y2, char ch)
{
	int y = y1;
	while (y != y2 + 1)
	{
		SetPos(x, y);
		cout << ch;
		y++;
	}
}


void manu::drawCol(COORD a, COORD b, char ch)
{
	if (a.X == b.X)
		drawCol(a.X, a.Y, b.Y, ch);
	else
	{
		SetPos(0, 25);
		cout << "error code 02";
		system("pause");
	}
}
void manu::drawFrame(COORD a, COORD  b, char row, char col)
{
	drawRow(a.Y, a.X + 1, b.X - 1, row);
	drawRow(b.Y, a.X + 1, b.X - 1, row);
	drawCol(a.X, a.Y + 1, b.Y - 1, col);
	drawCol(b.X, a.Y + 1, b.Y - 1, col);
}

void manu::drawFrame(int x1, int y1, int x2, int y2, char row, char col)
{
	COORD a = { x1, y1 };
	COORD b = { x2, y2 };
	drawFrame(a, b, row, col);
}

void manu::drawFrame(Frame frame, char row, char col)
{
	COORD a = frame.position[0];
	COORD b = frame.position[1];
	drawFrame(a, b, row, col);
}












