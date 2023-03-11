#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int BOARD_SIZE = 9;
char board[BOARD_SIZE];

void initBoard()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board[i] = '-';
    }
}

void printBoard()
{
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " " << endl;
    cout << "-----------" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " " << endl;
    cout << "-----------" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " " << endl;
}

bool isValidMove(int position)
{
    return (position >= 0 && position <= 8 && board[position] == '-');
}

bool checkWin(char symbol)
{
    // Check rows
    for (int i = 0; i < 9; i += 3)
    {
        if (board[i] == symbol && board[i + 1] == symbol && board[i + 2] == symbol) return true;
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[i] == symbol && board[i + 3] == symbol && board[i + 6] == symbol) return true;
    }

    // Check diagonals
    if (board[0] == symbol && board[4] == symbol && board[8] == symbol) return true;
    
    if (board[2] == symbol && board[4] == symbol && board[6] == symbol) return true;

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
                srand(time(NULL)); // seed the random number generator
                position = rand() % 9; // generate a random number between 0 and 8
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

        if (checkWin(symbol))
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

