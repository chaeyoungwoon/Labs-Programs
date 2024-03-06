#include "Card.h"

#include<vector>

using namespace std;

//Assigns a default value of 2 of Clubs
Card::Card(){
    suit = 'c';
    rank = 2;
}

/*Assigns the Card the suit and rank provided.
suits: c = Clubs, d = Diamonds, h = Hearts, s = Spades
If an invalid suit is provided, sets the suit to Clubs
ranks: 1 - 13 (1 = Ace, 11 = Jack, 12 = Queen, 13 = King)
If an invalid rank is provided, sets the rank to 2
Accepts lower or upper case characters for suit
*/
Card::Card(char s, int r){
    s = tolower(s);
    
    if (s == 'c'){
        suit = 'c';
    }
    else if (s == 'd'){
        suit = 'd';
    }
    else if (s == 'h'){
        suit = 'h';
    }
    else if (s == 's'){
        suit = 's';
    }
    else{
        suit = 'c';
    }

    if (r > 13 || r < 1){
        rank = 2;
    }
    else {
        rank = r;
    }
}

//Returns the Card's suit
char Card::getSuit() const{
    return suit;
}

// Returns the Card's rank as an integer
int Card::getRank() const{
    return rank;
}

/* Outputs a Card in the following format: Rank of Suit
For example, if the rank is 3 and the suit is h: 3 of Hearts
Or, if the rank is 1 and the suit is d: Ace of Diamonds
Or, if the rank is 12 and the suit is c: Queen of Clubs
etc.
*/
ostream & operator<<(ostream &out, const Card &rhs){
    string completeSuit;
    string rankAssign;

    if (rhs.rank == 1){
        out << "Ace";
    }
    else if (rhs.rank == 11){
        out << "Jack";
    }
    else if (rhs.rank == 12){
        out << "Queen";
    }
    else if (rhs.rank == 13){
        out << "King";
    }
    else {
        out << rhs.rank;
    }

    if (rhs.suit == 'c'){
        completeSuit = "Clubs";
    }
    else if (rhs.suit == 'd'){
        completeSuit = "Diamonds";
    }
    else if (rhs.suit == 'h'){
        completeSuit = "Hearts";
    }
    else if (rhs.suit == 's'){
        completeSuit = "Spades";
    }
    out << " of " << completeSuit;
    return out;
}
