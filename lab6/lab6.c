/* 	������������ ������ 6
	������������ ������ 4, ������� 14. ����� ������ ������� ������������ ����� � �������� ���
	���������. ����������, �������� �� ��� �������� �������
	�������������� ���������� � ������� �������� ����������� ����������.	*/

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
            printf("�������� ������� �� �������� �������������� ����������\n");
            system("pause");
            return;
        }
    }
    if (i == size) {
        printf("��� �������� ������� ����� ����\n");
        system("pause");
        return;
    }
    for (; i < size; i++) {
        if (arr[i - 1] == 0) {
            if (arr[i] != 0) {
                printf("�������� ������� �� �������� �������������� ����������\n");
                system("pause");
                return;
            }
        } else if (arr[i] / arr[i - 1] != ratio) {
            printf("�������� ������� �� �������� �������������� ����������\n");
            system("pause");
            return;
        }
    }
    printf("�������� ������� �������� �������������� ���������� � ������������ %.2f\n", ratio);
}

void input_array(double arr[], int size) {
    printf("������� �������� �������:\n");
    for (int i = 0; i < size; i++) {
        while (printf("%d:", i + 1),
                fflush(stdin),
                scanf("%lf", &arr[i]) != 1)
            printf("�� ���-�� �� �� �����!\n");
    }
}

int main() {
    system("chcp 1251 > nul");  /* ��������� �������� ����� */
    int size;
    while (printf("������� ������ �������: "),
            fflush(stdin),
            scanf("%d", &size) != 1 || size < 2)
        printf("������ ������ ��������� ��� ������� ��� ��������, ���� �� ���-�� �� �� �����\n");
    double arr[size];
    input_array(arr, size); /* ���� ������� */
    check_geometric_progression(arr, size); /* �������� �� ���������� */
    system("pause");
    return 0;
}
