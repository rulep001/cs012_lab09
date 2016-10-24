#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Deck.h"
#include "Card.h"

using namespace std;

Deck::Deck() {
    /* Constructs a Deck of 52 cards:
   Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King of each suit.
   Cards should start off in this order with the order of suits being:
   Clubs, Diamonds, Hearts, Spades.
    */
    unsigned i;
    
    for (i = 13; i > 0; --i) { // Adds all the clubs to the deck
        theDeck.push_back(Card('s',i));
    }
    for (i = 13; i > 0; --i) { // Adds all the diamonds to the deck
        theDeck.push_back(Card('h',i));
    }
    for (i = 13; i > 0; --i) { // Adds all the hearts to the deck
        theDeck.push_back(Card('d',i));
    }
    for (i = 13; i > 0; --i) { // Adds all the spades to the deck
        theDeck.push_back(Card('c',i));
    }
}


Card Deck::dealCard() {
    /* Deals (returns) the top card on the deck. 
   Removes this card from theDeck and places it in the dealtCards.
    */
    Card p;
    
    p = theDeck.at(theDeck.size() - 1);
    dealtCards.push_back(p);
    theDeck.pop_back();
    
    return p;
}


void Deck::shuffleDeck() {
    /* Places all cards back into theDeck and shuffles them into random order.
    */
    for (unsigned i = 0; i < dealtCards.size(); ++i) {
        theDeck.push_back(dealtCards.at(i));
    }
    dealtCards.clear();
    
    random_shuffle(theDeck.begin(), theDeck.end());
}


unsigned Deck::deckSize() const {
    /* returns the size of the Deck (how many cards have not yet been dealt).
    */
    return theDeck.size();
}