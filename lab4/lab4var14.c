/* 	������������ ������ 4
	������� 14. ����� ������ ������� ������������ ����� � �������� ���
	���������. ����������, �������� �� ��� �������� �������
	�������������� ���������� � ������� �������� ����������� ����������.	*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 1251 > nul");  /* ��������� �������� ����� */
    int size;
    while (printf("������� ������ �������: "),
            fflush(stdin),
            scanf("%d", &size) != 1 || size < 2)
        printf("������ ������ ��������� ��� ������� ��� ��������, ���� �� ���-�� �� �� �����\n");
    double arr[size];
    printf("������� �������� �������:\n");
    for (int i = 0; i < size; i++) {
        while (printf("%d:", i + 1),
                fflush(stdin),
                scanf("%lf", &arr[i]) != 1)
            printf("�� ���-�� �� �� �����!\n");
    }
    double ratio = 0;
    int i;
    for (i = 1; i < size; i++) {
        if (arr[i - 1] != 0) {
            ratio = arr[i] / arr[i - 1];
            break;
        }
        else if (arr[i] != 0) {
            printf("�������� ������� �� �������� �������������� ����������\n");
            system("pause");
            return 0;
        }
    }
    if (i == size) {
        printf("��� �������� ������� ����� ����\n");
        system("pause");
        return 0;
    }
    for (; i < size; i++) {
        if (arr[i - 1] == 0 && arr[i] != 0) {
            printf("�������� ������� �� �������� �������������� ����������\n");
            system("pause");
            return 0;
        }
        else if (arr[i] / arr[i - 1] != ratio) {
            printf("�������� ������� �� �������� �������������� ����������\n");
            system("pause");
            return 0;
        }
    }
    printf("�������� ������� �������� �������������� ���������� � ������������ %.2f\n", ratio);
    system("pause");
    return 0;
}
