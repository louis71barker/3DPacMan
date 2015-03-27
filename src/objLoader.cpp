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
      if (*firstWord=="v")
      {
//        std::cout<<"aslkdjlkasjd"<<"\n";
        Vec3 vert(boost::lexical_cast<float>(*++firstWord),
                  boost::lexical_cast<float>(*++firstWord),
                  boost::lexical_cast<float>(*++firstWord));

        _vec.push_back(vert);
      }
      else if (*firstWord == "vt")
      {
//        std::cout<<"aslkdjlkasjdalkhsdkashdkh"<<"\n";
        Vec3 text(boost::lexical_cast<float>(*++firstWord),
                  boost::lexical_cast<float>(*++firstWord));

        _text.push_back(text);
      }
      else if (*firstWord == "vn")
      {
        Vec3 norm(boost::lexical_cast<float>(*++firstWord),
                  boost::lexical_cast<float>(*++firstWord),
                  boost::lexical_cast<float>(*++firstWord));

        _norm.push_back(norm);
      }
      else if (*firstWord == "f")
      {
          _index.push_back(boost::lexical_cast<int>(*++firstWord));
          ++(++firstWord);
          _index.push_back(boost::lexical_cast<int>(*++firstWord));
          ++(++firstWord);
          _index.push_back(boost::lexical_cast<int>(*++firstWord));
          ++(++firstWord);
      }
    }
  }
  fileIn.close();
}
