#include "Deck.h"
#include <string>
#include <iostream>

using namespace std;

Deck::Deck(){ //constructor
    cout << "New deck created." << endl;
    arraySize = 52;
    cardsLeft = 52;
    cards = new Card[52];
}

Deck::~Deck(){ //destructor
    cout << "This deck is gone." << endl;
    delete[] cards;
}

Deck::Deck(const Deck& orig){ //copy constructor
    cards = new Card[arraySize];
    for(int i = 0; i < orig.arraySize; i++){
        cards[i] = orig.cards[i];
    }
    arraySize = orig.arraySize;
}

Deck& Deck :: operator = (const Deck D){ //copy assignment operator
    Deck tmp(D);
    swap(cards, tmp.cards);
    return *this;
}

void Deck::NewDeck(){ //deck populating
    int numCard = 0;
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 4; j++){
            cards[numCard] = Card(i, j); //
            numCard ++;
        }
    }
}

void Deck::Shuffle() {
    for (int i = 0; i < cardsLeft * cardsLeft; i++) { //performing cardsLeft^2 swaps
        int A = rand() % cardsLeft;
        int B = rand() % cardsLeft; //generate random numbers for the shuffle
        swap (cards[A], cards[B]);
    }
}

Card Deck::RemoveCard() {
    if(cardsLeft > 0){
        cardsLeft--; //removes a card
        return cards[cardsLeft]; //returns the value
    }
    else {
        cout << "No cards left." << endl;
    }
}

bool Deck::AddCard(Card C) {
    if(cardsLeft < arraySize){ //there is still space left in the deck
        cards[cardsLeft] = C;
        cardsLeft ++; //update number of cards left
        return true;
    }
    else{
        return false;
    }
}