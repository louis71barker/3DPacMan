#ifndef BARN_H__
#define BARN_H__

#include <vector>
#include "scene.h"

class Barn
{
public:
  //skydome vectors
  std::vector<Vec3> m_Vertex;
  std::vector<Vec3> m_Normal;
  std::vector<Vec3> m_Texture;
  std::vector<int> m_Index;
  std::vector<GLuint> m_displayList;
  std::vector <GLuint> m_daList;

  Barn(const std::vector<std::vector<int> > &_matrix)
  {
    ObjLoader("obj/FarmhouseTri.obj",m_Vertex,m_Normal,m_Texture,m_Index);
    buildBarn(_matrix);

  }

  ~Barn()
  {
    //skydome vectors
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
    m_daList.clear();
    std::vector<GLuint>().swap (m_daList);
  }
  void buildBarn(const std::vector<std::vector<int> > &_matrix);
  void drawBarn();



private:
    GLuint BarnTextID;

};




#endif
