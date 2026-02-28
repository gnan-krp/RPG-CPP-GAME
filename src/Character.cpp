#include "../include/Character.h"
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

// ---------------- Constructor & Destructor ----------------

Character::Character(std::string n, int h, int a)
    : name(n), hp(h), maxHP(h), attackPower(a),
      specialCooldown(0), defending(false), burnEffect(false) {}

Character::~Character() {} // Virtual destructor ensures proper cleanup

// ---------------- Core Methods ----------------

void Character::attack(Character &enemy) {
    int damage = attackPower; // Base damage
    // Slight random variation (-2 to +3)
    damage += rand() % 6 - 2; 

    if (enemy.isDefending()) {
        damage /= enemy.defendMultiplier();
        cout << enemy.getName() << " reduced the damage! (" << damage << " dmg taken)\n";
        enemy.setDefending(false);
    }

    enemy.takeDamage(damage);
    cout << name << " dealt " << damage << " damage to " << enemy.getName() << "!\n";
}

void Character::defend() {
    defending = true;
    cout << name << " braces for incoming attacks!\n";
}

int Character::defendMultiplier() {
    return 2; // Default damage reduction is half
}

// ---------------- Status Effects ----------------

void Character::applyStatusEffects() {
    if (burnEffect) {
        int burnDamage = 5;
        takeDamage(burnDamage);
        cout << name << " suffers " << burnDamage << " burn damage!\n";
    }
}

// ---------------- Utilities ----------------

bool Character::isAlive() const { return hp > 0; }

std::string Character::getName() const { return name; }

void Character::showStatus() const {
    cout << name << " HP: " << hp << "/" << maxHP;
    if (burnEffect) cout << " (Burned)";
    if (specialCooldown > 0) cout << " [Special CD: " << specialCooldown << "]";
    cout << endl;
}

void Character::decreaseCooldown() {
    if (specialCooldown > 0) specialCooldown--;
}

void Character::takeDamage(int dmg) {
    hp = std::max(hp - dmg, 0);
}

void Character::heal(int amount) {
    hp = std::min(hp + amount, maxHP);
}

void Character::applyBurn() {
    burnEffect = true;
}

void Character::setDefending(bool value) {
    defending = value;
}

bool Character::isDefending() const {
    return defending;
}

void Character::setSpecialCooldown(int cd) {
    specialCooldown = cd;
}

int Character::getSpecialCooldown() const {
    return specialCooldown;
}
