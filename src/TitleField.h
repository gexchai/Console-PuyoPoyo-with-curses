#ifndef __TITLE_FIELD__
#define __TITLE_FIELD__

#include "Field.h"

class TitleField : public Field {
  private:
    int width, height;
    char **titleBoard;
  public:
    TitleField(int x, int y);
    void writeTo(Screen *scr);
};

#endif
