#ifndef ARENA_H__
#define ARENA_H__





class Arena
{
public:
  Arena () : MAPGRIDSIZE(15.0f)
  {
  }

  void ground();
  void sky();
  void drawArena();


private:
  const float MAPGRIDSIZE;


};






#endif
