#include <stdio.h>

int main() {
    int width = 0, height = 0;
    printf("Ange bredd: ");
    scanf("%d", &width);
    printf("Ange hojd: ");
    scanf("%d", &height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}