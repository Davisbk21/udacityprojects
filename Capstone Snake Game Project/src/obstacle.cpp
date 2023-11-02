#include "obstacle.h"


bool Obstacle::ObstacleCell(int x, int y)
{
  for (size_t i = 0; i < size; i++)
  {
    if (x == body[i].x && y == body[i].y)
    {
      return true;
    }
  }
  
  return false;
}
