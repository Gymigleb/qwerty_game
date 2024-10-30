#include <iostream>
#include <conio.h>

using namespace std;
 
int main() {
    char ch;
 
    //program pauses here until key is pressed
    ch = _getch();
 
    if(ch == 'a')
        std::cout << "Key Pressed: a" << std::endl;
    if(ch == 's')
        std::cout << "Key Pressed: s" << std::endl;
    else if(ch == 'A')
        std::cout << "Key Pressed: A" << std::endl;
 
    return 0;
}