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
  ghoAi(_matrix);
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

double Ghost::random(void)
{
  static boost::mt19937 rng(43);
  boost::uniform_01<boost::mt19937&> num(rng);
//  return num;


}

void Ghost::ghoAi(const std::vector<std::vector<int> > &_matrix)
{
  dirValSetter();
  for(int i = 0; i < (int)_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)_matrix[0].size(); ++j)
    {
//      if(matrix[i][j] != 0 || matrix[i][j] !=3 || matrix[i][j] !=13)
      if (North)
      {
        if(_matrix[i][j] == 0 || _matrix[i][j] == 2 || _matrix[i][j] == 6 || _matrix[i][j] == 4)
        {
                    float cubeCentreX = (i * 4);
                    float cubeCentreZ = (((int)_matrix[0].size() * 4) - (j * 4));
                    float cubeMinX, cubeMaxX, cubeMinZ, cubeMaxZ;
                    cubeMinX = cubeCentreX - 0.5f;
                    cubeMaxX = cubeCentreX + 0.5f;
                    cubeMinZ = cubeCentreZ - 0.5f;
                    cubeMaxZ = cubeCentreZ + 0.5f;
          if (ghostX > cubeMinX && ghostX < cubeMaxX && ghostZ > cubeMinZ && ghostZ < cubeMaxZ)
          {
            if (_matrix[i-1][j] == 1)
            {
              if (_matrix[i][j+1] == 1)
              {
                West = true;
                North = false;
              }
              else
              {
                East = true;
                North = false;
              }
              North = false;
            }

          }
        }
      }
      else if (South)
        {
          if(_matrix[i][j] == 0 || _matrix[i][j] == 2 || _matrix[i][j] == 6 || _matrix[i][j] == 4)
          {
                      float cubeCentreX = (i * 4);
                      float cubeCentreZ = (((int)_matrix[0].size() * 4) - (j * 4));
                      float cubeMinX, cubeMaxX, cubeMinZ, cubeMaxZ;
                      cubeMinX = cubeCentreX - 0.5f;
                      cubeMaxX = cubeCentreX + 0.5f;
                      cubeMinZ = cubeCentreZ - 0.5f;
                      cubeMaxZ = cubeCentreZ + 0.5f;
            if (ghostX > cubeMinX && ghostX < cubeMaxX && ghostZ > cubeMinZ && ghostZ < cubeMaxZ)
            {
              if(_matrix[i+1][j] == 1)
              {
                if(_matrix[i][j-1] == 1)
                {
                  East = true;
                  South = false;
                }
                else
                {
                  West = true;
                  South = false;
                }
                South = false;
              }


            }
          }
      }

      else if (East)
        {
          if(_matrix[i][j] == 0 || _matrix[i][j] == 2 || _matrix[i][j] == 6 || _matrix[i][j] == 4)
          {
                      float cubeCentreX = (i * 4);
                      float cubeCentreZ = (((int)_matrix[0].size() * 4) - (j * 4));
                      float cubeMinX, cubeMaxX, cubeMinZ, cubeMaxZ;
                      cubeMinX = cubeCentreX - 0.5f;
                      cubeMaxX = cubeCentreX + 0.5f;
                      cubeMinZ = cubeCentreZ - 0.5f;
                      cubeMaxZ = cubeCentreZ + 0.5f;
            if (ghostX > cubeMinX && ghostX < cubeMaxX && ghostZ > cubeMinZ && ghostZ < cubeMaxZ)
            {
              if(_matrix[i][j-1] == 1)
              {
                if (_matrix[i+1][j] == 1)
                {
                  North = true;
                  East = false;
                }
                else
                {
                  South = true;
                  East = false;
                }
                East = false;
              }



            }
          }
      }
      else if (West)
        {
          if(_matrix[i][j] == 0 || _matrix[i][j] == 2 || _matrix[i][j] == 6 || _matrix[i][j] == 4)
          {
                      float cubeCentreX = (i * 4);
                      float cubeCentreZ = (((int)_matrix[0].size() * 4) - (j * 4));
                      float cubeMinX, cubeMaxX, cubeMinZ, cubeMaxZ;
                      cubeMinX = cubeCentreX - 0.5f;
                      cubeMaxX = cubeCentreX + 0.5f;
                      cubeMinZ = cubeCentreZ - 0.5f;
                      cubeMaxZ = cubeCentreZ + 0.5f;
            if (ghostX > cubeMinX && ghostX < cubeMaxX && ghostZ > cubeMinZ && ghostZ < cubeMaxZ)
            {
              if(_matrix[i][j-1] == 1)
              {
                if(_matrix[i-1][j] == 1)
                {
                  South = true;
                  West = false;
                }
                else
                {
                  North = true;
                  West = false;
                }
                West = false;
              }
            }
          }
      }
    }
  }
}


void Ghost::dirValSetter()
{
// ghostZ+=0.5;
  if (North)
  {
    ghostZ+=0.5f;
    std::cout<<"North is true \n";
  }
  if (South)
  {
    ghostZ-=0.5f;
    std::cout<<"South is true \n";
  }
  if (East)
  {
    ghostX-=0.5f;
    std::cout<<"East is true \n";
  }
  if (West)
  {
    ghostX+=0.5f;
    std::cout<<"West is true \n";
  }
}

void Ghost::updater(const std::vector<std::vector<int> > &_matrix)
{
  ghoAi(_matrix);
  static int i = 0;
  glPushMatrix();
  //glLoadIdentity();
    glTranslatef(ghostX,1,ghostZ);
    glRotatef(5,0.0,1.0,0.0);
    glTranslatef(-ghostX,-1,-ghostZ);

    glCallList(m_displayList[0]);
  glPopMatrix();
}





