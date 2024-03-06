#include "Deck.h"
#include <algorithm>

using namespace std;

/* Constructs a Deck of 52 cards:
Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King of each suit.
Cards should start off in this order with the order of suits being:
Clubs, Diamonds, Hearts, Spades. So, the Card at the top of the
Deck should be the Ace of Clubs. The next Card should be 2 of Clubs.
The 3rd Card should be 3 of Clubs, and so on ...
       
For best efficiency, the top of Deck should be stored at 
back end of vector.
*/

Deck::Deck(){
    char suits[] = {'c', 'd', 'h', 's'};

    for (int i = 3; i >= 0; --i){
        for (int j = 13; j >= 1; --j){
            Card aCard(Card(suits[i], j));
            theDeck.push_back(aCard);
        }
    }
}

/* Deals (returns) the top card of the deck. 
Removes this card from theDeck and places it in dealtCards.
As mentioned in comments for the constructor, 
for best efficiency, the top card should come from the 
back end of vector.*/
Card Deck::dealCard(){
    Card topCard;

    topCard = theDeck.back();
    dealtCards.push_back(theDeck.back());
    theDeck.pop_back();

    return topCard;
}

/* Places all cards back into theDeck and shuffles them into random order.
Use random_shuffle function from algorithm library.
To pass test harness, this function must go forward through dealtCards
pushing each Card onto the back end of theDeck, then clear dealtCards.
Do not use pop_back on dealtCards.*/
void Deck::shuffleDeck(){
    for (unsigned int i = 0; i < dealtCards.size(); ++i){
        theDeck.push_back(dealtCards[i]);
    }
    random_shuffle(theDeck.begin(), theDeck.end());

    dealtCards.clear();
}

//Returns the size of the Deck (how many cards have not yet been dealt).
unsigned Deck::deckSize() const{
    return theDeck.size();
}