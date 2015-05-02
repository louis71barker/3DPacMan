#include "header/geoDome.h"



void geoDome::dome()
{
    textLoader("textures/Skydome.png", geodomeTextID);
    GLuint gid = glGenLists(1);
    glNewList(gid, GL_COMPILE);
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
            glBindTexture(GL_TEXTURE_2D, geodomeTextID);
  //          glutSolidCube(CUBESIZE);
            glBegin(GL_TRIANGLES);

              for (int a = 2; a < (int)m_Index.size(); a += 3)
              {
                m_Normal[m_Index[a]-1].normalGL();
                m_Texture[m_Index[a-1]-1].textureGL();
                m_Vertex[m_Index[a-2]-1].vertexGL();
              }
  //            glDisable(GL_TEXTURE_GEN_T);
  //            glDisable(GL_TEXTURE_GEN_S);
            glEnd();
          glPopMatrix();
  //      }
  //    }
  //  }
    std::cout<<"draw Dome \n";
    glBindTexture(GL_TEXTURE_2D, 0);
    glEndList();
    m_displayList.push_back(gid);
}

void geoDome::drawdome()
{
  glCallLists(m_displayList.size(), GL_UNSIGNED_INT, &m_displayList[0]);
}
