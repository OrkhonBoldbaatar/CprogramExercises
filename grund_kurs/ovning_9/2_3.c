#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int arr[], int i, int j);
int get_max_number();
void fill_array(int arr[], int size);
void randomize_array(int arr[], int size);
void print_array(int arr[], int size);
int longest_increasing_subsequence(int arr[], int size);
int set_max(int a, int b);

int main()
{
    srand(time(NULL));
    int max_number = get_max_number();

    int numbers[max_number];

    fill_array(numbers, max_number);
    randomize_array(numbers, max_number);
    print_array(numbers, max_number);
    int numbers_in_order = longest_increasing_subsequence(numbers, max_number);
    printf("\nLangsta foljden ar %d\n", numbers_in_order);

    return 0;
}

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int get_max_number()
{
    int max_number = 0;
    while (1)
    {
        printf("Vilket ar det hogsta heltal du vill ha med (1-1000): ");
        scanf("%d", &max_number);

        if (max_number >= 1 && max_number <= 1000)
        {
            return max_number;
        }
        printf("Du maste valja mellan 1 och 1000!\n");
    }
}

void fill_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }
}

void randomize_array(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        int index_to_swap = rand() % (size - i) + i;
        swap(arr, i, index_to_swap);
    }
}

void print_array(int arr[], int size)
{
    int count = 1;
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
}

int longest_increasing_subsequence(int arr[], int size)
{
    int count = 1, max_count = 1;
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            count++;
            max_count = set_max(count, max_count);
        }
        else
        {
            count = 1;
        }
    }
    return max_count;
}

int set_max(int a, int b)
{
    return (a > b) ? a : b;
}
