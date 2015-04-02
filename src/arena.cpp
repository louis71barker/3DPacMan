#include "header/arena.h"
#include "header/walls.h"
#include <iostream>
#include <cmath>
#include <SDL.h>
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>






#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif



void Arena::ground(std::vector<std::vector<int> > _matrix)
{
  for(int i = 0; i < (int)_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)_matrix[0].size(); ++j)
    {
      if(_matrix[i][j] <= 10)
      {
        glPushMatrix();
          glTranslatef((i)*CUBESIZE, -4, ((int)_matrix.size() *CUBESIZE) - (j) * CUBESIZE);
          glColor3f(1,1,1);
          glutSolidCube(CUBESIZE);
        glPopMatrix();
      }
    }
  }
}

void Arena::sky()
{
    // Draw ground
}

void Arena::drawArena(std::vector<std::vector<int> > _matrix)
{
  ground(_matrix);
  sky();

}


