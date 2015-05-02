#ifndef GHOST_H__
#define GHOST_H__


#include <boost/random.hpp>
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
    double random(void);
  float zeroone;

  std::vector<Vec3> m_Vertex;
  std::vector<Vec3> m_Normal;
  std::vector<Vec3> m_Texture;
  std::vector<int> m_Index;
  std::vector<GLuint> m_displayList;
  std::vector<Vec2> m_GhostPos;

  Ghost(const std::vector<std::vector<int> > _matrix)
  {
    ObjLoader("obj/GhostObj.obj",m_Vertex,m_Normal,m_Texture,m_Index);
    buildGhost(_matrix);
    ghostX = 0;
    ghostZ = 0;
    zeroone = 0;
    North = false;
    South = false;
    East = false;
    West = false;
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
    m_GhostPos.clear();
    std::vector<Vec2>().swap (m_GhostPos);
  }


private:
  void ghoAi(const std::vector<std::vector<int> > &_matrix);
  void buildGhost(const std::vector<std::vector<int> > &_matrix);
  void setGhost(const int _a, const int _b,const std::vector<std::vector<int> > &_matrix);
  void dirValSetter();

  int ghostX, ghostZ;
  bool North, South, East, West;





};





#endif
