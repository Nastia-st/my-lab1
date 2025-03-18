#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 16

int main() {
    system("chcp 65001");
    double X[SIZE], Z[SIZE / 2];
    
    printf("Введіть 16 дійсних чисел: ");
    for (int i = 0; i < SIZE; i++) {
        scanf("%lf", &X[i]);
    }
    
    for (int i = 0; i < SIZE / 2; i++) {
        Z[i] = X[i] + X[SIZE - 1 - i];
    }
    
    double max_Z = Z[0];
    for (int i = 1; i < SIZE / 2; i++) {
        if (Z[i] > max_Z) {
            max_Z = Z[i];
        }
    }
    
    printf("Максимальний елемент масиву Z: %.2lf\n", max_Z);
    return 0;
}