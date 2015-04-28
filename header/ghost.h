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
  void drawGhosts(const std::vector<std::vector<int> > _matrix);

  std::vector<Vec3> m_Vertex;
  std::vector<Vec3> m_Normal;
  std::vector<Vec3> m_Texture;
  std::vector<int> m_Index;
  std::vector<GLuint> m_displayList;

  Ghost(const std::vector<std::vector<int> > _matrix)
  {
    ObjLoader("obj/GhostObj.obj",m_Vertex,m_Normal,m_Texture,m_Index);
    drawGhosts(_matrix);
  }
  ~Ghost()
  {
    m_Vertex.clear();
    std::vector<Vec3>().swap (m_Vertex);
    m_Normal.clear();
    std::vector<Vec3>().swap (m_Normal);
    m_Texture.clear();
    std::vector<Vec3>().swap (m_Texture);
    m_displayList.clear();
    std::vector<GLuint>().swap (m_displayList);
    m_Index.clear();
    std::vector<int>().swap (m_Index);
  }


private:
  typedef boost::tokenizer<boost::char_separator<char> >tokenizer;
  void objFileParser(const std::string &);
  void vectorBuilder();





};





#endif
