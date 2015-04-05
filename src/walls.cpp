#include "walls.h"
#include <GL/glut.h>







#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif

Walls::Walls(const std::string &_fname)
{

  fileReader(_fname);
  gridCounter = 0;
  gridXPos = -15;
  gridZPos = 15;
//  initMaze();
//  draw();
}

void Walls::draw()
{
  glCallLists(dList.size(), GL_UNSIGNED_INT, &dList[0]);
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
  int max1 = 17;
  double init_value = 1;

  std::cout<<lineCount<<"ajghksjhdkjhalk\n";

  //now we have an empty 2D-matrix of size (0,0). Resizing it with one single command:
  matrix.resize( max1 , std::vector<int>( max1 , init_value ) );

  ++_firstWord;

  //adds the coor data from the text file into the 2d vector
  for (int i=0; i<max1; i++)
  {
    matrix[lineCount][i] = boost::lexical_cast<int>(*_firstWord++);
//    std::cout<<matrix[lineCount][i];

  }
}

void Walls::initMaze()
{
  //loads in the wall texure
  textLoader("textures/Hedge.jpg", WallTextID);

  GLuint id = glGenLists(1);
  glNewList(id, GL_COMPILE);
  glPushMatrix();

  for(int i = 0; i < (int)matrix.size(); ++i)
  {
    for(int j = 0; j < (int)matrix[0].size(); ++j)
    {
      if(matrix[i][j] == 1)
      {
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
        glBindTexture(GL_TEXTURE_2D, WallTextID);
        letsDraw(i, j);
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
        glBindTexture(GL_TEXTURE_2D, 0);
        //std::cout<<matrix[i][j]<<"  asdgakjd     "<<j<<"\n";
      }
    }
  }
  glPopMatrix();

  glEndList();
  dList.push_back(id);

}

void Walls::letsDraw(int _x, int _y)
{
    glPushMatrix();
//      glTranslatef(-30 + (_x+0.5)*4, 0, 30 - (_y+0.5)*4);
      glTranslatef((_x)*4, 0, ((int)matrix[0].size() * 4) - (_y)*4);

      drawCube();
    glPopMatrix();
}

void Walls::propChanger(std::vector<std::vector<int> > matrix, int w, int h)
{
  matrix[w][h] = 2;
}

void Walls::drawCube()
{


  glPushMatrix();
  glutSolidCube(CUBESIZE);

  glBegin(GL_LINE_STRIP);
    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f((CUBESIZE+0.1), 0, 0);
  glEnd();
  glPopMatrix();
}





