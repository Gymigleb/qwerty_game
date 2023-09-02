#include <iostream> // defolt
#include <conio.h> // to read symbols from keyboard
#include<windows.h> // to change color
#include <stdlib.h> // to rand
#include <time.h> // to rand

#define str 21
#define colomn 33 

using namespace std;

bool rcheck(int field[str][colomn], int i, int j)
{
    if (field[i][j] == field[i][j + 2] && field[i][j - 2]) { return false; }

    if (field[i][j] == field[i - 1][j - 1] && field[i + 1][j + 1]) { return false; }

    if (field[i][j] == field[i - 1][j + 1] && field[i + 1][j - 1]) { return false; }

    if (field[i][j] == field[i - 2][j] && field[i + 2][j]) { return false; }
    return true;
}