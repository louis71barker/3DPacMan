#include"header/scene.h"

//vec3 layout for normals
void Vec3::normalGL()
{
  glNormal3f(m_x, m_y, m_z);
}
//vec4 layout for normals
void Vec4::normalGL()
{
  glNormal3f(m_x, m_y, m_z);
}
//vec3 layout for vertex
void Vec3::vertexGL()
{
  glVertex3f(m_x, m_y, m_z);
}
//vec4 layout for vertex
void Vec4::vertexGL()
{
  glVertex3f(m_x, m_y, m_z);
}
//vec4 layout for texture
void Vec4::textureGL()
{
  glTexCoord2f(m_x, m_y);
}
//vec3 layout for texture
void Vec3::textureGL()
{
  glTexCoord2f(m_x, m_y);
}
