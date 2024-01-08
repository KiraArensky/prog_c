/* 	Лабораторная работа 6
	Лабораторная работа 4, вариант 14. Задан размер массива вещественных чисел и значения его
	элементов. Определить, являются ли его элементы членами
	геометрической прогрессии и вывести значение знаменателя прогрессии.	*/

#include <stdio.h>
#include <stdlib.h>

void check_geometric_progression(const double arr[], int size) {
    double ratio = 0;
    int i;
    for (i = 1; i < size; i++) {
        if (arr[i - 1] != 0) {
            ratio = arr[i] / arr[i - 1];
            break;
        } else if (arr[i] != 0) {
            printf("Элементы массива не образуют геометрическую прогрессию\n");
            system("pause");
            return;
        }
    }
    if (i == size) {
        printf("Все элементы массива равны нулю\n");
        system("pause");
        return;
    }
    for (; i < size; i++) {
        if (arr[i - 1] == 0) {
            if (arr[i] != 0) {
                printf("Элементы массива не образуют геометрическую прогрессию\n");
                system("pause");
                return;
            }
        } else if (arr[i] / arr[i - 1] != ratio) {
            printf("Элементы массива не образуют геометрическую прогрессию\n");
            system("pause");
            return;
        }
    }
    printf("Элементы массива образуют геометрическую прогрессию с знаменателем %.2f\n", ratio);
}

void input_array(double arr[], int size) {
    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++) {
        while (printf("%d:", i + 1),
                fflush(stdin),
                scanf("%lf", &arr[i]) != 1)
            printf("Вы что-то не то ввели!\n");
    }
}

int main() {
    system("chcp 1251 > nul");  /* поддержка русского языка */
    int size;
    while (printf("Введите размер массива: "),
            fflush(stdin),
            scanf("%d", &size) != 1 || size < 2)
        printf("Массив должен содержать как минимум два элемента, либо вы что-то не то ввели\n");
    double arr[size];
    input_array(arr, size); /* ввод массива */
    check_geometric_progression(arr, size); /* проверка на прогрессию */
    system("pause");
    return 0;
}
