//description//description//description//description//
/*
this file neded to test function fix_random_simbols
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

void fix_random_simbols(int *field)
{
    /*
    this function saolutions problem with not unique simbols near one cell
    a b c     a b c
    d x y  => d x y
    z c z     z c m
    */

    int *cursor = field;

    // int mask [num_str][num_column];
    // int *masks_cudsor = &mask[0][0];

    // for (int now_str = 0; now_str < num_str; now_str++) // fill mask by zeros
    // {
    //     for (int now_column = 0; now_column < num_column; now_column++)
    //     {
    //         mask [now_str][now_column] = 0;
    //     }
    // }

    for (int now_str = 1; now_str < num_str; now_str++)
    {
        for (int now_column = 1; now_column < num_column; now_column++)
        {
            cursor = field + calculate_now_pos(now_str, now_column);

            int *left_simbol = cursor - 1;
            int *top_simbol = cursor - num_column;
            int *right_simbol = cursor + 1;
            int *bottom_simbol = cursor + num_column;

            while (true)
            {
                if (*left_simbol == *top_simbol && *left_simbol != wall_char)
                {
                    *top_simbol = get_random_int(min_char, max_char);
                    now_str = 1;
                    now_column = 1;
                }
                else if (*left_simbol == *right_simbol && *left_simbol != wall_char)
                {
                    *right_simbol= get_random_int(min_char, max_char);
                    now_str = 1;
                    now_column = 1;
                }
                else if (*left_simbol == *bottom_simbol && *left_simbol != wall_char)
                {
                    *bottom_simbol = get_random_int(min_char, max_char);
                    now_str = 1;
                    now_column = 1;
                }
                else if (*right_simbol == *top_simbol && *right_simbol != wall_char)
                {
                    *top_simbol = get_random_int(min_char, max_char);
                    now_str = 1;
                    now_column = 1;
                }
                else if (*right_simbol == *bottom_simbol && *right_simbol != wall_char)
                {
                    *bottom_simbol = get_random_int(min_char, max_char);
                    now_str = 1;
                    now_column = 1;
                }
                else if (*bottom_simbol == *top_simbol && *bottom_simbol != wall_char)
                {
                    *top_simbol = get_random_int(min_char, max_char);
                    now_str = 1;
                    now_column = 1;
                }
                else {break;}
            }

        }
    }
}

//functoins//functoins//functoins//functoins//functoins//

//main//main//main//main//main//main//main//main//main//main//

int main()
{
    srand(time(NULL)); // create random seed

    int map [num_str][num_column] = {
    {219, 219, 219, 219, 219},
    {219, 0, 1, 2, 219},
    {219, 1, 4, 5, 219},
    {219, 6, 7, 8, 219},
    {219, 219, 219, 219, 219},
    };
    fix_random_simbols(&map[0][0]);
    debagging_out(&map[0][0], "", 0, " ");
}

//main//main//main//main//main//main//main//main//main//main//