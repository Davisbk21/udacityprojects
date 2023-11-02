#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height, 1), snake_2(grid_width, grid_height, 2), obs(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake, snake_2);
    Update();
    renderer.Render(snake, snake_2, food, food2, obs);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(snake.score, snake_2.score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y, x2, y2;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    x2 = random_w(engine);
    y2 = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
    if (!snake.SnakeCell(x2, y2)) {
      food2.x = x2;
      food2.y = y2;
      return;
    }
  }
}
}

void Game::eat_food(Snake& snake) {
  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);
  //Check if there's food over here
  if (food.x == new_x && food.y == new_y || food2.x == new_x && food2.y == new_y) {
    score++;
    snake.score++;
    PlaceFood();
    //Grow snake and incerase speed
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

void Game::check_crashing() {
  int head_1_x = static_cast<int>(snake.head_x);
  int head_1_y = static_cast<int>(snake.head_y);
  
  int head_2_x = static_cast<int>(snake_2.head_x);
  int head_2_y = static_cast<int>(snake_2.head_y);
  
  if(snake.SnakeCell(head_2_x, head_2_y))   snake.alive = false;  
  if(obs.ObstacleCell(head_1_x, head_1_y))   snake.alive = false;

  if(snake_2.SnakeCell(head_1_x, head_1_y)) snake_2.alive = false;
   if(obs.ObstacleCell(head_2_x, head_2_y))   snake_2.alive = false;

  
  
}

void Game::Update() {
  if (!snake.alive) return;
  if (!snake_2.alive) return;

  snake.Update();
  snake_2.Update();
  
  check_crashing();
  
  eat_food(snake);
  eat_food(snake_2);

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y || food2.x == new_x && food2.y == new_y){
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }