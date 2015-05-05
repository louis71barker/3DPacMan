//------------------------------------------------------------------------------------------------------------------
/// INCLUDE GUARD CHANGE TO NAME OF FILE BELOW
//------------------------------------------------------------------------------------------------------------------
#ifndef GEODOME_H__
#define GEODOME_H__

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
/// The geoDome class
/// This is the class that is used to draw the geoDome around the map to give it and enviroment
//------------------------------------------------------------------------------------------------------------------
class geoDome
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
  std::vector <GLuint> m_daList;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// geoDome - This is the constructor for the class which bring in the geoDome obj file into the vectors so that
  /// it can be drawn. Once it is imported, it is textures and added to displayList so it is able to be drawn.
  //------------------------------------------------------------------------------------------------------------------
  geoDome()
  {
    ObjLoader("obj/geoSphere.obj",m_Vertex,m_Normal,m_Texture,m_Index);
    dome();
  }

  ~geoDome()
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
    m_daList.clear();
    std::vector<GLuint>().swap (m_daList);
  }

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// dome - This is the function that builds the geoDome into the vectors and adds it to the displayList
  //------------------------------------------------------------------------------------------------------------------
  void dome();

  //------------------------------------------------------------------------------------------------------------------
  /// \This is the function that is called in the main to draw the displayList with the barn in.
  //------------------------------------------------------------------------------------------------------------------
  void drawdome();



private:
  //------------------------------------------------------------------------------------------------------------------
  /// \This is the texture id that is used for the texturing of the object
  //------------------------------------------------------------------------------------------------------------------
  GLuint m_geodomeTextID;

};




#endif
