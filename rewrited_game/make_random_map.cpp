//description//description//description//description//
/*
This file make arr with random map.
Somethilg like that:
#########    '#' is wall
#as##zxh#    letters is field where game is takes place
##d##c#x#    this letters have to be placet in random order,
#jkgsd#m#    but same letters have not be near
#########
*/
//description//description//description//description//



//libraries//libraries//libraries//libraries//libraries//

#include <bits/stdc++.h> //base library with all what can will be used
#include "storadge.cpp" //all data

//libraries//libraries//libraries//libraries//libraries//



//functoins//functoins//functoins//functoins//functoins//

int get_random_int(int min, int max)
{
    /*
    this fynction take in input 2 numbers (min - from, max - to)
    output is random int in range from min to max
    */
    int num = min + rand() % (max - min + 1);
    return num;
}

void made_arr(int num_str, int num_column, int field[9][9])
{
    for (int i = 0; i < num_str; i++)
    {
        for (int j = 0; j < num_column; j++)
        {
                if(i == 0 || j == 0) {field[i][j] = wall_char;}
                else if(i == num_str - 1 || j == num_column - 1) {field[i][j] = wall_char;}
                else {field[i][j] = get_random_int(min_char,max_char);}
        }
    }
}

//functoins//functoins//functoins//functoins//functoins//