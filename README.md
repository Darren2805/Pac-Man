# Pac-Man
# Pacman Game (C + Allegro)

##  Overview

This project is a **Pacman-style 2D game** developed in **C** using the **Allegro 5** graphics library.
It recreates the classic arcade gameplay where the player navigates through a maze, collects pellets, and avoids enemies.

The project focuses on **low-level game development**, including rendering, input handling, and real-time game logic.

---

## Features

* Player-controlled Pacman
* Maze-based movement & collision detection
* Pellet collection and scoring system
* Ghost enemies with movement behavior
* Multiple scenes (menu, game, settings)
* Mouse interaction support
* Audio support (if enabled)

---

## Tech Stack

* **Language:** C
* **Graphics Library:** Allegro 5
* **Platform:** Windows (MSYS2 MinGW)

---

## Project Structure

```
Darren_Pac-man/
│── Src/
│   ├── main.c
│   ├── game.c / game.h
│   ├── scene_game.c
│   ├── scene_menu.c
│   ├── scene_settings.c
│   ├── ghost.c
│   ├── map.c
│   ├── utility.c
│   └── ...
│
│── Assets/
│── Makefile (optional)
│── README.md
```

---

## Installation & Setup

### 1. Install MSYS2

Download and install MSYS2:
https://www.msys2.org/

---

### 2. Install dependencies

Open **MSYS2 MinGW x64 terminal** and run:

```
pacman -S mingw-w64-x86_64-gcc
pacman -S mingw-w64-x86_64-allegro
```

---

### 3. Navigate to project

```
cd /d/Darren/Darren_Pac-man
```

---

### 4. Compile

```
gcc Src/*.c -o pacman.exe -ISrc \
-lallegro \
-lallegro_primitives \
-lallegro_font \
-lallegro_ttf \
-lallegro_image \
-lallegro_audio \
-lallegro_acodec
```

---

### 5. Run

```
./pacman.exe
```

---

## Controls

* **Arrow Keys / WASD** → Move Pacman
* **Mouse Click** → Menu interaction
* **ESC** → Exit game
