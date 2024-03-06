#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include "Character.h"
#include <iostream>

using namespace std;

class Warrior : public Character{
 private:
    string allegiance;

 public:
    Warrior(const string &name, double health, double attackStrength, string ally);

    void attack(Character &opponent) override;
};

#endif