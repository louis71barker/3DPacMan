#include "header/collectables.h"
#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>




void Collecable::drawCollectable(std::vector<std::vector<int> > &_matrix,float _x, float _y)
{
  drawCollectiblesLeft();
  normalSetter(_matrix);
  collisonDetection(_matrix, _x, _y);
  glPushMatrix();
    static int rotVal = 0;
    rotVal++;
//    glRotatef(rotVal,1,0,0);
    glCallLists(m_displayList.size(), GL_UNSIGNED_INT, &m_displayList[0]);
  glPopMatrix();
}



void Collecable::normalSetter(std::vector<std::vector<int> > _matrix)
{
  for(int i = 0; i < (int)_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)_matrix[0].size(); ++j)
    {
      if(_matrix[i][j] == 0)
      {
        placeObj(i, j, _matrix);

        if (countSet == false)
        {
          collecibleCount++;
//          std::cout<<collecibleCount<<"\n";
        }
      }
    }
    if(i == (int)_matrix.size()-1 )
    {
      countSet = true;
    }
  }
}


void Collecable::placeObj(int _x, int _y,std::vector<std::vector<int> > _matrix)
{
  glPushMatrix();
//    glTranslatef(-30 + (_x+0.5)*4, -1, 30 - (_y+0.5)*4);
      glTranslatef((_x)*4, -1, ((int)_matrix[0].size() * 4) - (_y)*4);

    drawBalls();
  glPopMatrix();
}

void Collecable::placeSpecials(std::vector<std::vector<int> > _matrix)
{
  //load the texture here and bind inside the list bellow!!!!!! :)

  for(int i = 0; i < (int)_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)_matrix[0].size(); ++j)
    {
      if(_matrix[i][j] == 5)
      {
        GLuint id = glGenLists(1);
        glNewList(id, GL_COMPILE);
        glPushMatrix();
//          glTranslatef(-30 + (i+0.5)*4, 0 , 30 - (j+0.5)*4);
          glTranslatef((i)*4, -0.5, ((int)_matrix[0].size() * 4) - (j)*4);
          glScalef(0.1,0.1,0.1);
          glTranslatef(0,-6,0);
          glBegin(GL_TRIANGLES);


          for (int a = 2; a < (int)m_Index.size(); a += 3)
          {
            m_Normal[m_Index[a]-1].normalGL();
            m_Texture[m_Index[a-1]-1].textureGL();
            m_Vertex[m_Index[a-2]-1].vertexGL();
          }


          glEnd();
        glPopMatrix();
        m_displayList.push_back(id);

       }
    }
  }
}

void Collecable::drawBalls()
{

          GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 };

          glPushMatrix();
          glColor3f(1.0, 0.0, 0.0);
            glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
            glEnable(GL_BLEND_COLOR);
            glutSolidSphere(0.4,20,20);
//          glColor3f(0.0f ,0.0f ,0.0f);
          glColor3f(1.0, 1.0, 1.0f);
          glPopMatrix();

}

void Collecable::collisonDetection(std::vector<std::vector<int> > &_matrix, float _x, float _y)
{
  for(int i = 0; i < (int)_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)_matrix[0].size(); ++j)
    {
      if(_matrix[i][j] == 0)
      {

        float collecableCentreX = (i * CUBESIZE);
        float collecableCentreZ = (((int)_matrix[0].size() * CUBESIZE) - (j * CUBESIZE));
        float collecableMinX, collecableMaxX, collecableMinZ, collecableMaxZ;
        collecableMinX = collecableCentreX - 1.0f;
        collecableMaxX = collecableCentreX + 1.0f;
        collecableMinZ = collecableCentreZ - 1.0f;
        collecableMaxZ = collecableCentreZ + 1.0f;

        if (_x > collecableMinX && _x < collecableMaxX && _y > collecableMinZ && _y < collecableMaxZ)
        {
          _matrix[i][j] = 2;
          collecibleCount--;
        }
      }

      //specials collision detection
      if(_matrix[i][j] == 5)
      {

        float collecableCentreX = (i * CUBESIZE);
        float collecableCentreZ = (((int)_matrix[0].size() * CUBESIZE) - (j * CUBESIZE));
        float collecableMinX, collecableMaxX, collecableMinZ, collecableMaxZ;
        collecableMinX = collecableCentreX - 1.0f;
        collecableMaxX = collecableCentreX + 1.0f;
        collecableMinZ = collecableCentreZ - 1.0f;
        collecableMaxZ = collecableCentreZ + 1.0f;

        if (_x > collecableMinX && _x < collecableMaxX && _y > collecableMinZ && _y < collecableMaxZ)
        {
          _matrix[i][j] = 2;
          std::cout<<"special collected yeyyeeyeyyey\n";

        }
      }
    }
  }
}

void Collecable::drawCollectiblesLeft()
{
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
        strm << "Collectibles Left = " << collecibleCount;
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
}

