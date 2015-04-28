#include "header/scene.h"


void FileLoad::fileLoader(const std::string &_fname, std::vector<std::vector<int> > &_gridCoor, const std::string &_typeDef)
{
  int lineCount = 0;


  std::fstream fileIn;
  fileIn.open(_fname.c_str(),std::ios::in);
  if (!fileIn.is_open())
  {
    std::cerr<<"could not open file "<<_fname<<"\n";
    exit(EXIT_FAILURE);
  }

  //boost parser separtor
  boost::char_separator<char> sep(" \t\r\n");

  std::string lineBuffer;
  while(!fileIn.eof())
  {
    getline(fileIn,lineBuffer,'\n');
    if (lineBuffer.size() !=0)
    {
      tokenizer tokens(lineBuffer,sep);
      tokenizer::iterator firstWord=tokens.begin();
      if (*firstWord == "#")
      {
        std::cerr<<"Found a comment \n";
      }
      else if (*firstWord==_typeDef)
      {
        fileParser(firstWord, lineCount, _gridCoor);
        lineCount++;
      }
    }
  }
}


void FileLoad::fileParser(tokenizer::iterator &_firstWord, int lineCount, std::vector<std::vector<int> > &_gridCoor)
{
  int max1 = 28;
  double init_value = 1;

  std::cout<<lineCount<<"ajghksjhdkjhalk\n";

  //now we have an empty 2D-matrix of size (0,0). Resizing it with one single command:
  _gridCoor.resize( max1 , std::vector<int>( max1 , init_value ) );

  ++_firstWord;

  //adds the coor data from the text file into the 2d vector
  for (int i=0; i<max1; i++)
  {
    std::cout<<_gridCoor[lineCount][i];
    _gridCoor[lineCount][i] = boost::lexical_cast<int>(*_firstWord++);
//    std::cout<<matrix[lineCount][i];

  }
}
