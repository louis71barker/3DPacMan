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
      int northVal = j+1;
      int southVal = j-1;
      int eastVal = i+1;
      int westVal = i-1;

      if (northVal > (int)_matrix.size())
        northVal = (int)_matrix.size();
      if (southVal < 0)
        southVal = 0;
      if (eastVal > (int)_matrix.size())
        eastVal = (int)_matrix.size();
      if (westVal < 0)
        westVal = 0;
//      if(matrix[i][j] != 0 || matrix[i][j] !=3 || matrix[i][j] !=13)
      if (North)
      {
        if(_matrix[i][northVal] == 0 || _matrix[i][northVal] == 2)
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
            if (East == true && (ghostX > cubeMinX && ghostX < cubeMaxX && ghostZ > cubeMinZ && ghostZ < cubeMaxZ))
            {
              East = false;
              West = true;

            }
            North = false;
            East = true;

          }
        }
      }
      else if (South)
        {
          if(_matrix[i][southVal] == 0 || _matrix[i][southVal] == 2)
          {
                      float cubeCentreX = (i * 4);
                      float cubeCentreZ = (((int)_matrix[0].size() * 4) - (j * 4));
                      float cubeMinX, cubeMaxX, cubeMinZ, cubeMaxZ;
                      cubeMinX = cubeCentreX - 1.0f;
                      cubeMaxX = cubeCentreX + 1.0f;
                      cubeMinZ = cubeCentreZ - 1.0f;
                      cubeMaxZ = cubeCentreZ + 1.0f;
            if (ghostX > cubeMinX && ghostX < cubeMaxX && ghostZ > cubeMinZ && ghostZ < cubeMaxZ)
            {
              if ((East == true ) && (ghostX > cubeMinX && ghostX < cubeMaxX && ghostZ > cubeMinZ && ghostZ < cubeMaxZ))
              {
                East = false;
                West = true;

              }
              South = false;
              East = true;


            }
          }
      }

      else if (East)
        {
          if(_matrix[eastVal][j] == 0 || _matrix[eastVal][j] == 2)
          {
                      float cubeCentreX = (i * 4);
                      float cubeCentreZ = (((int)_matrix[0].size() * 4) - (j * 4));
                      float cubeMinX, cubeMaxX, cubeMinZ, cubeMaxZ;
                      cubeMinX = cubeCentreX - 1.0f;
                      cubeMaxX = cubeCentreX + 1.0f;
                      cubeMinZ = cubeCentreZ - 1.0f;
                      cubeMaxZ = cubeCentreZ + 1.0f;
            if (ghostX > cubeMinX && ghostX < cubeMaxX && ghostZ > cubeMinZ && ghostZ < cubeMaxZ)
            {
              if ((North == true ) && (ghostX > cubeMinX && ghostX < cubeMaxX && ghostZ > cubeMinZ && ghostZ < cubeMaxZ))
              {
                North = false;
                South = true;

              }
              East = false;
              West = true;
            }
          }
      }
      else if (West)
        {
          if(_matrix[westVal][j] == 0 || _matrix[westVal][j] == 2)
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
              if ((North == true ) && (ghostX > cubeMinX && ghostX < cubeMaxX && ghostZ > cubeMinZ && ghostZ < cubeMaxZ))
              {
                North = false;
                South = true;
              }
              East = false;
              West = true;
            }
          }
      }
    }
  }
}


void Ghost::dirValSetter()
{
  if (North)
  {
    ghostZ+=0.005f;
    std::cout<<"North is true \n";
  }
  if (South)
  {
    ghostZ-=0.005f;
    std::cout<<"South is true \n";
  }
  if (East)
  {
    ghostX+=0.005f;
    std::cout<<"East is true \n";
  }
  if (West)
  {
    ghostX-+0.005f;
    std::cout<<"West is true \n";
  }
}

void Ghost::updater(const std::vector<std::vector<int> > &_matrix)
{
//  wghoAi(_matrix);
  glPushMatrix();
//  glLoadIdentity();
    glTranslatef(ghostX,0,ghostZ);
//    glRotatef(180,0.0,1.0,0.0);
    glCallList(m_displayList[0]);
  glPopMatrix();
}





