//-- TicTacToe --

#include <iostream>
#include <string>
#include <thread>
#include <cmath>
#include <Windows.h>


using namespace std;

// declare & initialize
char gameBoard[3][3];
char playerSymbol[2] = { 'X', 'O' };
string playerName[2]; // store player names
int numPlayers;
int currentPlayer = 1;
int playerChoiceX = 0;
int playerChoiceY = 0;
int BOARD_SIZE = 3;
bool gameOver = false;


// function prototypes
void SetUp();
void LetsPlay();
void DrawBoard();
void PlayerTurn();
void BaymaxTurn();
void CheckWin();
void CheckDraw();

// main function
int main()
{
    SetUp();
    LetsPlay();
    return 0;
}

void LetsPlay()
{
    while (!gameOver)
    {
        if (numPlayers == 2)
        {
            currentPlayer = (currentPlayer + 1) % 2;
            PlayerTurn();
        }
        else
        {
            currentPlayer = (currentPlayer + 1) % 2;
            if (currentPlayer == 0) PlayerTurn();
            else BaymaxTurn();
        }
        DrawBoard();
        CheckWin();
        CheckDraw();
    }
}

// Setup Game
void SetUp()
{
    // reset gameBoard array values
    gameBoard[0][0] = '1'; gameBoard[1][0] = '2'; gameBoard[2][0] = '3';
    gameBoard[0][1] = '4'; gameBoard[1][1] = '5'; gameBoard[2][1] = '6';
    gameBoard[0][2] = '7'; gameBoard[1][2] = '8'; gameBoard[2][2] = '9';

    cout << "--X- Welcome to TicTacToe -O--" << endl;
    cout << "     - by Stewart Wan -" << endl;

    // Number of players
    int numPlayers;
    while (true)
    {
        cout << "Please enter the number of player 1 or 2" << endl;
        string userInput;
        cin >> userInput;
        switch (stoi(userInput))
        {
        case 1:
            numPlayers = 1;
            cout << "Player 1, please enter your name" << endl;
            cin >> playerName[0];
            playerName[1] = "Baymax";
            cout << endl << "Lets Play !" << endl << endl;
            DrawBoard();
            LetsPlay();
            return;
        case 2:
            numPlayers = 2;
            for (int i = 0; i < 2; i++)
            {
                cout << "Player " << i + 1 << ", please enter your name" << endl;
                cin >> playerName[i];
            }
            cout << endl << "Lets Play !" << endl << endl;
            DrawBoard();
            LetsPlay();
            return;
        default:
            cout << "Invalid input." << endl;
            break;
        }
    }
}


void DrawBoard()
{
    system("cls"); // Clear the console

    // Set the color of the text to green
    std::cout << "\033[32m";

    std::cout << std::endl;
    std::cout << " " << gameBoard[0][2] << " | " << gameBoard[1][2] << " | " << gameBoard[2][2] << std::endl;
    std::cout << " - + - + -" << std::endl;
    std::cout << " " << gameBoard[0][1] << " | " << gameBoard[1][1] << " | " << gameBoard[2][1] << std::endl;
    std::cout << " - + - + - " << std::endl;
    std::cout << " " << gameBoard[0][0] << " | " << gameBoard[1][0] << " | " << gameBoard[2][0] << std::endl;
    std::cout << std::endl;

    // Reset the color of the text to the default color
    std::cout << "\033[0m";
}

void NumKeyInput()
{
    cout << "Player " << playerName[currentPlayer] << ", enter the number of the cell you want to play: " << endl;
    int playerInput;
    cin >> playerInput;
    playerInput--;
    playerChoiceX = playerInput % BOARD_SIZE;
    playerChoiceY = playerInput / BOARD_SIZE;
}

void PlayerTurn()
{
PlayerInput:
    NumKeyInput();
    if (gameBoard[playerChoiceX][playerChoiceY] == 'X' || gameBoard[playerChoiceX][playerChoiceY] == 'O')
    {
        cout << "Cell has been played, please select another number" << endl;
        goto PlayerInput;
    }
    gameBoard[playerChoiceX][playerChoiceY] = playerSymbol[currentPlayer];
}

void HasWon()
{
    DrawBoard();
    cout << "Player " << playerName[currentPlayer] << " has won!" << endl;
    gameOver = true;
}

void CheckWin()
{
    // check rows
    for (int i = 0; i < 3; i++) {
        if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2])
        {
            HasWon();
            return;
        }
    }

    // check columns
    for (int i = 0; i < 3; i++) {
        if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i])
        {
            HasWon();
            return;
        }
    }

    // check diagonals
    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) {
        HasWon();
        return;
    }
    if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]) {
        HasWon();
        return;
    }
}

void CheckDraw() {
    bool emptyFound = false;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (gameBoard[i][j] != 'X' && gameBoard[i][j] != 'O')
            {
                emptyFound = true;
                break;
            }
        }
    }
    if (!emptyFound)
    {
        DrawBoard();
        cout << "The game is a draw." << endl;
        gameOver = true;
    }
}

//End Game
void EndGame()
{
    cout << "Thanks for Playing" << endl;
    exit(0);
}

void PlayAgain()
{
    while (true)
    {
        cout << "Would you like to play again?" << endl;
        cout << "[1] for YES : [2] for NO" << endl;

        string userInput;
        getline(cin, userInput);

        if (userInput != "1" && userInput != "2")
        {
            cout << "Invalid input." << endl;
        }
        else
        {
            int playAgain = stoi(userInput);
            if (playAgain == 1)
            {
                system("cls");
                SetUp();
            }
            else
            {
                system("cls");
                EndGame();
            }
            break;
        }
    }
}


// Single Player Methods
// Generate a random number between 0 and max-1
int GenerateRandomNumber(int max)
{
    srand(time(NULL));
    return rand() % max;
}

// Get a valid move from the player
void GetPlayerMove()
{
    while (true)
    {
        // Prompt the player for input
        cout << "Enter your move (1-9): ";
        string input;
        getline(cin, input);

        // Validate the input
        if (input.size() != 1 || input[0] < '1' || input[0] > '9')
        {
            cout << "Invalid input. Please enter a number between 1 and 9." << endl;
            continue;
        }

        // Convert the input to coordinates on the game board
        int position = input[0] - '1';
        playerChoiceX = position % BOARD_SIZE;
        playerChoiceY = position / BOARD_SIZE;

        // Check if the chosen position is available
        if (gameBoard[playerChoiceX][playerChoiceY] != ' ')
        {
            cout << "That position is already occupied. Please choose a different position." << endl;
            continue;
        }

        // The move is valid, so exit the loop
        break;
    }
}

// Let Baymax make a move
void BaymaxTurn()
{
    int x, y;
    do
    {
        x = GenerateRandomNumber(BOARD_SIZE);
        y = GenerateRandomNumber(BOARD_SIZE);
    } while (gameBoard[x][y] != ' ');

    gameBoard[x][y] = playerSymbol[1];
    cout << "Baymax plays " << gameBoard[x][y] << endl;
    Sleep(2000);
}