#include "header/collectables.h"
#include <GL/glut.h>
#include <GL/glu.h>



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
  GLfloat mat_emission[] = {1.0, 1.0, 0.0, 1.0};
  GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 };

  GLfloat x = 0.0f;
  GLfloat y = -0.5f;
  GLfloat z = 0.0f;
  glPushMatrix();
  glPointSize(30);
  glColor3f(1.0, 0.0, 0.0);
  //smooths the points within the game that are used for the collectables
//  glEnable( GL_POINT_SMOOTH );
//  glBegin(GL_POINTS);
//    glVertex3f(x,y,z);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT7);
    glEnable(GL_BLEND_COLOR);
//    glEnable(GL_DEPTH_TEST)
    glutSolidSphere(0.4,50,50);


  glEnd();
  glPopMatrix();
}

//void Collecable::drawSpecials()
//{
//  std::cout<<"draw a special here/n";
//}
