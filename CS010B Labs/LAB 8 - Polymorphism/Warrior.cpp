#include "Warrior.h"
#include <iostream>

using namespace std;

Warrior::Warrior(const string & _name, double _health, double _attackStrength, string _ally) : Character(WARRIOR, _name, _health, _attackStrength) ,allegiance(_ally){}
    
void Warrior::attack(Character &opponent){
    if (opponent.getType() == WARRIOR){

        Warrior &opp = dynamic_cast<Warrior &>(opponent);

        if (allegiance == opp.allegiance){
            cout << "Warrior " << name << " does not attack Warrior " << opp.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
            return;
        }
    }
    cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;


    double damage = (health / MAX_HEALTH) * (attackStrength);
    opponent.damage(damage);

    cout << opponent.getName() << " takes " << damage << " damage." << endl;
}



