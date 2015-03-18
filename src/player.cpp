#include "header/player.h"

void Player::colliosion(std::vector<std::vector<int> > matrix)
{
  for(int i = 0; i < (int)matrix.size(); ++i)
  {
    for(int j = 0; j < (int)matrix[0].size(); ++j)
    {
      if(matrix[i][j] == 1)
      {
        playerMoveAllowed = false;

      }
      if (matrix[i][j]== 0)
      {
        playerMoveAllowed = true;
        //have it so that the player can only move within the coor of 0 meaning that all collisions with work iin the path :)
      }

    }
  }
}

void Player::draw()
{

}

void Player::update(std::vector<std::vector<int> > matrix)
{
  draw();
  colliosion(matrix);
}
