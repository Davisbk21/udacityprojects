# Capstone Project Option 2: Snake Racing Game 

## Description
This project is a modified version of the traditional snake game. The objective is for two players to race to get to the closest one of two different food objects in order to grow as large as possible without hitting the other snake or the obstacles. As soon as either snake eats a piece of food, the other piece of food spoils and is removed from the field and two more pieces of food are placed randomly on the board. A larger playing area and high constrast colors (white playing area, blue and black snakes, green food, and purple obstacles) make this version of the snake game easier to play. This is an extension of the starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The starter code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses. 

## Expected behavior:
1. 8 Bit graphics
2. Large white play area, 2 black snakes with blue heads, green food, and purple obstacles.
3. Player one uses arrow keys and player two uses "ADWS" to move Left, Right, Up and Down respectively.
4. Snake grows by 1 unit and becomes faster after eating food.
5. Game ends when a snake head hits either snake's body, or obstacle.

## Rubric Points (5 required):
1. The project makes use of references in function declarations. - controller.cpp line 12
2. A mutex or lock is used in the project. - renderer.cpp line 44
3. Classes use appropriate access specifiers for class members. - obstacle.h lines 13 and 43
4. The project accepts user input and processes the input. - controller.cpp lines 39 - 57
5. The project uses destructors appropriately. - obstacle.h line 33

## Basic Build Instructions
1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)


