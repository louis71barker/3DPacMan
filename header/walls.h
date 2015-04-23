#ifndef WALLS_H__
#define WALLS_H__

#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <boost/tokenizer.hpp>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <GL/gl.h>
#include "scene.h"



class Walls
{
public:
  Walls();

  void cubeInit(const std::string &_fname);
  void fileReader(const std::string &);
  void draw();
  void initMaze(std::vector<std::vector<int> > _matrix);
  void propChanger(std::vector<std::vector<int> > matrix, int w, int h);
  std::vector< std::vector<int> > matrix;








private:
  typedef boost::tokenizer<boost::char_separator<char> >tokenizer;
  void parseVector(tokenizer::iterator &, int lineCount, int sortCount);
  void cubeSetter() const;
  void mapBuilder(std::vector<std::vector<int> > matrix, int sortCount);

  std::vector<Vec3> m_Vertex;
  std::vector<Vec3> m_Normal;
  std::vector<Vec3> m_Texture;
  std::vector<int> m_Index;
  std::vector<GLuint> m_displayList;

  void letsDraw(int _x, int _y, std::vector<std::vector<int> > _matrix);
  void drawCube(std::vector<std::vector<int> > _matrix);
  void triangleCubCoor(GLfloat cube_buffer);

  int gridCounter;
  float gridXPos, gridZPos;
//  std::vector< std::vector<int> > matrix;
  std::vector <GLuint> dList;
  GLuint WallTextID;

  // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices





  //Map Coor

/*
  1,0,0,5,0,0,0,0,0,0,0,0,0,0,0
  1,0,1,1,1,0,1,1,0,1,1,1,1,1,0
  1,0,0,1,0,0,0,1,0,1,0,0,5,1,0
  1,1,0,0,0,1,0,0,0,0,0,1,0,1,0
  0,0,0,1,1,1,0,1,1,1,0,1,0,0,0
  0,1,0,5,1,0,0,0,0,0,0,1,0,1,0
  0,1,1,0,1,0,1,6,1,1,0,1,0,1,0
  0,0,0,0,0,0,1,0,0,1,0,0,0,1,0
  1,0,1,0,1,0,1,4,0,1,0,1,0,0,0
  1,0,1,0,1,0,1,1,1,1,0,1,1,1,0
  0,0,5,0,0,0,0,0,0,0,0,1,5,0,0
  0,1,1,1,1,1,0,1,1,0,1,1,0,1,0
  0,1,0,0,0,0,0,5,1,0,0,0,0,1,0
  0,1,0,1,1,0,1,0,1,0,1,1,0,1,0
  3,0,0,0,0,0,1,0,0,0,0,0,0,0,0


  0 = path and collectable
  1 = wall
  2 = collectable collected
  3 = player start
  4 = ghost spawn
  5 = specials
  6 = 1 direction wall for ghosts
  */


};



#endif
