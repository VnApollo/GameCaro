#include "Controller.h"

Controller::Controller()
{
}

bool Controller::checkWin(Player p1, Board& board)
{//dọc
	for (int i = 0; i < board.get_w(); i++) {
		for (int j = 0; j < board.get_h(); j++) {
			if (board.get_arr(i, j) == p1.getSingal() && board.get_arr(i, j + 1) == p1.getSingal()
				&& board.get_arr(i, j + 2) == p1.getSingal() && board.get_arr(i, j + 3) == p1.getSingal() 
				&& board.get_arr(i, j + 4) == p1.getSingal()) {
				return true;
			}
		}
	}
// ngang
	for (int i = 0; i < board.get_w(); i++) {
		for (int j = 0; j < board.get_h(); j++) {
			if (board.get_arr(i, j) == p1.getSingal() && board.get_arr(i+1, j) == p1.getSingal()
				&& board.get_arr(i+2, j) == p1.getSingal() && board.get_arr(i+3, j) == p1.getSingal()
				&& board.get_arr(i+4, j) == p1.getSingal()) {
				return true;
			}
		}
	}
//Chéo phải
	for (int i = 0; i < board.get_w(); i++) {
		for (int j = 0; j < board.get_h(); j++) {
			if (board.get_arr(i, j) == p1.getSingal() && board.get_arr(i + 1, j+1) == p1.getSingal()
				&& board.get_arr(i + 2, j+2) == p1.getSingal() && board.get_arr(i + 3, j+3) == p1.getSingal()
				&& board.get_arr(i + 4, j+4) == p1.getSingal()) {
				return true;
			}
		}
	}
//chéo trái
	for (int i = 0; i < board.get_w(); i++) {
		for (int j = 0; j < board.get_h(); j++) {
			if (board.get_arr(i, j) == p1.getSingal() && board.get_arr(i + 1, j-1) == p1.getSingal()
				&& board.get_arr(i + 2, j-1) == p1.getSingal() && board.get_arr(i + 3, j-1) == p1.getSingal()
				&& board.get_arr(i + 4, j-1) == p1.getSingal()) {
				return true;
			}
		}
	}
}

void Controller::playGame(Player &p1, Player &p2, int w, int h, int count, Board board, View view)
{
	string n1, n2;
	int x, y;
	p1.setSignal('X');
	p2.setSignal('O');
	system("cls");

	// Nhập tên người chơi
	cout << "Name player 1: ";
	cin >> n1;
	p1.setName(n1);
	cout << "Name player 2: ";
	cin >> n2;
	p2.setName(n2);

	//Nhập kích thước bàn cờ
	cout << "Board size: \n";
	cout << "Width: "; cin >> w;
	cout << "Height: "; cin >> h;
	board.set_w(w);
	board.set_h(h);
	system("cls");

	view.displayBoard(board); // hiển thị bàn cờ

	for (int i = 0; i <= ((w * h) / 2); i++) {
		int count = 0;
		// Lượt đi của người thứ 1:
		p1.turn(board, x, y);
		count++;
		system("cls");
		view.displayBoard(board);

		if (checkWin(p1, board) == true) {
			view.endgame(p1);
			p1.Increase_Win();
			p2.Increase_Lose();
			return;
		}
		if (count == (w * h) && checkWin(p1, board) != true) {
			cout << "2 player is draw!\n";
			p1.Increase_Draw();
			p2.Increase_Draw();
			return;
		}
		p2.turn(board, x, y);
		count++;
		system("cls");
		view.displayBoard(board);
		if (checkWin(p2, board) == true) {
			view.endgame(p2);
			p1.Increase_Win();
			p2.Increase_Lose();
			return;
		}
		if (count == (w * h) && checkWin(p2, board) != true) {
			cout << "2 player is draw!";
			p1.Increase_Draw();
			p2.Increase_Draw();
			return;
		}
	}
}

void Controller::run(View view, Board board, Player &p1, Player &p2)
{
	int count = 0;
	int w = 0, h = 0;
	playGame(p1, p2, w, h, count, board, view);
}

void Controller::saveResult(Player p1, Player p2)
{
	// Tạo đối tượng ofstream và mở file
	std::ofstream outFile("C:/Users/Admin/source/repos/test3/Result.txt");
	// Kiểm tra xem file có mở thành công hay không
	if (!outFile) {
		cerr << "cannot open the file for writing.\n";
		return;
	}

	// Ghi dữ liệu vào file
	outFile << "Player 1: " << p1.getName() << "\n";
	outFile << "Wins: " << p1.getWin() << "\n";
	outFile << "Losses: " << p1.getLose() << "\n";
	outFile << "Draws: " << p1.getDraw() << "\n";
	outFile << "\n";
	outFile << "Player 2: " << p2.getName() << "\n";
	outFile << "Wins: " << p2.getWin() << "\n";
	outFile << "Losses: " << p2.getLose() << "\n";
	outFile << "Draws: " << p2.getDraw() << "\n";

	// Đóng file sau khi ghi xong
	outFile.close();
}
