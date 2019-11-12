#ifndef SCREEN_H
#define SCREEN_H
//------------------------------------------------------------------------

/*! \brief Just an "imitation" of canvas/screen on which we will draw */
/*! TScreen */
class TScreen
{
public:

  /*! \brief Constructor */
  /*! TScreen() */
  TScreen() {}

  /*! \brief If IsDrawingMode, we draw figure. Else work with buttons and other GUI */
  bool IsDrawingMode;

  /*! \brief Stores background color */
  int BackGroundColor;
};
//------------------------------------------------------------------------
#endif // SCREEN_H
