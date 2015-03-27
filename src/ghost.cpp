#include "header/ghost.h"


void Ghost::updater()
{
  glCallLists(m_displayList.size(), GL_UNSIGNED_INT, &m_displayList[0]);
}

void Ghost::drawGhosts()
{

  //load the texture here and bind inside the list bellow!!!!!! :)

    GLuint id = glGenLists(1);
    glNewList(id, GL_COMPILE);
    glPushMatrix();
      glScalef(0.2,0.2,0.2);
      glTranslatef(0,2,0);
      glBegin(GL_TRIANGLES);


        for (int i = 0; i < (int)m_Index.size(); i ++)
        {
          m_Normal[m_Index[i+2]-1].normalGL();
          m_Vertex[m_Index[i]-1].vertexGL();
        }


      glEnd();
    glPopMatrix();
    m_displayList.push_back(id);
}






