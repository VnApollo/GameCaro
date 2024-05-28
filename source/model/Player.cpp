#include "Player.h"

void Player::setName(string name)
{
	this->name = name;

}

void Player::setSignal(char signal)
{
	this->signal = signal;
}

void Player::setWin(int win)
{
	this->win = win;
}

void Player::setLose(int lose)
{
	this->lose = lose;
}

void Player::setDraw(int draw)
{
	this->draw = draw;
}

string Player::getName()
{
	return name;
}

char Player::getSingal()
{
	return signal;
}

int Player::getWin()
{
	return win;
}

int Player::getLose()
{
	return lose;
}

int Player::getDraw()
{
	return draw;
}

Player::Player()
{
}

Player::Player(string& name, char& signal)
{
	this->name = name;
	this->signal = signal;
}

Player::Player(string& name, char& signal, int& win, int& lose, int& draw)
{
	this->name = name;
	this->signal = signal;
	this->win = win;
	this->lose = lose;
	this->draw = draw;
}

void Player::Increase_Win()
{
	win++;
}

void Player::Increase_Lose()
{
	lose++;
}

void Player::Increase_Draw()
{
	draw++;
}

void Player::turn(Board& board, int& i, int& j)
{
	cout << "Player " << name << " turn: ";
	cin >> i >> j;
	if (i<1 || i>(board.get_w()) || j<1 || j>(board.get_h()) || board.get_arr(i - 1, j - 1) != ' ') {
		cout << "Invalid\n";
		Player::turn(board, i, j);// g?i ?? quy ?? th? l?i l??t
	}
	else {
		board.set_arr(i - 1, j - 1, signal);
	}
}
