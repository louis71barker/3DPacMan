#include "header/ghost.h"


void Ghost::updater()
{
  glCallLists(m_displayList.size(), GL_UNSIGNED_INT, &m_displayList[0]);
}


void Ghost::objFileParser(const std::string &_objName)
{
  std::fstream fileIn;
  fileIn.open(_objName.c_str(),std::ios::in);
  if (!fileIn.is_open())
  {
    std::cerr<<"could not open file "<<_objName<<"\n";
    exit(EXIT_FAILURE);
  }

  //boost parser separtor
  boost::char_separator<char> sep(" /\t\r\n");

  std::string lineBuffer;
  while(!fileIn.eof())
  {
    getline(fileIn,lineBuffer,'\n');
    if (lineBuffer.size() !=0)
    {
      tokenizer tokens(lineBuffer,sep);
      tokenizer::iterator firstWord = tokens.begin();
      if (*firstWord=="v")
      {
//        std::cout<<"aslkdjlkasjd"<<"\n";
        Vec3 vert(boost::lexical_cast<float>(*++firstWord),
                  boost::lexical_cast<float>(*++firstWord),
                  boost::lexical_cast<float>(*++firstWord));

        m_Vertex.push_back(vert);
      }
      else if (*firstWord == "vt")
      {
//        std::cout<<"aslkdjlkasjdalkhsdkashdkh"<<"\n";
        Vec3 text(boost::lexical_cast<float>(*++firstWord),
                  boost::lexical_cast<float>(*++firstWord));

        m_Texture.push_back(text);
      }
      else if (*firstWord == "vn")
      {
        Vec3 norm(boost::lexical_cast<float>(*++firstWord),
                  boost::lexical_cast<float>(*++firstWord),
                  boost::lexical_cast<float>(*++firstWord));

        m_Normal.push_back(norm);
      }
      else if (*firstWord == "f")
      {
          Vec3 comp(boost::lexical_cast<float>(*++firstWord),
                    boost::lexical_cast<float>(*++firstWord),
                    boost::lexical_cast<float>(*++firstWord));
          m_Index.push_back(comp);
      }
    }


  }
  fileIn.close();
}

void Ghost::drawGhosts()
{

  //load the texture here and bind inside the list bellow!!!!!! :)

    vectorBuilder();
    GLuint id = glGenLists(1);
    glNewList(id, GL_COMPILE);
    glPushMatrix();
      glPointSize(120);
      glBegin(GL_TRIANGLES);
        for (int i = 0; i < (int)m_Index.size(); i += 3)
        {
          m_Index[i + 2].normalGL();
          m_Index[i].vertexGL();
        }


      glEnd();
    glPopMatrix();
    m_displayList.push_back(id);
}

void Ghost::vectorBuilder()
{
  for (int i=0; i < (int)m_Normal.size(); i += 3)
  {
    m_VId.push_back(i);
  }
}




