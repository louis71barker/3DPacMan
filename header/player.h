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


  void update();
  void draw();



private:
  bool playerMoveAllowed;



};






#endif
