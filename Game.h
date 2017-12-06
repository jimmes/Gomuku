#pragma once
#include "iostream"
#include "manu.h"
#include <string>
class Game:manu
{
public:
	Game();
	COORD position;
	
	char arrayxo[100][100];
	void drawPlay();
	int player;
	int locationx;
	int locationy;

	void cursormove(char x);
	void Add();
	void Jug();
	void playing();
	void BackSlash(char x);
	void SlashForX(char x);
	void YInTheLine(char x);
	void XInTheLine(char x);
	void gameover();
};