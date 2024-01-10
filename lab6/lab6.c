/* 	Лабораторная работа 6
	Лабораторная работа 4, вариант 14. Задан размер массива вещественных чисел и значения его
	элементов. Определить, являются ли его элементы членами
	геометрической прогрессии и вывести значение знаменателя прогрессии.	*/

#include <stdio.h>
#include <stdlib.h>

double check_geometric_progression(const double arr[], int size) {
    double ratio = arr[1] / arr[0];
    int i;
    for (i = 2; i < size; i++) {
        if (arr[i] / arr[i - 1] != ratio) {
            return 0;
        }
    }
    return ratio;
}

void input_array(double arr[], int size) {
    printf("Введите элементы массива:\n");
    int i;
    for (i = 0; i < size; i++) {
        while (printf("%d:", i + 1),
                fflush(stdin),
                scanf("%lf", &arr[i]) != 1)
            printf("Вы что-то не то ввели!\n");
    }
}

void sort_array(double arr[], int size) {
    int i, x;
    double xx, ii;
    for (i = 0; i < size; i++)	/* сортировка по возрастанию независимо от знака */
    {
        for (x = i; x < size; x++)
        {
            if (arr[i] < 0 && arr[x] < 0)
            {
                ii = -1 * arr[i];
                xx = -1 * arr[x];
            }
            else if (arr[x] < 0)
            {
                xx = -1 * arr[x];
                ii = arr[i];
            }

            else if (arr[i] < 0)
            {
                ii = -1 * arr[i];
                xx = arr[x];
            }
            else
            {
                ii = arr[i];
                xx = arr[x];
            }
            if (xx < ii)
            {
                double b = arr[x];
                arr[x] = arr[i];
                arr[i] = b;
            }
        }
    }
}

int main() {
    system("chcp 1251 > nul");  /* поддержка русского языка */
    int size;
    while (printf("Введите размер массива: "),
            fflush(stdin),
            scanf("%d", &size) != 1 || size < 2)
        printf("Массив должен содержать как минимум два элемента, либо вы что-то не то ввели\n");
    double arr[20];
    input_array(arr, size); /* ввод массива */
    sort_array(arr, size); /* сортировка массива независимо от знака */
    double ratio;
    ratio = check_geometric_progression(arr, size);	/* проверка на прогрессию */
    if (ratio == 0)
    {
        printf("Элементы массива не образуют геометрическую прогрессию\n");
        system("pause");
        return 0;
    }
    printf("Элементы массива образуют геометрическую прогрессию с знаменателем %.2f\n", ratio);
    system("pause");
    return 0;
}