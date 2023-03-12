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
    cout << " " << (board[0] == '-' ? "0" : string(1, board[0])) << " | "
        << (board[1] == '-' ? "1" : string(1, board[1])) << " | "
        << (board[2] == '-' ? "2" : string(1, board[2])) << " " << endl;
    cout << "---+---+---" << endl;
    cout << " " << (board[3] == '-' ? "3" : string(1, board[3])) << " | "
        << (board[4] == '-' ? "4" : string(1, board[4])) << " | "
        << (board[5] == '-' ? "5" : string(1, board[5])) << " " << endl;
    cout << "---+---+---" << endl;
    cout << " " << (board[6] == '-' ? "6" : string(1, board[6])) << " | "
        << (board[7] == '-' ? "7" : string(1, board[7])) << " | "
        << (board[8] == '-' ? "8" : string(1, board[8])) << " " << endl;
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

    bool hasWon = false;
    for (int i = row * 3; i < row * 3 + 3; i++)
    {
        if (board[i] != symbol)
        {
            hasWon = false;
            break;
        }
        hasWon = true;
    }
    if (hasWon) return true;

    hasWon = false;
    for (int i = col; i < BOARD_SIZE; i += 3)
    {
        if (board[i] != symbol)
        {
            hasWon = false;
            break;
        }
        hasWon = true;
    }
    if (hasWon) return true;

    if (isDiagonal)
    {
        hasWon = false;
        if (row == col && board[0] == symbol && board[4] == symbol && board[8] == symbol)
        {
            hasWon = true;
        }
        else
        {
            for (int i = 2; i <= 6; i += 2)
            {
                if (board[i] != symbol)
                {
                    hasWon = false;
                    break;
                }
                hasWon = true;
            }
        }
        if (hasWon) return true;
    }
    return false;
}

int getPlayerMove(char symbol)
{
    int position;
    do
    {
        cout << "Enter a position (0-8): ";
        cin >> position;
    } while (!isValidMove(position));
    board[position] = symbol;
    return position;
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
        int position;

        if (player == 1)
        {
            // Player's turn
            do
            {
                cout << "Enter a position (0-8): ";
                cin >> position;
            }
            while (!isValidMove(position));
        }
        else
        {
            // Computer's turn
            bool hasMoved = false;

            // Check for a winning move
            for (int i = 0; i < BOARD_SIZE; i++)
            {
                if (isValidMove(i))
                {
                    board[i] = symbol;
                    if (checkWin(i, symbol))
                    {
                        position = i;
                        hasMoved = true;
                        break;
                    }
                    board[i] = '-';
                }
            }

            // Check for a blocking move
            if (!hasMoved)
            {
                char opponentSymbol = (symbol == 'X') ? 'O' : 'X';
                for (int i = 0; i < BOARD_SIZE; i++)
                {
                    if (isValidMove(i))
                    {
                        board[i] = opponentSymbol;
                        if (checkWin(i, opponentSymbol))
                        {
                            position = i;
                            hasMoved = true;
                            break;
                        }
                        board[i] = '-';
                    }
                }
            }

            // Choose a random move if no winning or blocking move is possible
            if (!hasMoved)
            {
                do
                {
                    srand(time(NULL));
                    position = rand() % 9;
                }
                while (!isValidMove(position));
            }

            cout << "Computer chose position " << position << endl;
        }

        // Make the move
        board[position] = symbol;
        printBoard();

        // Check if the game is over
        if (checkWin(position, symbol))
        {
            cout << "Player " << player << " wins!" << endl;
            break;
        }
        else if (moveCount == BOARD_SIZE - 1)
        {
            cout << "The game is a draw." << endl;
            break;
        }

        // Switch to the other player
        player = (player == 1) ? 2 : 1;
        symbol = (symbol == 'X') ? 'O' : 'X';
        moveCount++;
    }

    return 0;
}
