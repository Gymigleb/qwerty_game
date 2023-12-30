# include <bits/stdc++.h>

using namespace std;

int random(int start, int end)
{
    //srand(time(NULL)); // for random starting count time
    return rand() % (end - start + 1) + start; // magic
}