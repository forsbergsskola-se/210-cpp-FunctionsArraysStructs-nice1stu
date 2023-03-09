//-- TicTacToe --

#include <iostream>
#include <string>
#include <thread>
#include <cmath>

using namespace std;

// declare & initialize
char gameBoard[3][3];
char playerSymbol[3] = { 'X', 'O', 'Ö' };
string playerName[4]; // store player names
int numPlayers;
int currentPlayer = 1;
int playerChoiceX = 0;
int playerChoiceY = 0;

// function prototypes
void SetUp();
void LetsPlay();
void DrawBoard();
void PlayerTurn();
void BaymaxTurn();
void NumKeyInput();
void CheckWin();
void CheckDraw();
void HasWon();

// main function
int main() {
    SetUp();
    return 0;
}

// Lets Play
void LetsPlay() {
GameOn:
    if (numPlayers == 2) {
        currentPlayer = (currentPlayer + 1) % 2;
        PlayerTurn();
    }
    else {
        currentPlayer = (currentPlayer + 1) % 2;
        if (currentPlayer == 0) {
            PlayerTurn();
        }
        else {
            BaymaxTurn();
        }
    }

    DrawBoard();
    CheckWin();
    CheckDraw();
    goto GameOn;
}

// Setup Game
void SetUp() {
    // reset gameBoard array values
    gameBoard[0][0] = '1'; gameBoard[1][0] = '2'; gameBoard[2][0] = '3';
    gameBoard[0][1] = '4'; gameBoard[1][1] = '5'; gameBoard[2][1] = '6';
    gameBoard[0][2] = '7'; gameBoard[1][2] = '8'; gameBoard[2][2] = '9';

    cout << "--X- Welcome to TicTacToe -O--" << endl;
    cout << "     - by Stewart Wan -" << endl;

    // Number of players
Player2Play:
    cout << "Please enter the number of player 1 or 2" << endl;
    string userInput;
    cin >> userInput;
    if ((userInput != "1") && (userInput != "2")) {
        cout << "Invalid input." << endl;
        goto Player2Play;
    }
    numPlayers = stoi(userInput);
    numPlayers = (int)fmin((double)numPlayers, 2);
    if (numPlayers == 2) {
        // Players enter name
        for (int i = 0; i < 2; i++) {
            cout << "Player " << i + 1 << ", please enter your name" << endl;
            string playerAnswer;
            cin >> playerAnswer;
            playerName[i] = playerAnswer;
        }
        cout << endl << "Lets Play !" << endl << endl;
        DrawBoard();
        LetsPlay();
    }
    else {
        cout << "Player 1, please enter your name" << endl;
        string playerAnswer;
        cin >> playerAnswer;
        playerName[0] = playerAnswer;
        cout << "Player 2 is your friendly medical robot Baymax" << endl;
        this_thread::sleep_for(chrono::milliseconds(3000));
        playerName[1] = "Baymax";
        cout << endl << "Lets Play !" << endl << endl;
        DrawBoard();
        LetsPlay();
    }
}

void DrawBoard()
{
    system("clear"); // Clear the console (works in Linux/MacOS)

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


//check win
void CheckWin()
{
    if (gameBoard[0][0] == gameBoard[1][0] && gameBoard[1][0] == gameBoard[2][0]) //row 1-3
    {
        HasWon();
    }

    if (gameBoard[0][1] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][1]) //row 4-6
    {
        HasWon();
    }

    if (gameBoard[0][2] == gameBoard[1][2] && gameBoard[1][2] == gameBoard[2][2]) //row 7-9
    {
        HasWon();
    }

    if (gameBoard[0][0] == gameBoard[0][1] && gameBoard[0][1] == gameBoard[0][2]) //column 1-7
    {
        HasWon();
    }

    if (gameBoard[1][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[1][2]) //column 2-8
    {
        HasWon();
    }

    if (gameBoard[2][0] == gameBoard[2][1] && gameBoard[2][1] == gameBoard[2][2]) //column 3-9
    {
        HasWon();
    }

    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) //Diagonal 0-9
    {
        HasWon();
    }

    if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]) //Diagonal 3-7
    {
        HasWon();
    }
}


//Has won
void HasWon()
{
    cout << playerName[currentPlayer] << " Wins !" << endl;
    PlayAgain();
}

//check draw
void CheckDraw()
{
    if (gameBoard[0][0] != '1' && gameBoard[1][0] != '2' && gameBoard[2][0] != '3' && gameBoard[0][1] != '4' && gameBoard[1][1] != '5' && gameBoard[2][1] != '6' && gameBoard[0][2] != '7' && gameBoard[1][2] != '8' && gameBoard[2][2] != '9')
    {
        HasDrawn();
    }
}

//Has drawn
void HasDrawn()
{
    cout << "Game is a draw" << endl;
    PlayAgain();
}


//Play Again
void PlayAgain()
{
Back2Game:
    cout << "Would you like to play again?" << endl;
    cout << "[1] for YES : [2] for NO" << endl;
    string userInput;
    getline(cin, userInput);
    if ((userInput != "1") && (userInput != "2"))
    {
        cout << "Invalid input." << endl;
        goto Back2Game;
    }
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
}

//End Game
void EndGame()
{
    cout << "Thanks for Playing" << endl;
    exit(0);
}


//Use number key for input
void NumKeyInput()
{
    cout << playerName[currentPlayer] << " press the NumKey where you want to play" << endl;
    string playerInput;
    cin >> playerInput;
    if (playerInput == "1")
    {
        playerChoiceX = 0;
        playerChoiceY = 0;
    }
    if (playerInput == "2")
    {
        playerChoiceX = 1;
        playerChoiceY = 0;
    }
    if (playerInput == "3")
    {
        playerChoiceX = 2;
        playerChoiceY = 0;
    }
    if (playerInput == "4")
    {
        playerChoiceX = 0;
        playerChoiceY = 1;
    }
    if (playerInput == "5")
    {
        playerChoiceX = 1;
        playerChoiceY = 1;
    }
    if (playerInput == "6")
    {
        playerChoiceX = 2;
        playerChoiceY = 1;
    }
    if (playerInput == "7")
    {
        playerChoiceX = 0;
        playerChoiceY = 2;
    }
    if (playerInput == "8")
    {
        playerChoiceX = 1;
        playerChoiceY = 2;
    }
    if (playerInput == "9")
    {
        playerChoiceX = 2;
        playerChoiceY = 2;
    }
}

//Single Player Methods
void BaymaxTurn()
{
    srand(time(NULL));
PlayerInput:
    playerChoiceX = rand() % 3;
    playerChoiceY = rand() % 3;
    if (gameBoard[playerChoiceX][playerChoiceY] == playerSymbol[0] || gameBoard[playerChoiceX][playerChoiceY] == playerSymbol[2])
    {
        goto PlayerInput;
    }
    cout << "Baymax plays " << gameBoard[playerChoiceX][playerChoiceY] << endl;
    gameBoard[playerChoiceX][playerChoiceY] = playerSymbol[2];
    Sleep(2000);
}