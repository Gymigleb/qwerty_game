#include <bits/stdc++.h>
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
    srand(time(NULL)); // for random starting count time

    // int const num_str = 21;
    // int const num_column = 33;
    // int const min_char = 33;
    // int const max_char = 122;
    // int const wall_char = 219;
    int field[num_str][num_column]; // game feild now it is empty

    for (int i = 0; i < num_str; i++) // the string enumeration cycle
    {
        for (int j = 0; j < num_column; j++) // the column enumeration cycle
        {
                if(i == 0 || j == 0) {field[i][j] = wall_char;} // create left and top walls
                else if(i == num_str - 1 || j == num_column - 1) {field[i][j] = wall_char;}// create right and bottom walls
                else {field[i][j] = get_random(min_char,max_char);} // create random simbols in ASCII
        }
    }

// this part of code displays the field on the screen // this part of code displays the field on the screen //

    for (int i = 0; i < num_str; i++) // the string enumeration cycle
    {
        for (int j = 0; j < num_column; j++) // the string enumeration cycle
        {
            cout << char(field[i][j]) << " "; // simpl output
        }
    cout << endl;
    }
// this part of code displays the field on the screen // this part of code displays the field on the screen //
}