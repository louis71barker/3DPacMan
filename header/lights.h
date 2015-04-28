#ifndef LIGHTS_H__
#define LIGHTS_H__

#include "camera.h"
#include "walls.h"
#include <vector>



class Lights : public Camera
{
public:

  Lights() : Camera()
  {
    lightIdSet = false;
    lights.resize(150);
  }

  std::vector<std::vector<float> > lights;
  std::vector<float> lightPos;
  void distanceCal(const std::vector<std::vector<int> > matrix);


private:
  bool lightIdSet;
  void distanceSorter();


};







#endif
