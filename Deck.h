#ifndef DECK_H
#define DECK_H

#include <vector>
#include <iostream>
#include "Card.h"

using namespace std;

class Deck {
 private:
    vector<Card> theDeck;
    vector<Card> dealtCards;
 public:
    Deck();
    Card dealCard();
    void shuffleDeck();
    unsigned deckSize() const;
    void sortBySuit(vector<Card> &v);
    void mergeSort(vector<Card> &v, unsigned begin, unsigned end);
    void merge(vector<Card> &v, unsigned begin, unsigned mid, unsigned end);
};

#endif