#include "Wizard.h"
#include <iostream>
using namespace std;
#include "Character.h"

Wizard::Wizard(const string & _name, double _health, double _attackStrength, int _rank) : Character(WIZARD, _name, _health, _attackStrength), rank(_rank) {}

void Wizard::attack(Character &opponent){
    double damage;
    if (opponent.getType() == WIZARD){
        Wizard &opp = dynamic_cast<Wizard &>(opponent);

        double attackRatio = static_cast<double>(rank) / static_cast<double>(opp.rank);
        damage = attackStrength * attackRatio;
    }
    else{
        damage = attackStrength;        
    }
    cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;

    opponent.damage(damage);

    cout << opponent.getName() << " takes " << damage << " damage." << endl;  
}