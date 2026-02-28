// new branch
# ⚔️ RPG-CPP-GAME

A turn-based, two-player RPG battle game written in **C++**. Choose your hero, unleash powerful special abilities, and outlast your opponent in strategic combat!

---

## 🎮 Gameplay Overview

Two players go head-to-head in a turn-based battle. Each player picks a character class with unique stats, a special ability, and a defensive style. On each turn, a player can **attack**, **defend**, or **use their special** — the last one standing wins.

---

## 🧙 Character Classes

| Class | ❤️ HP | ⚔️ Attack | 🌟 Special Ability | Cooldown |
|-----------|--------|-----------|-------------------------------|----------|
| Warrior | 120 | 20 | **Power Strike** — heavy hit, 30% crit chance | 3 turns |
| Archer | 90 | 18 | **Sniper Shot** — 40 dmg, 40% miss chance | 3 turns |
| Mage | 80 | 22 | **Fireball** — 45 dmg, 25% burn proc | 3 turns |
| Paladin | 130 | 16 | **Divine Heal** — restores 30 HP, 20% fail | 4 turns |
| Assassin | 85 | 24 | **Shadow Strike** — 50 dmg, 50% crit, 40% miss | 4 turns |

---

## ✨ Features

- 🧬 **5 unique character classes**, each with distinct HP, attack power, and playstyle
- 💥 **Special abilities** with cooldown management
- 🛡️ **Defensive mechanics** — reduce, dodge, or heavily mitigate incoming damage depending on class
- 🔥 **Status effects** — burn deals ongoing damage each turn
- 🎲 **RNG-driven combat** — attack variance, critical hits, miss chances, and random burn procs keep every match unpredictable
- 🧑‍🤝‍🧑 **Local 2-player** — both players share the same keyboard

---

## 📁 Project Structure

```
RPG-CPP-GAME/
├── include/        # Header files
├── src/            # Source files
│   └── main.cpp    # Full game logic
├── .gitignore
├── LICENSE         # MIT License
└── README.md
```

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler supporting **C++11** or later (`g++`, `clang++`, MSVC, etc.)

### 🔧 Build

```bash
g++ -std=c++11 -I include/ src/main.cpp -o rpg_game
```

### ▶️ Run

```bash
./rpg_game
```

On Windows:
```bash
rpg_game.exe
```

---

## 🕹️ How to Play

1. **Player 1** selects a class (1–5)
2. **Player 2** selects a class (1–5)
3. Each turn, choose your action:
   - `1` — ⚔️ Attack
   - `2` — 🛡️ Defend
   - `3` — 🌟 Use Special
4. Players alternate turns until one falls
5. The last hero standing wins! 🏆

---

## ⚙️ Combat Mechanics

- **Attack** deals `attackPower ± random variance` damage each hit
- **Defend** halves incoming damage (Paladin reduces to 1/3; Archer has a 50% dodge chance)
- **Specials** are powerful but locked behind cooldown timers — use them wisely
- **Burn** deals 5 damage per turn until the battle ends
- **Critical Hits** can double damage on Power Strike and Shadow Strike

---

## 🧪 Class Strategies

> 🗡️ **Warrior** — Reliable tank. Use Power Strike every 3 turns for burst damage.
>
> 🏹 **Archer** — High risk, high reward. Sniper Shot hits hard but can miss; dodge-defend adds survivability.
>
> 🔮 **Mage** — Fragile but devastating. Fireball + burn combos can swing fights quickly.
>
> 🛡️ **Paladin** — Outlast your opponent. Heavy defense and healing make you hard to kill.
>
> 🗡️ **Assassin** — Explosive damage ceiling. A lucky Shadow Strike crit deals 100 damage — but misses sting.

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).

---

## 🤝 Contributing

Pull requests are welcome! For major changes, please open an issue first to discuss what you'd like to change.

---

<p align="center">Made with ❤️ and C++</p>
