#include <iostream>
#include <sstream>
#include <string>
#include "Card.h"

using namespace std;

Card::Card() {
    /* Assigns a default value of 2 of Clubs
    */
    suit = 'c';
    rank = 2;
}


Card::Card(char s, int r) {
    /* Assigns the Card the suit and rank provided.
        suits: c = Clubs, d = Diamonds, h = Hearts, s = Spades
        If an invalid suit is provided, sets the suit to Clubs
        ranks: 1 - 13 (1 = Ace, 11 = Jack, 12 = Queen, 13 = King)
        If an invalid rank is provided, sets the rank to 2
        Accepts lower or upper case characters for suit
    */
    suit = s;
    rank = r;
    
    if (suit != 'c' && suit != 'C' && suit != 'd' && suit != 'D' && suit != 'h' && suit != 'H' && suit != 's' && suit != 'S') {
        suit = 'c';
    }
    if (rank < 1 || rank > 13) {
        rank = 2;
    }
}


char Card::getSuit() const {
    /* Returns the Card's suit
    */
    if (suit == 'C') {
        return 'c';
    }
    if (suit == 'D') {
        return 'd';
    }
    if (suit == 'H') {
        return 'h';
    }
    if (suit == 'S') {
        return 's';
    }
    return suit;
}


int Card::getRank() const {
    /* Returns the Card's rank as an integer
    */
    return rank;
}


ostream & operator<<(ostream &out, const Card &crd) {
    /* Outputs a Card in the following format: Rank of Suit
   For example, if the rank is 3 and the suit is h: 3 of Hearts
   Or, if the rank is 1 and the suit is d: Ace of Diamonds
   Or, if the rank is 12 and the suit is c: Queen of Clubs
   etc.
    */
    out << crd.createRankName() << " of " << crd.createSuitName();
	return out;    
}


const string Card::createSuitName() const {
    if (suit == 'c' || suit == 'C') {
        return "Clubs";
    }
    else if (suit == 'd' || suit == 'D') {
        return "Diamonds";
    }
    else if (suit == 'h' || suit == 'H') {
        return "Hearts";
    }
    else if (suit == 's' || suit == 'S') {
        return "Spades";
    }
    else {
        return "0";
    }
}


const string Card::createRankName() const {
    stringstream rnk;
    string result;
    
    if (rank == 1) {
        rnk << "Ace";
    }
    
    else if (rank == 11) {
        rnk << "Jack";
    }
    
    else if (rank == 12) {
        rnk << "Queen";
    }
    
    else if (rank == 13) {
        rnk << "King";
    }
    
    else if (rank != 1 && rank != 11 && rank != 12 && rank != 13) {
        rnk << rank;
    }
    
    result = rnk.str();
    
    return result;
}