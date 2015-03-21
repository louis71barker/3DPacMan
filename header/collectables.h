#ifndef COLLECTABLE_H__
#define COLLECTABLE_H__
#include <vector>
#include <GL/gl.h>
#include <stdlib.h>
#include <istream>



class Collecable
{
public:
  void drawCollectable(std::vector<std::vector<int> > matrix);



private:
  void normalSetter(std::vector<std::vector<int> > matrix);
  void specialSetter(int _x, int _y);
  void placeObj(int _x, int _y);
  void drawBalls();
  void drawSpecials();



};





#endif
