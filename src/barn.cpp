#include "header/barn.h"



void Barn::buildBarn()
{
  textLoader("textures/BarnTextures/Farmhouse_Diffuse_Map.jpg", BarnTextID);
  GLuint bid = glGenLists(1);
  glNewList(bid, GL_COMPILE);

  glPushMatrix();
//    glScalef(0.2,0.2,0.2);
    glBindTexture(GL_TEXTURE_2D, BarnTextID);
    glBegin(GL_TRIANGLES);
      for (int a = 2; a < (int)m_Index.size(); a += 3)
      {
        m_Normal[m_Index[a]-1].normalGL();
        m_Texture[m_Index[a-1]-1].textureGL();
        m_Vertex[m_Index[a-2]-1].vertexGL();
      }
    glEnd();
  glPopMatrix();
  glBindTexture(GL_TEXTURE_2D, 0);
  glEndList();
  std::cout<<"build the barn \n";
  m_displayList.push_back(bid);

}

void Barn::drawBarn()
{
  glCallLists(m_displayList.size(), GL_UNSIGNED_INT, &m_displayList[0]);
}
