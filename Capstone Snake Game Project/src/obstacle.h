#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "SDL.h"

class Obstacle
{
public:
  Obstacle(int garid_width, int grid_height)
    : grid_width(grid_width),
      grid_height(grid_height)
  {
  
   size = (1. / 3.) * grid_height;
   printf("%d \n", size);
   
   body = new SDL_Point[size];
   
   for (size_t i = 0; i < size; i++)
   {SDL_Point p;
   p.x = size + i;
   p.y = size + i;
   
   body[i] = p;
   }
}

~Obstacle() {delete[] body; }

Obstacle(Obstacle const &source);
Obstacle &operator=(Obstacle const &source);

bool ObstacleCell(int x, int y);

int size;
SDL_Point *body;

private:
int grid_width;
int grid_height;
};

#endif