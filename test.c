#include "stdio.h"

int magic(int x)
{
    return 2 * x;
}

int main()
{
    int outer = 30;
    int inner = 100;
    int array[outer * inner];
    int sum = 0;
    for (int i = 0; i < outer; i++)
    {
        for (int j = 0; j < inner; j++)
        {
            array[i * inner + j] = i * j;
            sum += array[i * inner + j];
        }
    }

    fprintf("%d", sum);
}