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
    cout << " " << (board[0] == '-' ? "7" : string(1, board[0])) << " | "
        << (board[1] == '-' ? "8" : string(1, board[1])) << " | "
        << (board[2] == '-' ? "9" : string(1, board[2])) << " " << endl;
    cout << " - + - + -" << endl;
    cout << " " << (board[3] == '-' ? "4" : string(1, board[3])) << " | "
        << (board[4] == '-' ? "5" : string(1, board[4])) << " | "
        << (board[5] == '-' ? "6" : string(1, board[5])) << " " << endl;
    cout << " - + - + -" << endl;
    cout << " " << (board[6] == '-' ? "1" : string(1, board[6])) << " | "
        << (board[7] == '-' ? "2" : string(1, board[7])) << " | "
        << (board[8] == '-' ? "3" : string(1, board[8])) << " " << endl;
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

    if (row >= 0 && row <= 2 && board[row * 3] == symbol && board[row * 3 + 1] == symbol && board[row * 3 + 2] == symbol) return true;

    if (board[col] == symbol && board[col + 3] == symbol && board[col + 6] == symbol) return true;

    if ((board[0] == symbol && board[4] == symbol && board[8] == symbol) || (board[2] == symbol && board[4] == symbol && board[6] == symbol)) return true;
    
    return false;
}


int getPlayerMove(char symbol)
{
    int position;
    do
    {
        cout << "Enter a position (1-9): ";
        cin >> position;
        position--;
        cout << "Position after subtraction: " << position << endl;
    } while (!isValidMove(position));
    board[position] = symbol;
    cout << "Cell " << position + 1 << " now contains " << board[position] << endl;
    return position + 1;
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
            do
            {
                cout << "Enter a position (1-9): ";
                int input;
                cin >> input;

                switch (input)
                {
                case 1: position = 6; break;
                case 2: position = 7; break;
                case 3: position = 8; break;
                case 4: position = 3; break;
                case 5: position = 4; break;
                case 6: position = 5; break;
                case 7: position = 0; break;
                case 8: position = 1; break;
                case 9: position = 2; break;
                default: position = -1; break;
                }
            } while (position == -1 || !isValidMove(position));
        }

        else
        {
            bool hasMoved = false;

            for (int i = 0; i < BOARD_SIZE; ++i)
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

            if (!hasMoved)
            {
                char opponentSymbol = (symbol == 'X') ? 'O' : 'X';
                for (int i = 0; i < BOARD_SIZE; ++i)
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

        board[position] = symbol;
        printBoard();

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

        player = (player == 1) ? 2 : 1;
        symbol = (symbol == 'X') ? 'O' : 'X';
        moveCount++;
    }
    return 0;
}
