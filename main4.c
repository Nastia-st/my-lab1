#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    system("chcp 65001");
    int N;
    
    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &N);
    
    int *A = (int*)malloc(N * sizeof(int));
    if (A == NULL) {
        printf("Помилка виділення пам'яті!\n");
        return 1;
    }
    
    printf("Введіть %d цілих чисел: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    int max_diff = 0, index1 = 0, index2 = 1;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int diff = abs(A[i] - A[j]);
            if (diff > max_diff) {
                max_diff = diff;
                index1 = i;
                index2 = j;
            }
        }
    }
    
    printf("Пара елементів з найбільшою різницею: A[%d] = %d і A[%d] = %d\n", index1, A[index1], index2, A[index2]);
    printf("Максимальне абсолютне значення різниці: %d\n", max_diff);
    
    return 0;
}