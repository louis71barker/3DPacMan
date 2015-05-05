//------------------------------------------------------------------------------------------------------------------
/// INCLUDE GUARD CHANGE TO NAME OF FILE BELOW
//------------------------------------------------------------------------------------------------------------------
#ifndef WINDOW_H__
#define WINDOW_H__

//------------------------------------------------------------------------------------------------------------------
///Here are all the includes that are needed
//------------------------------------------------------------------------------------------------------------------
#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "camera.h"
#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif

//------------------------------------------------------------------------------------------------------------------
/// \Louis Barker
/// \Version 1.0
/// 04/05/2015
//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
/// @brief
/// SDLErrorExit - This function is used to test to make sure that SDL is working correctly and if it isnt then
/// the error is captured and printed out
/// @param
/// _err - This is the error that is captured so it can be printed to the terminal
//------------------------------------------------------------------------------------------------------------------
void SDLErrorExit(const std::string &_err);

//------------------------------------------------------------------------------------------------------------------
/// @brief
/// createOpenGLContext
/// This function is used to create and open all the required SDL GL content that is required
/// @param
/// _win - This is the window link that is give in in the main when called
//------------------------------------------------------------------------------------------------------------------
SDL_GLContext createOpenGLContext(SDL_Window *_win);


//------------------------------------------------------------------------------------------------------------------
/// @brief
/// The Window class
/// This class is used to init alot of the required SDL and GL content to save space in the main and to be more
/// organised
//------------------------------------------------------------------------------------------------------------------
class Window
{
public:
  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// m_screenW - This is the value that will be used for the window width
  /// @brief
  /// m_screenH - This is the value that will be used for the window height
  //------------------------------------------------------------------------------------------------------------------
  double m_screenW, m_screenH;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// Lighting - This function is used to enable all of the lighting setting that are required throughout the game
  //------------------------------------------------------------------------------------------------------------------
  void Lighting() const;


protected:



};






#endif
