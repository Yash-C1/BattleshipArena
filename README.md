# ⚓ Battleship Game

A modular, object-oriented implementation of the classic **Battleship** game designed with scalability in mind. The project starts with **Player vs CPU (local)** gameplay and is architected to extend seamlessly to **Player vs Player (networked)** and **GUI-based** versions without changing core game logic.

---

## 🎯 Project Goals

- Build a clean, testable Battleship game using **low-level design principles**
- Demonstrate **OOP, SOLID principles, and design patterns**
- Enable easy extension from:
  - PvC → PvP (networked)
  - Terminal UI → GUI

---

## 🧩 Features

### Phase 1 – Player vs CPU (Local)
- Terminal-based UI
- Configurable game board
- Manual ship placement for human player
- Random (or extendable AI) ship placement & moves for CPU
- Turn-based gameplay
- Hit, miss, sunk detection
- Win/loss detection

### Phase 2 – Player vs Player (Networked)
- Client–Server architecture
- Socket-based communication
- Remote moves handled via `NetworkPlayer`
- **Game logic remains unchanged**

### Future Enhancements
- Smarter CPU AI (hunt/target strategy)
- GUI using Qt / SFML
- Replay & game history

---

## 🏗 Architecture Overview

The design strictly separates **game logic**, **players**, **UI**, and **networking**.

### Core Components

- **Game** – Controls game loop, turn switching, win condition
- **Board** – Manages grid, ship placement, and attack handling
- **Ship** – Tracks ship state, hits, and sunk status
- **Player (abstract)** – Base class for all player types
  - `HumanPlayer`
  - `CPUPlayer`
  - `NetworkPlayer`

This separation ensures that adding networking or a GUI does **not** affect core rules.

---

## 📐 UML Class Diagram

The project follows a clean UML-based design showing inheritance, composition, and associations between:
- Game
- Board
- Ship
- Player hierarchy

(See `docs/uml/` for diagrams.)

---

## 📁 Project Structure

```
battleship/
├── src/
│   ├── game/        # Game loop & state management
│   ├── board/       # Board & cell logic
│   ├── ship/        # Ship model
│   ├── player/      # Player implementations
│   ├── network/     # Client / Server (Phase 2)
│   ├── ui/          # Terminal UI (GUI later)
│   ├── ai/          # CPU strategies
│   └── utils/       # Shared helpers
├── tests/           # Unit tests
├── docs/            # UML & design docs
└── README.md
```

---

## 🔁 Game Flow (Simplified)

1. Initialize boards and players
2. Players place ships
3. Alternate turns:
   - Attacker makes a move
   - Defender board processes attack
   - Hit / Miss / Sunk determined
4. Check win condition
5. Declare winner

---

## 🧪 Testing Strategy

- Unit tests for:
  - Ship hit & sunk logic
  - Board placement & attack handling
  - Game win condition
- Integration tests for full game flow
- Network tests added in Phase 2

---

## 🚀 How to Run (Example)

```bash
make
./battleship
```

---

## 👥 Contributors

- Vaidehi Zade
- Yash Chaudhari

---

## 📌 Key Design Principles

- **Single Responsibility Principle**
- **Open/Closed Principle**
- **Polymorphism for player types**
- **Loose coupling between UI, logic, and networking**

---

## 📄 License

This project is for learning and educational purposes.
