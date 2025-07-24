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
Players can choose between three different characters to fight against each other. The game ends when a player has reached 0 health. Players can choose between:

| Fire Knight 🔥       | Water Priestess 🌊      | Ground Monk 🪨         |
|--------------------|-----------------------|----------------------|
| ![Fire Knight](./assets/characters/fire_knight/fire_knight.png) | ![Water Priestess](./assets/characters/water_priestess/water_priestess.png) | ![Ground Monk](./assets/characters/ground_monk/ground_monk.png) |
        
## Getting Started <a name="getting-started"></a>

### Dependencies <a name="dependencies"></a>
The system requirements for running on a macOS are:
* [Clang](https://clang.llvm.org/)
* [Homebrew](https://brew.sh/)
* [SDL2](https://www.libsdl.org/)
* [SDL2_image](https://www.libsdl.org/projects/SDL_image/)

### Installation <a name="installation"></a>

1. Clone the repo
    ```sh
    git clone https://github.com/ramirezfernando/turn-based-rpg.git
    ```
2. Download Homebrew
    ```sh
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)
    ```
3. Download SDL2 libraries
   ```sh
    brew install sdl2
    brew install sdl2_image
   ```

### Executing program <a name="executing-program"></a>

1. Compile the program into an executable
```
make game
```
2. Run the executable
```
./play
```

## Acknowledgments <a name="acknowledgments"></a>

Special thanks to:
* [Let's Make Games](https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx)
* [Chierit](https://chierit.itch.io/)
* [Forest Background](https://pixeljoint.com/pixelart/120493.htm)
