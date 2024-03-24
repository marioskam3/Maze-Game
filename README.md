![ProjectLogo](/Logo-&-Screenshots/Maze_Game.png)

## Overview

This is a terminal maze game developed in c++

## Contents

- [Origin](#Origin)
- [How to Play](#How-to-play)
- [Gameplay Screenshots](#Gameplay-Screenshots)
- [How to Install](#How-to-Install)
- [How to Compile and Run](How-to-Compile-and-Run)
- [Future Plans](#Future-Plans)
- [License](#License)


## Origin

You are Lucas (L) and you have to explore the maze and find the magic stone before Mpampis (M) does.\
Be careful, the magic stone will randomly disappear and reappear in different places.\
FAST! Mpampis is already in the maze...

## How to Play

### Goal

The goal of the game is to find the magic stone before Mpampis does.

### Controls

You can move Lucas with W-A-S-D keys.\
You can skip your turn with the spacebar.\
Exit the game with the ESC key.


## Gameplay Screenshots

Here are some screenshots of the game in action:

### Main Game Field

![screenshot-1](/Logo-&-Screenshots/Screenshot_1.png)

### Loser's Screen

![screenshot-2](/Logo-&-Screenshots/Screenshot_2.png)

### Winner's Screen

![screenshot-3](/Logo-&-Screenshots/Screenshot_3.png)

## How to Install

1. **Clone the repository to your local machine:**
    ```bash
        git clone https://github.com/marioskam3/Maze-Game
    ```

2. **Navigate to the project directory:**
    ```bash
        cd Maze-Game/Game-Code
    ```

## How to compile and run

1. **You will need a c++ compiler:**
    ```bash
        sudo apt update && sudo apt upgrade
    ```

I am using g++.\
Download g++ with:
    ```bash
        sudo apt install g++
    ```

2. **Install the ncurses library:**
  ```bash
    sudo apt-get install libncurses5-dev libncursesw5-dev
  ```

  Confirm the Installation:
  ```bash
    dpkg -L libncurses-dev libncurses5-dev libncursesw5-dev
  ```
  

3. **Compile program:**

  ```bash
    g++ *.cpp -o magic_stone -lncurses
  ```

4. **Run program:**

  ```bash
    ./magic_stone map.txt 
  ```
  (you can change the map with your custom map file)

## Future Plans

- **A more efficient and clever algorithm for Mpampis movement (feel free to suggest your ideas!)**

## License

This project is licensed under the MIT License
