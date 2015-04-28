#include "header/skyDome.h"



void skyDome::sky()
{
    textLoader("textures/Skydome.jpg", SkydomeTextID);
    GLuint sid = glGenLists(1);
    glNewList(sid, GL_COMPILE);
  //  for(int i = 0; i < (int)_matrix.size(); ++i)
  //  {
  //    for(int j = 0; j < (int)_matrix[0].size(); ++j)
  //    {
  //      if(_matrix[i][j] <= 10)
  //      {

          glPushMatrix();
          glTranslatef(20,0,20);
          glScalef(10,10,10);
  //          glTranslatef((i)*CUBESIZE, -4, ((int)_matrix.size() *CUBESIZE) - (j) * CUBESIZE);
  //          glColor3f(1,0,0);
  //          glEnable(GL_TEXTURE_GEN_S);
  //          glEnable(GL_TEXTURE_GEN_T);
  //          gluQuadricTexture(id, GL_TRUE);
            glBindTexture(GL_TEXTURE_2D, SkydomeTextID);
  //          glutSolidCube(CUBESIZE);
            glBegin(GL_TRIANGLES);

              for (int a = 2; a < (int)m_SkyIndex.size(); a += 3)
              {
                m_SkyNormal[m_SkyIndex[a]-1].normalGL();
                m_SkyTexture[m_SkyIndex[a-1]-1].textureGL();
                m_SkyVertex[m_SkyIndex[a-2]-1].vertexGL();
              }
  //            glDisable(GL_TEXTURE_GEN_T);
  //            glDisable(GL_TEXTURE_GEN_S);
            glEnd();
          glPopMatrix();
  //      }
  //    }
  //  }
    std::cout<<"draw Sphere \n";
    glBindTexture(GL_TEXTURE_2D, 0);
    glEndList();
    m_SkydisplayList.push_back(sid);
}

void skyDome::drawSky()
{
  glCallLists(m_SkydisplayList.size(), GL_UNSIGNED_INT, &m_SkydisplayList[0]);
}
