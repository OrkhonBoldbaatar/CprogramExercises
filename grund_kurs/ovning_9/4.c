#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUMBER_OF_AGES 21

void randomize_age(int arr[], int size);
void print_ages(int arr[], int size);
float calculate_average(int arr[], int size);
float calculate_median(int arr[], int size);
void swap(int arr[], int i, int j);
void initialize_array(int arr[], int size);
int count_occurrences(int age_arr[], int age_size, int type_arr[]);
void print_type_values(int type_arr[], int size, int max_occurrences);
bool print_each_type_value(int index, bool is_first);

int main()
{
    srand(time(NULL));
    int nr_of_people;
    printf("Hur manga personer vill du gora statistik pa? ");
    scanf("%d", &nr_of_people);

    int age[nr_of_people];
    randomize_age(age, nr_of_people);
    print_ages(age, nr_of_people);

    float average = calculate_average(age, nr_of_people);
    printf("Medelvardet: %.1f ar\n", average);

    float median = calculate_median(age, nr_of_people);
    printf("Median: %.1f ar\n", median);

    int type_values[NUMBER_OF_AGES];
    initialize_array(type_values, NUMBER_OF_AGES);

    int max_occurrences = count_occurrences(age, nr_of_people, type_values);
    print_type_values(type_values, NUMBER_OF_AGES, max_occurrences);
    return 0;
}

void randomize_age(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 21 + 20;
    }
}

void print_ages(int arr[], int size)
{
    if (size < 31)
    {
        for (int i = 0; i < size; i++)
        {
            printf("%d, ", arr[i]);
        }
        printf("\n");
    }
}

float calculate_average(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return (float)sum / size;
}

float calculate_median(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            swap(arr, j, j + 1);
        }
    }

    if (size % 2 == 0)
    {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    }
    else
    {
        return arr[size / 2];
    }
}

void swap(int arr[], int i, int j)
{
    if (arr[i] > arr[j])
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void initialize_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}

int count_occurrences(int age_arr[], int age_size, int type_arr[])
{
    int max_occurrences = 0;
    for (int i = 0; i < age_size; i++)
    {
        type_arr[age_arr[i] - 20]++;
        if (type_arr[age_arr[i] - 20] > max_occurrences)
        {
            max_occurrences = type_arr[age_arr[i] - 20];
        }
    }
    return max_occurrences;
}

void print_type_values(int type_arr[], int size, int max_occurrences)
{
    bool is_first = true;
    printf("Typvarde: ");
    for (int i = 0; i < size; i++)
    {
        if (type_arr[i] == max_occurrences)
        {
            is_first = print_each_type_value(i, is_first);
        }
    }
}

bool print_each_type_value(int index, bool is_first)
{
    if (is_first == 1)
    {
        printf("%d", index + 20);
        is_first = false;
    }
    else
    {
        printf(", %d", index + 20);
    }
    return is_first;
}
