#include <stdio.h>

int main() {
    int maxNumber;
    printf("Ange maxtal: ");
    scanf("%d", &maxNumber);

    for (int i = 1; i < maxNumber; i++)
    {
        printf("%d, ", i);
    }
    printf("%d\n", maxNumber);

    return 0;
}