//------------------------------------------------------------------------
#include "primitive_interface.h"
#include "primitives_storage.h"
//------------------------------------------------------------------------

void TPoint::Save(std::ofstream *Stream)
{
  *Stream << X;
  *Stream << Y;
  *Stream << IsDrawed;
}
//------------------------------------------------------------------------

void TPoint::Load(std::ifstream *Stream)
{
  *Stream >> X;
  *Stream >> Y;
  *Stream >> IsDrawed;
}
//------------------------------------------------------------------------

bool TPoint::IsVisible()
{
  return true;
}
//------------------------------------------------------------------------

void TPoint::Draw(TScreen *Screen)
{
  UNUSED(Screen);
  IsDrawed = true;
}
//------------------------------------------------------------------------

TPoint& TPoint::operator =(const TPoint& Rhs)
{
  X = Rhs.X;
  Y = Rhs.Y;
  //---
  return *this;
}
//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------

bool TRectangle::IsCrossing(const TRectangle* Other)
{
  UNUSED(Other);
  // Check if some of corner points of Other is inside THIS rectangle
  return false; // Just for compile
}
//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------

IPrimitive& IPrimitive::operator =(IPrimitive& Src)
{
  SetType(Src.GetType());
  SetVersion(Src.GetVersion());
  SetMaxPointQty(Src.GetMaxPointQty());
  //---
  const std::vector<TPoint>* SrcVec = Src.GetPointVec();
  SetPointVec(SrcVec);
  return *this;
}
//------------------------------------------------------------------------

bool IPrimitive::CanAddPoint()
{
  return VecOfPoints.size() < MaxPointQty;
}
//------------------------------------------------------------------------

void IPrimitive::Save(std::ofstream* Stream)
{
  *Stream << Version;
  *Stream << (char) Type;
  *Stream << Color;
  *Stream << MaxPointQty;
  //---
  for (TPoint& It : VecOfPoints)
  {
    It.Save(Stream);
  }
}
//------------------------------------------------------------------------

void IPrimitive::Load(std::ifstream* Stream)
{
  *Stream >> Version;
  char Tmp;
  *Stream >> Tmp;
  Type = (EPrimType) Tmp;
  *Stream >> Color;
  *Stream >> MaxPointQty;
  //---
  VecOfPoints.clear();
  for (std::size_t i = 0; i < MaxPointQty; ++i)
  {
    TPoint Point;
    Point.Load(Stream);
    VecOfPoints.push_back(Point);
  }
}
//------------------------------------------------------------------------

bool IPrimitive::IsVisible()
{
  bool Res = false;
  for (TPoint& It : VecOfPoints)
  {
    if (It.IsVisible())
    {
      Res = true;
    }
  }
  //---
  return Res;
}
//------------------------------------------------------------------------

void IPrimitive::Draw(TScreen *Screen)
{
  if (!this->IsVisible())
    return;
  //---
  UNUSED(Screen);
  /* Draw primitive on Screen by LineTo, for example.
   * Drawing is making in cycle by VecOfPoints. For each point checks IsDrawed && IsVisible,
   * if !IsDrawed && IsVisible - draw Point and LineTo Point */
}
//------------------------------------------------------------------------

void IPrimitive::Delete(TScreen *Screen)
{
  UNUSED(Screen);
  SetColor(Screen->BackGroundColor);
  Draw(Screen);
}
//------------------------------------------------------------------------

void IPrimitive::SetType(EPrimType Type)
{
  this->Type = Type;
}
//------------------------------------------------------------------------

EPrimType IPrimitive::GetType()
{
  return Type;
}
//------------------------------------------------------------------------

void IPrimitive::SetVersion(char Version)
{
  this->Version = Version;
}
//------------------------------------------------------------------------

char IPrimitive::GetVersion()
{
  return Version;
}
//------------------------------------------------------------------------

void IPrimitive::SetMaxPointQty(int Qty)
{
  this->MaxPointQty = Qty;
}
//------------------------------------------------------------------------

int IPrimitive::GetMaxPointQty()
{
  return MaxPointQty;
}
//------------------------------------------------------------------------

void IPrimitive::SetPointVec(const std::vector<TPoint>* SrcVec)
{
  this->VecOfPoints.resize(SrcVec->size());
  std::copy(SrcVec->begin(), SrcVec->end(), this->VecOfPoints.begin());
}
//------------------------------------------------------------------------

const std::vector<TPoint>* IPrimitive::GetPointVec()
{
  return &VecOfPoints;
}
//------------------------------------------------------------------------

void IPrimitive::SetColor(int Color)
{
  this->Color = Color;
}
//------------------------------------------------------------------------

int IPrimitive::GetColor()
{
  return this->Color;
}
//------------------------------------------------------------------------

void IPrimitive::CopyIPrim(IPrimitive *IPrim)
{
  *this = (*IPrim);
}
//------------------------------------------------------------------------

TRectangle IPrimitive::GetBorderRect()
{
  TRectangle Result;
  //---
  if (!this->VecOfPoints.empty() && this->IsVisible())
  {
    Result.LeftTop = this->VecOfPoints.at(0);
    Result.RightBottom = this->VecOfPoints.at(0);
  }
  //---
  return Result;
}
//------------------------------------------------------------------------

void IPrimitive::SetStoragePtr(TStorage* Storage)
{
  this->Storage = Storage;
}
//------------------------------------------------------------------------

void IPrimitive::SetNoDrawed()
{
  for (auto& It : VecOfPoints)
  {
    It.IsDrawed = false;
  }
}
//------------------------------------------------------------------------
