#include "header/geoDome.h"



void geoDome::dome()
{
    textLoader("textures/Skydome.png", geodomeTextID);
    GLuint gid = glGenLists(1);
    glNewList(gid, GL_COMPILE);
      glPushMatrix();
      glTranslatef(20,0,20);
      glScalef(10,10,10);
        glBindTexture(GL_TEXTURE_2D, geodomeTextID);
        glBegin(GL_TRIANGLES);
          for (int a = 2; a < (int)m_Index.size(); a += 3)
          {
            m_Normal[m_Index[a]-1].normalGL();
            m_Texture[m_Index[a-1]-1].textureGL();
            m_Vertex[m_Index[a-2]-1].vertexGL();
          }
        glEnd();
      glPopMatrix();
    std::cout<<"draw Dome \n";
    glBindTexture(GL_TEXTURE_2D, 0);
    glEndList();
    m_displayList.push_back(gid);
}

void geoDome::drawdome()
{
  glCallLists(m_displayList.size(), GL_UNSIGNED_INT, &m_displayList[0]);
}
