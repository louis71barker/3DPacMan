#ifndef ARENA_H__
#define ARENA_H__



class Arena
{
public:
  static void ground();
  static void walls();
  static void sky();
  float x = 0.0f,z = 5.0f, lx = 0.0f, lz = -1.0f;

  static void drawArena();


private:

};




#endif
