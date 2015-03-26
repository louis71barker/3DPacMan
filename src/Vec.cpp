#include"header/scene.h"


void Vec3::normalGL()
{
  glNormal3f(m_x, m_y, m_z);
}

void Vec4::normalGL()
{
  glNormal3f(m_x, m_y, m_z);
}

void Vec3::vertexGL()
{
  glVertex3f(m_x, m_y, m_z);
}

void Vec4::vertexGL()
{
  glVertex3f(m_x, m_y, m_z);
}
