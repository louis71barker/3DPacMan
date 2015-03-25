#include "header/ghost.h"


void Ghost::objFileParser(const std::string &_objName)
{
  int lineCount = 0, sortCount = 0;


  std::fstream fileIn;
  fileIn.open(_objName.c_str(),std::ios::in);
  if (!fileIn.is_open())
  {
    std::cerr<<"could not open file "<<_objName<<"\n";
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
      else if (*firstWord=="v")
      {
        Vec3 vert(boost::lexical_cast<float>(*firstWord++),
                  boost::lexical_cast<float>(*firstWord++),
                  boost::lexical_cast<float>(*firstWord++));
        Vertex.push_back(vert);
      }
      else if (*firstWord == "vt")
      {
        Vec3 text(boost::lexical_cast<float>(*firstWord++),
                  boost::lexical_cast<float>(*firstWord++),
                  boost::lexical_cast<float>(*firstWord++));
        Texture.push_back(text);
      }
      else if (*firstWord == "vn")
      {
        Vec3 norm(boost::lexical_cast<float>(*firstWord++),
                  boost::lexical_cast<float>(*firstWord++),
                  boost::lexical_cast<float>(*firstWord++));
        Normal.push_back(norm);
      }
    }

  }
}

void Ghost::drawGhosts()
{

  for (int i = 0; i >= Vertex.size(); i += 3)
  {
    glPushMatrix();
      glBegin(GL_TRIANGLES);


      glEnd();
    glPopMatrix();
  }
}




