#include <iostream>
#include <string>
#include <cctype>
#include "Card.h"
#include "Deck.h"
#include <ctime>


using namespace std;

int main() {
    cout << "Welcome to Blind Man's Bluff" << endl << endl;
    bool play, invalid, guessedHigher;
    string response;
    int nWin = 0, nLoss = 0, nTie = 0;
    srand(time(NULL));
    Card PlayerCard;
    Card ComputerCard; //cards being used by computer and player
    Deck Game; //deck for the game
    Game.NewDeck();
    Game.Shuffle();
    int RoundsLeft = 27;

    play = true;
    while(play && RoundsLeft > 0) {

        PlayerCard = Game.RemoveCard();
        ComputerCard = Game.RemoveCard(); //deal cards to computer and user, removing dealt cards from the deck


        cout << "Computer's value is " << ComputerCard.PrintCard() << endl; //show Computer's card to the player


        invalid = true;
        while(invalid) { //get user input
            cout << "Do you think your number is higher or lower? (H/L)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'H') {
                // continue playing
                guessedHigher = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'L') {
                // break out of while(play) loop
                guessedHigher = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }

        // determine outcome
        if((ComputerCard < PlayerCard && guessedHigher) || (ComputerCard > PlayerCard && !guessedHigher)) {
            cout << "Great! You're right:" << endl;
            nWin++;
        } else if((ComputerCard > PlayerCard && guessedHigher) || (ComputerCard < PlayerCard && !guessedHigher)) {
            cout << "Sorry, you're wrong:" << endl;
            nLoss++;
        } else {
            cout << "It's a tie:" << endl;
            nTie++;
        }
        cout << "\tyour value is " ;
        cout << PlayerCard.PrintCard() << endl;

        // ask user to play again
        invalid = true;
        while(invalid) {
            cout << "Play again? (Y/N)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') {
                // continue playing
                play = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'N') {
                // break out of while(play) loop
                play = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }
        RoundsLeft --;
    }
    if(RoundsLeft == 0){
        cout << "Out of Cards!" << endl;
    }

    // output stats
    cout << "Thanks for playing!" << endl;
    cout << "Your record was " << nWin << "-" << nLoss << "-" << nTie << " (W-L-T)" << endl;

    return 0;
}