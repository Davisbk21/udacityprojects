#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "obstacle.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  ~Game()
  {
    if (snake.score > snake_2.score)
      printf("Player 1 wins! \n");
    else if (snake.score < snake_2.score)
      printf("Player 2 wins! \n");
    else
      printf("No winner \n");
  }
      
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  void eat_food(Snake&);
  void check_crashing();

 private:
  Snake snake;
  Snake snake_2;
  
  Obstacle obs;
  
  SDL_Point food;
  SDL_Point food2;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void PlaceFood2();
  void Update();
};

#endif