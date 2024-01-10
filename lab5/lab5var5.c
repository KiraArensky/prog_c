/* 	Лабораторная работа 5
	Вариант 5. Задано количество строк и столбцов
    прямоугольного массива и действительные значения
    его элементов. Дополнить массив строкой и столбцом,
    содержащих суммы элементов по столбцам и строкам соответственно.	*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 1251 > nul");  /* поддержка русского языка */

    int rows, cols, i, j;
    while (printf("Введите количество строк (натуральное число не больше 15): "),
            fflush(stdin),
            scanf("%d", &rows) != 1 || rows <= 0 || rows > 15)
        printf("Вы что-то не то ввели!\n");

    while (printf("Введите количество столбцов (натуральное число не больше 15): "),
            fflush(stdin),
            scanf("%d", &cols) != 1 || cols <= 0 || cols > 15)
        printf("Вы что-то не то ввели!\n");

    double array[15][15];
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            while (printf("Введите элемент array[%d][%d]: ", i, j),
                    fflush(stdin),
                    scanf("%lf", &array[i][j]) != 1)
                printf("Вы что-то не то ввели!\n");
        }
    }

    for (i = 0; i < rows; i++) {
        double rowSum = 0;
        for (j = 0; j < cols; j++) {
            rowSum += array[i][j];
        }
        array[i][cols] = rowSum;
    }

    for (j = 0; j < cols; j++) {
        double colSum = 0;
        for (i = 0; i < rows; i++) {
            colSum += array[i][j];
        }
        array[rows][j] = colSum;
    }

    printf("Итоговый массив:\n");
    for (i = 0; i <= rows; i++) {
        for (j = 0; j <= cols; j++) {
            if (i == rows && j == cols)
                break;
            printf("%lf ", array[i][j]);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}