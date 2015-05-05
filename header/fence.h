//------------------------------------------------------------------------------------------------------------------
/// INCLUDE GUARD CHANGE TO NAME OF FILE BELOW
//------------------------------------------------------------------------------------------------------------------
#ifndef FENCE_H__
#define FENCE_H__

//------------------------------------------------------------------------------------------------------------------
///Here are all the includes that are needed
//------------------------------------------------------------------------------------------------------------------
#include <vector>
#include "scene.h"


//------------------------------------------------------------------------------------------------------------------
/// Louis Barker
/// Version 1.0
/// 04/05/2015
//------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------------------------
/// @brief
/// The Fence class
/// This classs is used to draw the fences around the map depending on where they are defined in the map matrix
//------------------------------------------------------------------------------------------------------------------
class Fence
{
public:
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

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// Fence
  /// In the constructor the fence object is loaded into the vectors. Once this is done, the object is then built into
  /// the display list and relocated to the location on the map that is is assainged.
  /// @param
  /// m_matrix
  /// This is passed in as a reference to allow for the location of the fence to be found and then moved.
  //------------------------------------------------------------------------------------------------------------------
  Fence(const std::vector<std::vector<int> > &m_matrix)
  {
    ObjLoader("obj/OldFence.obj",m_Vertex,m_Normal,m_Texture,m_Index);
    buildFence(m_matrix);
  }

  ~Fence()
  {
    //------------------------------------------------------------------------------------------------------------------
    /// @brief
    /// ~Fence - Here are all the functions to clean and clear all the Vectors used through the .clear function
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
  /// buildFence - This is the function that is used to build the obj file so that it is able to be drawn
  /// This function also textures the object
  /// Once the obj had been build and assained correctly from the obj file, it is passed into the displayList to
  /// be drawn
  /// @param
  /// m_matrix - This it the map matrix which is passed in so that the fences can be placed in the correct location
  //------------------------------------------------------------------------------------------------------------------
  void buildFence(const std::vector<std::vector<int> > &m_matrix);

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// drawFence - This is the function that is called in the main to draw the displayList with the fence in.
  //------------------------------------------------------------------------------------------------------------------
  void drawFence();



private:
  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// This is the texture id that is used for the texturing of the object
  //------------------------------------------------------------------------------------------------------------------
  GLuint m_FenceTextID;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// setFence - This is the function that is used to move the fences to the location allocated in the maze and rotate
  /// them accordingly.
  /// @param
  /// _a - This is the for loop i value that is used to find the location within the maze matrix without having
  /// another for loop.
  /// @param
  /// _b - This is the for loop j value that is used to find the location within the maze matrix without having
  /// another for loop.
  /// @param
  /// m_matrix - This it the map matrix which is passed in so that the fences can be placed in the correct location
  //------------------------------------------------------------------------------------------------------------------
  void setFence(const int _a, const int _b, const std::vector<std::vector<int> > &m_matrix);

  //------------------------------------------------------------------------------------------------------------------
  ///
  /// @brief
  /// createFenceNormal - This is the function that is used for placeing the feneces.
  /// @param
  /// m_matrix - This it the map matrix which is passed in so that the fences can be placed in the correct location
  //------------------------------------------------------------------------------------------------------------------
  void createFenceNormal(const std::vector<std::vector<int> > &m_matrix);
};




#endif
