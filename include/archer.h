#ifndef ARCHER_H
#define ARCHER_H

#include "Character.h"
#include <string>
using std::string;

class Archer : public Character {
public:
    Archer(string n);
    void special(Character &enemy) override;
    void defend() override;
};

#endif
