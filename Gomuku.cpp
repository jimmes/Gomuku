// Gomuku.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "MoveAdd.h"
//#include "GameJug.h"

#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<string>

//#include "manu.h"
#include "Game.h"

using namespace std;


int main()
{
	manu gMenu;
	Game gGame;
	
	gMenu.SetPos(30, 1);
	cout << "Hallow\n";
	gMenu.drawManu();

	system("cls");	
	gGame.drawPlay();
	gGame.playing();
	//CursorLocation();
    return 0;
}

