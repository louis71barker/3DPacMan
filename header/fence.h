#ifndef FENCE_H__
#define FENCE_H__

#include <vector>
#include "scene.h"

class Fence
{
public:
  //Fence vectors
  std::vector<Vec3> m_Vertex;
  std::vector<Vec3> m_Normal;
  std::vector<Vec3> m_Texture;
  std::vector<int> m_Index;
  std::vector<GLuint> m_displayList;
  std::vector <GLuint> m_daList;

  Fence()
  {
    ObjLoader("obj/geoSphere.obj",m_Vertex,m_Normal,m_Texture,m_Index);
    drawFence();
  }

  ~Fence()
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
  void fence();
  void drawFence();



private:
    GLuint FenceTextID;

};




#endif
