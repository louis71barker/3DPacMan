#include "header/fence.h"

void Fence::buildFence(const std::vector<std::vector<int> > &m_matrix)
{
  //loads the texture in for the fence
  textLoader("textures/oldFence_texture.jpg", m_FenceTextID);
  GLuint fid = glGenLists(1);
  glNewList(fid, GL_COMPILE);
  glPushMatrix();
  //itterate though the map matrix
  for(int i = 0; i < (int)m_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)m_matrix[0].size(); ++j)
    {
      if(m_matrix[i][j] == 7 | m_matrix[i][j] == 8)
      {
        //binds the texture to the fence
        glBindTexture(GL_TEXTURE_2D, m_FenceTextID);
        setFence(i,j,m_matrix);
        glBindTexture(GL_TEXTURE_2D, 0);
      }
    }
  }
  glPopMatrix();
  glEndList();
  //add all the fences to the matrix
  m_displayList.push_back(fid);


}

void Fence::setFence(const int _a, const int _b, const std::vector<std::vector<int> > &m_matrix)
{
  glPushMatrix();
  //moves the fences to their allocated location in the map matrix
    glTranslatef((_a)*4, -1, ((int)m_matrix[0].size() * 4) - (_b)*4);
    glScalef(0.042,0.045,0.045);
    //tests to see if the fences need to be rotated
    if (m_matrix[_a][_b] == 7)
    {
      glRotatef(-90.0,0.0,1.0,0.0);
    }
    createFenceNormal(m_matrix);
  glPopMatrix();
}

void Fence::createFenceNormal(const std::vector<std::vector<int> > &m_matrix)
{
  glPushMatrix();
    glBegin(GL_TRIANGLES);
    for(int i = 0; i < (int)m_matrix.size(); ++i)
    {
      for(int j = 0; j < (int)m_matrix[0].size(); ++j)
      {
        if(m_matrix[i][j] == 3)
        {
          for (int a = 2; a < (int)m_Index.size(); a += 3)
          {
            //set the normals for the obj
            m_Normal[m_Index[a]-1].normalGL();
            //set the texture coor for the obj
            m_Texture[m_Index[a-1]-1].textureGL();
            //set the vertex for the obj
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
  //draws the display matrix
  glCallLists(m_displayList.size(), GL_UNSIGNED_INT, &m_displayList[0]);
}
