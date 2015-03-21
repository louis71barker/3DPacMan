#ifndef COLLECTABLE_H__
#define COLLECTABLE_H__
#include <vector>
#include <GL/gl.h>


class Collecable
{
public:
  void drawCollectable(std::vector<std::vector<int> > matrix);



private:
  void normalSetter(std::vector<std::vector<int> > matrix);
  void specialSetter(std::vector<std::vector<int> > matrix);
  void placeObj(int _x, int _y);
  void drawBalls();



};





#endif
