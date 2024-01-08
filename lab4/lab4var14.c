#include <stdio.h>
#include <stdlib.h>

int main(){
    double arr[100];
    int n, i;

    printf("������� ���������� ��������� �������: ");
    scanf("%d", &n);

    printf("������� �������� �������:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int size = sizeof(arr) / sizeof(arr[0]);
    if (size < 2) {
        printf("������ ������ ��������� ��� ������� ��� ��������\n");
        system("pause");
        return 1;
    }
    double ratio = 0;
    for (i = 1; i < size; i++) {
        if (arr[i-1] != 0) {
            ratio = arr[i] / arr[i-1];
            break;
        } else if (arr[i] != 0) {
            printf("�������� ������� �� �������� �������������� ����������\n");
            system("pause");
            return 1;
        }
    }
    if (i == size) {
        printf("��� �������� ������� ����� ����\n");
            system("pause");
            return 1;
    }
    for (i = 0; i < size; i++) {
        if (arr[i-1] == 0) {
            if (arr[i] != 0) {
                printf("�������� ������� �� �������� �������������� ����������\n");
                system("pause");
                return 1;
            }
        } else if (arr[i] / arr[i-1] != ratio) {
            printf("�������� ������� �� �������� �������������� ����������\n");
            system("pause");
            return 1;
        }
    }
    printf("�������� ������� �������� �������������� ���������� � ������������ %.2f\n", ratio);
    system("pause");
    return 0;
}
