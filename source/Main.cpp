#include <iostream>
#include "Player.h"
#include "View.h"
#include "Controller.h"
#include "Board.h"


int main() {
    Controller controller;
    View view;
    Player p1, p2;
    Board board;

    controller.run(view, board, p1, p2);
    controller.saveResult(p1, p2);
}