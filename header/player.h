#ifndef PLAYER_H__
#define PLAYER_H__


#include <vector>
#include <stdlib.h>
#include <iostream>
#include <GL/gl.h>


#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif


class Player
{
public:
  Player ()
  {
  playerMoveAllowed = true;
  }

  void colliosion(std::vector<std::vector<int> > matrix, float playerXpos, float playerZpos);
  void update(std::vector<std::vector<int> > matrix, float playerXpos, float playerZpos);
  void draw();



private:
  bool playerMoveAllowed;



};






#endif
