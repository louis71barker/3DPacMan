#include "header/lights.h"



void Lights::distanceCal(std::vector<std::vector<int> > matrix)
{

  for (int i = 0; i <(int)matrix.size(); i++)
  {
    for (int j = 0; j <(int)matrix[0].size(); j++)
    {

      if(matrix[i][j] == 0)
      {
        float lightCentreX = (-30 + (i+0.5)*4);
        float lightCentreZ = (30 - (j+0.5)*4);
        float distX = playerXpos - lightCentreX;
        float distZ = playerZpos - lightCentreZ;
        if (distX < 0)
        {
          distX = fabs(distX);
        }
        if (distZ < 0 )
        {
          distZ = fabs(distZ);
        }

        float distVal = distX + distZ;

        if (lightIdSet == false)
        {
          lightPos.push_back(distVal);
        }



        distanceSorter();
      }
    }
    if (i == (int)matrix.size()-1)
    {
      lightIdSet = true;
    }
  }
}

void Lights::distanceSorter()
{
  std::sort(lightPos.begin(), lightPos.end());
//  std::cout << lightPos.size()<< " \n ";
  for( int i = 0; i < (int)lightPos.size();i++)
  {
//    std::cout << lightPos.size()<< " \n ";
  }
//  std::cout<<"\n";
}
