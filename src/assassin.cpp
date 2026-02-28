#include "../include/Assassin.h"
#include <iostream>
#include "../src/main.cpp"

using std::cout;
using std::endl;

Assassin::Assassin(std::string n) : Character(n, 85, 24) {}

void Assassin::special(Character &enemy) {
    if (getSpecialCooldown() > 0) {
        cout << name << "'s Shadow Strike is on cooldown!\n";
        return;
    }
    if (randInt(1,100) <= 40) {
        cout << "Shadow Strike MISSED!\n";
        return;
    }
    int damage = 50;
    if (randInt(1,100) <= 50) {
        damage *= 2;
        cout << "CRITICAL SHADOW STRIKE!\n";
    }
    enemy.takeDamage(damage);
    cout << name << " dealt " << damage << " damage!\n";
    setSpecialCooldown(4);
}
