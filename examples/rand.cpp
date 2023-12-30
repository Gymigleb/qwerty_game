#include <iostream> // defolt
#include <stdlib.h> // to rand
#include <time.h> // to rand

using namespace std;

int main()
{
    srand(time(NULL)); // create random seed
    int x;
    int start = 10;
    int end = 30;
    x = rand() % (end - start + 1) + start;
    cout << "x = " << x << endl;
}