#include <stdio.h>

int main() {
    int maxNumber = 0, counter = 1;
    printf("Ange maxtal: ");
    scanf("%d", &maxNumber);

    while (counter <= maxNumber) 
    {
        printf("%d, ", counter);
        counter++;
    }

    return 0;
}