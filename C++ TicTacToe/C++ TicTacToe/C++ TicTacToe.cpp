// C++ TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>



int main()
{
    std::cout << "Welcome to Tic Tac Toe\n";

    char cells[9];
    std::fill_n(cells, 9, ' ');


    //Draw Board
    std::cout << cells[6] << " | " << cells[7] << " | " << cells[8] << std::endl;
    std::cout << "- + - + -" << std::endl;
    std::cout << cells[3] << " | " << cells[4] << " | " << cells[05] << std::endl;
    std::cout << "- + - + -" << std::endl;
    std::cout << cells[0] << " | " << cells[1] << " | " << cells[2] << std::endl;

    //check row 0: 0 1 2


    return 0;
}
