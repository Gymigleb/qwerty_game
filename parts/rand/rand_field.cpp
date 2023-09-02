#include <iostream> // defolt
#include <conio.h> // to read symbols from keyboard
#include<windows.h> // to change color
#include <stdlib.h> // to rand
#include <time.h> // to rand
#include "storadge.cpp"

using namespace std;

int get_random(int min, int max)
{
    int num = min + rand() % (max - min + 1);
    return num;
}

int main()
{
    //setlocale(LC_ALL, "ru"); for russian
    srand(time(NULL));

    // int const num_str = 21;
    // int const num_column = 33;
    // int const min_char = 33;
    // int const max_char = 122;
    // int const wall_char = 219;
    int field[num_str][num_column];

    for (int i = 0; i < num_str; i++)
    {
        for (int j = 0; j < num_column; j++)
        {
                if(i == 0 || j == 0) {field[i][j] = wall_char;}
                else if(i == num_str - 1 || j == num_column - 1) {field[i][j] = wall_char;}
                else {field[i][j] = get_random(min_char,max_char);}
        }
    }

    for (int i = 0; i < num_str; i++)
    {
        for (int j = 0; j < num_column; j++)
        {
            cout << field[i][j] << " ";
        }
    cout << endl;
    }
}