#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int secret[3] = {0, 0, 0}, guess[3] = {0, 0, 0};
    int correct_guess = 0, nr_of_guesses = 0;

    for (int i = 0; i < 3; i++)
    {
        secret[i] = rand() % 10;
    }

    while (correct_guess < 3)
    {
        correct_guess = 0;
        printf("Gissa koden: ");
        scanf("%d %d %d", &guess[0], &guess[1], &guess[2]);
        nr_of_guesses++;
        for (int i = 0; i < 3; i++)
        {
            if (guess[i] == secret[i])
            {
                correct_guess++;
            }
        }

        if (correct_guess == 3)
        {
            printf("Ratt kod. Du behovde %d gissningar.\n", nr_of_guesses);
        }
        else
        {
            printf("Fel gissat! Du hade %d ratt.\n", correct_guess);
        }
    }
    return 0;
}