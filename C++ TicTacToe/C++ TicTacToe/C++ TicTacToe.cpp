#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int BOARD_SIZE = 9;
char board[BOARD_SIZE];

void initBoard()
{
    std::fill(std::begin(board), std::end(board), '-');
}

void printBoard()
{
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " " << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " " << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " " << endl;
}

bool isValidMove(int position)
{
    return (position >= 0 && position <= 8 && board[position] == '-');
}

bool checkWin(int position, char symbol)
{
    int row = position / 3;
    int col = position % 3;
    bool isDiagonal = (row == col) || (row + col == 2);

    bool hasWon = true;
    for (int i = row * 3; i < row * 3 + 3; i++)
    {
        return (board[i] != symbol);
    }
    if (hasWon) return true;

    hasWon = true;
    for (int i = col; i < BOARD_SIZE; i += 3)
    {
        hasWon = (board[i] == symbol) ? true : false;
    }
    if (hasWon) return true;

    if (isDiagonal)
    {
        hasWon = true;
        if (row == col && board[0] == symbol && board[4] == symbol && board[8] == symbol)
        {
            hasWon = true;
        }
        else
        {
            for (int i = 2; i < BOARD_SIZE - 1; i += 2)
            {
                hasWon = (board[i] == symbol);
            }
        }
        if (hasWon) return true;
    }
    return false;
}

int main()
{
    int player = 1;
    char symbol = 'X';
    int position;
    int moveCount = 0;

    initBoard();
    printBoard();

    while (true)
    {
        cout << "Player " << player << "'s turn (" << symbol << ")" << endl;
        if (player == 1)
        {
            cout << "Enter a position (0-8): ";
            cin >> position;
        }
        else
        {
            do
            {
                srand(time(NULL));
                position = rand() % 9;
            }
            while (!isValidMove(position));
            cout << "Computer chose position " << position << endl;
        }

        if (!isValidMove(position))
        {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[position] = symbol;
        printBoard();
        moveCount++;

        if (checkWin(position, symbol))
        {
            cout << "Player " << player << " wins!" << endl;
            break;
        }


        if (moveCount == BOARD_SIZE)
        {
            cout << "The game is a draw." << endl;
            break;
        }

        if (player == 1)
        {
            player = 2;
            symbol = 'O';
        }
        else
        {
            player = 1;
            symbol = 'X';
        }
    }
    return 0;
}

