/* 	������������ ������ 5
	������� 5. ������ ���������� ����� � ��������
    �������������� ������� � �������������� ��������
    ��� ���������. ��������� ������ ������� � ��������,
    ���������� ����� ��������� �� �������� � ������� ��������������.	*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 1251 > nul");  /* ��������� �������� ����� */

    int rows, cols, i, j;
    while (printf("������� ���������� ����� (����������� �����): "),
            fflush(stdin),
            scanf("%d", &rows) != 1 || rows <= 0)
        printf("�� ���-�� �� �� �����!\n");

    while (printf("������� ���������� �������� (����������� �����): "),
            fflush(stdin),
            scanf("%d", &cols) != 1 || cols <= 0)
        printf("�� ���-�� �� �� �����!\n");

    double array[rows + 1][cols + 1];
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            while (printf("������� ������� array[%d][%d]: ", i, j),
                    fflush(stdin),
                    scanf("%lf", &array[i][j]) != 1)
                printf("�� ���-�� �� �� �����!\n");
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

    printf("�������� ������:\n");
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
