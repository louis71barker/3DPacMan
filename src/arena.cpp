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



void Arena::ground()
{


  textLoader("textures/GroundTextures/Diffuse.jpg", GroundTextID);
  GLuint id = glGenLists(1);
  glNewList(id, GL_COMPILE);
        glPushMatrix();
        glTranslatef(0,-2.3,0);

          glBindTexture(GL_TEXTURE_2D, GroundTextID);

          glScalef(0.4,0.4,0.4);
          glBegin(GL_TRIANGLES);


            for (int a = 2; a < (int)m_Index.size(); a += 3)
            {
              m_Normal[m_Index[a]-1].normalGL();
              m_Texture[m_Index[a-1]-1].textureGL();
              m_Vertex[m_Index[a-2]-1].vertexGL();
            }
          glEnd();
        glPopMatrix();

  glBindTexture(GL_TEXTURE_2D, 0);
  glEndList();
  m_displayList.push_back(id);
}


void Arena::drawArena()
{
  glCallLists(m_displayList.size(), GL_UNSIGNED_INT, &m_displayList[0]);

}
