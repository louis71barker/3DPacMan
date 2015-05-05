#include "walls.h"
#include <GL/glut.h>







#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif

Walls::Walls()
{
  FileLoad fl;
  //load the map file into the game
  fl.fileLoader("src/MapCoor.txt",m_matrix,"MAP1");
  //load the OBJ file
  ObjLoader("obj/NewTriBush.obj",m_Vertex,m_Normal,m_Texture,m_Index);
  //build the maze walls for the trees
  initMaze(m_matrix);
}

void Walls::draw()
{
  //draw the trees from the dlist
  glCallLists(m_dList.size(), GL_UNSIGNED_INT, &m_dList[0]);
}

void Walls::initMaze(std::vector<std::vector<int> > &m_matrix)
{
  //loads in the wall texure
  textLoader("textures/Hedge.jpg", m_WallTextID);

  GLuint id = glGenLists(1);
  glNewList(id, GL_COMPILE);
  glPushMatrix();

  for(int i = 0; i < (int)m_matrix.size(); ++i)
  {
    for(int j = 0; j < (int)m_matrix[0].size(); ++j)
    {
      //checks to find the wall value in the map matrix
      if(m_matrix[i][j] == 1)
      {
        //binds the texure
        glBindTexture(GL_TEXTURE_2D, m_WallTextID);
        letsDraw(i, j, m_matrix);
        //unbind the texture
        glBindTexture(GL_TEXTURE_2D, 0);
      }
    }
  }
  glPopMatrix();
  glEndList();
  //add to the dlist
  m_dList.push_back(id);

}

void Walls::letsDraw(const int _x, const int _y, const std::vector<std::vector<int> > &m_matrix)
{
    glPushMatrix();
      //move the tree to the allocated location
      glTranslatef((_x)*CUBESIZE, -1.5, ((int)m_matrix[0].size() * CUBESIZE) - (_y)*CUBESIZE+0.5);
      drawCube();
    glPopMatrix();
}

void Walls::drawCube()
{
  glPushMatrix();
    glScalef(0.022,0.02,0.02);
    glBegin(GL_TRIANGLES);
    {
      for (int a = 2; a < (int)m_Index.size(); a += 3)
      {
        //set the normals for the obj
        m_Normal[m_Index[a]-1].normalGL();
        //set the texture coor for the obj
        m_Texture[m_Index[a-1]-1].textureGL();
        //set the vertex for the obj
        m_Vertex[m_Index[a-2]-1].vertexGL();
      }
    }
    glEnd();
  glPopMatrix();
}





