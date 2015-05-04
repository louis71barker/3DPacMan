#ifndef ARENA_H__
#define ARENA_H__

#include <vector>
#include "walls.h"
#include "audio.h"





class Arena
{
public:

  void drawArena(const std::vector<std::vector<int> > _matrix);

  //ground vectors
  std::vector<Vec3> m_Vertex;
  std::vector<Vec3> m_Normal;
  std::vector<Vec3> m_Texture;
  std::vector<int> m_Index;
  std::vector<GLuint> m_displayList;
  std::vector <GLuint> m_daList;

  Mix_Chunk *a_ambMusic;



  Arena(const std::vector<std::vector<int> > _matrix)
  {
    Audio au;
    ObjLoader("obj/OBJ_Ground.obj",m_Vertex,m_Normal,m_Texture,m_Index);
    au.loadSoundChunk("sounds/ambMusic.wav", &a_ambMusic);

    Mix_VolumeChunk(a_ambMusic, MIX_MAX_VOLUME * 0.6);

    Mix_PlayChannel(-1, a_ambMusic, -1);
  }
  ~Arena()
  {
    //ground vectors
    m_Vertex.clear();
    std::vector<Vec3>().swap (m_Vertex);
    m_Normal.clear();
    std::vector<Vec3>().swap (m_Normal);
    m_Texture.clear();
    std::vector<Vec3>().swap (m_Texture);
    m_displayList.clear();
    std::vector<GLuint>().swap (m_displayList);
    m_Index.clear();
    std::vector<int>().swap (m_Index);
    m_daList.clear();
    std::vector<GLuint>().swap (m_daList);

    Mix_FreeChunk(a_ambMusic);
    a_ambMusic = NULL;
    Mix_Quit();


  }
  void ground(const std::vector<std::vector<int> > _matrix);







private:
  GLuint GroundTextID;




};






#endif
