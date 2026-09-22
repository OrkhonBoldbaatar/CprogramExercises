#include <stdio.h>
#include <math.h>

#define SIZE 10

char get_input();
void view(int arr[], int size);
int enter(int measurement[], int nr_of_measurements);
void compute(int measurement[], int nr_of_measurements);
int max(int arr[], int size);
int min(int arr[], int size);
float avg(int arr[], int size);

int main()
{
    int measurement[SIZE] = {0};
    int nr_of_measurements = 0;

    printf("Measurement tool 2.0\n");
    while (1)
    {
        char choice = get_input();
        switch (choice)
        {
        case 'v':
        case 'V':
            view(measurement, nr_of_measurements);
            break;
        case 'e':
        case 'E':
            nr_of_measurements = enter(measurement, nr_of_measurements);
            break;
        case 'c':
        case 'C':
            compute(measurement, nr_of_measurements);
            break;
        case 'r':
        case 'R':
            nr_of_measurements = 0;
            printf("Measurements reset\n");
            break;
        case 'q':
        case 'Q':
            printf("Exit measurement tool\n");
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

char get_input()
{
    char input;
    printf("VECRQ? ");
    scanf(" %c", &input);
    return input;
}

void view(int arr[], int size)
{
    if (size == 0)
    {
        printf("No measurements\n");
        return;
    }
    printf("Measurements: [ ");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("%d ]\n", arr[size - 1]);
}

int enter(int measurement[], int nr_of_measurements)
{
    int oneMeasurement = 0;

    while (nr_of_measurements < SIZE)
    {
        printf("Enter measurement #%d (or q to quit): ", nr_of_measurements + 1);
        int readInteger = scanf("%d", &oneMeasurement);
        if (readInteger)
        {
            measurement[nr_of_measurements] = oneMeasurement;
            nr_of_measurements++;
        }
        else
        {
            char tmp;
            scanf(" %c", &tmp);
            return nr_of_measurements;
        }
    }
    printf("Measurement array is full\n");
    return nr_of_measurements;
}

void compute(int measurement[], int nr_of_measurements)
{
    if (nr_of_measurements == 0)
    {
        printf("No measurements\n");
        return;
    }
    printf("Max value: %d\n", max(measurement, nr_of_measurements));
    printf("min value: %d\n", min(measurement, nr_of_measurements));

    float average = avg(measurement, nr_of_measurements);
    printf("Avr value: %.2f\n", average);

    int rounded_average = round(average);
    int normalized_measurements[SIZE];
    for (int i = 0; i < nr_of_measurements; i++)
    {
        normalized_measurements[i] = measurement[i] - rounded_average;
    }
    view(normalized_measurements, nr_of_measurements);
}

int max(int arr[], int size)
{
    int max_value = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }
    return max_value;
}

int min(int arr[], int size)
{
    int min_value = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min_value)
        {
            min_value = arr[i];
        }
    }
    return min_value;
}

float avg(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return (float) sum / size;
}