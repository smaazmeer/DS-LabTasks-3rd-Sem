#include <iostream>
#include <cstdlib>   // for rand()
using namespace std;

void guessNumberGame(int targetNumber, int playerTurn = 1) 
{
    int guess;
    cout << "Player " << playerTurn << ", guess a number between 1 and 100: ";
    cin >> guess;

    if (guess == targetNumber) 
    {
        cout << "Player " << playerTurn << " wins! The correct number was " << targetNumber << endl;
        return;
    }

    if (guess < targetNumber) 
    {
        cout << "Too low! Try again" << endl;
    } 
    else 
    {
        cout << "Too high! Try again" << endl;
    }

    int nextPlayer = (playerTurn == 1) ? 2 : 1;
    guessNumberGame(targetNumber, nextPlayer);
}

void startGame()
{
    int targetNumber = rand() % 100 + 1; 
    cout << "Welcome to the number guessing game!" << endl;
    guessNumberGame(targetNumber, 1);
}

int main() 
{
    startGame();
    return 0;
}
