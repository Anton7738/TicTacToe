#include <stdio.h>

void main() {

    char filler = 'F';

    printf("1 Dimensional Array:\n");
    char array1[5];
    for (int i = 0; i < 5; i++) {
        array1[i] = filler;
        printf("%c", array1[i]);
    }

    printf("\n");

    printf("2 Dimensional Array:\n");
    char array2[5][10];
    for (int n = 0; n < 5; n++) {
        for (int m = 0; m < 10; m++) {
            array2[n][m] = filler;
        }
    }

    for (int n = 0; n < 5; n++) {
        for (int m = 0; m < 10; m++) {
            printf("%c", array2[n][m]);
        }
        printf("\n");
    }


    

    printf("\n");

}