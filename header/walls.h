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



class Walls
{
public:
  Walls(const std::string &_fname);
  void cubeInit(const std::string &_fname);
  void fileReader(const std::string &);
  void draw();
  void initMaze();
  void propChanger(std::vector<std::vector<int> > matrix, int w, int h);
  std::vector< std::vector<int> > matrix;


  const float CUBEDEPTH;
  const float CUBEWIDTH;
  const float CUBEHEIGHT;






private:
  typedef boost::tokenizer<boost::char_separator<char> >tokenizer;
  void parseVector(tokenizer::iterator &, int lineCount, int sortCount);
  void cubeSetter() const;
  void mapCoorSetter();
  void mapBuilder(std::vector<std::vector<int> > matrix, int sortCount);

  void letsDraw(int _x, int _y);
  void drawCube();
  void triangleCubCoor(GLfloat cube_buffer);
  const float GRIDCOUNTTOTAL;

  int gridCounter;
  float gridXPos, gridZPos;
//  std::vector< std::vector<int> > matrix;
  std::vector <GLuint> dList;

  struct GridPos
  {
    int m_gridPoint;
    float m_Gx;
    float m_Gz;
  };
  GridPos GridCoor[15][15];

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
