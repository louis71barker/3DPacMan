#ifndef VEC4_H__
#define VEC4_H__

#include "Mat4.h"


class Vec4
{

public:

  Vec4(float _x=0.0f,float _y=0.0f,float _z=0.0f,float _w=0.0f) :
    m_x(_x), m_y(_y), m_z(_z), m_w(_w){}


  //copy constructor, takes in the class construct and copies it
  Vec4(const Vec4 &_rhs);
  //use the current Vec4 as a call to glColour4fv
  void colourGL();
  //return the cross product of this vector with _r
  Vec4 cross(const Vec4 &_r) const;
  //calculate the dot product for this vector with _r
  float dot(const Vec4 &_r);
  //calculate the length of this vector
  float length() const;
  //calculate the lenght squared
  float lengthSquared() const;
  //set the current Vec4 as the call to glNormal3fv(x,y,z)
  void normalGL();
  //normalize vector
  void normalize();
  //allows use to overload the multiplcation so we can multiply matix across different classes ( V1 * Mat4)
  Vec4 operator *(const Mat4 &_rhs);
  //* a scaler
  Vec4 operator *(float _rhs);
  //V1 *= 2,
  void operator *=(float _rhs);
  //V1+V2
  Vec4 operator +(const Vec4 &_rhs);
  // V1+=V2
  void operator +=(const Vec4 &rhs);
  //V1-V2
  Vec4 operator -(const Vec4 &_rhs);
  // V1-=V2
  void operator -=(const Vec4 &rhs);
  //equality V1==V2 (bool)
  bool operator ==(const Vec4 &rhs);
  //subscript operator Vec4 v; v[0]=1.0; // set x;
  float & operator [] (int i);
  //set component
  void set(float _x, float _y, float _z, float _w=1.0f);
  //call glvertex3f with component
  void vertexGL();



  union
  {
    struct
    {
      float m_x;
      float m_y;
      float m_z;
      float m_w;
    };
    float m_openGL[4];

  };

private:

};


#endif
