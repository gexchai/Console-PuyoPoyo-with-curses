#ifndef __SCORE_FIELD__
#define __SCORE_FIELD__

#include "Field.h"

class ScoreField : public Field {
  private:
    int width, height;
    int score;
  public:
    ScoreField();
    void addScore(int score);
    void writeTo(Screen *scr);
};

#endif
