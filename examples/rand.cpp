#include <iostream> // defolt
#include <stdlib.h> // to rand
#include <time.h> // to rand

using namespace std;

int main()
{
    srand(time(NULL));
    int x;
    x = rand();
    cout << "x = " << x << endl;
}