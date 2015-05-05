//------------------------------------------------------------------------------------------------------------------
/// INCLUDE GUARD CHANGE TO NAME OF FILE BELOW
//------------------------------------------------------------------------------------------------------------------
#ifndef SCENE_H__
#define SCENE_H__

//------------------------------------------------------------------------------------------------------------------
///Here are all the includes that are needed
//------------------------------------------------------------------------------------------------------------------
#include <SDL.h>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <boost/tokenizer.hpp>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


#define CUBESIZE 4
#define SCREENWIDTH 1000
#define SCREENHEIGHT 700
#define MAXMAPSIZE 400


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
///This is the struct for the Vec2 so that they are able to be used throughout the game for x and y values
//------------------------------------------------------------------------------------------------------------------
typedef struct {
  GLfloat x;
  GLfloat y;
}Vector2;
Vector2 NormalizeVec3(Vector2 Vector);

//------------------------------------------------------------------------------------------------------------------
///This is the struct for the Vec3 so that they are able to be used throughout the game for x and y and z values
//------------------------------------------------------------------------------------------------------------------
typedef struct {
  GLfloat x;
  GLfloat y;
  GLfloat z;
}Vector3;
Vector3 NormalizeVec3(Vector3 Vector);

//------------------------------------------------------------------------------------------------------------------
///This is the struct for the Vec4 so that they are able to be used throughout the game for x and y and z and w
///values
//------------------------------------------------------------------------------------------------------------------
typedef struct {
  GLfloat x;
  GLfloat y;
  GLfloat z;
  GLfloat w;
}Vector4;
Vector4 NormalizeVec4(Vector4 Vector);


//vector 2 class
class Vec2
{
public:
  Vec2(float _x=0.0f,float _y=0.0f) :
    m_x(_x), m_y(_y){}
  void normalGL();
  void vertexGL();
  void textureGL();

  struct
  {
    float m_x;
    float m_y;
  };

};


//vector 3 class
class Vec3
{
public:
  Vec3(float _x=0.0f,float _y=0.0f, float _z=0.0f) :
    m_x(_x), m_y(_y), m_z(_z){}
  void normalGL();
  void vertexGL();
  void textureGL();

  struct
  {
    float m_x;
    float m_y;
    float m_z;
  };

};




//vector 4 class
class Vec4
{
public:
  Vec4(float _x=0.0f, float _y=0.0f, float _z=0.0f, float _w=0.0f) :
    m_x(_x), m_y(_y), m_z(_z), m_w(_w){}
  void normalGL();
  void vertexGL();
  void textureGL();

  struct
  {
    float m_x;
    float m_y;
    float m_z;
    float m_w;
  };

};


//------------------------------------------------------------------------------------------------------------------
/// @brief
/// ObjLoader - This is the object loader function which is called throughout the game to load obj into the
/// indercated vector
/// @param
/// _vec - This is the place holder Vertex vector that is replaced when called
/// @param
/// _norm - This is the place holder Normals vector that is replaced when called
/// @param
/// _text - This is the place holder Texture vector that is replaced when called
/// @param
/// _index - This is the place holder Index vector that is replaced when called
//------------------------------------------------------------------------------------------------------------------
void ObjLoader(const std::string &, std::vector<Vec3> &_vec, std::vector<Vec3> &_norm, std::vector<Vec3> &_text, std::vector<int> &_index);

//------------------------------------------------------------------------------------------------------------------
/// @brief
/// textLoader - This is the texture loader function that is called throughout the game to load texture images onto
/// surfaces
/// @param
/// _fname - This is a placeholder for the file name that is entered when the function is called
/// @param
/// _tid - This is a placeholder for the texture ID which is replaced when function is called
//------------------------------------------------------------------------------------------------------------------
void textLoader(const std::string &_fname, GLuint &_tid);

//------------------------------------------------------------------------------------------------------------------
/// @brief
/// The FileLoad class
/// This class is used to import the map file from a text file into map matrix
//------------------------------------------------------------------------------------------------------------------
class FileLoad
{
private:
  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// tokenizer - this is the tokenizer for the file
  //------------------------------------------------------------------------------------------------------------------
  typedef boost::tokenizer<boost::char_separator<char> >tokenizer;

  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// fileParser - this function is used to resize the matrix to the size of the map and then to add the information
  /// from the text file into the vector defined
  /// @param
  /// _firstWord - this is the current word which is being passed down to be added to the matrix
  /// @param
  /// lineCount - this is the counter for all the lines in the matrix which increments everytime the matrix hits it
  /// max width
  /// @param
  /// _gridCoor - this is a place holder for what will be the matrix vector once it is defined in the function
  /// calling
  //------------------------------------------------------------------------------------------------------------------
  void fileParser(tokenizer::iterator &_firstWord, int lineCount, std::vector<std::vector<int> > &_gridCoor);

public:
  //------------------------------------------------------------------------------------------------------------------
  /// @brief
  /// fileLoader - this function is the function that is called to actually read the text file and add it to the map
  /// matrix that is defined.
  /// @param
  /// _fname - This is a placeholder for the file name that will be read when the function is called
  /// @param
  /// _gridCoor - This is a placeholder for the matrix vector that the map will be stored in
  /// @param
  /// _typeDef - This is the string that the file reader will be looking for at the begin of each sentence to know
  /// what lines need to be read
  //------------------------------------------------------------------------------------------------------------------
  void fileLoader(const std::string &_fname, std::vector<std::vector<int> > &_gridCoor, const std::string &_typeDef);


};






#endif
