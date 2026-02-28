#ifndef PALADIN_H
#define PALADIN_H

#include "Character.h"
#include <string>
using std::string;

class Paladin : public Character {
public:
    Paladin(string n);
    void special(Character &enemy) override;
    void defend() override;
    int defendMultiplier() override;
};

#endif
