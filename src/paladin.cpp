#include "../include/Paladin.h"
#include <iostream>
#include "../src/main.cpp"

using std::cout;
using std::endl;

Paladin::Paladin(std::string n) : Character(n, 130, 16) {}

void Paladin::special(Character &enemy) {
    if (getSpecialCooldown() > 0) {
        cout << name << "'s Divine Heal is on cooldown!\n";
        return;
    }
    if (randInt(1,100) <= 20) {
        cout << "Divine Heal FAILED!\n";
        return;
    }
    heal(30);
    cout << name << " healed 30 HP!\n";
    setSpecialCooldown(4);
}

void Paladin::defend() {
    setDefending(true);
    cout << name << " reduces incoming damage heavily!\n";
}

int Paladin::defendMultiplier() {
    return 3; // reduces damage even more
}
