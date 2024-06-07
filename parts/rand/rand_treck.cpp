#include <iostream> // defolt
#include <conio.h> // to read symbols from keyboard
#include<windows.h> // to change color
#include <stdlib.h> // to rand
#include <time.h> // to rand
#include <vector>
#include "storadge.cpp"

using namespace std;

int get_random(int min, int max) // random in range from 0 to 3
{
    int num = min + rand() % (max - min + 1); // 0 - left // 1 - top // 2 - right // 3 - bottom //
    return num;
}

bool can_move(int left, int top, int right, int bottom) //this func return false if you in ded end
{
    if(left == 1 && top == 1 && right == 1 && bottom == 1) {return false;}
    return true;
}

void rand_treck(int num_str, int num_column, int field[9][9])
{
    /*
    this func make 1 treck from left top corner(1,1) to right bottom corner(n-1,n-1) alwaus different
    */
    int direction; //direction of movement
    int pos_str = 1;
    int pos_column  = 1;
    bool gg = true;
    field[1][1] = 1; // this arr fild only // 0 - wall /or/ 1 - i was there, rand it
    vector <int> treck = {0}; // arr of derictions

    while (pos_str != num_str - 2 || pos_column != num_column - 2) // we make treck while we aren't in right bottom corner(n-1,n-1)
    {
        gg = true;

        if(can_move(field[pos_str + 1][pos_column], field[pos_str - 1][pos_column], field[pos_str][pos_column + 1], field[pos_str][pos_column - 1]))
        {
            while (gg)
            {
                direction = get_random(0,3);

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
                // field[pos_str][pos_column] = 0;
                pos_column++;
                treck.pop_back();
            }

            else if(treck.back() == 1)
            {
                // field[pos_str][pos_column] = 0;
                pos_str++;
                treck.pop_back();
            }

            else if(treck.back() == 2)
            {
                // field[pos_str][pos_column] = 0;
                pos_column--;
                treck.pop_back();
            }

            else if(treck.back() == 3)
            {
                // field[pos_str][pos_column] = 0;
                pos_str--;
                treck.pop_back();
            }
        }
    }
}


int main()
{
    srand(time(NULL));

//this part of code from file what named "rand_field.cpp"//

    int field[num_str][num_column];

    for (int i = 0; i < num_str; i++)
    {
        for (int j = 0; j < num_column; j++)
        {
                if(i == 0 || j == 0) {field[i][j] = 1;}
                else if(i == num_str - 1 || j == num_column - 1) {field[i][j] = 1;}
                else {field[i][j] = 0;}
        }
    }
    
//this part of code from file what named "rand_field.cpp"//

    rand_treck(num_str, num_column, field);

    cout << endl;

    for (int i = 0; i < num_str; i++)
    {
        for (int j = 0; j < num_column; j++)
        {
            cout << field[i][j] << " ";
        }
    cout << endl;
    }
}