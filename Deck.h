#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H

#include "Card.h"

class Deck {
public:
    Deck(); //constructor
    ~Deck(); //destructor
    Deck(const Deck& orig); //copy constructor
    Deck& operator = (const Deck D); //copy operator
    void NewDeck(); //deck initializer
    void Shuffle(); //shuffle function
    Card RemoveCard();
    bool AddCard(Card C);

private:
    Card* cards;
    int arraySize;
    int cardsLeft;
};


#endif //BLINDMANSBLUFF_DECK_H
