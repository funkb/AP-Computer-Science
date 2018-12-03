#include <iostream>
#include <stdio.h>
using namespace std;

enum Type {VERTICAL = '|', HORIZONTAL = '-'};

int main()
{
        Type blue = VERTICAL;

        printf("\033[1;34m%c\033[0m\n", static_cast<char>(blue));

        Type red  = HORIZONTAL;

        printf("\033[1;31m%c\033[0m\n", static_cast<char>(red));

        return 0;
}
