#include "header/helicopter.h"



void Heli::buildHeli(const std::vector<std::vector<int> > _matrix)
{
  textLoader("textures/HelicopterTextures/Helicopter_Crash_D.tga", HeliTextID);
  GLuint hid = glGenLists(1);
  glNewList(hid, GL_COMPILE);

  glPushMatrix();
  for(int i = 0; i < (int)_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)_matrix[0].size(); ++j)
    {
      if(_matrix[i][j] == 10)
      {
        glTranslatef((i)*4, -2.3, ((int)_matrix[0].size() * 4) - (j)*4);
//        glScalef(0.5,0.5,0.5);
//        glRotatef(-90.0,0.0,1.0,0.0);
    //    glScalef(0.2,0.2,0.2);
        glBindTexture(GL_TEXTURE_2D, HeliTextID);
        glBegin(GL_TRIANGLES);
          for (int a = 2; a < (int)m_Index.size(); a += 3)
          {
            m_Normal[m_Index[a]-1].normalGL();
            m_Texture[m_Index[a-1]-1].textureGL();
            m_Vertex[m_Index[a-2]-1].vertexGL();
          }
        glEnd();
      }
    }
  }

  glPopMatrix();
  glBindTexture(GL_TEXTURE_2D, 0);
  glEndList();
  std::cout<<"build the Heli \n";
  m_displayList.push_back(hid);


}

void Heli::drawHeli()
{
  glCallLists(m_displayList.size(), GL_UNSIGNED_INT, &m_displayList[0]);
}
