#include "Board.h"

Board::Board()
{
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			arr[i][j] = ' ';
		}
	}
}

Board::Board(int w, int h)
{
	this->w = w;
	this->h = h;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			arr[i][j] = ' ';
		}
	}
}

void Board::set_w(int a)
{
	this->w = a;

}

void Board::set_h(int b)
{
	this->h = b;

}

void Board::set_arr(int a, int b, char c)
{
	this->arr[a][b] = c;

}

int Board::get_w()
{
	return w;
}

int Board::get_h()
{
	return h;
}

char Board::get_arr(int a, int b)
{
	return arr[a][b];
}
