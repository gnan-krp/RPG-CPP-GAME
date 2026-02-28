#include "../include/Archer.h"
#include <iostream>
#include "../src/main.cpp"

using std::cout;
using std::endl;

Archer::Archer(std::string n) : Character(n, 90, 18) {}

void Archer::special(Character &enemy) {
    if (getSpecialCooldown() > 0) {
        cout << name << "'s Sniper Shot is on cooldown!\n";
        return;
    }
    if (randInt(1,100) <= 40) {
        cout << "Sniper Shot MISSED!\n";
    } else {
        enemy.takeDamage(40);
        cout << name << " used Sniper Shot for 40 damage!\n";
    }
    setSpecialCooldown(3);
}

void Archer::defend() {
    if (randInt(1,100) <= 50) {
        cout << name << " dodged the next attack!\n";
        setDefending(true);
    } else {
        cout << name << " failed to dodge!\n";
    }
}
