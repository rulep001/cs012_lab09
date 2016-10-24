#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Deck.h"
#include "Card.h"

using namespace std;

void sortBySuit(vector<Card> &v);
void mergeSort(vector<Card> &v, unsigned begin, unsigned end);
void merge(vector<Card> &v, unsigned begin, unsigned mid, unsigned end);

void fillHand(vector<Card> &hand, Deck &d, unsigned handSize) {
   hand.resize(handSize);
   for (unsigned i = 0; i < hand.size(); ++i) {
      hand.at(i) = d.dealCard();
   }
}

ostream & operator<<(ostream &out, const vector<Card> &s) {
    /* Passes in a vector of Cards and outputs to the stream each Card
       separated by a comma and a space, 
       with no comma, space, or newline at the end.
    */
    if (s.size() == 0) {
        return out;
    }
    for (unsigned i = 0; i < s.size(); ++i) {
        if (i != s.size() - 1) {
            out << s.at(i).createRankName() << " of " << s.at(i).createSuitName() << ", ";
        }
        else {
            out << s.at(i).createRankName() << " of " << s.at(i).createSuitName();
        }
    }
	
	return out;
}

int main() {
   vector<Card> hand;
   Deck deck;
   int handSize;
   cout << "Enter hand size: ";
   cin >> handSize;
   cout << endl;

   srand(time(0));
   deck.shuffleDeck();
   fillHand(hand, deck, handSize);
   cout << hand << endl;
   sortBySuit(hand);
   cout << hand << endl;
   return 0;
}

void sortBySuit(vector<Card> &v) {
    /* Sorts the contents of v into suit order,
       i.e., all clubs first (in numerically ascending order),
       then all diamonds (in ascending order),
       then all hearts (in ascending order),
       and finally all spades (in ascending order).
       Calls mergeSort recursive function to actually sort the vector.
    */
    if (v.size() == 0) {
        return;
    }
    mergeSort(v,0,v.size() - 1);
}

void mergeSort(vector<Card> &v, unsigned begin, unsigned end) {
    /* Uses the recursive merge sort algorithm to sort the contents
       of the vector from begin to end in suit order.
       (see above SortBySuit function for definition of suit order)
       Uses merge helper function to merge the two sorted
       halves.
    */
    unsigned mid = 0;
    
    if (begin < end) {
        mid = (begin + end) / 2;  // Find the midpoint in the partition
        
        // Recursively sort left and right partitions
        mergeSort(v, begin, mid);
        mergeSort(v, mid + 1, end);
        
        // Merge left and right partition in sorted order
        merge(v, begin, mid, end);
    }
}

void merge(vector<Card> &v, unsigned begin, unsigned mid, unsigned end) {
    /* Assumes all values from begin to mid are in suit order,
       (see above SortBySuit function for definition of suit order)
       and all values from mid + 1 to end are in suit order.
       Merges the two halves so that all values from begin to end
       are in suit order.
    */
    unsigned mergedSize = end - begin + 1; // Size of merged partition
    vector<Card> mergedCards(52);       // Temporary deck for merged numbers
    unsigned mergePos = 0;                 // Position to insert merged number
    unsigned leftPos = 0;                  // Position of elements in left partition
    unsigned rightPos = 0;                 // Position of elements in right partition
    
    leftPos = begin;                      // Initialize left partition position
    rightPos = mid + 1;                 // Initialize right partition position
    
    // Add smallest element from left or right partition to merged numbers
    while (leftPos <= mid && rightPos <= end) {
        if (v.at(leftPos).getSuit() < v.at(rightPos).getSuit()) {
            mergedCards.at(mergePos) = v.at(leftPos);
            ++leftPos;
        }
        
        else if (v.at(leftPos).getSuit() == v.at(rightPos).getSuit()) {
            if (v.at(leftPos).getRank() < v.at(rightPos).getRank()) {
                mergedCards.at(mergePos) = v.at(leftPos);
                ++leftPos;
            }
            else {
                mergedCards.at(mergePos) = v.at(rightPos);
                ++rightPos;
            }
        }
        
        else {
            mergedCards.at(mergePos) = v.at(rightPos);
            ++rightPos;
        }
        ++mergePos;
    }
    // If left partition is not empty, add remaining elements to merged numbers
    while (leftPos <= mid) {
        mergedCards.at(mergePos) = v.at(leftPos);
        ++leftPos;
        ++mergePos;
    }
    // If right partition is not empty, add remaining elements to merged numbers
    while (rightPos <= end) {
        mergedCards.at(mergePos) = v.at(rightPos);
        ++rightPos;
        ++mergePos;
    }
    
    // Copy merge number back to numbers
    for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
        v.at(begin + mergePos) = mergedCards.at(mergePos);
    }
}