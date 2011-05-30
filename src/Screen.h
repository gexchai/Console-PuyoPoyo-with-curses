#ifndef __SCREEN__
#define __SCREEN__

class Screen {
private:
    int width, height;
    char **screen;
    char blankChar;
public:
    Screen(int width, int height);
    bool writePixel(int y, int x, char c);
    bool writeLinePixels(int y, int x, const char *c);
    void flash();
    void initScreen();
    void finalizeScreen();
    void refreshScreen();
    void eraseScreen();

    void setBlankChar(char b);
};

#endif
