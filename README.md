# Breakout

**Breakout** is a C++ project designed to practice Template usage.

## Cloning and Opening the Project in Visual Studio

1. Clone the repository

2. Open the `Bouncer.sln` solution file located at the root of the repository.

3. Build the project in Visual Studio using **release** configuration.

4. Copy the dll files sfml-graphics-2.dll, sfml-system-2.dll and sfml-window-2.dll at the root of the .exe

5. Copy the Ressource folder in Source folder and paste it at the root of the .exe as well

That's it! You can edit your own level at will. You just need to fill the level1.txt file with X where you want to place a brick and an O where you want an empty space.

**Note:** This project makes the use of concepts, you need C++20 to compile it !

## Controls

Use Left and Right arrows to move with the player.
Use space to release the ball and play again.

## Code we are proud of

**All of us**:

- Not a single raw pointer in the project, all pointers are Smart Pointers.

**François**:

- EntityManager -> The map structure to store and access data easily, template functions and concepts to access it.
- Entity Sprites management -> Easy to access the sprite to draw it every frame, and paying attention on the owernership as well (returning a weak_ptr).

**Tristan**:

- BrickGrid -> Easy to use tool that allows us to quickly "draw" and import a brick layout to play with, simply by editing a .txt file.
