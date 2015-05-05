#include "header/barn.h"



void Barn::buildBarn(const std::vector<std::vector<int> > &m_matrix)
{
  //adds the texture the the barn
  textLoader("textures/BarnTextures/Farmhouse_Diffuse_Map.jpg", m_BarnTextID);
  GLuint bid = glGenLists(1);
  glNewList(bid, GL_COMPILE);

  glPushMatrix();
  for(int i = 0; i < (int)m_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)m_matrix[0].size(); ++j)
    {
      //check to find the location in the matrix of the barn
      if(m_matrix[i][j] == 9)
      {
        //moves to the location of the barn
        glTranslatef((i)*4, -2.3, ((int)m_matrix[0].size() * 4) - (j)*4);
        //scales down
        glScalef(0.5,0.5,0.5);
        //rotate to file the map better
        glRotatef(-90.0,0.0,1.0,0.0);
        //bind the texture to the obj
        glBindTexture(GL_TEXTURE_2D, m_BarnTextID);
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
        glBindTexture(GL_TEXTURE_2D, 0);
      }
    }
  }

  glPopMatrix();
  //unbind the texture
  glBindTexture(GL_TEXTURE_2D, 0);
  glEndList();
  //add the barn to the display list
  m_displayList.push_back(bid);


}

void Barn::drawBarn()
{
  //draw the barn from the display list
  glCallLists(m_displayList.size(), GL_UNSIGNED_INT, &m_displayList[0]);
}
