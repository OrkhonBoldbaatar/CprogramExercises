#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void randomize_array(int arr[], int size);
void init_game(int arr[], int size);
void print_array(int arr[], int size);
void fill_censor(char arr[], int size);
void initialize_array(int arr[], int size);
void print_censor(char arr[], int size);
int get_input(char censor[],  int size);
bool is_correct(int arr[], int guess[], char censor[], int size);
void input_into_guess(int input, int guess[], int size);

int main()
{
    srand(time(NULL));
    int guess;

    printf("Gissa koden\n");
    for (int size = 2; size <= 5; size++)
    {
        int secret_number[size];
        randomize_array(secret_number, size);
        init_game(secret_number, size);
    }

    return 0;
}

void randomize_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 9 + 1;
    }
}

void init_game(int arr[], int size)
{
    char censor[size];
    fill_censor(censor, size);

    int guess[size];
    initialize_array(guess, size);

    while (1)
    {
        int input =get_input(censor, size);
        input_into_guess(input, guess, size);
        
        if (is_correct(arr, guess, censor, size))
        {
            print_array(arr, size);
            printf(" korrekt!\n");
            break;
        }
    }
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }

}

void fill_censor(char arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = '*';
    }
}

void print_censor(char arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%c", arr[i]);
    }
}

void initialize_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}

int get_input(char censor[], int size)
{
    int input = 0;
    print_censor(censor, size);
    printf(": ");
    scanf("%d", &input);
    return input;
}

bool is_correct(int arr[], int guess[], char censor[], int size)
{
    int correct_guess = 0;
    fill_censor(censor, size);
    for (int i = 0; i < size; i++)
    {
        if (guess[i] == arr[i])
        {
            censor[i] = guess[i] + '0';
            correct_guess++;
        }
    }
    return correct_guess == size;
}

void input_into_guess(int input, int guess[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        guess[i] = input % 10;
        input /= 10;
    }
}
