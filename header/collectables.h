#ifndef COLLECTABLE_H__
#define COLLECTABLE_H__
#include <vector>
#include <GL/gl.h>
#include <stdlib.h>
#include <iostream>
#include "walls.h"



class Collecable
{
public:
  Collecable()
  {
    collecibleCount = 0;
    countSet = false;
  }

  void drawCollectable(std::vector<std::vector<int> > &_matrix, float _x, float _y, float yRot);
  int collecibleCount;




private:

  void normalSetter(std::vector<std::vector<int> > matrix);
  void specialSetter(int _x, int _y);
  void placeObj(int _x, int _y);
  void drawBalls();
  void drawSpecials();
  void collisonDetection(std::vector<std::vector<int> > &_matrix, float _x, float _y);
  void countSetter(std::vector<std::vector<int> > &_matrix);
  void drawCollectiblesLeft(float _x, float _y, float _yRot);
  bool countSet;



};





#endif
