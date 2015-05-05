#include "header/geoDome.h"



void geoDome::dome()
{
  //loads the texture for the dome
    textLoader("textures/Skydome.png", m_geodomeTextID);
    GLuint gid = glGenLists(1);
    glNewList(gid, GL_COMPILE);
      glPushMatrix();
      //scale and move to correct locations
      glTranslatef(20,0,20);
      glScalef(10,10,10);
        //binf the textures
        glBindTexture(GL_TEXTURE_2D, m_geodomeTextID);
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
    //unbind the textures
    glBindTexture(GL_TEXTURE_2D, 0);
    glEndList();
    //add to the display list
    m_displayList.push_back(gid);
}

void geoDome::drawdome()
{
  //draw the dome from the list
  glCallLists(m_displayList.size(), GL_UNSIGNED_INT, &m_displayList[0]);
}
