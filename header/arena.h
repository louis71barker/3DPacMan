#ifndef ARENA_H__
#define ARENA_H__

#include <vector>
#include "walls.h"





class Arena
{
public:
  std::vector<Vec3> m_Vertex;
  std::vector<Vec3> m_Normal;
  std::vector<Vec3> m_Texture;
  std::vector<int> m_Index;
  std::vector<GLuint> m_displayList;

  Arena(std::vector<std::vector<int> > _matrix)
  {
    ObjLoader("obj/cubeTri.obj",m_Vertex,m_Normal,m_Texture,m_Index);
    ground(_matrix);
  }
  ~Arena()
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



  void drawArena(std::vector<std::vector<int> > _matrix);


private:
  void ground(std::vector<std::vector<int> > _matrix);
  void sky();
  GLuint GroundTextID;



};






#endif
