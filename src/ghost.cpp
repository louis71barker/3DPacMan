#include "header/ghost.h"


void Ghost::updater()
{
  glCallLists(m_displayList.size(), GL_UNSIGNED_INT, &m_displayList[0]);
}

void Ghost::drawGhosts(std::vector<std::vector<int> > _matrix)
{

  //load the texture here and bind inside the list bellow!!!!!! :)

    GLuint id = glGenLists(1);
    glNewList(id, GL_COMPILE);
    glPushMatrix();
      glScalef(0.2,0.2,0.2);
//      glTranslatef(0,2,0);
      glBegin(GL_TRIANGLES);
      for(int i = 0; i < (int)_matrix.size(); ++i)
      {
        for(int j = 0; j < (int)_matrix[0].size(); ++j)
        {
          if(_matrix[i][j] == 4)
          {
            std::cout<<"spawn Ghost please\n";
            glTranslatef((i)*4, -4, ((int)_matrix[0].size() * 4) - (j)*4);
            for (int a = 0; a < (int)m_Index.size(); a += 3)
            {
//              m_Normal[m_Index[a+2]-1].normalGL();
              m_Vertex[m_Index[a]-1].vertexGL();
            }
            std::cout<<"spawned Ghost thank you\n";
          }
        }
      }


      glEnd();
    glPopMatrix();
    m_displayList.push_back(id);
}






