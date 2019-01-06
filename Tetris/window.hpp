#ifndef WINDOW_HPP
#define _WIN32_WINNT 0x0502
#include <windows.h>

class Window
{
public:
    void makeWindow(int const width, int const height);
private:
    HWND hwnd = GetConsoleWindow();
};
#endif // WINDOW_HPP
