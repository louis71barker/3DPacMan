//------------------------------------------------------------------------------------------------------------------
/// INCLUDE GUARD CHANGE TO NAME OF FILE BELOW
//------------------------------------------------------------------------------------------------------------------
#ifndef ARENA_H__
#define ARENA_H__

//------------------------------------------------------------------------------------------------------------------
///Here are all the includes that are needed
//------------------------------------------------------------------------------------------------------------------
#include <vector>
#include "walls.h"
#include "audio.h"

//------------------------------------------------------------------------------------------------------------------
/// Louis Barker
/// Version 1.0
/// 04/05/2015
//------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------------------------
/// @brief
/// The Arena class
/// This class is used for the drawing of the ground obj for the arena ground as well as also the background ambient music
/// in the game
///
/// @todo
/// The ground texture needs to be imporved and the ground needs to be made rough to git a more realistic
/// appearence.
//------------------------------------------------------------------------------------------------------------------
class Arena
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
  /// This is the audio chunk defination where the audio file is assigned to allow for the sound to be played
  //------------------------------------------------------------------------------------------------------------------
  Mix_Chunk *a_ambMusic;


  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// Arena class constutor which is used to build all the functions needed for the game
  //------------------------------------------------------------------------------------------------------------------
  Arena()
  {
    //------------------------------------------------------------------------------------------------------------------
    /// @brief
    /// Class defination for the audio class so the audio is able to be added as needed
    //------------------------------------------------------------------------------------------------------------------
    Audio au;

    //------------------------------------------------------------------------------------------------------------------
    /// @brief
    /// Here is a call the the OBJLoader class which loads the obj files data into the relivent vectors
    //------------------------------------------------------------------------------------------------------------------
    ObjLoader("obj/OBJ_Ground.obj",m_Vertex,m_Normal,m_Texture,m_Index);

    //------------------------------------------------------------------------------------------------------------------
    /// @brief
    /// Here the ground is built and added to the display list so it can be drawn
    //------------------------------------------------------------------------------------------------------------------
    ground();

    //------------------------------------------------------------------------------------------------------------------
    /// @brief
    /// This is a call to the loading a sound file function in Audio class to load in the background music and assigned it to a_ambMusic
    //------------------------------------------------------------------------------------------------------------------
    au.loadSoundChunk("sounds/ambMusic.wav", &a_ambMusic);

    //------------------------------------------------------------------------------------------------------------------
    /// @brief
    /// a_ambMusic is now called in with the VolumeChunk function to set the volume level within the game
    //------------------------------------------------------------------------------------------------------------------
    Mix_VolumeChunk(a_ambMusic, MIX_MAX_VOLUME * 0.6);

    //------------------------------------------------------------------------------------------------------------------
    /// @brief
    /// the audio is now called in to be played on the next available channel and set to repeat on an endless loop
    //------------------------------------------------------------------------------------------------------------------
    Mix_PlayChannel(-1, a_ambMusic, -1);
  }
  ~Arena()
  {
    //------------------------------------------------------------------------------------------------------------------
    /// @brief
    /// Here are all the functions to clean and clear all the Vectors used through the .clear function
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

    //------------------------------------------------------------------------------------------------------------------
    ///@brief
    ///Here is the free function to clear the memory saved for the music file
    //------------------------------------------------------------------------------------------------------------------
    Mix_FreeChunk(a_ambMusic);
  }
  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// This is the function that is called in the main to draw the displayList with the ground in.
  //------------------------------------------------------------------------------------------------------------------
  void drawArena();

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// This is the function that is used to build the obj file so that it is able to be drawn
  /// This function also textures the object
  /// Once the obj had been build and assained correctly from the obj file, it is passed into the displayList to
  /// be drawn
  //------------------------------------------------------------------------------------------------------------------
  void ground();

private:
  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// This is the texture id that is used for the texturing of the object
  //------------------------------------------------------------------------------------------------------------------
  GLuint GroundTextID;
};
#endif
