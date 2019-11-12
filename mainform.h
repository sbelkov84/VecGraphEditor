#ifndef MAINFORM_H
#define MAINFORM_H
//------------------------------------------------------------------------
#include "document.h"
//------------------------------------------------------------------------
#include <memory>
//------------------------------------------------------------------------

/*! \brief Just an "imitation" of class for GUI buttons: "create point", "create circle", etc. */
/*! TButton */
class TButton
{
public:
  /*! \brief Parameter that is used to store a primitive's type */
  int Tag;
};
//------------------------------------------------------------------------

class TMainForm
{
private:

  /*! Document that contains primitives data */
  std::unique_ptr<TDocument> Document;

  /*! Screen for drawing primitives */
  TScreen* Screen;

  /*! \brief Sets screen for drawing primitives */
  /*! void SetScreen(TScreen* Screen) */
  void SetScreen(TScreen* Screen)
  {
    this->Screen = Screen;
  }

public:

  /*! \brief Explicitly constructs a mainform with document pointer */
  /*! TMainForm(TDocument* Document) */
  explicit TMainForm(TScreen* Screen)
  {
    SetScreen(Screen);
  }

  /*! \brief Creates new document */
  /*! void CreateDocument() */
  void CreateDocument()
  {
    Document = std::make_unique<TDocument>();
  }

  /*! \brief Export data from Document in file */
  /*! void Export() */
  void Export()
  {
    std::string FileName;
    // Open GUI dialog to specify FileName
    Document->Export(FileName);
  }

  /*! \brief Import data from file to Document */
  /*! void Import() */
  void Import()
  {
    Document->ClearDocument();
    std::string FileName;
    // Open GUI dialog to specify FileName
    Document->Import(FileName);
  }

  /*! \brief General function that is called for all button, which creates primitives */
  /*! void NewPrimitiveButtonClick(TButton* Button) */
  void NewPrimitiveButtonClick(TButton* Button);

  /*! \brief Reaction of mainform on right mouse button click */
  /*! void OnMouseRightClick() */
  void OnMouseRightClick();

  /*! \brief Reaction of mainform on right mouse button click */
  /*! void OnMouseLeftClick() */
  void OnMouseLeftClick();
};
//------------------------------------------------------------------------
#endif // MAINFORM_H
