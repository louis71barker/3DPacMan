#include "header/fence.h"


void Fence::buildFence(const std::vector<std::vector<int> > _matrix)
{
  textLoader("textures/FenceTextures/Metal_Fence_Diffuse_02.png", FenceTextID);

  GLuint fid = glGenLists(1);
  glNewList(fid, GL_COMPILE);
  height = 2.3;
  glPushMatrix();

  glBindTexture(GL_TEXTURE_2D, FenceTextID);
  for(int i = 0; i< (int)_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)_matrix.size(); ++j)
    {
      glScalef(0.5,0.5,0.5);
      if(_matrix[i][j] == 7)
      {
        glTranslatef((i)*4, height, ((int)_matrix[0].size() * 4) - (j)*4);
        createFenceNormal();
        height = 0;

//        glRotatef(-90.0,0.0,1.0,0.0);
    //    glScalef(0.2,0.2,0.2);


      }
      if(_matrix[i][j] == 8)
      {
        glTranslatef((i)*4, height, ((int)_matrix[0].size() * 4) - (j)*4);
        glRotatef(-90.0,0.0,1.0,0.0);
    //    glScalef(0.2,0.2,0.2);
        createFenceRotated();
        height = 0;

      }
    }
  }
  glPopMatrix();
  glBindTexture(GL_TEXTURE_2D, 0);
  glEndList();
  std::cout<<"build Fence \n";
  m_displayList.push_back(fid);

}

void Fence::createFenceNormal()
{

  glBegin(GL_TRIANGLES);
    for (int a = 2; a < (int)m_Index.size(); a += 3)
    {
      m_Normal[m_Index[a]-1].normalGL();
      m_Texture[m_Index[a-1]-1].textureGL();
      m_Vertex[m_Index[a-2]-1].vertexGL();
    }
  glEnd();
}

void Fence::createFenceRotated()
{
  glBegin(GL_TRIANGLES);
    for (int a = 2; a < (int)m_Index.size(); a += 3)
    {
      m_Normal[m_Index[a]-1].normalGL();
      m_Texture[m_Index[a-1]-1].textureGL();
      m_Vertex[m_Index[a-2]-1].vertexGL();
    }
  glEnd();
}

void Fence::drawFence()
{
  glCallLists(m_displayList.size(), GL_UNSIGNED_INT, &m_displayList[0]);
}
