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
#include <GL/gl.h>
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
  std::vector<Vec3> Vertex;
  std::vector<Vec3> Normal;
  std::vector<Vec3> Texture;


private:
  typedef boost::tokenizer<boost::char_separator<char> >tokenizer;
  void objFileParser(const std::string &);





};





#endif
