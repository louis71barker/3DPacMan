#include "header/collectables.h"
#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>



void Collecable::drawCollectable(std::vector<std::vector<int> > &_matrix,float _x, float _y, float yRot)
{
  drawCollectiblesLeft(_x,_y,yRot);
  normalSetter(_matrix);
  collisonDetection(_matrix, _x, _y);

}



void Collecable::normalSetter(std::vector<std::vector<int> > matrix)
{
  static float f;
  for(int i = 0; i < (int)matrix.size(); ++i)
  {
    for(int j = 0; j < (int)matrix[0].size(); ++j)
    {
      if(matrix[i][j] == 0)
      {
        placeObj(i, j);
        f = i-0.5;
        if (countSet == false)
        {
          collecibleCount++;
          std::cout<<collecibleCount<<"\n";
        }


      }
      if(matrix[i][j] == 5)
      {
        specialSetter(i,j);

      }
    }
    if(i == (int)matrix.size()-1 )
    {
      countSet = true;
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
    glTranslatef(-30 + (_x+0.5)*4, -1, 30 - (_y+0.5)*4);

    drawBalls();
  glPopMatrix();
}

void Collecable::drawBalls()
{
//  GLfloat mat_emission[] = {1.0, 1.0, 0.0, 1.0};
  GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 };

  glPushMatrix();
  glColor3f(1.0, 0.0, 0.0);
  //smooths the points within the ga  glRasterPos3f(0,0,0);me that are used for the collectables
//  glEnable( GL_POINT_SMOOTH );
//  glBegin(GL_POINTS);
//    glVertex3f(x,y,z);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT7);
    glEnable(GL_BLEND_COLOR);
//    glEnable(GL_DEPTH_TEST)
    glutSolidSphere(0.4,50,50);



  glEnd();
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
        float collecableCentreX = (-30 + (i+0.5)*4);
        float collecableCentreZ = (30 - (j+0.5)*4);
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
    }
  }
}

void Collecable::drawCollectiblesLeft(float _x, float _y, float _yRot)
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

//  glDisable(GL_TEXTURE_2D);
//  glLoadIdentity();
      glPushAttrib(GL_COLOR_BUFFER_BIT);
        glColor3f(0,1.0f,0);
        glRasterPos3f(0.05, 0.95, 0);
//        glRotatef(_yRot,0,1.0f,0);
        std::stringstream strm;
        strm << "Collectibles Left = " << collecibleCount;
        std::string text = strm.str();
        for(std::string::iterator it = text.begin(); it != text.end(); ++it)
        {
          glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *it);
      //    std::cout<<"draw score god dam it \n";
        }
      //  glEnable(GL_TEXTURE_2D);
        glPopAttrib();
     glPopMatrix();

   glMatrixMode(GL_PROJECTION);

  glPopMatrix();
  glMatrixMode(matrix);
}


