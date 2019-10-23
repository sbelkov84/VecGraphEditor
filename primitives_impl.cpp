//------------------------------------------------------------------------
#include "primitives_impl.h"
//------------------------------------------------------------------------
#include <algorithm>
//------------------------------------------------------------------------

/*TPrimitivePoint::TPrimitivePoint(IPrimitive *IPrim)
{
  IPrimitive::operator =(*IPrim);
}*/
//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------

void TPrimitiveCircle::SetRadius(unsigned int Radius)
{
  this->Radius = Radius;
}
//------------------------------------------------------------------------

unsigned int TPrimitiveCircle::GetRadius()
{
  return Radius;
}
//------------------------------------------------------------------------

void TPrimitiveCircle::Draw(TScreen *Screen)
{
  // Draws circle of radius = Radius wiht center in VecOfPoints[0]
  UNUSED(Screen);
}
//------------------------------------------------------------------------

TRectangle TPrimitiveCircle::GetBorderRect()
{
  TRectangle Result;
  TPoint Center = this->GetPointVec()->at(0);
  Result.LeftTop.X = Center.X - GetRadius();
  Result.LeftTop.Y = Center.Y - GetRadius();
  Result.RightBottom.X = Center.X + GetRadius();
  Result.RightBottom.Y = Center.Y + GetRadius();
  //---
  return Result;
}
//------------------------------------------------------------------------
