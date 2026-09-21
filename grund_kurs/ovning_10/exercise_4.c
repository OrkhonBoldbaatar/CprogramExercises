#include <stdio.h>
void swap(int *a, int *b);
void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main()
{
    int n;
    printf("Ange antalet element i arrayen: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Ange %d heltal:\n", n);
        scanf("%d", &arr[i]);
    }

    int largest, second_largest;
    find_two_largest(arr, n, &largest, &second_largest);

    printf("Storsta talet: %d\n", largest);
    printf("Nasta storsta talet: %d\n", second_largest);

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
    if (a[0] > a[1]) {
        *largest = a[0];
        *second_largest = a[1];
    } else {
        *largest = a[1];
        *second_largest = a[0];
    }

    for (int i = 2; i < n; i++)
    {
        if (a[i] > *largest)
        {
            *second_largest = *largest;
            *largest = a[i];
        }
        else if (a[i] > *second_largest)
        {
            *second_largest = a[i];
        }
    }
}