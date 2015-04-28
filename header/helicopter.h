#ifndef HELI_H__
#define HELI_H__

#include <vector>
#include "scene.h"

class Heli
{
public:
  //Helicopter vectors
  std::vector<Vec3> m_Vertex;
  std::vector<Vec3> m_Normal;
  std::vector<Vec3> m_Texture;
  std::vector<int> m_Index;
  std::vector<GLuint> m_displayList;
  std::vector <GLuint> m_daList;

  Heli(const std::vector<std::vector<int> > _matrix)
  {
    ObjLoader("obj/Helicopter_crashed.obj",m_Vertex,m_Normal,m_Texture,m_Index);
    buildHeli(_matrix);

  }

  ~Heli()
  {
    //destroy Helicopter vectors
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
  void buildHeli(const std::vector<std::vector<int> > _matrix);
  void drawHeli();



private:
    GLuint HeliTextID;

};




#endif
