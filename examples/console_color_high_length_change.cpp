#include <iostream>
#include <Windows.h>
#include <wincon.h>
using namespace std;
 
void set_color(int text, int bg)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

void set_size(int height, int length)
{
    HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = {height, length};
    SetConsoleScreenBufferSize(hWnd, bufferSize);
}

// void SetWindowSize(COORD newsize)
// {
//     CONSOLE_SCREEN_BUFFER_INFOEX consolesize;

//     CONSOLE_SCREEN_BUFFER_INFO

//     consolesize.cbSize=sizeof(consolesize);

//     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//     GetConsoleScreenBufferInfoEx(hConsole,&consolesize);

//     COORD c;
//     c.X = 80;
//     c.Y = 40;
//     consolesize.dwSize = c;

//     consolesize.srWindow.Left = 0;
//     consolesize.srWindow.Right = 80;
//     consolesize.srWindow.Top = 0;
//     consolesize.srWindow.Bottom = 40;

//     SetConsoleScreenBufferInfoEx(hConsole, &consolesize);
// }
 
int main()
{
    HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = {16, 32};
    SetConsoleScreenBufferSize(hWnd, bufferSize);
    HWND hWindowConsole = GetConsoleWindow();
    RECT r;
    GetWindowRect(hWindowConsole, &r); //stores the console's current dimensions
    MoveWindow(hWindowConsole, r.left, r.top, 161, 170, TRUE);
    
    while (true)
    {
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                set_color(i, j);

                // if (i < 10) {cout << "0" << i << " ";}
                // else {cout << i << " ";}

                // if (j < 10) {cout << "0" << j << " ";}
                // else {cout << j << "// ";}

                cout << "0";
            }
            cout << endl;
        }
        set_color(0, 0);
        cin.get();
    }
    return 0;
}
/*
Name number
black 0
ultramarin 1
green 2
blue 3
red 4
purple 5
orange 6
light grey 7
grey 8
light blue 9
light green 10
turquoise 11
light red 12
pink 13
yellow 14
white 15
*/