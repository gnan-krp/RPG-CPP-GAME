#ifndef MAGE_H
#define MAGE_H

#include "Character.h"
#include <string>
using std::string;

class Mage : public Character {
public:
    Mage(string n);
    void special(Character &enemy) override;
};

#endif
