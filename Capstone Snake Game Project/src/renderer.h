#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <mutex>
#include "SDL.h"
#include "snake.h"
#include "obstacle.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();
  
  void Render(Snake const snake, Snake const snake_2, SDL_Point const &food, SDL_Point const &food2);
  void render_snake(Snake const snake, SDL_Rect &block);
  
  void Render(Snake const snake, Snake const snake_2, SDL_Point const &food, SDL_Point const &food2, Obstacle&);
  void UpdateWindowTitle(int score, int score_2, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
  
  std::mutex mtx_;
};

#endif