# Turn-Based RPG 
A 2D, turn-based RPG developed using C++ and SDL2.

![turn-based-rpg](https://github.com/user-attachments/assets/01d9c749-29c3-46ab-a5e0-525c7e57c60c)

## Table of Contents
- [How to Play](#how-to-play)
  - [Gameplay](#gameplay)
- [Getting Started](#getting-started)
  - [Dependencies](#dependencies)
  - [Installation](#installation)
  - [Executing program](#executing-program)
- [Acknowledgments](#acknowledgments)

## How to Play <a name="how-to-play"></a>
### Gameplay <a name="gameplay"></a>
Players can choose between three different characters to fight against enemy AI (gpt-3.5-turbo). The game features a turn-based combat system where players can attack, check stats, save progress, or run away from battles.

| Fire Knight 🔥       | Water Priestess 🌊      | Ground Monk 🪨         |
|--------------------|-----------------------|----------------------|
| ![Fire Knight](./assets/characters/fire_knight/fire_knight.png) | ![Water Priestess](./assets/characters/water_priestess/water_priestess.png) | ![Ground Monk](./assets/characters/ground_monk/ground_monk.png) |
        
## Getting Started <a name="getting-started"></a>

### Installation <a name="installation"></a>

1. Clone the repo
    ```sh
    git clone https://github.com/ramirezfernando/turn-based-rpg.git
    ```
2. Download Homebrew
    ```sh
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)
    ```
3. Download dependencies
   ```sh
    brew install sdl2 # for peripheral handling
    brew install sdl2_image # for image loading
    brew install sdl2_ttf # for text rendering
    brew install nlohmann_json # for JSON handling
    ```
   ```

### Executing program <a name="executing-program"></a>

1. Compile and run the game
```
make game
```

## Acknowledgments <a name="acknowledgments"></a>

Special thanks to:
* [Let's Make Games](https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx)
* [Chierit](https://chierit.itch.io/)
* [Forest Background](https://pixeljoint.com/pixelart/120493.htm)
