#include "header/scene.h"

void ObjLoader(const std::string &_objName,
               std::vector <Vec3> &_vec,
               std::vector <Vec3> &_norm,
               std::vector <Vec3> &_text,
               std::vector <int> &_index)
{
  typedef boost::tokenizer<boost::char_separator<char> >tokenizer;
  std::fstream fileIn;
  fileIn.open(_objName.c_str(),std::ios::in);
  if (!fileIn.is_open())
  {
    std::cerr<<"could not open file "<<_objName<<"\n";
    exit(EXIT_FAILURE);
  }

  //boost parser separtor
  boost::char_separator<char> sep(" /\t\r\n");

  std::string lineBuffer;
  while(!fileIn.eof())
  {
    getline(fileIn,lineBuffer,'\n');
    if (lineBuffer.size() !=0)
    {
      tokenizer tokens(lineBuffer,sep);
      tokenizer::iterator firstWord = tokens.begin();
      //checks for the vertex identifier in the OBJ file
      if (*firstWord=="v")
      {
        //this adds the vertex's to the vertex vector
        Vec3 vert(boost::lexical_cast<float>(*++firstWord),
                  boost::lexical_cast<float>(*++firstWord),
                  boost::lexical_cast<float>(*++firstWord));

        _vec.push_back(vert);
      }
      //checks for the vertex texture identifier in the OBJ file
      else if (*firstWord == "vt")
      {
        //add the vertex textures coor to the texture vector
        Vec3 text(boost::lexical_cast<float>(*++firstWord),
                  boost::lexical_cast<float>(*++firstWord));

        _text.push_back(text);
      }
      //checks for the vertex normals identifier in the OBJ file
      else if (*firstWord == "vn")
      {
        //add the vertec normals to the normals vector
        Vec3 norm(boost::lexical_cast<float>(*++firstWord),
                  boost::lexical_cast<float>(*++firstWord),
                  boost::lexical_cast<float>(*++firstWord));

        _norm.push_back(norm);
      }
      //checks for the index identifier in the OBJ file
      else if (*firstWord == "f")
      {
        //adds all the identifiers to build the model into a index vector
          _index.push_back(boost::lexical_cast<int>(*++firstWord));
          _index.push_back(boost::lexical_cast<int>(*++firstWord));
          _index.push_back(boost::lexical_cast<int>(*++firstWord));

          _index.push_back(boost::lexical_cast<int>(*++firstWord));
          _index.push_back(boost::lexical_cast<int>(*++firstWord));
          _index.push_back(boost::lexical_cast<int>(*++firstWord));

          _index.push_back(boost::lexical_cast<int>(*++firstWord));
          _index.push_back(boost::lexical_cast<int>(*++firstWord));
          _index.push_back(boost::lexical_cast<int>(*++firstWord));
      }
    }
  }
  //close the file once read is completed
  fileIn.close();
}
