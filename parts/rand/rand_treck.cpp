#include <bits/stdc++.h>
#include "random.cpp"
#include "output.cpp"

using namespace std;

bool can_move(int left, int top, int right, int bottom)
{
    /*this func check where a you. it return false if you in ded end, else return true*/

    if(left != 0 && top != 0 && right != 0 && bottom != 0) {return false;}
    return true;
}

void field_prepare(int field[num_str][num_column])
{
    for (int i = 0; i < num_str; i++)
    {
        for (int j = 0; j < num_column; j++)
        {
            if(i == 0 || j == 0) {field[i][j] = wall_char;} // create left and top walls
            else if(i == num_str - 1 || j == num_column - 1) {field[i][j] = wall_char;}// create right and bottom walls
            else {field[i][j] = 0;}
        }
    }
}

void rand_treck(int num_str, int num_column, int field[9][9])
{
    /*this func make random treck (using 1) from left top corner(1,1) to right bottom corner(n-1,n-1) alwaus different*/

    field_prepare(field);

    int direction; //direction of movement
    int pos_str = 1;
    int pos_column  = 1;
    bool gg = true; // It's temporary, i hope
    field[1][1] = 1; // this arr fild only // 0 - wall /or/ 1 - i have to rand this cell
    vector <int> treck = {0}; // arr of derictions

    while (pos_str != num_str - 2 || pos_column != num_column - 2) // we make treck while we aren't in right bottom corner(n-1,n-1)
    {
        gg = true;

        if(can_move(field[pos_str + 1][pos_column], field[pos_str - 1][pos_column], field[pos_str][pos_column + 1], field[pos_str][pos_column - 1]))
        {
            /*if we can move ve move in random deriction*/
            while (gg)
            {
                direction = random(0,3);

                if(direction == 0 && field[pos_str][pos_column - 1] == 0)
                {
                    pos_column--;
                    field[pos_str][pos_column] = 1;
                    treck.push_back(direction);
                    gg = false;
                    break;
                }

                else if(direction == 1 && field[pos_str - 1][pos_column] == 0)
                {
                    pos_str--;
                    field[pos_str][pos_column] = 1;
                    treck.push_back(direction);
                    gg = false;
                    break;
                }

                else if(direction == 2 && field[pos_str][pos_column + 1] == 0)
                {
                    pos_column++;
                    field[pos_str][pos_column] = 1;
                    treck.push_back(direction);
                    gg = false;
                    break;
                }

                else if(direction == 3 && field[pos_str + 1][pos_column] == 0)
                {
                    pos_str++;
                    field[pos_str][pos_column] = 1;
                    treck.push_back(direction);
                    gg = false;
                    break;
                }
            }
        }
        else
        {
            if(treck.back() == 0)
            {
                pos_column++;
                treck.pop_back();
            }

            else if(treck.back() == 1)
            {
                pos_str++;
                treck.pop_back();
            }

            else if(treck.back() == 2)
            {
                pos_column--;
                treck.pop_back();
            }

            else if(treck.back() == 3)
            {
                pos_str--;
                treck.pop_back();
            }
        }
    }
}

// int main()
// {
//     srand(time(NULL));

//     int field[num_str][num_column];

//     rand_treck(num_str, num_column, field);
//     output(field);
// }