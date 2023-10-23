#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    HWND hwnd = GetConsoleWindow();
    HDC hdc = GetDC(hwnd);

    system("title Flag of France");
    system("mode con cols=120 lines=30");

    int x = 50;
    int y = 50;

    int flagWidth = 700; 
    int flagHeight = flagWidth / 3 * 2;

    /////////////////////////////////////////////////////////////
    HBRUSH franceFlagBlue = CreateSolidBrush(RGB(0, 85, 164)); 
    HBRUSH franceFlagWhite = CreateSolidBrush(RGB(255, 255, 255)); 
    HBRUSH franceFlagRed = CreateSolidBrush(RGB(239, 65, 53)); 

    SelectObject(hdc, franceFlagBlue);
    Rectangle(hdc, x, y, x + flagWidth / 3, y + flagHeight);
    SelectObject(hdc, franceFlagWhite);
    Rectangle(hdc, x + flagWidth / 3, y, x + (flagWidth / 3) * 2, y + flagHeight);
    SelectObject(hdc, franceFlagRed);
    Rectangle(hdc, x + (flagWidth / 3) * 2, y, x + flagWidth, y + flagHeight);

    DeleteObject(franceFlagBlue);
    DeleteObject(franceFlagWhite);
    DeleteObject(franceFlagRed);

    /////////////////////////////////////////////////////////
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = false;
    cci.dwSize = 100;
    SetConsoleCursorInfo(h, &cci);

    Sleep(INFINITE);
}
