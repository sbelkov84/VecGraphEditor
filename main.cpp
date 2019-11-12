#include "primitives_impl.h"
#include "primitives_storage.h"
#include "document.h"
#include "mainform.h"
//------------------------------------------------------------------------
TScreen* Screen; // Just imitation of screen for drawing primitives
//------------------------------------------------------------------------

void TMainForm::NewPrimitiveButtonClick(TButton* Button)
{
  Document->Storage.CreatePrimitive((EPrimType) Button->Tag);
  Screen->IsDrawingMode = true;
}
//------------------------------------------------------------------------

void TMainForm::OnMouseLeftClick()
{
  /*
  if (Screen->IsDrawingMode == false && Storage.SelectedPrim == nullptr)
    1) if single primitive under mouse define Storage.SelectedPrim
    2) if several primitives under mouse show context menu with list of these primitives,
       select necessary primitive,
       define Storage.SelectedPrim
    3) if none of primitives under mouse show context menu

  else (Screen->IsDrawingMode == true)
    1) if (Storage.SelectedPrim->VecOfPoints.size() < Storage.SelectedPrim->MaxPointQty - 1)
  */
}
//------------------------------------------------------------------------

void TMainForm::OnMouseRightClick()
{
  if (Document->Storage.SelectedPrim != nullptr)
  {
    Document->Storage.SelectedPrim = nullptr;
  }
  else
  {
    // show context menu
  }
}
//------------------------------------------------------------------------

int main(int argc, char *argv[])
{
  UNUSED(argc);
  UNUSED(argv);
  TMainForm MainForm(Screen);
  //---
  return 0;
}
