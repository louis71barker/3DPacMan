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
  //this loads the texture file for the ground
  textLoader("textures/GroundTextures/Diffuse.jpg", GroundTextID);
  GLuint id = glGenLists(1);
  glNewList(id, GL_COMPILE);
        glPushMatrix();
        //this moves the ground down to the
        glTranslatef(0,-2.3,0);
          //binds the texture to the tree ground obj
          glBindTexture(GL_TEXTURE_2D, GroundTextID);
          //scales down the floor
          glScalef(0.4,0.4,0.4);
          glBegin(GL_TRIANGLES);
            for (int a = 2; a < (int)m_Index.size(); a += 3)
            {
              //set the normals for the obj
              m_Normal[m_Index[a]-1].normalGL();
              //set the texture coor for the obj
              m_Texture[m_Index[a-1]-1].textureGL();
              //set the vertex for the obj
              m_Vertex[m_Index[a-2]-1].vertexGL();
            }
          glEnd();
        glPopMatrix();
  //unbind the texture
  glBindTexture(GL_TEXTURE_2D, 0);
  glEndList();
  //add ground to the displaylist
  m_displayList.push_back(id);
}


void Arena::drawArena()
{
  //draw the ground from in the list
  glCallLists(m_displayList.size(), GL_UNSIGNED_INT, &m_displayList[0]);

}
