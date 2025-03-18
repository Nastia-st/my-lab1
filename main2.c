#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    system("chcp 65001");
    int N;
    
    printf("Введіть кількість чисел: ");
    scanf("%d", &N);

    int *MAS = (int*)malloc(N * sizeof(int));
    if (MAS == NULL) {
        printf("Помилка виділення пам'яті!\n");
        return 1;
    }

    printf("Введіть %d цілих чисел: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &MAS[i]);
    }

    long long product_even_index = 1;
    for (int i = 0; i < N; i += 2) { 
        product_even_index *= MAS[i];
    }
    
    int first_zero = -1, last_zero = -1;
    for (int i = 0; i < N; i++) {
        if (MAS[i] == 0) {
            if (first_zero == -1) first_zero = i;
            last_zero = i;
        }
    }
    
    int sum_between_zeros = 0;
    if (first_zero != -1 && last_zero != -1 && first_zero != last_zero) {
        for (int i = first_zero + 1; i < last_zero; i++) {
            sum_between_zeros += MAS[i];
        }
    }
    
    printf("Добуток елементів з парними номерами: %lld\n", product_even_index);
    if (first_zero != -1 && last_zero != -1 && first_zero != last_zero) {
        printf("Сума елементів між першим і останнім нулем: %d\n", sum_between_zeros);
    } else {
        printf("Немає двох нульових елементів для обчислення суми.\n");
    }
    return 0;
}