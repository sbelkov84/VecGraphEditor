//------------------------------------------------------------------------
#include "document.h"
//------------------------------------------------------------------------

TDocument::TDocument()
{
  ClearDocument();
}
//------------------------------------------------------------------------

void TDocument::ClearDocument()
{
  Storage.Clear();
}
//------------------------------------------------------------------------

void TDocument::Export(std::string FileName)
{
  std::ofstream OutputFile;
  OutputFile.open(FileName);
  //---
  if (OutputFile.is_open())
    Storage.Save(&OutputFile);
  //---
  OutputFile.close();
}
//------------------------------------------------------------------------

void TDocument::Import(std::string FileName)
{
  std::ifstream InputFile;
  InputFile.open(FileName);
  //---
  if (InputFile.is_open())
    Storage.Load(&InputFile);
  //---
  InputFile.close();
}
//------------------------------------------------------------------------
