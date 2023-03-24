#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>

using namespace std;

const int BOARD_SIZE = 9;
char board[BOARD_SIZE];

void initBoard();
void printBoard();

bool isValidMove(int position);
bool checkWin(int position, char symbol);

int getPlayerMove(char symbol);
int getHumanMove();
int getComputerMove(char symbol);

enum class BoardValue
{
    Empty = '-',
    Player1 = 'X',
    Player2 = 'O',
};

int main()
{
    int player = 1;
    char symbol = 'X';
    int position = -1;
    int moveCount = 0;

    initBoard();
    printBoard();

    while (true)
    {
        cout << "Player " << player << "'s turn (" << symbol << ")" << endl;
        position = (player == 1) ? getHumanMove() : getComputerMove(symbol);

        board[position] = symbol;
        system("cls");
        printBoard();

        if (checkWin(position, symbol) || moveCount == BOARD_SIZE - 1)
        {
            cout << ((checkWin(position, symbol)) ? "Player " + to_string(player) + " wins!" : "The game is a draw.") << endl;
            break;
        }

        player = (player == 1) ? 2 : 1;
        symbol = (symbol == 'X') ? 'O' : 'X';
        ++moveCount;
    }
        return 0;
}

void initBoard()
{
    fill(begin(board), end(board), static_cast<char>(BoardValue::Empty));
}

void printBoard()
{
    auto printCell = [](BoardValue value)
    {
        switch (value)
        {
        case BoardValue::Empty: return "\033[31m-\033[0m";
        case BoardValue::Player1: return "X";
        case BoardValue::Player2: return "O";
        }
    };

    cout << " " << printCell(static_cast<BoardValue>(board[0])) << " | "
        << printCell(static_cast<BoardValue>(board[1])) << " | "
        << printCell(static_cast<BoardValue>(board[2])) << " " << endl;
    cout << " - + - + -" << endl;
    cout << " " << printCell(static_cast<BoardValue>(board[3])) << " | "
        << printCell(static_cast<BoardValue>(board[4])) << " | "
        << printCell(static_cast<BoardValue>(board[5])) << " " << endl;
    cout << " - + - + -" << endl;
    cout << " " << printCell(static_cast<BoardValue>(board[6])) << " | "
        << printCell(static_cast<BoardValue>(board[7])) << " | "
        << printCell(static_cast<BoardValue>(board[8])) << " " << endl;
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
    bool rowWin = board[row * 3] == symbol && board[row * 3 + 1] == symbol && board[row * 3 + 2] == symbol;
    bool colWin = board[col] == symbol && board[col + 3] == symbol && board[col + 6] == symbol;
    bool diagWin = (board[0] == symbol && board[4] == symbol && board[8] == symbol) || (board[2] == symbol && board[4] == symbol && board[6] == symbol);

    return rowWin || colWin || diagWin;
}

int getPlayerMove(char symbol)
{
    int position;
    while (true)
    {
        cout << "Enter a position (1-9): ";
        cin >> position;
        position--;
        if (isValidMove(position)) break;
        cout << "Invalid move, please try again." << endl;
    }
    ++position;
    board[position - 1] = symbol;
    cout << "Cell " << position << " now contains " << symbol << endl;
    return position;
}

int getHumanMove()
{
    const int map[] = { 6, 7, 8, 3, 4, 5, 0, 1, 2 };
    int position;
    do
    {
        cout << "Enter a position (1-9): ";
        int input;
        cin >> input;
        position = (input >= 1 && input <= 9) ? map[input - 1] : -1;
    }
    while (position == -1 || !isValidMove(position));
    return position;
}

int getComputerMove(char symbol)
{
    bool hasMoved = false;
    int position = -1;
    for (size_t i = 0; i < BOARD_SIZE; ++i)
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
        for (size_t i = 0; i < BOARD_SIZE; ++i)
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
    return position;
}