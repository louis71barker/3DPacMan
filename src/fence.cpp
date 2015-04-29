#include "header/fence.h"

void Fence::buildFence(const std::vector<std::vector<int> > _matrix)
{
  textLoader("textures/oldFence_texture.jpg", FenceTextID);
  GLuint fid = glGenLists(1);
  glNewList(fid, GL_COMPILE);
  glPushMatrix();
  for(int i = 0; i < (int)_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)_matrix[0].size(); ++j)
    {
      if(_matrix[i][j] == 7 | _matrix[i][j] == 8)
      {
        glBindTexture(GL_TEXTURE_2D, FenceTextID);
        setFence(i,j,_matrix);
        glBindTexture(GL_TEXTURE_2D, 0);
      }
    }
  }
  glPopMatrix();
  glEndList();
  m_displayList.push_back(fid);


}

void Fence::setFence(const int _a, const int _b, const std::vector<std::vector<int> > &_matrix)
{
  glPushMatrix();
    glTranslatef((_a)*4, -1, ((int)_matrix[0].size() * 4) - (_b)*4);
    glScalef(0.042,0.045,0.045);
    if (_matrix[_a][_b] == 7)
    {
      glRotatef(-90.0,0.0,1.0,0.0);
    }
    createFenceNormal(_matrix);
  glPopMatrix();
}

void Fence::createFenceNormal(const std::vector<std::vector<int> > &_matrix)
{
  glPushMatrix();
    glBegin(GL_TRIANGLES);
    for(int i = 0; i < (int)_matrix.size(); ++i)
    {
      for(int j = 0; j < (int)_matrix[0].size(); ++j)
      {
        if(_matrix[i][j] == 3)
        {
          for (int a = 2; a < (int)m_Index.size(); a += 3)
          {
            m_Normal[m_Index[a]-1].normalGL();
            m_Texture[m_Index[a-1]-1].textureGL();
            m_Vertex[m_Index[a-2]-1].vertexGL();
          }
        }
      }
    }
    glEnd();
  glPopMatrix();
}

void Fence::drawFence()
{
  glCallLists(m_displayList.size(), GL_UNSIGNED_INT, &m_displayList[0]);
}
