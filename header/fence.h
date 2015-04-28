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

  Fence(const std::vector<std::vector<int> > _matrix)
  {
    heightSet = false;
    height = -2.3;
    ObjLoader("obj/FenceFrame.obj",m_Vertex,m_Normal,m_Texture,m_Index);
    buildFence(_matrix);
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
  void buildFence(const std::vector<std::vector<int> > _matrix);
  void drawFence();



private:
  GLuint FenceTextID;
  bool heightSet;
  int height;
  void setFence(const int _a, const int _b);
  void createFenceNormal();
  void createFenceRotated();
};




#endif
