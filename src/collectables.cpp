#include "header/collectables.h"



void Collecable::drawCollectable(std::vector<std::vector<int> > matrix)
{
  normalSetter(matrix);
}



void Collecable::normalSetter(std::vector<std::vector<int> > matrix)
{
  for(int i = 0; i < (int)matrix.size(); ++i)
  {
    for(int j = 0; j < (int)matrix[0].size(); ++j)
    {
      if(matrix[i][j] == 0)
      {
        placeObj(i, j);
      }
      if(matrix[i][j] == 5)
      {
        specialSetter(i,j);

      }
    }
  }
}

void Collecable::specialSetter(int _x, int _y)
{
  glPushMatrix();
    glTranslatef(-30 + (_x+0.5)*4, 0 , 30 - (_y+0.5)*4);

    //drawSpecials();
  glPopMatrix();
}

void Collecable::placeObj(int _x, int _y)
{
  glPushMatrix();
    glTranslatef(-30 + (_x+0.5)*4, 0, 30 - (_y+0.5)*4);

    drawBalls();
  glPopMatrix();
}

void Collecable::drawBalls()
{

  GLfloat x = 1.0f;
  GLfloat y = 1.0f;
  GLfloat z = 1.0f;
  glPushMatrix();
  glPointSize(10);
  glBegin(GL_POINTS);
    glVertex3f(x,y,z);
  glEnd();
  glPopMatrix();
}

//void Collecable::drawSpecials()
//{
//  std::cout<<"draw a special here/n";
//}
