#ifndef SCENE_H__
#define SCENE_H__

#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>



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

Vector4 NormalizeVec3(Vector4 Vector);


//vector 3 class
class Vec3
{
public:
  Vec3(float _x=0.0f,float _y=0.0f, float _z=0.0f) :
    m_x(_x), m_y(_y), m_z(_z){}

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
  Vec4(float _x=0.0f,float _y=0.0f, float _z=0.0f, float _w=0.0f) :
    m_x(_x), m_y(_y), m_z(_z), m_w(_w){}

  struct
  {
    float m_x;
    float m_y;
    float m_z;
    float m_w;
  };

};





#endif
