#include "stdio.h"

int magic(int x)
{
    return 2 * x;
}

int main()
{
    printf("hi");
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += i;
    }
}