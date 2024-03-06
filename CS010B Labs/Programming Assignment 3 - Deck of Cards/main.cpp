#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand);

// Sends to output stream a hand of Cards on a single line, 
// each Card separated by a comma.
// If the vector is empty, do not output anything.
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs 
ostream & operator<<(ostream &out, const vector<Card> &aDeal);

//Estimates percentage of when a person will get a pair of cards
double monteCarlo(int numPairs, int numDeals);

int main() {
    srand(2222);

    ofstream outFS;
    string filename;
    string userChoice;
    int numCards = 0;
    int numDeals = 0;
    int numPairs = 0;

    Deck deal;
    vector<Card> aDeal;

    cout << "Do you want to output all hands to a file?(Yes/No)";
    cin >> userChoice;
    cout << endl;

    if (userChoice == "Yes"){
        cout << "Enter name of output file: ";
        cin >> filename;
        cout << endl;

        outFS.open(filename);
        if (!outFS.is_open()){
            cout << "Error opening " << filename << endl;
            return 1;
        }
    }

    cout << "Enter number of cards per hand: ";
    cin >> numCards;
    cout << endl;

    cout << "Enter number of deals (simulations): ";
    cin >> numDeals;
    cout << endl;

    for (int i = 0; i < numDeals; ++i){
        deal.shuffleDeck();
        aDeal.clear();
        for (int j = 0; j < numCards; ++j){
            aDeal.push_back(deal.dealCard());
        }
        if (hasPair(aDeal)){
            ++numPairs;
            outFS << "Found Pair!! ";
        } 
        else {
            outFS << "             ";
        }
        if (userChoice == "Yes"){
            outFS << aDeal << endl;
        }
    }

    cout << "Chances of receiving a pair in a hand of " << numCards << " cards is: " << monteCarlo(numPairs, numDeals) << "%" << endl;
    
    outFS.close();

    return 0;
}

ostream & operator<<(ostream &out, const vector<Card> &aDeal){
    out << aDeal[0];
    for (unsigned int i = 1; i < aDeal.size(); ++i){
        out << ", " << aDeal[i];
    }
    return out;
}

bool hasPair(const vector<Card> &aDeal){
    bool same = false;
    for (unsigned int i = 0; i < aDeal.size(); ++i){
        for (unsigned int j = i + 1; j < aDeal.size(); ++j){
            if (aDeal[i].getRank() == aDeal[j].getRank()){
                same = true;
            }
        }
    }
    return same;
}

double monteCarlo(int numPairs, int numDeals){
    return 100.0 * (static_cast<double>(numPairs) / numDeals);
}