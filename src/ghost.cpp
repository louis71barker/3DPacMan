#include "header/ghost.h"




void Ghost::buildGhost(const std::vector<std::vector<int> > &m_matrix)
{

  //load the texture here and bind inside the list bellow!!!!!! :)
    textLoader("textures/GhostText.jpg", m_GhostTextID);
    GLuint gid = glGenLists(1);
    glNewList(gid, GL_COMPILE);
    glPushMatrix();
      for(int i = 0; i < (int)m_matrix.size(); ++i)
      {
        for(int j = 0; j < (int)m_matrix[0].size(); ++j)
        {
          //test to see where the ghost spawn locations are
          if(m_matrix[i][j] == 4)
          {
            glBindTexture(GL_TEXTURE_2D, m_GhostTextID);
            setGhost(i, j, m_matrix);
            glBindTexture(GL_TEXTURE_2D, 0);
          }
        }
      }
    glPopMatrix();
    glEndList();
    m_displayList.push_back(gid);
}


void Ghost::setGhost(const int _a, const int _b, const std::vector<std::vector<int> > &m_matrix)
{
//  ghoAi(m_matrix);
  glPushMatrix();
    //moves and scales to needed size
    glTranslatef((_a)*4, 1, ((int)m_matrix[0].size() * 4) - (_b)*4);
    glScalef(0.18,0.18,0.18);
    drawGhosts(m_matrix);
    //sets start pos for the first ghost
    m_ghostX = (_a)*4;
    m_ghostZ = ((int)m_matrix[0].size() * 4) - (_b)*4;
  glPopMatrix();
}

void Ghost::drawGhosts(const std::vector<std::vector<int> > &m_matrix)
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


void Ghost::ghoAi(const std::vector<std::vector<int> > &m_matrix)
{

  for(int i = 0; i < (int)m_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)m_matrix[0].size(); ++j)
    {
      //check to see which direction the ghost is going
      if (m_North)
      {
        //check to make sure ghost is inside moveable areas
        if(m_matrix[i][j] == 0 || m_matrix[i][j] == 2 || m_matrix[i][j] == 6 || m_matrix[i][j] == 4)
        {
          //find the centre of the cube currently in
          float cubeCentreX = (i * 4);
          float cubeCentreZ = (((int)m_matrix[0].size() * 4) - (j * 4));
          float cubeMinX, cubeMaxX, cubeMinZ, cubeMaxZ;
          cubeMinX = cubeCentreX - 0.5f;
          cubeMaxX = cubeCentreX + 0.5f;
          cubeMinZ = cubeCentreZ - 0.5f;
          cubeMaxZ = cubeCentreZ + 0.5f;
          //simple AABB collsion box
          if (m_ghostX > cubeMinX && m_ghostX < cubeMaxX && m_ghostZ > cubeMinZ && m_ghostZ < cubeMaxZ)
          {
            //checks to see if the chunk ahead is free
            if (m_matrix[i-1][j] == 1)
            {
             //checks to see if chunk on the right is free or not
              if (m_matrix[i][j+1] == 1)
              {
                m_West = true;
                m_North = false;
              }
              //right has to be free so makes sets ghost to go right
              else
              {
                m_East = true;
                m_North = false;
              }
              //makes it so the ghost can not continue if collision
              m_North = false;
            }

          }
        }
      }
      else if (m_South)
        {
          //check to see which direction the ghost is going
          if(m_matrix[i][j] == 0 || m_matrix[i][j] == 2 || m_matrix[i][j] == 6 || m_matrix[i][j] == 4)
          {
            //find the centre of the cube currently in
            float cubeCentreX = (i * 4);
            float cubeCentreZ = (((int)m_matrix[0].size() * 4) - (j * 4));
            float cubeMinX, cubeMaxX, cubeMinZ, cubeMaxZ;
            cubeMinX = cubeCentreX - 0.5f;
            cubeMaxX = cubeCentreX + 0.5f;
            cubeMinZ = cubeCentreZ - 0.5f;
            cubeMaxZ = cubeCentreZ + 0.5f;
            //simple AABB collsion box
            if (m_ghostX > cubeMinX && m_ghostX < cubeMaxX && m_ghostZ > cubeMinZ && m_ghostZ < cubeMaxZ)
            {
              //checks to see if the chunk ahead is free
              if(m_matrix[i+1][j] == 1)
              {
                //checks to see if chunk on the right is free or not
                if(m_matrix[i][j-1] == 1)
                {
                  m_East = true;
                  m_South = false;
                }
                else
                //right has to be free so makes sets ghost to go right
                {
                  m_West = true;
                  m_South = false;
                }
                //makes it so the ghost can not continue if collision
                m_South = false;
              }


            }
          }
      }

      else if (m_East)
        {
          //check to see which direction the ghost is going
          if(m_matrix[i][j] == 0 || m_matrix[i][j] == 2 || m_matrix[i][j] == 6 || m_matrix[i][j] == 4)
          {
            //find the centre of the cube currently in
            float cubeCentreX = (i * 4);
            float cubeCentreZ = (((int)m_matrix[0].size() * 4) - (j * 4));
            float cubeMinX, cubeMaxX, cubeMinZ, cubeMaxZ;
            cubeMinX = cubeCentreX - 0.5f;
            cubeMaxX = cubeCentreX + 0.5f;
            cubeMinZ = cubeCentreZ - 0.5f;
            cubeMaxZ = cubeCentreZ + 0.5f;
            //simple AABB collsion box
            if (m_ghostX > cubeMinX && m_ghostX < cubeMaxX && m_ghostZ > cubeMinZ && m_ghostZ < cubeMaxZ)
            {
              //checks to see if the chunk ahead is free
              if(m_matrix[i][j-1] == 1)
              {
                //checks to see if chunk on the right is free or not
                if (m_matrix[i+1][j] == 1)
                {
                  m_North = true;
                  m_East = false;
                }
                else
                  //right has to be free so makes sets ghost to go right
                {
                  m_South = true;
                  m_East = false;
                }
                //makes it so the ghost can not continue if collision
                m_East = false;
              }



            }
          }
      }
      else if (m_West)
        {
          //check to see which direction the ghost is going
          if(m_matrix[i][j] == 0 || m_matrix[i][j] == 2 || m_matrix[i][j] == 6 || m_matrix[i][j] == 4)
          {
            //find the centre of the cube currently in
            float cubeCentreX = (i * 4);
            float cubeCentreZ = (((int)m_matrix[0].size() * 4) - (j * 4));
            float cubeMinX, cubeMaxX, cubeMinZ, cubeMaxZ;
            cubeMinX = cubeCentreX - 0.5f;
            cubeMaxX = cubeCentreX + 0.5f;
            cubeMinZ = cubeCentreZ - 0.5f;
            cubeMaxZ = cubeCentreZ + 0.5f;
            //simple AABB collsion box
            if (m_ghostX > cubeMinX && m_ghostX < cubeMaxX && m_ghostZ > cubeMinZ && m_ghostZ < cubeMaxZ)
            {
              //checks to see if the chunk ahead is free
              if(m_matrix[i][j-1] == 1)
              {
                //checks to see if chunk on the right is free or not
                if(m_matrix[i-1][j] == 1)
                {
                  m_South = true;
                  m_West = false;
                }
                else
                //right has to be free so makes sets ghost to go right
                {
                  m_North = true;
                  m_West = false;
                }
                //makes it so the ghost can not continue if collision
                m_West = false;
              }
            }
          }
      }
    }
  }
  // set the direction
  dirValSetter();
}


void Ghost::dirValSetter()
{
  //if the ghost is going up the map
  if (m_North)
  {
    m_ghostZ+=0.5f;
  }
  //if the ghost is going down the map
  if (m_South)
  {
    m_ghostZ-=0.5f;
  }
  //if the ghost is going left
  if (m_East)
  {
    m_ghostX-=0.5f;
  }
  //if the ghost is going right
  if (m_West)
  {
    m_ghostX+=0.5f;
  }
}

void Ghost::updater(const std::vector<std::vector<int> > &m_matrix)
{
  //calls the ghost AI
  ghoAi(m_matrix);
  glPushMatrix();
    glTranslatef(m_ghostX,1,m_ghostZ);
    glRotatef(5,0.0,1.0,0.0);
    glTranslatef(-m_ghostX,-1,-m_ghostZ);
    glCallList(m_displayList[0]);
  glPopMatrix();
}





