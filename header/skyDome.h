#ifndef SKYDOME_H__
#define SKYDOME_H__

#include <vector>
#include "scene.h"

class skyDome
{
public:
  //skydome vectors
  std::vector<Vec3> m_SkyVertex;
  std::vector<Vec3> m_SkyNormal;
  std::vector<Vec3> m_SkyTexture;
  std::vector<int> m_SkyIndex;
  std::vector<GLuint> m_SkydisplayList;
  std::vector <GLuint> m_SkydaList;

  skyDome()
  {
    ObjLoader("obj/geoSphere.obj",m_SkyVertex,m_SkyNormal,m_SkyTexture,m_SkyIndex);
  }

  ~skyDome()
  {
    //skydome vectors
    m_SkyVertex.clear();
    std::vector<Vec3>().swap (m_SkyVertex);
    m_SkyNormal.clear();
    std::vector<Vec3>().swap (m_SkyNormal);
    m_SkyTexture.clear();
    std::vector<Vec3>().swap (m_SkyTexture);
    m_SkydisplayList.clear();
    std::vector<GLuint>().swap (m_SkydisplayList);
    m_SkyIndex.clear();
    std::vector<int>().swap (m_SkyIndex);
    m_SkydaList.clear();
    std::vector<GLuint>().swap (m_SkydaList);
  }
  void sky();
  void drawSky();



private:
    GLuint SkydomeTextID;

};




#endif
