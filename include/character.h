#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using std::string;

class Character {
protected:
    string name;
    int hp;
    int maxHP;
    int attackPower;
    int specialCooldown;
    bool defending;
    bool burnEffect;

public:
    Character(string n, int h, int a);
    virtual ~Character();

    virtual void special(Character &enemy) = 0;
    virtual void attack(Character &enemy);
    virtual void defend();
    virtual int defendMultiplier();

    void applyStatusEffects();
    bool isAlive() const;
    string getName() const;
    void showStatus() const;
    void decreaseCooldown();
    void takeDamage(int dmg);
    void heal(int amount);
    void applyBurn();
    void setDefending(bool value);
    bool isDefending() const;
    void setSpecialCooldown(int cd);
    int getSpecialCooldown() const;
};

#endif
