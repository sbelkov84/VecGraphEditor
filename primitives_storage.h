#ifndef PRIMITIVES_STORAGE_H
#define PRIMITIVES_STORAGE_H
//------------------------------------------------------------------------
#include "primitive_interface.h"
#include "screen.h"
//------------------------------------------------------------------------
#include <map>
#include <string>
#include <memory>
//------------------------------------------------------------------------

/*! \brief Storage for graphic primitives is used in current variant */
struct TStorage
{
  using TPrimPtrsMap = std::map<std::size_t, std::shared_ptr<IPrimitive>>;

  /*! \brief Pool of pointers on primitives objects */
  TPrimPtrsMap PrimPool;

  /*! \brief Pointer to primitive was selected by user's GUI */
  std::shared_ptr<IPrimitive> SelectedPrim;

  /*! \brief Clear PrimPool */
  /*! void Clear() */
  void Clear();

  /*! \brief Creates new primitive. It is called from GUI */
  /*! void CreatePrimitive(EPrimType Type) */
  void CreatePrimitive(EPrimType Type);

  /*! \brief Deletes primitive. Redraw all primitives for those bordering rectangles are crossing with
   * a bordering rectangle of deleted primitive */
  /*! void DeletePrimitive(IPrimitive* Prim) */
  void DeletePrimitive(IPrimitive* Prim);

  /*! \brief Load all primitives from stream corresponding some file */
  /*! void Load(std::ifstream Stream) */
  void Load(std::ifstream* Stream);

  /*! \brief Save all primitives to stream corresponding some file */
  /*! void Save(std::ofstream Stream) */
  void Save(std::ofstream* Stream);

  /*! \brief Sets Screen-pointer for this storage */
  /*! void SetScreenPtr(TScreen* Screen) */
  void SetScreenPtr(TScreen* Screen);

private:

  /*! \brief Pointer on screen on which is drawed all primitives */
  TScreen* Screen;

  /*! \brief Creates a new primitive by type */
  /*! std::shared_ptr<IPrimitive> CreatePrimitive(EPrimType) */
  std::shared_ptr<IPrimitive> PrimitivesFactory(EPrimType Type);
};
//------------------------------------------------------------------------
#endif // PRIMITIVES_STORAGE_H
