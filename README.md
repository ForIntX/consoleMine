# ConsoleMine

A custom-built, lightweight console game engine and game project developed in C++. This project is born out of a principle of self-reliance—building the engine from scratch to understand the core mechanics of game development, graphics logic, and system architecture.

## Overview

`consoleMine` is a terminal-based game that focuses on efficient console rendering and modular software design. Instead of using third-party engines, it utilizes custom-written systems to handle game loops, input, and rendering.

## Tech Stack

- **Language:** C++
- **Environment:** Linux (Developed & Optimized for Linux Mint)
- **Compiler:** GCC / G++
- **Focus:** Low-level architecture, memory management, and procedural logic.

## Current Features (v0.1.3-alpha)

- **Custom Rendering:** Optimized console output for smooth gameplay.
- **Movement System:** Real-time movement tracking with a dedicated counter.
- **Game State Management:** Integrated game-over conditions and end-game logic.
- **Minimalist Design:** High performance with zero external dependencies.

## Architectural Vision (Work in Progress)

The project is currently undergoing a major architectural shift to decouple responsibilities:

- **Engine Module:** Will handle core timing and logic.
- **Renderer Module:** Will be responsible for frame updates and console UI.
- **Game Object:** Being refactored to be a lightweight controller rather than a monolithic object.

## Getting Started

### Prerequisites

- `g++` compiler installed.

### Installation & Running

1. Clone the repository:
```bash
   git clone https://github.com/ForIntX/consoleMine.git
```

2. Navigate to the project directory and run:
```bash
   make run
```

## Roadmap

- [ ] Procedural Map System: Infinite map generation logic.
- [ ] ANSI Color Integration: Richer visual experience in the terminal.
- [ ] Standardization: Full migration of codebase from Turkish to English.
- [ ] ECS Implementation: Investigating Entity Component System for future scalability.
