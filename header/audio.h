/// INCLUDE GUARD CHANGE TO NAME OF FILE BELOW
#ifndef AUDIO_H__
#define AUDIO_H__

///Here are all the includes that are needed
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <iostream>
#include <string>


/// \Louis Barker
/// \Version 1.0
/// 04/05/2015


//------------------------------------------------------------------------------------------------------------------
/// @brief The Audio class
/// \This class is used for the ease of use to import and implement audio files throughout the game
///
/// @todo Add more file formats that are allowed to be imported into the game
///       Also maybe make as a namespace to make more pratical
//------------------------------------------------------------------------------------------------------------------
class Audio
{
public:
  //------------------------------------------------------------------------------------------------------------------
  /// \brief Audio
  /// \Here is the constuctor for the Audio class
  /// \m_audioSuccess is set to it dephault of false here
  //------------------------------------------------------------------------------------------------------------------
  Audio() : m_audioSuccess(false) {}

  //------------------------------------------------------------------------------------------------------------------
  /// \breif Audio distructor
  //------------------------------------------------------------------------------------------------------------------
  ~Audio() {}

  //------------------------------------------------------------------------------------------------------------------
  /// \brief m_audioSuccess
  /// This is used to check if the audio init has been successful or not, if it stay as false, an error is outputted
  //------------------------------------------------------------------------------------------------------------------
  bool m_audioSuccess;

  //------------------------------------------------------------------------------------------------------------------
  /// \brief loadSoundChunk
  /// This function is what is called throughout the program to load in a music file
  /// \param _fname
  /// This is what will be used for the location of the file so it can be imported
  /// \param a_sound
  /// This is the chunk that will be used to play and store the sound
  //------------------------------------------------------------------------------------------------------------------
  void loadSoundChunk(const std::string &_fname, Mix_Chunk **a_sound);
};





#endif
