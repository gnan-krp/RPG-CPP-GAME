#ifndef ASSASSIN_H
#define ASSASSIN_H

#include "Character.h"
#include <string>
using std::string;

class Assassin : public Character {
public:
    Assassin(string n);
    void special(Character &enemy) override;
};

#endif
