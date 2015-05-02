#include "header/ghost.h"




void Ghost::buildGhost(const std::vector<std::vector<int> > &_matrix)
{

  //load the texture here and bind inside the list bellow!!!!!! :)

    GLuint gid = glGenLists(1);
    glNewList(gid, GL_COMPILE);
    glPushMatrix();
      for(int i = 0; i < (int)_matrix.size(); ++i)
      {
        for(int j = 0; j < (int)_matrix[0].size(); ++j)
        {
          if(_matrix[i][j] == 4)
          {
            setGhost(i, j, _matrix);
          }
        }
      }
    glPopMatrix();
    glEndList();
    m_displayList.push_back(gid);
}


void Ghost::setGhost(const int _a, const int _b, const std::vector<std::vector<int> > &_matrix)
{
  glPushMatrix();
    glTranslatef((_a)*4, 1, ((int)_matrix[0].size() * 4) - (_b)*4);
    glScalef(0.18,0.18,0.18);
    drawGhosts(_matrix);
    ghostX = (_a)*4;
    ghostZ = ((int)_matrix[0].size() * 4) - (_b)*4;
  glPopMatrix();
}

void Ghost::drawGhosts(const std::vector<std::vector<int> > _matrix)
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

void Ghost::ghoAi(const std::vector<std::vector<int> > &_matrix)
{
  for(int i = 0; i < (int)_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)_matrix[0].size(); ++j)
    {
//      if(matrix[i][j] != 0 || matrix[i][j] !=3 || matrix[i][j] !=13)
      if (North)
      {
        if(_matrix[i][j+1] == 0 || _matrix[i][j+1] == 2)
        {
                    float cubeCentreX = (i * 4);
                    float cubeCentreZ = (((int)_matrix[0].size() * 4) - (j * 4));
                    float cubeMinX, cubeMaxX, cubeMinZ, cubeMaxZ;
                    cubeMinX = cubeCentreX - 1.0;
                    cubeMaxX = cubeCentreX + 1.0;
                    cubeMinZ = cubeCentreZ - 1.0f;
                    cubeMaxZ = cubeCentreZ + 1.0f;
          if (ghostX > cubeMinX && ghostX < cubeMaxX && ghostZ > cubeMinZ && ghostZ < cubeMaxZ)
          {

          }
        }
      }
      else if (South)
        {
          if(_matrix[i][j-1] == 0 || _matrix[i][j-1] == 2)
          {
                      float cubeCentreX = (i * 4);
                      float cubeCentreZ = (((int)_matrix[0].size() * 4) - (j * 4));
                      float cubeMinX, cubeMaxX, cubeMinZ, cubeMaxZ;
                      cubeMinX = cubeCentreX - 1.0;
                      cubeMaxX = cubeCentreX + 1.0;
                      cubeMinZ = cubeCentreZ - 1.0f;
                      cubeMaxZ = cubeCentreZ + 1.0f;
            if (ghostX > cubeMinX && ghostX < cubeMaxX && ghostZ > cubeMinZ && ghostZ < cubeMaxZ)
            {

            }
          }
      }

      else if (East)
        {
          if(_matrix[i+1][j] == 0 || _matrix[i+1][j] == 2)
          {
                      float cubeCentreX = (i * 4);
                      float cubeCentreZ = (((int)_matrix[0].size() * 4) - (j * 4));
                      float cubeMinX, cubeMaxX, cubeMinZ, cubeMaxZ;
                      cubeMinX = cubeCentreX - 1.0;
                      cubeMaxX = cubeCentreX + 1.0;
                      cubeMinZ = cubeCentreZ - 1.0f;
                      cubeMaxZ = cubeCentreZ + 1.0f;
            if (ghostX > cubeMinX && ghostX < cubeMaxX && ghostZ > cubeMinZ && ghostZ < cubeMaxZ)
            {

            }
          }
      }
      else if (West)
        {
          if(_matrix[i-1][j] == 0 || _matrix[i-1][j] == 2)
          {
                      float cubeCentreX = (i * 4);
                      float cubeCentreZ = (((int)_matrix[0].size() * 4) - (j * 4));
                      float cubeMinX, cubeMaxX, cubeMinZ, cubeMaxZ;
                      cubeMinX = cubeCentreX - 1.0;
                      cubeMaxX = cubeCentreX + 1.0;
                      cubeMinZ = cubeCentreZ - 1.0f;
                      cubeMaxZ = cubeCentreZ + 1.0f;
            if (ghostX > cubeMinX && ghostX < cubeMaxX && ghostZ > cubeMinZ && ghostZ < cubeMaxZ)
            {

            }
          }
      }
    }
  }
}

void Ghost::updater()
{

  glPushMatrix();
//  glLoadIdentity();
    glTranslatef(ghostX,0,ghostZ);
//    glRotatef(180,0.0,1.0,0.0);
    glCallList(m_displayList[0]);
  glPopMatrix();
}





