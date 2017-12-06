#pragma once
#include "iostream"

/*=============== all the structures ===============*/
typedef struct Frame
{
	COORD position[2];
	int flag;
}Frame;

class manu {
public:
	manu();
	void SetPos(COORD);
	void SetPos(int, int);
	void drawRow(int, int, int, char);
	void drawRow(COORD, COORD, char);
	void drawCol(int, int, int, char);
	void drawCol(COORD, COORD, char);
	void drawFrame(COORD, COORD, char, char);
	void drawFrame(int, int, int, int, char, char);
	void drawFrame(Frame, char, char);
	void drawManu();
		
private:

};