#include <bits/stdc++.h> //base library with all what can will be used

using namespace std;

int const num_str = 4;
int const num_column = 4;
int const min_char = 33;
int const max_char = 122;
int const wall_char = 219;

int main()
{
    int arr[num_str][num_column];

    int *cursor_start = &arr[0][0]; // neded to write field
    int *cursor_end = cursor_start + num_str * num_column - 1;

    int i = 0, j = 0;

    // for (int x = 0; cursor_start <= cursor_end; cursor_start++, x++) // prepare arr
    // {
    //     if(i == 0 || j == 0) {*cursor_start = 1; cout << "a";}
    //     if(i == num_str - 1 || j == num_column - 1) {*cursor_start = 1; cout << "b";}// 1 - wall, i was there, rand it later // 0 - never be there
    //     // else if(i == num_str - 1 || j == num_column - 1) {*cursor_start = 1;}
    //     else {*cursor_start = 0;}
    //     j++;
    //     if(j % (num_column - 1) == 0) {i++; j = 0;}
    //     cout << "|";
    // }

     for (int i = 0; i < num_str; i++)
    {
        for (int j = 0; j < num_column; j++)
        {
            if(i == 0 || j == 0) {*cursor_start = 1; cout << "a";}
            else if(i == num_str - 1 || j == num_column - 1) {*cursor_start = 1; cout << "b";}// 1 - wall, i was there, rand it later // 0 - never be there
            else {*cursor_start = 0;}
            cursor_start++;
            cout << "|";
        }
    }

cout << endl;
    for (int i = 0; i < num_str; i++)
    {
        for (int j = 0; j < num_column; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}