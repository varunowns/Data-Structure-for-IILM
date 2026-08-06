#include <stdio.h>

int main(){
    int temps[5][1];
    int i;

    printf("Enter temperature for 5 cities:\n");
    for (i = 0; i < 5; i++){
        printf("City %d: ", i + 1);
        scanf("%d", &temps[i][0]);
    }

    printf("\nTemperatures of 5 cities are:\n");
    for (i = 0; i < 5; i++){
        printf("City %d: %d\n", i + 1, temps[i][0]);
    }

    return 0;
}