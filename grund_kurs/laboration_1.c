#include <stdio.h>

int main()
{
    int currentPos = 6;
    char input;
    printf("Play ball!\n");

    do
    {
        printf("|           |\n");
        for (int i = 0; i < 13; i++)
        {
            if (i == 0 || i == 12)
            {
                printf("|");
            }
            else if (i == currentPos)
            {
                printf("O");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n-------------\n: ");
        scanf(" %c", &input);
        if (input == '<')
        {
            currentPos = currentPos - 2;
        }
        else if (input == '>')
        {
            currentPos = currentPos + 2;
        }
    } while (currentPos > 0 && currentPos < 12);
    printf("GOAL!\n");
    return 0;
}