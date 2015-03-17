#include "header/arena.h"
#include <iostream>
#include <cmath>
#include <SDL.h>
#include <iostream>
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



void Arena::ground()
{
  // assume the  cube centered at the origin
  GLfloat w=0.5f;
  GLfloat h=0.5f;
  GLfloat d=0.5f;


  glBegin(GL_QUADS);
    // front face
    glNormal3f(0,0,1);
    glVertex3f(-w,h,d);
    glVertex3f(w,h,d);
    glVertex3f(w,-h,d);
    glVertex3f(-w,-h,d);
    // back face
    glNormal3d(0,0,-1);
    glVertex3f(-w,h,-d);
    glVertex3f(w,h,-d);
    glVertex3f(w,-h,-d);
    glVertex3f(-w,-h,-d);
    // Left face
    glNormal3f(1,0,0);
    glVertex3f(-w,-h,d);
    glVertex3f(-w,-h,-d);
    glVertex3f(-w,h,-d);
    glVertex3f(-w,h,d);
    // Right face
    glNormal3f(-1,0,0);
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
    glNormal3f(0,-1,0);
    glVertex3f(-w,-h,d);
    glVertex3f(-w,-h,-d);
    glVertex3f(w,-h,-d);
    glVertex3f(w,-h,d);

  glEnd();
}

void Arena::sky()
{
  Arena a;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



          // Draw ground
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_QUADS);
      glVertex3f(-100.0f, 0.0f, -100.0f);
      glVertex3f(-100.0f, 0.0f,  100.0f);
      glVertex3f( 100.0f, 0.0f,  100.0f);
      glVertex3f( 100.0f, 0.0f, -100.0f);
    glEnd();
}

void Arena::drawArena()
{
  ground();

}


