#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"
#include <string>
using std::string;

class Warrior : public Character {
public:
    Warrior(string n);
    void special(Character &enemy) override;
};

#endif
