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
    
    int sum_even = 0, count_even = 0;
    int product_odd = 1, count_odd = 0;
    int max_value = MAS[0], max_index = 0;
    
    for (int i = 0; i < N; i++) {
        if (MAS[i] % 2 == 0) {
            sum_even += MAS[i];
            count_even++;
        } else {
            product_odd *= MAS[i];
            count_odd++;
        }
        
        if (MAS[i] > max_value) {
            max_value = MAS[i];
            max_index = i;
        }
    }
    
    double avg_even = (count_even > 0) ? (double)sum_even / count_even : 0;
    double geo_mean_odd = (count_odd > 0) ? pow(product_odd, 1.0 / count_odd) : 0;
    
    printf("Сума парних чисел: %d\n", sum_even);
    printf("Середнє арифметичне парних чисел: %.2f\n", avg_even);
    printf("Добуток непарних чисел: %d\n", count_odd > 0 ? product_odd : 0);
    printf("Середнє геометричне непарних чисел: %.2f\n", geo_mean_odd);
    printf("Максимальне значення: %d, його номер: %d\n", max_value, max_index + 1);
    
    return 0;
}