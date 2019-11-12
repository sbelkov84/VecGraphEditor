#ifndef PRIMITIVES_H
#define PRIMITIVES_H
//------------------------------------------------------------------------
#include "screen.h"
//------------------------------------------------------------------------
#include <fstream>
#include <vector>
//------------------------------------------------------------------------
#define UNUSED(arg) (void)(arg)
//------------------------------------------------------------------------
struct TStorage;

/*! \brief Define type of graphic primitive */
/*! EPrimType */
enum EPrimType
{
  eptPoint
 ,eptCircle
 ,eptLine
 ,eptMultiLine
};
//------------------------------------------------------------------------

/*! \brief Point structure */
/*! TPoint */
struct TPoint
{
  /*! \brief Point's coordinates on screen */
  int X;
  int Y;

  /*! \brief Operator = */
  /*! TPoint& operator =(const TPoint& Src) */
  TPoint& operator =(const TPoint& Rhs);

  /*! \brief Contains sign that indicate if we already had drawed this point */
  bool IsDrawed;

  /*! \brief Saving data in stream */
  /*! void Save(std::ofstream*) */
  void Save(std::ofstream* Stream);

  /*! \brief Loading data from stream */
  /*! void Load(std::ifstream*) */
  void Load(std::ifstream* Stream);

  /*! \brief Check if point visible (in ranges of screen) */
  /*! bool IsVisible() */
  bool IsVisible();

  /*! \brief Draw point */
  /*! void Draw(TScreen* Screen) */
  void Draw(TScreen* Screen);
};
//------------------------------------------------------------------------

/*! \brief Rectangle structure */
/*! TRectangle */
struct TRectangle
{
  /*! \brief Left-top point's coordinates on screen */
  TPoint LeftTop;

  /*! \brief Right-bottom point's coordinates on screen */
  TPoint RightBottom;

  /*! \brief Constructor */
  /*! TRectangle() */
  TRectangle()
  {
    LeftTop.X = -1;
    LeftTop.Y = -1;
    RightBottom.X = -1;
    RightBottom.Y = -1;
  }

  /*! \brief Checks if rectangle is for empty figure */
  /*! bool IsEmpty() */
  bool IsEmpty()
  {
    return (LeftTop.X < 0 && LeftTop.Y < 0 && RightBottom.X < 0 && RightBottom.Y < 0);
  }

  /*! \brief Checks if this rectangle is crossing with Other rectangle */
  /*! bool IsCrossing(const TRectangle* Other) */
  bool IsCrossing(const TRectangle* Other);
};
//------------------------------------------------------------------------

/*! \brief Interface parent class for all graphic primitives */
class IPrimitive
{
private:
  /*! \brief Type of graphic primitive */
  /*! EPrimType Type */
  EPrimType Type;

  /*! \brief Version of class. Increases if we will add some new features to primitive.
   * Needed for Save/Load functions. Now (in the beginnig of development) for all
   * objects Version = 0 */
  /*! char Version */
  char Version;

  /*! \brief Point quantity of various primitives */
  /*! int PointQty */
  std::size_t MaxPointQty;

  /*! \brief Vector of primitive's points */
  /*! std::vector<TPoint> VecOfPoints */
  std::vector<TPoint> VecOfPoints;

  /*! \brief Stores color value */
  /*! int Color */
  int Color;

  /*! \brief Pointer to Storage of primitives */
  /*! TStorage* Storage */
  TStorage* Storage;

public:

  /*! \brief Constructor */
  /*! IPrimitive() */
  IPrimitive() {};

  /*! \brief Assign operator */
  /*! IPrimitive& operator =(IPrimitive& Src) */
  IPrimitive& operator =(IPrimitive& Src);

  /*! \brief Destructor */
  /*! virtual ~IPrimitive() */
  virtual ~IPrimitive() {};

  /*! \brief Saving data in stream */
  /*! void Save(std::ofstream*) */
  virtual void Save(std::ofstream* Stream);

  /*! \brief Loading data from stream */
  /*! void Load(std::ifstream*) */
  virtual void Load(std::ifstream* Stream);

  /*! \brief Check if we can add a new point to primitive.
   * For example, point or circle contains only one point */
  /*! bool CanAddPoint() */
  bool CanAddPoint();

  /*! \brief Adding point to graphic primitive */
  /*! void AddPoint(TPoint*) */
  void AddPoint(TPoint* Point);

  /*! \brief Check if graphic primitive is visible (in ranges of screen) */
  /*! bool IsVisible() */
  virtual bool IsVisible();

  /*! \brief Draws primitive on screen */
  /*! void Draw(TScreen* Screen) */
  virtual void Draw(TScreen* Screen);

  /*! \brief Deletes primitive from screen. In this function we have to check figures  */
  /*! void Delete(TScreen* Screen) */
  virtual void Delete(TScreen* Screen);

  /*! \brief Sets the type of graphic primitive */
  /*! void SetType(EPrimType Type) */
  void SetType(EPrimType Type);

  /*! \brief Returns the type of graphic primitive */
  /*! EPrimType GetType() */
  EPrimType GetType();

  /*! \brief Sets version number of struct */
  /*! void SetVersion(char Value) */
  void SetVersion(char Value);

  /*! \brief Returns points quantity of graphic primitive */
  /*! char GetVersion() */
  char GetVersion();

  /*! \brief Sets quantity of points was included in primitive */
  /*! void SetMaxPointQty(int Qty) */
  void SetMaxPointQty(int Qty);

  /*! \brief Returns quantity of points was included in primitive */
  /*! int GetMaxPointQty() */
  int GetMaxPointQty();

  /*! \brief In fact, copies elements of SrcVec to VecOfPoints */
  /*! void SetPointVec(const std::vector<TPoint>* SrcVec) */
  void SetPointVec(const std::vector<TPoint>* SrcVec);

  /*! \brief Sets color of primitive */
  /*! void SetColor(int Color) */
  void SetColor(int Color);

  /*! \brief Returns color of primitive */
  /*! int GetColor() */
  int GetColor();

  /*! \brief Returns pointer to vector of primitive's points */
  /*! const std::vector<TPoint>* GetPointVec() */
  const std::vector<TPoint>* GetPointVec();

  /*! \brief Copies IPrim members to this */
  /*! void CopyIPrim(IPrimitive *IPrim) */
  void CopyIPrim(IPrimitive *IPrim);

  /*! \brief Returns bordering rectangle. Needs if we check crossing of primitives in
   * cases: 1) select one of primitives those are stacking on screen
   *        2) delete one of primitives and necessary to redraw stacking primitives */
  /*! virtual TRectangle GetBorderRect() */
  virtual TRectangle GetBorderRect();

  /*! \brief Sets pointer to Storage. Necessary to implement observer-pattern */
  /*! void SetStoragePtr(const TStorage* Storage) */
  void SetStoragePtr(TStorage* Storage);

  /*! \brief Sets for all points of primitive parametr IsDrawed = false */
  /*! void SetNoDrawed() */
  void SetNoDrawed();
};
//------------------------------------------------------------------------

#endif // PRIMITIVES_H
