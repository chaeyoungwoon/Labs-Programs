#include "Elf.h"
#include <iostream>

using namespace std;

Elf::Elf(const string & _name, double _health, double _attackStrength, string _ally) : Character(ELF, _name, _health, _attackStrength) , family(_ally){}

void Elf::attack(Character &opponent) {

    if (opponent.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(opponent);

        if(family == opp.family) {
            cout << "Elf " << name << " does not attack Elf " << opp.getName() << "." << endl;
            cout << "They are both members of the " << family << " family." << endl;
            return;
        }
    }
    cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;

    double damage = (health / MAX_HEALTH) * (attackStrength);
    opponent.damage(damage);

    cout << opponent.getName() << " takes " << damage << " damage." << endl; 
}


   
