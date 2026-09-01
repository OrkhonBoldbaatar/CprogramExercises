#include <stdio.h>

int main() {
    int weekDay;
    printf("Ange veckodag: ");
    scanf("%d", &weekDay);

    switch (weekDay) {
        case 1:
            printf("Det motsvarar måndag\n");
            break;
        case 2:
            printf("Det motsvarar tisdag\n");
            break;
        case 3:
            printf("Det motsvarar onsdag\n");
            break;
        case 4:
            printf("Det motsvarar torsdag\n");
            break;
        case 5:
            printf("Det motsvarar fredag\n");
            break;
        case 6:
            printf("Det motsvarar lördag\n");
            break;
        case 7:
            printf("Det motsvarar söndag\n");
            break;
        default:
            printf("Ogiltig tal.\n");
    }
    printf("Avslutar\n");
    return 0;
}