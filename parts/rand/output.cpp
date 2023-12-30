#include <bits/stdc++.h>
#include "storadge.cpp"

using namespace std;

void output(int field[num_str][num_column])
{
    for (int i = 0; i < num_str; i++)
    {
        for (int j = 0; j < num_column; j++)
        {
            cout << (char) field[i][j];
            // cout << field[i][j] << " ";
        }
    cout << endl;
    }
}