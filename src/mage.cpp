#include "../include/Mage.h"
#include <iostream>
#include "../src/main.cpp"

using std::cout;
using std::endl;

Mage::Mage(std::string n) : Character(n, 80, 22) {}

void Mage::special(Character &enemy) {
    if (getSpecialCooldown() > 0) {
        cout << name << "'s Fireball is on cooldown!\n";
        return;
    }
    enemy.takeDamage(45);
    cout << name << " used Fireball for 45 damage!\n";
    if (randInt(1,100) <= 25) {
        enemy.takeDamage(10);
        enemy.applyBurn();
        cout << "Burn effect! Extra 10 damage and ongoing burn!\n";
    }
    setSpecialCooldown(3);
}
