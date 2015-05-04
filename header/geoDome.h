/// INCLUDE GUARD CHANGE TO NAME OF FILE BELOW
#ifndef GEODOME_H__
#define GEODOME_H__

///Here are all the includes that are needed
#include <vector>
#include "scene.h"

class geoDome
{
public:
  //skydome vectors
  std::vector<Vec3> m_Vertex;
  std::vector<Vec3> m_Normal;
  std::vector<Vec3> m_Texture;
  std::vector<int> m_Index;
  std::vector<GLuint> m_displayList;
  std::vector <GLuint> m_daList;

  geoDome()
  {
    ObjLoader("obj/geoSphere.obj",m_Vertex,m_Normal,m_Texture,m_Index);
    dome();
//    drawSky();
  }

  ~geoDome()
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
  void dome();
  void drawdome();



private:
    GLuint geodomeTextID;

};




#endif
