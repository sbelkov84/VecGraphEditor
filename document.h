#ifndef DOCUMENT_H
#define DOCUMENT_H
//------------------------------------------------------------------------
#include "primitives_storage.h"
//------------------------------------------------------------------------

struct TDocument
{
  /*! Storage that includes data of primitives */
  TStorage Storage;

  /*! Constructor of TDocument */
  /*! TDocument() */
  TDocument();

  /*! Clears all primitives's data */
  /*! void ClearDocument() */
  void ClearDocument();

  /*! \brief Calls Save-function. Export all primitives data to file is set by FileName */
  /*! void Export(std::string FileName) */
  void Export(std::string FileName);

  /*! \brief Calls Load-function. Export all primitives data from file is set by FileName */
  /*! void Import(std::string FileName) */
  void Import(std::string FileName);
};
//------------------------------------------------------------------------
#endif // DOCUMENT_H
