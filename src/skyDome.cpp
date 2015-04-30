#include "header/skyDome.h"



void skyDome::sky()
{
    textLoader("textures/Skydome.png", SkydomeTextID);
    GLuint sid = glGenLists(1);
    glNewList(sid, GL_COMPILE);

          //glPushMatrix();
//          glTranslatef(20,0,20);
//          glScalef(10,10,10);
          glBindTexture(GL_TEXTURE_2D, SkydomeTextID);
          glBegin(GL_TRIANGLES);
            glColor3f(1, 1, 1);
            for (int a = 2; a < (int)m_SkyIndex.size(); a += 3)
            {
              m_SkyNormal[m_SkyIndex[a]-1].normalGL();
              m_SkyTexture[m_SkyIndex[a-1]-1].textureGL();
              m_SkyVertex[m_SkyIndex[a-2]-1].vertexGL();
            }
          glEnd();
        //glPopMatrix();
      glBindTexture(GL_TEXTURE_2D, 0);
    std::cout<<"build Sphere \n";
    glEndList();
    m_displayList.push_back(sid);
}




void skyDome::drawSky()
{
  glCallLists(m_displayList.size(), GL_UNSIGNED_INT, &m_displayList[0]);
}




