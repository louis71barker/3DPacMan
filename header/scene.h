#ifndef SCENE_H__
#define SCENE_H__

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





typedef struct {
  GLfloat x;
  GLfloat y;
  GLfloat z;
}Vector3;

Vector3 NormalizeVec3(Vector3 Vector);

typedef struct {
  GLfloat x;
  GLfloat y;
  GLfloat z;
  GLfloat w;
}Vector4;

Vector4 NormalizeVec4(Vector4 Vector);


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


void ObjLoader(const std::string &, std::vector<Vec3> &_vec, std::vector<Vec3> &_norm, std::vector<Vec3> &_text, std::vector<int> &_index);
void textLoader(const std::string &_fname, GLuint &_tid);

class FileLoad
{

private:
  typedef boost::tokenizer<boost::char_separator<char> >tokenizer;
  void fileParser(tokenizer::iterator &_firstWord, int lineCount, std::vector<std::vector<int> > &_gridCoor);

public:
    void fileLoader(const std::string &_fname, std::vector<std::vector<int> > &_gridCoor, const std::string &_typeDef);


};






#endif
