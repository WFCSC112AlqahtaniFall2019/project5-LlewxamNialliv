#include "Card.h"
#include <string>
using namespace std;
Card::Card() {
    NumRank = 0;
    NumSuit = 0;
}

Card::Card(int Rank, int Suit) {
    NumRank = Rank;
    NumSuit = Suit;
}

bool Card::operator > (Card C){ //operator overloading of >
    if(this->NumRank > C.NumRank){
        return true;
    }
    if(this->NumRank == C.NumRank){
        if(this->NumSuit > C.NumSuit){
            return true;
        }
    }
    else{
        return false;
    }
}

bool Card::operator < (Card C){ //operator overloading of <
    if(this->NumRank < C.NumRank){
        return true;
    }
    if(this->NumRank == C.NumRank){
        if(this->NumSuit < C.NumSuit){
            return true;
        }
    }
    else{
        return false;
    }
}

string Card::PrintCard() {
    return ranks[NumRank] + " of " + suits[NumSuit];
}