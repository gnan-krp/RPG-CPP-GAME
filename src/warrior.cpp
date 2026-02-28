#include "../include/Warrior.h"
#include <iostream>
#include "../src/main.cpp" // for randInt function if using central random

using std::cout;
using std::endl;

Warrior::Warrior(std::string n) : Character(n, 120, 20) {}

void Warrior::special(Character &enemy) {
    if (getSpecialCooldown() > 0) {
        cout << name << "'s Power Strike is on cooldown!\n";
        return;
    }
    int damage = 35 + randInt(0,5);
    if (randInt(1,100) <= 30) {
        damage *= 2;
        cout << "CRITICAL HIT!\n";
    }
    enemy.takeDamage(damage);
    cout << name << " used Power Strike for " << damage << " damage!\n";
    setSpecialCooldown(3);
}
