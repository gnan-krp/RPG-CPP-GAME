#include <iostream>
#include <string>
#include "../include/Character.h"
#include "../include/Warrior.h"
#include "../include/Archer.h"
#include "../include/Mage.h"
#include "../include/Paladin.h"
#include "../include/Assassin.h"

using std::cout;
using std::cin;
using std::endl;

// Forward declaration of helper functions (defined below)
int randInt(int min, int max);
Character* chooseCharacter(int choice, std::string playerName);
void playerTurn(Character* player, Character* enemy);

int main() {
    cout << "===== WELCOME TO THE C++ RPG GAME =====\n";
    cout << "Choose Character:\n";
    cout << "1. Warrior\n2. Archer\n3. Mage\n4. Paladin\n5. Assassin\n";

    int c1, c2;
    cout << "Player 1 choose: "; cin >> c1;
    cout << "Player 2 choose: "; cin >> c2;

    Character* player1 = chooseCharacter(c1, "Player 1");
    Character* player2 = chooseCharacter(c2, "Player 2");

    while(player1->isAlive() && player2->isAlive()) {
        cout << "\n===== STATUS =====\n";
        player1->showStatus();
        player2->showStatus();

        // Player 1 turn
        playerTurn(player1, player2);
        if(!player2->isAlive()) break;

        // Player 2 turn
        playerTurn(player2, player1);
    }

    cout << "\n===== GAME OVER =====\n";
    if(player1->isAlive())
        cout << "Player 1 Wins!\n";
    else
        cout << "Player 2 Wins!\n";

    // Clean up
    delete player1;
    delete player2;

    return 0;
}

// ---------------- Helper Functions ----------------

#include <random>
#include <ctime>

std::mt19937 rng(std::time(nullptr)); // Random engine

int randInt(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

Character* chooseCharacter(int choice, std::string playerName) {
    switch(choice) {
        case 1: return new Warrior(playerName);
        case 2: return new Archer(playerName);
        case 3: return new Mage(playerName);
        case 4: return new Paladin(playerName);
        case 5: return new Assassin(playerName);
        default: return new Warrior(playerName);
    }
}

void playerTurn(Character* player, Character* enemy) {
    player->applyStatusEffects();

    cout << "\n" << player->getName() << "'s Turn\n";
    cout << "1. Attack\n2. Defend\n3. Special\n";

    int choice;
    while (!(cin >> choice) || choice < 1 || choice > 3) {
        cin.clear(); cin.ignore(1000,'\n');
        cout << "Invalid choice! Enter 1,2,3: ";
    }

    switch(choice) {
        case 1: player->attack(*enemy); break;
        case 2: player->defend(); break;
        case 3: player->special(*enemy); break;
    }

    player->decreaseCooldown();
}
