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
//  fileReader(_fname);
  gridCounter = 0;
  gridXPos = -15;
  gridZPos = 15;
  fl.fileLoader("src/MapCoor.txt",matrix,"MAP1");
  ObjLoader("obj/NewTriBush.obj",m_Vertex,m_Normal,m_Texture,m_Index);
  initMaze(matrix);
//  draw();
}

void Walls::draw()
{
  glCallLists(dList.size(), GL_UNSIGNED_INT, &dList[0]);
}

void Walls::initMaze(std::vector<std::vector<int> > _matrix)
{
  //loads in the wall texure
  textLoader("textures/Hedge.jpg", WallTextID);

  GLuint id = glGenLists(1);
  glNewList(id, GL_COMPILE);
  glPushMatrix();

  for(int i = 0; i < (int)matrix.size(); ++i)
  {
    for(int j = 0; j < (int)matrix[0].size(); ++j)
    {
      if(matrix[i][j] == 1)
      {

        glBindTexture(GL_TEXTURE_2D, WallTextID);
        letsDraw(i, j, _matrix);

        glBindTexture(GL_TEXTURE_2D, 0);
        //std::cout<<matrix[i][j]<<"  asdgakjd     "<<j<<"\n";
      }
    }
  }
  glPopMatrix();

  glEndList();
  dList.push_back(id);

}

void Walls::letsDraw(int _x, int _y, const std::vector<std::vector<int> > _matrix)
{
    glPushMatrix();
      glTranslatef((_x)*CUBESIZE, -1.5, ((int)matrix[0].size() * CUBESIZE) - (_y)*CUBESIZE);

      drawCube(_matrix);
    glPopMatrix();
}

void Walls::drawCube(const std::vector<std::vector<int> > _matrix)
{



  glPushMatrix();
    glScalef(0.02,0.02,0.016);
    glBegin(GL_TRIANGLES);
    for(int i = 0; i < (int)_matrix.size(); ++i)
    {
      for(int j = 0; j < (int)_matrix[0].size(); ++j)
      {
        if(_matrix[i][j] == 3)
        {
          for (int a = 2; a < (int)m_Index.size(); a += 3)
          {
            m_Normal[m_Index[a]-1].normalGL();
            m_Texture[m_Index[a-1]-1].textureGL();
            m_Vertex[m_Index[a-2]-1].vertexGL();
          }
        }
      }
    }
    glEnd();
  glPopMatrix();


}





