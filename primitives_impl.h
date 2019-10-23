#ifndef PRIMITIVES_IMPL_H
#define PRIMITIVES_IMPL_H
//------------------------------------------------------------------------
#include "primitive_interface.h"
//------------------------------------------------------------------------

/*! \brief Implementation of Point graphic primitive */
class TPrimitivePoint : public IPrimitive
{
public:

  /*! \brief Constructor, which just sets type and point quantity for primitive */
  /*! TPrimitivePoint() */
  TPrimitivePoint() {SetType(eptPoint); SetMaxPointQty(1);}

  /*! \brief Constructor is needed to import data in primitive from file. See 'void TStorage::Load(std::ifstream* Stream)' */
  /*! TPrimitivePoint(IPrimitive* IPrim) */
  //TPrimitivePoint(IPrimitive* IPrim);
};
//------------------------------------------------------------------------

/*! \brief Implementation of Circle graphic primitive */
class TPrimitiveCircle : public IPrimitive
{
private:
  /*! \brief Radius of circle */
  unsigned int Radius;

public:

  /*! \brief Constructor, which just sets type and point quantity for primitive */
  /*! TPrimitiveCircle() */
  TPrimitiveCircle() {SetType(eptCircle); SetMaxPointQty(1);}

  /*! \brief Sets radius of circle */
  /*! void SetRadius(unsigned int Radius) */
  void SetRadius(unsigned int Radius);

  /*! \brief Returns radius */
  /*! unsigned int GetRadius() */
  unsigned int GetRadius();

  /*! \brief Circle needs own Draw-function */
  /*! void Draw(TScreen* Screen) */
  void Draw(TScreen* Screen) override;

  /*! \brief Overridden variant of GetBorderRect for circle */
  /*! TRectangle GetBorderRect() */
  TRectangle GetBorderRect() override;
};
//------------------------------------------------------------------------

/*! \brief Implementation of Line graphic primitive */
class TPrimitiveLine : public IPrimitive
{
public:

  /*! \brief Constructor, which just sets type and point quantity for primitive */
  /*! TPrimitiveLine() */
  TPrimitiveLine() {SetType(eptPoint); SetMaxPointQty(2);}
};
//------------------------------------------------------------------------

/*! \brief Implementation of MultiLine graphic primitive */
class TPrimitiveMultiLine : public IPrimitive
{
public:

  /*! \brief Constructor, which just sets type and point quantity for primitive.
   *  SetMaxPoint(-1) means that we can have many points */
  /*! TPrimitiveMultiLine() */
  TPrimitiveMultiLine() {SetType(eptPoint); SetMaxPointQty(-1);}
};
//------------------------------------------------------------------------

#endif // PRIMITIVE_IMPL_H
