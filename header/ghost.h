#ifndef GHOST_H__
#define GHOST_H__


#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <boost/tokenizer.hpp>
#include <fstream>
#include "scene.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
//#include "header/NCCA/Vec4.h"


#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif

class Ghost
{





public:
  void updater();
  void drawGhosts();

  std::vector<Vec3> m_Vertex;
  std::vector<Vec3> m_Normal;
  std::vector<Vec3> m_Texture;
  std::vector<Vec3> m_Index;
  std::vector<int> m_VId;
  std::vector<GLuint> m_displayList;

  Ghost(){objFileParser("obj/GhostObj.obj"); drawGhosts(); }
  ~Ghost()
  {
    m_Vertex.clear();
    std::vector<Vec3>().swap (m_Vertex);
    m_Normal.clear();
    std::vector<Vec3>().swap (m_Normal);
    m_Texture.clear();
    std::vector<Vec3>().swap (m_Texture);
    m_VId.clear();
    std::vector<int>().swap (m_VId);
  }


private:
  typedef boost::tokenizer<boost::char_separator<char> >tokenizer;
  void objFileParser(const std::string &);
  void vectorBuilder();





};





#endif
