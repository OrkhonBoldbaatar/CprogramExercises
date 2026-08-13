#include <stdio.h>

int main()
{
    int a = 100, b = 1;

    while (a > b)
    {
        printf("a = %d, b = %d\n", a, b);
        if (a / b > 20)
        {
            a /= 2;
        }
        else
        {
            if (b < a / 2)
            {
                b += 2;
            }
            else
            {
                b++;
            }
            printf("b = %d\n", b);
        }
    }

    printf("a = %d, b = %d\n", a, b);

    return 0;
}