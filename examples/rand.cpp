#include <iostream> // defolt
#include <stdlib.h> // to rand
#include <time.h> // to rand

using namespace std;

int get_random_int(int min, int max)
{
    /*
    this function take in input 2 numbers (min - from, max - to)
    output is random int in range from min to max
    */
    int num = min + rand() % (max - min + 1);
    return num;
}

int main()
{
    srand(time(NULL)); // create random seed
    cout << "x = " << get_random_int(0,3) << endl;
}