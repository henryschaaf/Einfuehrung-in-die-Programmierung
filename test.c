#include <stdio.h>

int hailstone(int n)
{
    int counter = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = n * 3 + 1;
        }
        counter++;
    }
    
    return counter;
}

int main()
{
    printf("Hello World\n");
    int p = hailstone(7);
    printf("Zahl : %d \n",p);
    return 0;
}