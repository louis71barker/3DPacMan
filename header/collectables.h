//------------------------------------------------------------------------------------------------------------------
/// INCLUDE GUARD CHANGE TO NAME OF FILE BELOW
//------------------------------------------------------------------------------------------------------------------
#ifndef COLLECTABLE_H__
#define COLLECTABLE_H__

//------------------------------------------------------------------------------------------------------------------
///Here are all the includes that are needed
//------------------------------------------------------------------------------------------------------------------
#include <vector>
#include <GL/gl.h>
#include <stdlib.h>
#include <iostream>
#include "walls.h"
#include "scene.h"

//------------------------------------------------------------------------------------------------------------------
/// Louis Barker
/// Version 1.0
/// 04/05/2015
//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
/// @brief
/// The Collectable class
/// This is the class that is used to place and draw all of the collectables within the maze.
///
/// @todo
/// Make the specials rotate and be able to be picked up once the player collided
/// Make the specials give an ability to the player
//------------------------------------------------------------------------------------------------------------------
class Collectable
{
public:
  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// Collectable - In the constructor of the collectable, the counter for the amount of collectables within the game
  /// is set to its dephault of zero before it is incremented.
  /// Next the the bool for the counter completed is set to false so when all the collectables have been counted, it
  /// can be set to true.
  /// Next the obj for the cherry is brought in so that it is able to be draw into the game
  /// Finally the  function to add the specials into the displayList is run so that it is able to be drawn.
  /// @param
  /// m_matrix - This is the map matrix that is brought in so that the location of the specials is able to be
  /// collected
  //------------------------------------------------------------------------------------------------------------------
  Collectable(std::vector<std::vector<int> > m_matrix)
  {
    m_collecibleCount = 0;
    m_countSet = false;
    ObjLoader("obj/CherryObj.obj",m_Vertex,m_Normal,m_Texture,m_Index);
    placeSpecials(m_matrix);

  }

  ~Collectable()
  {
    //------------------------------------------------------------------------------------------------------------------
    /// \Here are all the functions to clean and clear all the Vectors used through the .clear function
    //------------------------------------------------------------------------------------------------------------------
    m_Vertex.clear();
    std::vector<Vec3>().swap (m_Vertex);
    m_Normal.clear();
    std::vector<Vec3>().swap (m_Normal);
    m_Texture.clear();
    std::vector<Vec3>().swap (m_Texture);
    m_displayList.clear();
    std::vector<GLuint>().swap (m_displayList);
    m_Index.clear();
    std::vector<int>().swap (m_Index);
  }

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// collecibleCount - This is the counter for all the collectibles withtin the game.
  //------------------------------------------------------------------------------------------------------------------
  int m_collecibleCount;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// drawCollectable - This is the function that is called in the main to draw both types of collectibles on the
  /// screen through the displayList. It is also used to call for collision detection for the collectibles so they are
  /// able to be picked up accordingly.
  /// @param
  /// m_matrix - This is the map matrix that is passed in so the collectables are able to be placed where they are
  /// allocated on the map
  /// @param
  /// _playerx - This is the player x position that is passed into the collision detection so that they are able to
  /// detect when they have been picked up
  /// @param
  /// _playery - This is the player z position that is passed into the collision detection so that they are able to
  /// detect when they have been picked up
  //------------------------------------------------------------------------------------------------------------------
  void drawCollectable(std::vector<std::vector<int> > &m_matrix, const float _playerx, const float _playery);

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// drawCollectiblesLeft - This is the function that is used to draw on the screen how many more collectibles are
  /// left to be collected.
  //------------------------------------------------------------------------------------------------------------------
  void drawCollectiblesLeft();

private:
  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// countSet - This is the bool that used to detected once all the collectables have been counted at the start of
  /// the game.
  //------------------------------------------------------------------------------------------------------------------
  bool m_countSet;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// placeSpecials - This is the function that is used to import the obj file for the specials into the vectors and
  /// also to place them in the correct locations within the maze
  /// @param
  /// m_matrix - This the the map matrix that is passed in so that the location for the specials is able to be found
  //------------------------------------------------------------------------------------------------------------------
  void placeSpecials(std::vector<std::vector<int> > &m_matrix);

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// normalSetter - This is the function that is used to place the regular collectables throughout the maze.
  /// It also adds the counter up to the amount of regular collectables in the maze so it can be displayed in game
  /// @param
  /// m_matrix - This the the map matrix that is passed in so that the location for the collectables are able to be
  /// found.
  //------------------------------------------------------------------------------------------------------------------
  void normalSetter( std::vector<std::vector<int> > &m_matrix);

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// placeObj - This is the function that is called within the normalSetter function to place the collectables in
  /// their relivent locations
  /// @param
  /// _x - This is the value from the for loop inside the normalSetter which is used to calculate the location of the
  /// place where the collectable need to be places
  /// @param
  /// _y - This is the value from the for loop inside the normalSetter which is used to calculate the location of the
  /// place where the collectable need to be places
  /// @param
  /// m_matrix - This is used to find the location of where the colleceable needs to be places
  //------------------------------------------------------------------------------------------------------------------
  void placeObj(const int _x, const int _y, const std::vector<std::vector<int> > &m_matrix);

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// drawBalls - This is the function to draw the spheres at the location of the regualar collectables
  //------------------------------------------------------------------------------------------------------------------
  void drawBalls();

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// collisonDetection - This is the function that is used to detect once the collectables have been collected by
  /// the player. This changes the value of the normals location within the maze so that it isnt draw anymore meaning
  /// they are able to be picked up
  /// @param
  /// m_matrix - This is the map matrix that is sent in so it is able to be edited according once a collectable has
  /// been drawn
  /// @param
  /// _playerx - This is the current x player pos within the game so the collison is able to be found between the player
  /// and the collectable
  /// \param
  /// _playery - This is the current z player pos within the game so the collison is able to be found between the player
  /// and the collectable
  //------------------------------------------------------------------------------------------------------------------
  void collisonDetection(std::vector<std::vector<int> > &m_matrix, float _playerx, float _playery);





  //------------------------------------------------------------------------------------------------------------------
  /// \These are used to store the coordinate information of the objects that will be drawn in the game
  /// \These are before the constuctor and destructor as they are used in both.
  /// @m_Vertex is used to store the vertex coordinates of the Object file.
  /// @m_Normal is used to store the normal values from the object file.
  /// @m_Texture is used to store the texture coordinates of the object.
  /// @m_Index is used to store the list in which to join the vertex, normals and textures coordinates together.
  /// @m_displayList is the list which is used to actually draw the object onto the screen
  //------------------------------------------------------------------------------------------------------------------
  std::vector<Vec3> m_Vertex;
  std::vector<Vec3> m_Normal;
  std::vector<Vec3> m_Texture;
  std::vector<int> m_Index;
  std::vector<GLuint> m_displayList;
};
#endif
