#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "Board.h"

using namespace std;

class Player {
private:
	string name;
	char signal;
	int win=0;
	int lose=0;
	int draw=0;
public:
	void setName(string name);
	void setSignal(char signal);
	void setWin(int win);
	void setLose(int lose);
	void setDraw(int draw);

	string getName();
	char getSingal();
	int getWin();
	int getLose();
	int getDraw();

	Player();
	Player(string& name, char& signal);
	Player(string& name, char& signal, int& win, int& lose, int& draw);
	
	void Increase_Win();
	void Increase_Lose();
	void Increase_Draw();

	void turn(Board& board, int& i, int& j);


};

#endif // !PLAYER_H

