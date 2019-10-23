//------------------------------------------------------------------------
#include "primitives_storage.h"
#include "primitives_impl.h"
//------------------------------------------------------------------------
#include <memory>
//------------------------------------------------------------------------

void TStorage::Clear()
{
  PrimPool.clear();
}
//------------------------------------------------------------------------

void TStorage::Load(std::ifstream* Stream)
{
  int PrimCount;
  *Stream >> PrimCount;
  std::unique_ptr<IPrimitive> IPrim(new IPrimitive());
  for (int i = 0; i < PrimCount; ++i)
  {
    IPrim->Load(Stream);
    PrimPool[i] = PrimitivesFactory(IPrim->GetType());
    PrimPool[i]->CopyIPrim(IPrim.get());
    PrimPool[i]->Load(Stream);
  }
}
//------------------------------------------------------------------------

void TStorage::Save(std::ofstream* Stream)
{
  *Stream << PrimPool.size();
  for (auto& It : PrimPool)
  {
    It.second->Save(Stream);
  }
}
//------------------------------------------------------------------------

std::shared_ptr<IPrimitive> TStorage::PrimitivesFactory(EPrimType Type)
{
  std::shared_ptr<IPrimitive> Result;
  //---
  switch (Type) {
    case eptPoint:
      Result = std::make_shared<TPrimitivePoint>();
      break;
    case eptCircle:
      Result = std::make_shared<TPrimitiveCircle>();
      break;
    case eptLine:
      Result = std::make_shared<TPrimitiveLine>();
      break;
    case eptMultiLine:
      Result = std::make_shared<TPrimitiveMultiLine>();
      break;
    default:
      break;
  }
  // Set pointer to storage to implement observer-pattern
  Result->SetStoragePtr(this);
  //---
  return Result;
}
//------------------------------------------------------------------------

void TStorage::CreatePrimitive(EPrimType Type)
{
  std::size_t NewId = PrimPool.size();
  PrimPool[NewId] = PrimitivesFactory(Type);
  SelectedPrim = PrimPool[NewId];
}
//------------------------------------------------------------------------

void TStorage::DeletePrimitive(IPrimitive* Prim)
{
  TRectangle RectOfDeleted = Prim->GetBorderRect();
  TPrimPtrsMap::iterator IterOfDeleted;
  for (auto It = PrimPool.begin(); It != PrimPool.end(); ++It)
  {
    IPrimitive* CurrentPrim = It->second.get();
    if (CurrentPrim != Prim && CurrentPrim->GetBorderRect().IsCrossing(&RectOfDeleted))
    {
      CurrentPrim->SetNoDrawed();
      CurrentPrim->Draw(Screen);
    }
    else if (CurrentPrim == Prim)
    {
      IterOfDeleted = It;
    }
  }
  //---
  PrimPool.erase(IterOfDeleted);
}
//------------------------------------------------------------------------

void TStorage::SetScreenPtr(TScreen* Screen)
{
  this->Screen = Screen;

}
//------------------------------------------------------------------------
