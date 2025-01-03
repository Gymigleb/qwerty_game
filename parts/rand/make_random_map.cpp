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

//debagging////debagging////debagging////debagging////debagging//

string int_to_direction(int x)
{
    if (x == 0) {return "left";}
    if (x == 1) {return "top";}
    if (x == 2) {return "right";}
    if (x == 3) {return "bottom";}
    return "-1";
}

void debagging_out_treck(vector <int> treck)
{
    cout << "debagging_out_treck: ";

    while (treck.size() > 0)
    {
        cout << int_to_direction(treck.back()) << " ";
        treck.pop_back();
    }
    cout << endl;
}

void debagging_out(int *field, string comment, bool output_type, string tabs)
{
    /*
    output_tipe:
        false - string (numbers)
        true - char
    */
    cout << comment << endl;
    int *cursor = field;
    if (output_type) // char
    {
        for (int i = 0; i < num_str; i++)
        {
            for (int j = 0; j < num_column; j++)
            {
                cout << char(*cursor) << tabs;
                cursor++;
            }
        cout << endl;
        }
    }
    else // string (numbers)
    {
        for (int i = 0; i < num_str; i++)
        {
            for (int j = 0; j < num_column; j++)
            {
                cout << *cursor << tabs;
                cursor++;
            }
        cout << endl;
        }    
    }
}

//debagging////debagging////debagging////debagging////debagging//

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

int calculate_now_pos(int now_str, int now_column)
{
    /*calculates and return now position*/
    return now_str * num_column + now_column;
}

bool can_move(int *field, int now_str, int now_column)
{
    /*
    this function return false if you cant move (in ded end) or true if all ok
    */

    int *now_pos = (field + calculate_now_pos(now_str, now_column));

    int left_simbol = *(now_pos - 1);
    int top_simbol = *(now_pos - num_column);
    int right_simbol = *(now_pos + 1);
    int bottom_simbol = *(now_pos + num_column);

    if (left_simbol == 1 && top_simbol == 1 && right_simbol == 1 && bottom_simbol == 1) {return false;}
    else {return true;}
}

bool is_random_good(int *field)
{
    /*
    this function return true if simbols around you not same with your simbol
    */

    int *cursor = field;

    for (int now_str = 0; now_str < num_str; now_str++)
    {
        for (int now_column = 0; now_column < num_column; now_column++)
        {
            cursor = field + calculate_now_pos(now_str, now_column);
            int left_simbol = *(cursor - 1);
            int top_simbol = *(cursor - num_column);
            int right_simbol = *(cursor + 1);
            int bottom_simbol = *(cursor - num_column);

            if (*cursor != wall_char && (left_simbol == *cursor || top_simbol == *cursor || right_simbol == *cursor || bottom_simbol == *cursor)) {return false;}

            if (left_simbol != wall_char && (left_simbol == top_simbol || left_simbol == right_simbol || left_simbol == bottom_simbol)) {return false;}
            if (top_simbol != wall_char && (top_simbol == left_simbol || top_simbol == right_simbol || top_simbol == bottom_simbol)) {return false;}
        }
    }
    
    return true; 
}

void make_random_simbols(int *field)
{
    /*
    This function take to input pointer on start of map. Have no return, but change map, change 1 to random simbol, 0 to wall_char
    */

    int *cursor; // neded to write field   

    for (int now_str = 0; now_str < num_str; now_str++) // basic map prepare
    {
        for (int now_column = 0; now_column < num_column; now_column++) // basic map prepare
        {
            cursor = field + calculate_now_pos(now_str, now_column); // move cursor to now position

            if (now_str == 0 || now_column == 0 || now_str == num_str - 1 || now_column == num_column - 1) {*cursor = wall_char;} // set walls
            else
            {
                if (*cursor == 0) {*cursor = wall_char;} // set walls
                if (*cursor == 1)
                {
                    *cursor = get_random_int(min_char, max_char);
                }
            }
        }
    }

    // for (int now_str = 0; now_str < num_str; now_str++) // basic map prepare
    // {
    //     for (int now_column = 0; now_column < num_column; now_column++) // basic map prepare
    //     {
    //         cursor = field + calculate_now_pos(now_str, now_column); // move cursor to now position
            
    //         if(*cursor != wall_char)
    //         {
    //             while (!is_random_good(field))
    //             {
    //                 *cursor = get_random_int(min_char, max_char);
    //                 debagging_out(field, "roll", true, "");
    //             }
    //         }
    //     }
    // }
}

void make_random_map(int *field)
{
    /*This function take in input pointer on start of map. Have no return, but change map, add to it treck (1) and fill another cells by 0*/

    int *cursor = field; // neded to write field

    for (int i = 0; i < num_str; i++) // prepare arr
    {
        for (int j = 0; j < num_column; j++)
        {
                if(i == 0 || j == 0) {*cursor = 1;}
                else if(i == 1 && j == 1) {*cursor = 1;}
                else if(i == num_str - 1 || j == num_column - 1) {*cursor = 1;} // 1 - wall, i was there, rand it later
                else {*cursor = 0;} // 0 - never be there
                cursor++;
        }
    }

    int now_str = 1;
    int now_column = 1;
    int direction;

    int gg = 0;

    vector <int> treck = {0}; // this vector save all way

    while (!(now_str == num_str - 2 && now_column == num_column - 2))
    {
        if(can_move(field, now_str, now_column))
        {
            direction = get_random_int(0,3); // 0 - left // 1 - top // 2 - right // 3 - bottom //

            if(direction == 0 && *(field + calculate_now_pos(now_str, now_column) - 1) == 0) // 0 - left //
            {
                now_column--; // change position
                cursor = field + calculate_now_pos(now_str, now_column); // move cursor to now position
                *cursor = 1; // marking way
                treck.push_back(direction); // remeber way
            }

            else if(direction == 1 && *(field + calculate_now_pos(now_str, now_column) - num_column) == 0) // 1 - top //
            {
                now_str--; // change position
                cursor = field + calculate_now_pos(now_str, now_column); // move cursor to now position
                *cursor = 1; // marking way
                treck.push_back(direction); // remeber way
            }

            else if(direction == 2 && *(field + calculate_now_pos(now_str, now_column) + 1) == 0) // 2 - right //
            {
                now_column++; // change position
                cursor = field + calculate_now_pos(now_str, now_column); // move cursor to now position
                *cursor = 1; // marking way
                treck.push_back(direction); // remeber way
            }

            else if(direction == 3 && *(field + calculate_now_pos(now_str, now_column) + num_column) == 0) // 3 - bottom //
            {
                now_str++; // change position
                cursor = field + calculate_now_pos(now_str, now_column); // move cursor to now position
                *cursor = 1; // marking way
                treck.push_back(direction); // remeber way
            }
        }
        else
        {
            if(treck.back() == 0) // 0 - left //
            {
                now_column++;
            }

            else if(treck.back() == 1) // 1 - top //
            {
                now_str++;
            }

            else if(treck.back() == 2) // 2 - right //
            {
                now_column--;
            }

            else if(treck.back() == 3) // 3 - bottom //
            {
                now_str--;
            }
            treck.pop_back();
        }
    }

    make_random_simbols(field);
}

//functoins//functoins//functoins//functoins//functoins//

//main//main//main//main//main//main//main//main//main//main//

int main()
{
    srand(time(NULL)); // create random seed
    int map [num_str][num_column];

    make_random_map(&map[0][0]);
    debagging_out(&map[0][0], "bool", false, " ");
    debagging_out(&map[0][0], "numbers", false, " ");
    debagging_out(&map[0][0], "ready map", true, "");
   
    // int map [num_str][num_column] = {
    // {0, 1, 0},
    // {1, 0, 1},
    // {0, 1, 0}
    // };
    // cout << is_random_good(&map[0][0]) << endl;
}

//main//main//main//main//main//main//main//main//main//main//