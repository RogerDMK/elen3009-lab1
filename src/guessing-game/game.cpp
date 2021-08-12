#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int main(){
    cout << "This is the guessing game, you have 5 tries to guess a random number between 0 and 100. After each guess you will be told if the guess is too high, too low, if you won or if you lost." << endl;
    srand(time(NULL)); // Creates a seed for rand() function based on time
    int randNum = rand() % 100 + 1; // Generates a random number between 1 - 100
    int userGuess = 0;
    bool gameOver = false;
    int round = 0;
    int maxRound = 5; // User has 5 guesses
    while(gameOver == false){
        cout << "Make a guess: ";
        cin >> userGuess;
        cout << endl;
        if(userGuess == randNum){
            gameOver = true;
            cout << "You win" << endl;
        }
        else{
            round++;
            if(round == maxRound){
                cout << "You lose" << endl;
                gameOver = true;
            }
            else if(userGuess < randNum){
                cout << "Guess higher" << endl;
            }
            else if(userGuess > randNum){
                cout << "Guess lower" << endl;
            }
        }
    }
    return 0;
}