# Peg Game 🔵

A console-based peg solitaire puzzle game built in C++. 
Starting from a triangular board filled with pegs, the goal 
is to jump pegs over each other — removing the jumped peg — 
until as few pegs as possible remain.

## How to Play
- The board starts with pegs filling all positions except one
- Select a peg and a valid jump direction to move
- A jump is valid when a peg leaps over an adjacent peg into 
  an empty hole, removing the jumped peg
- The game ends when no more valid jumps exist
- **Goal:** Finish with as few pegs remaining as possible — 
  the perfect game ends with exactly 1 peg

## Features
- Triangular board representation in C++
- Full move validation — only legal jumps are accepted
- Dynamic board update and console display after each move
- Game-over detection when no valid moves remain
- Score display showing pegs remaining at end of game

## Concepts Demonstrated
- 2D array and triangular grid logic in C++
- Move validation with directional checks
- Game state management and loop design
- Clean console UI rendering
- Object-oriented structure with classes and methods

## How to Run
```bash
g++ -o peggame main.cpp
./peggame
```

## Language
- **C++**

---
*Built as part of CS coursework @ University of Illinois Chicago*
