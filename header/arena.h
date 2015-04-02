#ifndef ARENA_H__
#define ARENA_H__

#include <vector>
#include "walls.h"





class Arena
{
public:
  Arena ()
  {

  }

  void ground(std::vector<std::vector<int> > _matrix);
  void sky();
  void drawArena(std::vector<std::vector<int> > _matrix);


private:



};






#endif
