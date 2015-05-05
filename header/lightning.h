//------------------------------------------------------------------------------------------------------------------
/// INCLUDE GUARD CHANGE TO NAME OF FILE BELOW
//------------------------------------------------------------------------------------------------------------------
#ifndef LIGHTNING_H__
#define LIGHTNING_H__

//------------------------------------------------------------------------------------------------------------------
///Here are all the includes that are needed
//------------------------------------------------------------------------------------------------------------------
#include <SDL2/SDL.h>
#include "header/scene.h"
#include "header/audio.h"

//------------------------------------------------------------------------------------------------------------------
/// \Louis Barker
/// \Version 1.0
/// 04/05/2015
//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
/// @brief
/// The Lightning class - This class is for the lighting effects within the scene, it is used to play the lighting
/// sound and to also flash the light to give the effect
//------------------------------------------------------------------------------------------------------------------
class Lightning
{
public:
  //------------------------------------------------------------------------------------------------------------------
  /// \This is the audio chunk defination where the audio file is assigned to allow for the sound to be played
  //------------------------------------------------------------------------------------------------------------------
  Mix_Chunk *a_Thunder;

  //------------------------------------------------------------------------------------------------------------------
  /// \Class defination for the audio class so the audio is able to be added as needed
  //------------------------------------------------------------------------------------------------------------------
  Audio au;

  //------------------------------------------------------------------------------------------------------------------
  ///
  /// @brief
  /// Lightning - In this constuctior, the lightning trigger is set to its dephault of false so that it is able turn
  /// turn once the timer is triggered
  //------------------------------------------------------------------------------------------------------------------
  Lightning()
  {
    m_lightningTrig = false;
  }
  ~Lightning()
  {
    //------------------------------------------------------------------------------------------------------------------
    ///Here is the free function to clear the memory saved for the music file
    //------------------------------------------------------------------------------------------------------------------
    Mix_FreeChunk(a_Thunder);
  }

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// lightningTrig - This is the bool for the lightning to trigger the lighting on and off and to trigger the thunder
  /// sound effect.
  //------------------------------------------------------------------------------------------------------------------
  bool m_lightningTrig;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// lightningAudio - This is a simple funcion to turn on the sound effect. This is called in the drawLightning
  /// function but needs to be called after SDL_Mixer has been INIT so this needs to be seperate
  //------------------------------------------------------------------------------------------------------------------
  void lightningAudio() { au.loadSoundChunk("sounds/Thunder.wav", &a_Thunder); }

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// drawLightning - This is the function that turns on and off the light to give the lightning effect.
  //------------------------------------------------------------------------------------------------------------------
  void drawLightning();

};
#endif
