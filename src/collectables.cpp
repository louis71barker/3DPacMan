#include "header/collectables.h"
#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>


void Collectable::drawCollectable(std::vector<std::vector<int> > &m_matrix, const float _playerx, const float _playery)
{
  drawCollectiblesLeft();
  normalSetter(m_matrix);
  collisonDetection(m_matrix, _playerx, _playery);
  glPushMatrix();
    //call the display list to draw the collectable
    glCallLists(m_displayList.size(), GL_UNSIGNED_INT, &m_displayList[0]);
  glPopMatrix();
}



void Collectable::normalSetter(std::vector<std::vector<int> > &m_matrix)
{
  for(int i = 0; i < (int)m_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)m_matrix[0].size(); ++j)
    {
      if(m_matrix[i][j] == 0)
      {
        placeObj(i, j, m_matrix);
        //if the collectable setter is false then the incrementor is counting up until all collectables are drawn
        if (m_countSet == false)
        {
          m_collecibleCount++;
        }
      }
    }
    if(i == (int)m_matrix.size()-1 )
    {
      m_countSet = true;
    }
  }
}


void Collectable::placeObj(const int _x, const int _y, const std::vector<std::vector<int> > &m_matrix)
{
  glPushMatrix();
    //move the collectable to the relivent locations
    glTranslatef((_x)*4, -1, ((int)m_matrix[0].size() * 4) - (_y)*4);
    drawBalls();
  glPopMatrix();
}

void Collectable::placeSpecials(std::vector<std::vector<int> > &m_matrix)
{
  //load the texture
  textLoader("textures/CherryText.jpg", m_CherryTextID);

  for(int i = 0; i < (int)m_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)m_matrix[0].size(); ++j)
    {
      if(m_matrix[i][j] == 5)
      {
        GLuint id = glGenLists(1);
        glNewList(id, GL_COMPILE);
        glPushMatrix();
          glTranslatef((i)*4, -0.5, ((int)m_matrix[0].size() * 4) - (j)*4);
          glScalef(0.1,0.1,0.1);
          glTranslatef(0,-6,0);
          glBindTexture(GL_TEXTURE_2D, m_CherryTextID);
          glBegin(GL_TRIANGLES);
          for (int a = 2; a < (int)m_Index.size(); a += 3)
          {
            //set the normals for the obj
            m_Normal[m_Index[a]-1].normalGL();
            //set the texture coor for the obj
            m_Texture[m_Index[a-1]-1].textureGL();
            //set the vertex for the obj
            m_Vertex[m_Index[a-2]-1].vertexGL();
          }
          glBindTexture(GL_TEXTURE_2D, 0);


          glEnd();
        glPopMatrix();
        glEndList();
        //add the collectable to the display list
        m_displayList.push_back(id);

       }
    }
  }
}

void Collectable::drawBalls()
{
  glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glutSolidSphere(0.4,20,20);
    glColor3f(1.0, 1.0, 1.0f);
  glPopMatrix();

}

void Collectable::collisonDetection(std::vector<std::vector<int> > &m_matrix, float _playerx, float _playery)
{
  for(int i = 0; i < (int)m_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)m_matrix[0].size(); ++j)
    {
      //collision detections for the normal collectables
      if(m_matrix[i][j] == 0)
      {
        float CollectableCentreX = (i * CUBESIZE);
        float CollectableCentreZ = (((int)m_matrix[0].size() * CUBESIZE) - (j * CUBESIZE));
        float CollectableMinX, CollectableMaxX, CollectableMinZ, CollectableMaxZ;
        CollectableMinX = CollectableCentreX - 1.0f;
        CollectableMaxX = CollectableCentreX + 1.0f;
        CollectableMinZ = CollectableCentreZ - 1.0f;
        CollectableMaxZ = CollectableCentreZ + 1.0f;
        //simple AABB collision box around collectables
        if (_playerx > CollectableMinX && _playerx < CollectableMaxX && _playery > CollectableMinZ && _playery < CollectableMaxZ)
        {
          //changes the value in the matrix so they arnt displayed any longer
          m_matrix[i][j] = 2;
          //takes one off the total colletables left so counter going down accordingly
          m_collecibleCount--;
        }
      }

      //specials collision detection
      if(m_matrix[i][j] == 5)
      {
        float CollectableCentreX = (i * CUBESIZE);
        float CollectableCentreZ = (((int)m_matrix[0].size() * CUBESIZE) - (j * CUBESIZE));
        float CollectableMinX, CollectableMaxX, CollectableMinZ, CollectableMaxZ;
        CollectableMinX = CollectableCentreX - 1.0f;
        CollectableMaxX = CollectableCentreX + 1.0f;
        CollectableMinZ = CollectableCentreZ - 1.0f;
        CollectableMaxZ = CollectableCentreZ + 1.0f;

        if (_playerx > CollectableMinX && _playerx < CollectableMaxX && _playery > CollectableMinZ && _playery < CollectableMaxZ)
        {
          m_matrix[i][j] = 2;
        }
      }
    }
  }
}

void Collectable::drawCollectiblesLeft()
{
  //draws text to the screen to display the remaining amount of collectables left to be collected
  glDisable(GL_LIGHTING);
  GLint matrix;
  glGetIntegerv(GL_MATRIX_MODE, &matrix);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0,1,0,1);
    glMatrixMode(GL_MODELVIEW);
      glPushMatrix();
      glLoadIdentity();
      glPushAttrib(GL_COLOR_BUFFER_BIT);
        glColor3f(0,1.0f,0);
        glRasterPos3f(0.05, 0.95, 0);
        std::stringstream strm;
        strm << "Collectibles Left = " << m_collecibleCount;
        std::string text = strm.str();
        for(std::string::iterator it = text.begin(); it != text.end(); ++it)
        {
          glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *it);
        }
        glPopAttrib();
     glPopMatrix();
   glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(matrix);
  glEnable(GL_LIGHTING);
}

