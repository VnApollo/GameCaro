#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <fstream>
#include <string>
#include "Board.h"
#include "Player.h"

using namespace std;

class View {
public:
	void displayBoard(Board& board);
	void displayMessage(string& message);
	void endgame(Player pl);

};
#endif // !VIEW_H
