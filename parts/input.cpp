//libraries//libraries//libraries//libraries//libraries//

#include <bits/stdc++.h> //base library with all what can will be used
#include <conio.h> //library to listen qeys (check button preses)
#include "storadge.cpp" //all data
#include <windows.h>

//libraries//libraries//libraries//libraries//libraries//

using namespace std;

//functoins//functoins//functoins//functoins//functoins//

void qey_preses_checker(){}

//functoins//functoins//functoins//functoins//functoins//

//test funcs//test funcs//test funcs//test funcs//test funcs//
int get_random_int(int min, int max)
{
    /*
    this function take in input 2 numbers (min - from, max - to)
    output is random int in range from min to max
    */
    int num = min + rand() % (max - min + 1);
    return num;
}

bool can_move(int left, int top, int right, int bottom)
{
    /*
    this function return fals if you cant move (in ded end) or true if all ok
    */
    if(left == 1 && top == 1 && right == 1 && bottom == 1) {return false;}
    return true;
}

int now_pos(int now_str, int now_column)
{
    /*calculates and return now position*/
    return now_str * num_column + now_column;
}

void made_random_map(int *field)
{
    int *cursor = field; // neded to write field

    for (int i = 0; i < num_str; i++) // prepare arr
    {
        for (int j = 0; j < num_column; j++)
        {
                if(i == 0 || j == 0) {*cursor = 1;}
                else if(i == 1 && j == 1) {*cursor = 1;}
                else if(i == num_str - 1 || j == num_column - 1) {*cursor = 1;}// 1 - wall, i was there, rand it later // 0 - never be there
                else {*cursor = 0;}
                cursor++;
        }
    }

    int now_str = 1;
    int now_column = 1;
    int direction;

    int gg = 0;

    vector <int> treck = {0}; // this vector save all way

    while (now_str != num_str - 2 || now_column != num_column - 2)
    {
        if(can_move(*(field + now_pos(now_str, now_column) - 1), *(field + now_pos(now_str, now_column) - num_column), *(field + now_pos(now_str, now_column) + 1), *(field + now_pos(now_str, now_column) + num_column)))
        {
            direction = get_random_int(0,3); // 0 - left // 1 - top // 2 - right // 3 - bottom //

            if(direction == 0 && *(field + now_pos(now_str, now_column) - 1) == 0) // 0 - left //
            {
                now_column--; // change position
                cursor = field + now_pos(now_str, now_column); // move cursor to now position
                *cursor = 1; // marking way
                treck.push_back(direction); // remeber way
            }

            else if(direction == 1 && *(field + now_pos(now_str, now_column) - num_column) == 0) // 1 - top //
            {
                now_str--; // change position
                cursor = field + now_pos(now_str, now_column); // move cursor to now position
                *cursor = 1; // marking way
                treck.push_back(direction); // remeber way
            }

            else if(direction == 2 && *(field + now_pos(now_str, now_column) + 1) == 0) // 2 - right //
            {
                now_column++; // change position
                cursor = field + now_pos(now_str, now_column); // move cursor to now position
                *cursor = 1; // marking way
                treck.push_back(direction); // remeber way
            }

            else if(direction == 3 && *(field + now_pos(now_str, now_column) + num_column) == 0) // 3 - bottom //
            {
                now_str++; // change position
                cursor = field + now_pos(now_str, now_column); // move cursor to now position
                *cursor = 1; // marking way
                treck.push_back(direction); // remeber way
            }
        }
        else
        {
            if(treck.back() == 0) // 0 - left //
            {
                now_column++;
                treck.pop_back();
            }

            else if(treck.back() == 1) // 1 - top //
            {
                now_str++;
                treck.pop_back();
            }

            else if(treck.back() == 2) // 2 - right //
            {
                now_column--;
                treck.pop_back();
            }

            else if(treck.back() == 3) // 3 - bottom //
            {
                now_str--;
                treck.pop_back();
            }
        }
    }
}

//test funcs//test funcs//test funcs//test funcs//test funcs//

//main//main//main//main//main//main//main//main//main//main//

int main()
{
    char ch;

    while(!_kbhit())
    {
        ch =_getch();

    }

    return 0;
}
//main//main//main//main//main//main//main//main//main//main//