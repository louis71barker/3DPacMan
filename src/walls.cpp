#include "walls.h"
#include <GL/glut.h>







#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif

Walls::Walls(const std::string &_fname) :  CUBEDEPTH(2.0f), CUBEWIDTH(2.0f), CUBEHEIGHT(2.0f), GRIDCOUNTTOTAL(225.0f)
{
  fileReader(_fname);
  gridCounter = 0;
  gridXPos = -15;
  gridZPos = 15;
  mapCoorSetter();
  initMaze();
//  std::cout << dList.size() << "\n";
}

void Walls::draw()
{
  glCallLists(dList.size(), GL_UNSIGNED_INT, &dList[0]);
}


void Walls::mapBuilder(std::vector< std::vector<int> > matrix, int sortCount)
{
/*testing to see what has to be drawn
  0 = path and collectable
  1 = wall
  2 =
  3 = player start point
  4 = ghost spawner
  5 = special spawner
  6 = one way ghost door
  */

}

void Walls::fileReader(const std::string &_fname)
{
  int lineCount = 0, sortCount = 0;


  std::fstream fileIn;
  fileIn.open(_fname.c_str(),std::ios::in);
  if (!fileIn.is_open())
  {
    std::cerr<<"could not open file "<<_fname<<"\n";
    exit(EXIT_FAILURE);
  }

  //boost parser separtor
  boost::char_separator<char> sep(" \t\r\n");

  std::string lineBuffer;
  while(!fileIn.eof())
  {
    getline(fileIn,lineBuffer,'\n');
    if (lineBuffer.size() !=0)
    {
      tokenizer tokens(lineBuffer,sep);
      tokenizer::iterator firstWord=tokens.begin();
      if (*firstWord == "#")
      {
        std::cerr<<"Found a comment \n";
      }
      else if (*firstWord=="MAP1")
      {
        parseVector(firstWord, lineCount, sortCount);
        lineCount++;
        sortCount++;
      }
    }

  }
}

void Walls::parseVector(tokenizer::iterator &_firstWord, int lineCount, int sortCount)
{


  int num_of_col = 15;
  int num_of_row = 15;
  double init_value = 3.14;


  //now we have an empty 2D-matrix of size (0,0). Resizing it with one single command:
  matrix.resize( num_of_col , std::vector<int>( num_of_row , init_value ) );

  ++_firstWord;

  //adds the coor data from the text file into the 2d vector
  for (int i=0; i<15; i++)
  {
    matrix[lineCount][i] = boost::lexical_cast<int>(*_firstWord++);
//    std::cout<<matrix[lineCount][i];

  }

  mapBuilder(matrix, sortCount);





}

void Walls::mapCoorSetter()
{
  int PointCounter = 0;
  if (PointCounter <= GRIDCOUNTTOTAL)
  {
    for (int j=0;j<15;j++)
    {
      for (int a=0;a<15;a++)
      {

//        GridCoor[j][a].m_gridPoint = PointCounter;
//        GridCoor[j][a].m_Gx = gridXPos;
//        GridCoor[j][a].m_Gz = gridZPos;
//        gridXPos += CUBEWIDTH;
//        gridZPos += CUBEDEPTH;
//        PointCounter++;
//        if (a == 14)
        {
          gridXPos = -15;
          gridZPos = (13 - j)-j;
        }
        //std::cout<<GridCoor[j][a].m_gridPoint<<"     x "<<GridCoor[j][a].m_Gx<<"    y "<<GridCoor[j][a].m_Gz<<"\n";
      }
    }
  }
}

void Walls::initMaze()
{
  GLuint id = glGenLists(1);
  glNewList(id, GL_COMPILE);

  for(int i = 0; i < (int)matrix.size(); ++i)
  {
    for(int j = 0; j < (int)matrix[0].size(); ++j)
    {
      if(matrix[i][j] == 1)
      {
        //std::cout<<i<<"         "<<j<<"\n";
        letsDraw(i, j);
        //std::cout<<matrix[i][j]<<"  asdgakjd     "<<j<<"\n";
      }
      if(matrix[i][j] == 0)
      {
        //draw collectables here

      }
    }
  }
  glEndList();
  dList.push_back(id);
}

void Walls::letsDraw(int _x, int _y)
{
    glPushMatrix();
      glTranslatef(-30 + (_x+0.5)*4, 0, 30 - (_y+0.5)*4);

      drawCube();
    glPopMatrix();
}

void Walls::drawCube()
{
  GLfloat w=CUBEWIDTH;
  GLfloat h=CUBEHEIGHT;
  GLfloat d=CUBEDEPTH;
  GLfloat r = CUBEWIDTH;

  glColor3f(1,1,1);
  glutSolidCube(4);


//  glDrawArrays(GL_TRIANGLES,0,1);
//  glBegin(GL_TRIANGLES);
//    // front face



//  // Side 1
//        glNormal3f(0, 0, 1);
//        glVertex3f(r, r, r);
//        glVertex3f(-r, r, r);
//        glVertex3f(r, -r, r);

//        glVertex3f(-r, r, r);
//        glVertex3f(-r, -r, r);
//        glVertex3f(r, -r, r);



//        // Side 2
//        glNormal3f(0, 0, -1);
//        glVertex3f(r, r, -r);
//        glVertex3f(r, -r, -r);
//        glVertex3f(-r, r, -r);


//        glVertex3f(-r, r, -r);
//        glVertex3f(r, -r, -r);
//        glVertex3f(-r, -r, -r);

//        // Side 3

//        glNormal3f(-1, 0, 0);
//        glVertex3f(-r, r, -r);
//        glVertex3f(-r, -r, -r);
//        glVertex3f(-r, r, r);


//        glVertex3f(-r, r, r);
//        glVertex3f(-r, -r, -r);
//        glVertex3f(-r, -r, r);

//        // Side 4

//        glNormal3f(1, 0, 0);
//        glVertex3f(r, r, -r);
//        glVertex3f(r, r, r);
//        glVertex3f(r, -r, -r);

//        glVertex3f(r, r, r);
//        glVertex3f(r, -r, r);
//        glVertex3f(r, -r, -r);


//        // Side 5

//        glNormal3f(0, 1, 0);
//        glVertex3f(-r, r, -r);
//        glVertex3f(-r, r, r);
//        glVertex3f(r, r, -r);

//        glVertex3f(-r, r, r);
//        glVertex3f(r, r, -r);
//        glVertex3f(r, r, r);

//        // Side 6
//        glNormal3f(0, -1, 0);
//        glVertex3f(-r, -r, -r);
//        glVertex3f(-r, -r, r);
//        glVertex3f(r, -r, -r);

//        glVertex3f(-r, -r, r);
//        glVertex3f(r, -r, -r);
//        glVertex3f(r, -r, r);

//  glNormal3f(0,0,1);
//  glColor3f(0,0,0);
//  glVertex3f(-w,h,d);
//  glVertex3f(w,h,d);
//  glColor3f(1,1,1);
//  glVertex3f(w,-h,d);
//  glVertex3f(-w,-h,d);

//  glEnd();

//  glBegin(GL_POLYGON);
//    // back face

//  glNormal3d(0,0,-1);
//  glColor3f(0,0,0);
//  glVertex3f(-w,h,-d);
//  glVertex3f(w,h,-d);
//  glColor3f(1,1,1);
//  glVertex3f(w,-h,-d);
//  glVertex3f(-w,-h,-d);
//  glEnd();

//  glBegin(GL_POLYGON);
//    // Left face
//    glNormal3f(-1,0,0);
//    glColor3f(1,1,1);
//    glVertex3f(w,-h,d);
//    glVertex3f(w,-h,-d);
//    glColor3f(0,0,0);
//    glVertex3f(w,h,-d);
//    glVertex3f(w,h,d);
//  glEnd();

//  glBegin(GL_POLYGON);
//    // Right face


//    glNormal3f(1,0,0);

//    glColor3f(1,1,1);
//    glVertex3f(-w,-h,d);
//    glVertex3f(-w,-h,-d);

//    glColor3f(0,0,0);
//    glVertex3f(-w,h,-d);
//    glVertex3f(-w,h,d);
//  glEnd();

//  glBegin(GL_POLYGON);
//    // Top face
//    glNormal3f(0,1,0);
//    glVertex3f(-w,h,d);
//    glVertex3f(-w,h,-d);
//    glVertex3f(w,h,-d);
//    glVertex3f(w,h,d);
//  glEnd();

//  glBegin(GL_POLYGON);
//    // Bottom face
//    glNormal3f(0,-1,0);
//    glVertex3f(-w,-h,d);
//    glVertex3f(-w,-h,-d);
//    glVertex3f(w,-h,-d);
//    glVertex3f(w,-h,d);
//  glEnd();
  glBegin(GL_LINE_STRIP);
    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, (CUBEWIDTH+0.1), 0);
  glEnd();
}



