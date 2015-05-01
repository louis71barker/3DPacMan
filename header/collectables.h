#ifndef COLLECTABLE_H__
#define COLLECTABLE_H__
#include <vector>
#include <GL/gl.h>
#include <stdlib.h>
#include <iostream>
#include "walls.h"
#include "scene.h"



class Collecable
{
public:
  Collecable(std::vector<std::vector<int> > _matrix)
  {

    collecibleCount = 0;
    countSet = false;

    ObjLoader("obj/CherryObj.obj",m_Vertex,m_Normal,m_Texture,m_Index);
    placeSpecials(_matrix);

  }
  ~Collecable()
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

  void drawCollectable(std::vector<std::vector<int> > &_matrix, float _x, float _y);
  int collecibleCount;




private:
  void placeSpecials(std::vector<std::vector<int> > _matrix);
  void normalSetter( std::vector<std::vector<int> > matrix);
  void specialSetter(int _x, int _y);
  void placeObj(int _x, int _y, std::vector<std::vector<int> > _matrix);
  void drawBalls();
  void drawSpecials();
  void collisonDetection(std::vector<std::vector<int> > &_matrix, float _x, float _y);
  void countSetter(std::vector<std::vector<int> > _matrix);
  void drawCollectiblesLeft();
  bool countSet;

  std::vector<Vec3> m_Vertex;
  std::vector<Vec3> m_Normal;
  std::vector<Vec3> m_Texture;
  std::vector<int> m_Index;
  std::vector<GLuint> m_displayList;



};





#endif
