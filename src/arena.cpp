#include "header/arena.h"
#include "header/walls.h"
#include <iostream>
#include <cmath>
#include <SDL.h>
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>






#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif



void Arena::ground(std::vector<std::vector<int> > _matrix)
{

  textLoader("textures/GroundTextures/Diffuse.jpg", GroundTextID);
  GLuint id = glGenLists(1);
  glNewList(id, GL_COMPILE);
//  for(int i = 0; i < (int)_matrix.size(); ++i)
//  {
//    for(int j = 0; j < (int)_matrix[0].size(); ++j)
//    {
//      if(_matrix[i][j] <= 10)
//      {

        glPushMatrix();
        glTranslatef(0,-4,0);
//          glTranslatef((i)*CUBESIZE, -4, ((int)_matrix.size() *CUBESIZE) - (j) * CUBESIZE);
//          glColor3f(1,0,0);
//          glEnable(GL_TEXTURE_GEN_S);
//          glEnable(GL_TEXTURE_GEN_T);
//          gluQuadricTexture(id, GL_TRUE);
          glBindTexture(GL_TEXTURE_2D, GroundTextID);
//          glutSolidCube(CUBESIZE);
          glScalef(0.5,0.5,0.5);
          glBegin(GL_TRIANGLES);


            for (int a = 2; a < (int)m_Index.size(); a += 3)
            {
              m_Normal[m_Index[a]-1].normalGL();
              m_Texture[m_Index[a-1]-1].textureGL();
              m_Vertex[m_Index[a-2]-1].vertexGL();
            }
//            glDisable(GL_TEXTURE_GEN_T);
//            glDisable(GL_TEXTURE_GEN_S);
          glEnd();
        glPopMatrix();
//      }
//    }
//  }
  glBindTexture(GL_TEXTURE_2D, 0);
  glEndList();
  m_displayList.push_back(id);
}

//void Arena::sky()
//{
//  textLoader("textures/Skydome.jpg", SkydomeTextID);
//    GLuint sid = glGenLists(1);
//    glNewList(sid, GL_COMPILE);
//  //  for(int i = 0; i < (int)_matrix.size(); ++i)
//  //  {
//  //    for(int j = 0; j < (int)_matrix[0].size(); ++j)
//  //    {
//  //      if(_matrix[i][j] <= 10)
//  //      {

//          glPushMatrix();
//          glTranslatef(20,0,20);
//          glScalef(0.2,0.2,0.2);
//  //          glTranslatef((i)*CUBESIZE, -4, ((int)_matrix.size() *CUBESIZE) - (j) * CUBESIZE);
//  //          glColor3f(1,0,0);
//  //          glEnable(GL_TEXTURE_GEN_S);
//  //          glEnable(GL_TEXTURE_GEN_T);
//  //          gluQuadricTexture(id, GL_TRUE);
//            glBindTexture(GL_TEXTURE_2D, GroundTextID);
//  //          glutSolidCube(CUBESIZE);
//            glBegin(GL_TRIANGLES);

//              for (int a = 0; a < (int)m_Index.size(); a++)
//              {
//                m_SkyNormal[m_Index[a+2]-1].normalGL();
//                m_SkyTexture[m_Index[a+1]-1].textureGL();
//                m_SkyVertex[m_Index[a]-1].vertexGL();
//              }
//  //            glDisable(GL_TEXTURE_GEN_T);
//  //            glDisable(GL_TEXTURE_GEN_S);
//            glEnd();
//          glPopMatrix();
//  //      }
//  //    }
//  //  }
//    glBindTexture(GL_TEXTURE_2D, 0);
//    glEndList();
//    m_SkydisplayList.push_back(sid);
//}

void Arena::drawArena(std::vector<std::vector<int> > _matrix)
{
  glCallLists(m_displayList.size(), GL_UNSIGNED_INT, &m_displayList[0]);


//  sky();

}
