#ifndef ARENA_H__
#define ARENA_H__





class Arena
{
public:
  Arena ()
  {
  }

  static void ground();
  static void sky();

  static void drawArena();


private:
  const float MAPGRIDSIZE = 15.0;


};






#endif
