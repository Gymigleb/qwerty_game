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
    this function take in input 2 numbers (min - from, max - to)
    output is random int in range from min to max
    */
    int num = min + rand() % (max - min + 1);
    return num;
}

bool can_move(int left, int top, int right, int bottom)
{
    if(left == 1 && top == 1 && right == 1 && bottom == 1) {return false;}
    return true;
}

int now_pos(int now_str, int now_column)
{
    /*calculates and return now position*/
    return now_str * (num_column - 1) + now_column;
}

void debagging_out(int *field, string comment)
{
    cout << comment << endl;
    int *cursor = field;
    for (int i = 0; i < num_str; i++)
    {
        for (int j = 0; j < num_column; j++)
        {
            cout << *cursor << " ";
            cursor++;
        }
    cout << endl;
    }
}

void made_random_map(int *field)
{
    // int field[num_str][num_column];

    int *cursor = field; // neded to write field

    for (int i = 0; i < num_str; i++) // prepare arr
    {
        for (int j = 0; j < num_column; j++)
        {
                if(i == 0 || j == 0) {*cursor = 1;}
                else if(i == 1 || j == 1) {*cursor = 1;}
                else if(i == num_str - 1 || j == num_column - 1) {*cursor = 1;}// 1 - wall, i was there, rand it later // 0 - never be there
                else {*cursor = 0;}
                cursor++;
        }
    }

    int now_str = 1;
    int now_column = 1;
    int direction;

    vector <int> treck = {0}; //this vector save all way

    while (now_str != num_str - 2 || now_column != num_column - 2)
    {
        if(can_move(*(field + now_pos(now_str, now_column) - 1), *(field + now_pos(now_str, now_column) - (num_column - 1)), *(field + now_pos(now_str, now_column) + 1), *(field + now_pos(now_str, now_column) + (num_column - 1))))
        {
            cout << "if ";
            direction = get_random_int(0,3); // 0 - left // 1 - top // 2 - right // 3 - bottom

            if(direction == 0 && *(field + now_pos(now_str, now_column) - 1) == 0) // 0 - left
            {
                debagging_out(field, "if0|");
                int *cursor = field; // neded to write field
                now_column--; // change position
                cursor + (now_pos(now_str, now_column)); // move cursor to now position
                *cursor = 1; // marking way
                treck.push_back(direction); // remeber way
                cursor = new int;
                delete cursor; // clear memory
                cursor = NULL;
                debagging_out(field, "|if0");
            }

            else if(direction == 1 && *(field + now_pos(now_str, now_column) - (num_column - 1)) == 0) // 1 - top
            {
                debagging_out(field, "if1|");
                int *cursor = field; // neded to write field
                now_str--; // change position
                cursor + (now_pos(now_str, now_column)); // move cursor to now position
                *cursor = 1; // marking way
                treck.push_back(direction); // remeber way
                cursor = new int;
                delete cursor; // clear memory
                cursor = NULL;
                debagging_out(field, "|if1");
            }

            else if(direction == 2 && *(field + now_pos(now_str, now_column) + 1) == 0) // 2 - right
            {
                debagging_out(field, "if2|");
                int *cursor = field; // neded to write field
                now_column++; // change position
                cursor + (now_pos(now_str, now_column)); // move cursor to now position
                *cursor = 1; // marking way
                treck.push_back(direction); // remeber way
                cursor = new int;
                delete cursor; // clear memory
                cursor = NULL;
                debagging_out(field, "|if2");
            }

            else if(direction == 3 && *(field + now_pos(now_str, now_column) + (num_column - 1)) == 0)// 3 - bottom
            {
                debagging_out(field, "if3|");
                int *cursor = field; // neded to write field
                now_str++; // change position
                cursor + (now_pos(now_str, now_column)); // move cursor to now position
                *cursor = 1; // marking way
                treck.push_back(direction); // remeber way
                cursor = new int;
                delete cursor; // clear memory
                cursor = NULL;
                debagging_out(field, "|if3");
            }
        }
        else
        {
            if(treck.back() == 0)
            {
                now_column++;
                treck.pop_back();
            }

            else if(treck.back() == 1)
            {
                now_str++;
                treck.pop_back();
            }

            else if(treck.back() == 2)
            {
                now_column--;
                treck.pop_back();
            }

            else if(treck.back() == 3)
            {
                now_str--;
                treck.pop_back();
            }
        }
    }
}

//functoins//functoins//functoins//functoins//functoins//

//main//main//main//main//main//main//main//main//main//main//

int main()
{
    int map [num_str][num_column];

    made_random_map(&map[0][0]);

    for (int i = 0; i < num_str; i++)
    {
        for (int j = 0; j < num_column; j++)
        {
            cout << map[i][j] << " ";
        }
    cout << endl;
    }
}

//main//main//main//main//main//main//main//main//main//main//