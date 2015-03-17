#ifndef WALLS_H__
#define WALLS_H__



class Walls
{
public:
  void cubeInit();
  void cubeSetter();
  void mapBuilder();

private:
  const float CUBEHEIGHT = 2.0f;
  float CUBEWIDTH = 2.0f;
  float CUBEDEPTH = 2.0f;

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
  2 =
  3 = player start
  4 = ghost spawn
  5 = specials
  6 = 1 direction wall for ghosts
  */


};



#endif
