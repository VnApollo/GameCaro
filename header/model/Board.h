#ifndef BOARD_H
#define BOARD_H

#include<iostream>

using namespace std;

class Board {
private:
	int w, h;
	char arr[100][100];
public:
	Board();
	Board(int w, int h);

	void set_w(int a);
	void set_h(int b);
	void set_arr(int a, int b, char c);

	int get_w();
	int get_h();
	char get_arr(int a, int b);

};
#endif // !BOARD_H
