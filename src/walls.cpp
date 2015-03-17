#include "walls.h"
#include <stdlib.h>
#include <iostream>
#include <vector>




#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif



void Walls::cubeInit()
{
  cubeSetter();
}



void Walls::cubeSetter()
{
  GLfloat w=CUBEWIDTH;
  GLfloat h=CUBEHEIGHT;
  GLfloat d=CUBEDEPTH;

  glPushMatrix();
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_QUADS);
    // front face
    glNormal3f(0,0,-1);
    glVertex3f(-w,h,d);
    glVertex3f(w,h,d);
    glVertex3f(w,-h,d);
    glVertex3f(-w,-h,d);
    // back face
    glNormal3d(0,0,1);
    glVertex3f(-w,h,-d);
    glVertex3f(w,h,-d);
    glVertex3f(w,-h,-d);
    glVertex3f(-w,-h,-d);
    // Left face
    glNormal3f(-1,0,0);
    glVertex3f(-w,-h,d);
    glVertex3f(-w,-h,-d);
    glVertex3f(-w,h,-d);
    glVertex3f(-w,h,d);
    // Right face
    glNormal3f(1,0,0);
    glVertex3f(w,-h,d);
    glVertex3f(w,-h,-d);
    glVertex3f(w,h,-d);
    glVertex3f(w,h,d);
    // Top face
    glNormal3f(0,1,0);
    glVertex3f(-w,h,d);
    glVertex3f(-w,h,-d);
    glVertex3f(w,h,-d);
    glVertex3f(w,h,d);
    // Bottom face
    glNormal3f(0,1,0);
    glVertex3f(-w,-h,d);
    glVertex3f(-w,-h,-d);
    glVertex3f(w,-h,-d);
    glVertex3f(w,-h,d);

  glEnd();
  glPopMatrix();
}

void Walls::mapBuilder()
{
  int num_of_col = 15;
  int num_of_row = 15;
  double init_value = 3.14;

  std::vector< std::vector<double> > matrix;
  //now we have an empty 2D-matrix of size (0,0). Resizing it with one single command:
  matrix.resize( num_of_col , std::vector<double>( num_of_row , init_value ) );


}
