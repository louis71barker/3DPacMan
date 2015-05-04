/// INCLUDE GUARD CHANGE TO NAME OF FILE BELOW
#ifndef BARN_H__
#define BARN_H__

///Here are all the includes that are needed
#include <vector>
#include "scene.h"

/// \Louis Barker
/// \Version 1.0
/// 04/05/2015


//------------------------------------------------------------------------------------------------------------------
/// \brief The Barn class
/// This class is used for the importing, placing and drawing of the barn within the game
///
/// @todo
/// Make it so that their is a parent class to hold the vector information and displayLists and use inheritence
//------------------------------------------------------------------------------------------------------------------
class Barn
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
  /// \brief Barn
  /// Within the constructor of the class, the object load function is called to load in the barn object into the
  /// vextors. Once this is done, the object is then built into the display list and relocated to the location on
  /// the map that is is assainged.
  ///
  /// \param _matrix
  /// This is passed in as a reference to allow for the location of the barn to be found and then moved.
  //------------------------------------------------------------------------------------------------------------------
  Barn(const std::vector<std::vector<int> > &_matrix)
  {
    //------------------------------------------------------------------------------------------------------------------
    /// \Here is a call the the OBJLoader class which loads the obj files data into the relivent vectors
    //------------------------------------------------------------------------------------------------------------------
    ObjLoader("obj/FarmhouseTri.obj",m_Vertex,m_Normal,m_Texture,m_Index);

    //------------------------------------------------------------------------------------------------------------------
    /// \Here the buildbarn is called so it can be built and added to the display list so it can be drawn
    //------------------------------------------------------------------------------------------------------------------
    buildBarn(_matrix);

  }

  ~Barn()
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
  /// \brief buildBarn
  /// \This is the function that is used to build the obj file so that it is able to be drawn
  /// \This function also textures the object
  /// \Once the obj had been build and assained correctly from the obj file, it is passed into the displayList to
  /// be drawn
  /// @param[in] _matrix
  /// This it the map matrix which is passed in so that the barn can be placed in the correct location
  //------------------------------------------------------------------------------------------------------------------
  void buildBarn(const std::vector<std::vector<int> > &_matrix);

  //------------------------------------------------------------------------------------------------------------------
  /// \This is the function that is called in the main to draw the displayList with the barn in.
  //------------------------------------------------------------------------------------------------------------------
  void drawBarn();



private:
  //------------------------------------------------------------------------------------------------------------------
  /// \This is the texture id that is used for the texturing of the object
  //------------------------------------------------------------------------------------------------------------------
    GLuint BarnTextID;

};




#endif
