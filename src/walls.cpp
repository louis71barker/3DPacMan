#include "walls.h"
#include <GL/glut.h>







#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif

Walls::Walls()
{
  FileLoad fl;
//  fileReader(_fname);
  gridCounter = 0;
  gridXPos = -15;
  gridZPos = 15;
  fl.fileLoader("src/MapCoor.txt",matrix,"MAP1");
  ObjLoader("obj/BushWallHighPoly.obj",m_Vertex,m_Normal,m_Texture,m_Index);
//  initMaze();
//  draw();
}

void Walls::draw()
{
  glCallLists(dList.size(), GL_UNSIGNED_INT, &dList[0]);
}

//void Walls::fileReader(const std::string &_fname)
//{
//  int lineCount = 0, sortCount = 0;


//  std::fstream fileIn;
//  fileIn.open(_fname.c_str(),std::ios::in);
//  if (!fileIn.is_open())
//  {
//    std::cerr<<"could not open file "<<_fname<<"\n";
//    exit(EXIT_FAILURE);
//  }

//  //boost parser separtor
//  boost::char_separator<char> sep(" \t\r\n");

//  std::string lineBuffer;
//  while(!fileIn.eof())
//  {
//    getline(fileIn,lineBuffer,'\n');
//    if (lineBuffer.size() !=0)
//    {
//      tokenizer tokens(lineBuffer,sep);
//      tokenizer::iterator firstWord=tokens.begin();
//      if (*firstWord == "#")
//      {
//        std::cerr<<"Found a comment \n";
//      }
//      else if (*firstWord=="MAP1")
//      {
//        parseVector(firstWord, lineCount, sortCount);
//        lineCount++;
//        sortCount++;
//      }
//    }
//  }
//}

//void Walls::parseVector(tokenizer::iterator &_firstWord, int lineCount, int sortCount)
//{
//  int max1 = 17;
//  double init_value = 1;

//  std::cout<<lineCount<<"ajghksjhdkjhalk\n";

//  //now we have an empty 2D-matrix of size (0,0). Resizing it with one single command:
//  matrix.resize( max1 , std::vector<int>( max1 , init_value ) );

//  ++_firstWord;

//  //adds the coor data from the text file into the 2d vector
//  for (int i=0; i<max1; i++)
//  {
//    matrix[lineCount][i] = boost::lexical_cast<int>(*_firstWord++);
////    std::cout<<matrix[lineCount][i];

//  }
//}

void Walls::initMaze(std::vector<std::vector<int> > _matrix)
{
  //loads in the wall texure
  textLoader("textures/Tree_Text.png", WallTextID);

  GLuint id = glGenLists(1);
  glNewList(id, GL_COMPILE);
  glPushMatrix();

  for(int i = 0; i < (int)matrix.size(); ++i)
  {
    for(int j = 0; j < (int)matrix[0].size(); ++j)
    {
      if(matrix[i][j] == 1)
      {

        glBindTexture(GL_TEXTURE_2D, WallTextID);
        letsDraw(i, j, _matrix);

        glBindTexture(GL_TEXTURE_2D, 0);
        //std::cout<<matrix[i][j]<<"  asdgakjd     "<<j<<"\n";
      }
    }
  }
  glPopMatrix();

  glEndList();
  dList.push_back(id);

}

void Walls::letsDraw(int _x, int _y,std::vector<std::vector<int> > _matrix)
{
    glPushMatrix();
//      glTranslatef(-30 + (_x+0.5)*4, 0, 30 - (_y+0.5)*4);
      glTranslatef((_x)*4, 0, ((int)matrix[0].size() * 4) - (_y)*4);

      drawCube(_matrix);
    glPopMatrix();
}

void Walls::propChanger(std::vector<std::vector<int> > matrix, int w, int h)
{
  matrix[w][h] = 2;
}

void Walls::drawCube(std::vector<std::vector<int> > _matrix)
{


//  glPushMatrix();
//  glutSolidCube(CUBESIZE);

//  glBegin(GL_LINE_STRIP);
//    glColor3f(0, 1, 0);
//    glVertex3f(0, 0, 0);
//    glVertex3f((CUBESIZE+0.1), 0, 0);
//  glEnd();
//  glPopMatrix();
  GLuint id = glGenLists(1);
  glNewList(id, GL_COMPILE);
  glPushMatrix();
    glScalef(0.2,0.2,0.2);
//      glTranslatef(0,2,0);
    glBegin(GL_TRIANGLES);
    for(int i = 0; i < (int)_matrix.size(); ++i)
    {
      for(int j = 0; j < (int)_matrix[0].size(); ++j)
      {
        if(_matrix[i][j] == 3)
        {
          std::cout<<"spawn bus please\n";
          glTranslatef((i)*4, 0, ((int)_matrix[0].size() * 4) - (j)*4);
          for (int a = 2; a < (int)m_Index.size(); a += 3)
          {
            m_Normal[m_Index[a]-1].normalGL();
            m_Texture[m_Index[a-1]-1].textureGL();
            m_Vertex[m_Index[a-2]-1].vertexGL();
          }
          std::cout<<"spawned Ghost thank you\n";
        }
//        if(_matrix[i][j] <= 10)
//        {
//          std::cout<<"draw ground here\n";
//          glTranslatef((i)*4, -4, ((int)_matrix[0].size() * 4) - (j)*4);
//          for (int a = 0; a < (int)m_Index.size(); a ++)
//          {
//            m_Texture[m_Index[a+1]-1].textureGL();
//            m_Normal[m_Index[a+2]-1].normalGL();
//            m_Vertex[m_Index[a]-1].vertexGL();
//          }

//        }
      }
    }


    glEnd();
  glPopMatrix();
  m_displayList.push_back(id);


}





