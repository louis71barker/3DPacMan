#include "header/scene.h"


void FileLoad::fileLoader(const std::string &_fname, std::vector<std::vector<int> > &_gridCoor, const std::string &_typeDef)
{
  //line count to increment down the matrix each loop
  int lineCount = 0;

  //simple file loader
  std::fstream fileIn;
  fileIn.open(_fname.c_str(),std::ios::in);
  //error checker
  if (!fileIn.is_open())
  {
    std::cerr<<"could not open file "<<_fname<<"\n";
    exit(EXIT_FAILURE);
  }

  //boost parser separtors
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
  //max matrix size
  int max1 = 28;
  //dephault value for unallocated areas of the matrix
  double init_value = 1;


  //resize the matrix to the max size and add the dephault values to then all
  _gridCoor.resize( max1 , std::vector<int>( max1 , init_value ) );

  ++_firstWord;

  //adds the coor data from the text file into the 2d vector
  for (int i=0; i<max1; i++)
  {
    //add the value to the matrix in the correct location
    _gridCoor[lineCount][i] = boost::lexical_cast<int>(*_firstWord++);

  }
}
