#include "window.hpp"

void Window::makeWindow(int const width, int const height)
{
    if( hwnd != NULL )
    {
        RECT windowDimensions;
        const HWND hDesktop = GetDesktopWindow();
        GetWindowRect(hDesktop, &windowDimensions);
        int posX = ((windowDimensions.right/2)-(width/2));
        int posY = ((windowDimensions.bottom/2)-(height/2));
        MoveWindow(hwnd,posX,posY,width,height,TRUE);
    }
}

