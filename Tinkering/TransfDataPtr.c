#include <stdio.h>
#include <stdlib.h>

void updateArray(int array[2][4], int Xpos, int Ypos, int val) {
    array[Xpos - 1][Ypos - 1] = val;
}
void main() {
    int array1[2][4] = {{1,2,3,4},{5,6,7,8}};

    /*

    1 2 3 4
    5 6 7 8

    */

    updateArray(array1, 2, 3, 9);
    //               Xpos | Ypos
    //       which    row | col    ?
    /*

    1 2 3 4
    5 6 9 8

    */

    // Printout:
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d", array1[i][j]);
        }
        printf("\n");
    }
}