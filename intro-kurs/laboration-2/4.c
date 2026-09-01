#include <stdio.h>

int main()
{
    int number = 1, current = 1;
    while (number != 0) {
        printf("Ange ett tal: ");
        scanf("%d", &number);
        if (number < 0)
        {
            printf("Talet ska vara positivt.\n");
        }
        else if (number > 0)
        {
            for (int i = 1; i <= number; i++)
            {
                current = current * i;
            }
            printf("%d! = %d\n", number, current);
        }
        current = 1;
    }
    printf("Avslutar\n");

    return 0;
}