#include "header/player.h"
#include "header/camera.h"
#include <cmath>

void Player::colliosion(std::vector<std::vector<int> > matrix, float playerXpos, float playerZpos)
{
  Camera cam;
//  for(int i = 0; i < (int)matrix.size(); ++i)
//  {
//    for(int j = 0; j < (int)matrix[0].size(); ++j)
//    {
////      if(((playerXpos - matrix[i][j])<=2 && ((playerXpos - matrix[i][j])>=-2)) && ((playerZpos - matrix[i][j])<=2 && ((playerZpos - matrix[i][j])>=-2)))
////      {
////        if(((playerZpos - matrix[i][j])<=2 && ((playerZpos - matrix[i][j])>=-2)) && ((playerZpos - matrix[i][j])<=2 && ((playerZpos - matrix[i][j])>=-2)))
////        {
////          std::cout<<"woooooo you can move here!!!!!!\n";
////        }
////      }
////      if (matrix[i][j]== 0)
////      {
////        playerMoveAllowed = true;
////        //have it so that the player can only move within the coor of 0 meaning that all collisions with work iin the path :)
////      }
////      std::cout<<matrix[i][j]<<"\n";
////        if ((((fabs(matrix[i][j]) - playerXpos) <= 0.5) && ((playerXpos - playerXpos) + matrix[i][j] >= -0.5)) && ((((playerZpos - playerZpos) + matrix[i][j]) <= 0.5) && ((playerZpos - playerZpos) + matrix[i][j] >= -0.5)))
////        {
//////           std::cout<<"wooooooo we are inside a path cube :) \n";
////          std::cout<<((playerXpos - playerXpos) + matrix[i][j])<<"\n";
////        }
//      if(matrix[i][j] == 1)
//      {
//        if((fabs((-30 + (i+0.5)*4) - playerXpos) < 3) &&
//           (fabs((30 - (j+0.5)*4) - playerZpos) < 3))
//        {
//          float cubeCentreX = (-30 + (i+0.5)*4);
//          float cubeCentreZ = (30 - (j+0.5)*4);
//          if (cubeCentreX - (fabs((-30 + (i+0.5)*4) - playerXpos) < 3) > 0)
//          {
//            playerXpos -= 100;
//          }
//          else if (cubeCentreX - (fabs((-30 + (i+0.5)*4) - playerXpos) < 3) < 0)
//          {
//            playerXpos += 100 ;
//          }
//          if (cubeCentreZ - (fabs((30 - (j+0.5)*4) - playerZpos) < 3) > 0)
//          {
//            playerZpos -= 100;
//          }
//          else if (cubeCentreZ - (fabs((30 + (j+0.5)*4) - playerZpos) < 3) < 0)
//          {
//            playerZpos += 100;
//          }
//          std::cout << "Close to a wall!" << i << " " << j << " " << (30 - (j+0.5)*4) - playerZpos << "\n";
//        }
//      }
//      std::cout << playerXpos << "        "<<playerZpos << "\n";

//glTranslatef(-30 + (_x+0.5)*4, 0, 30 - (_y+0.5)*4);


//    }
//  }
//  return playerXpos, playerZpos;

}

void Player::draw()
{

}

void Player::update(std::vector<std::vector<int> > matrix, float playerXpos, float playerZpos)
{
  draw();
  colliosion(matrix,playerXpos,playerZpos);
}
