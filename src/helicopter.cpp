#include "header/helicopter.h"



void Heli::buildHeli(const std::vector<std::vector<int> > &m_matrix)
{
  //adds the texture to the heli
  textLoader("textures/HelicopterTextures/Helicopter_Crash_D.png", m_HeliTextID);
  GLuint hid = glGenLists(1);
  glNewList(hid, GL_COMPILE);

  glPushMatrix();
  for(int i = 0; i < (int)m_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)m_matrix[0].size(); ++j)
    {
      //checks to see there the heli is located in the map matrix
      if(m_matrix[i][j] == 10)
      {
        //moves to he location in map that tha heli i located
        glTranslatef((i)*4, -2.3, ((int)m_matrix[0].size() * 4) - (j)*4);
        //binds the texture
        glBindTexture(GL_TEXTURE_2D, m_HeliTextID);
        glBegin(GL_TRIANGLES);
          for (int a = 2; a < (int)m_Index.size(); a += 3)
          {
            //set the normals for the obj
            m_Normal[m_Index[a]-1].normalGL();
            //set the texture coor for the obj
            m_Texture[m_Index[a-1]-1].textureGL();
            //set the vertex for the obj
            m_Vertex[m_Index[a-2]-1].vertexGL();
          }
        glEnd();
      }
    }
  }

  glPopMatrix();
  //unbinds the texture
  glBindTexture(GL_TEXTURE_2D, 0);
  glEndList();
  //add to the display list
  m_displayList.push_back(hid);


}

void Heli::drawHeli()
{
  //calls the list to draw the heli
  glCallLists(m_displayList.size(), GL_UNSIGNED_INT, &m_displayList[0]);
}
