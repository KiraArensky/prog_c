/*	������������ ������ 1
	������� 25. ������ �������� x �� -1 �� 1. ����� �������� ������ ��� ������� 
	sqrt(1 + x), ������������������ ����������� 1 + x/2 - x^2/8 + x^3/16. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
     
int main()
{
	/* ���������� x, ��������� �������, ��������� ����������, �������� ������ */
    double x, result0, result1, result;
    
    system("chcp 1251 > nul");	/* ��������� �������� ����� */
    
    /* ���� ���������� x */
    printf("������� x: ");
    scanf("%lf", &x);
	
	result0 = sqrt(1 + x);	/* ��������� ������� */
	result1 = 1 + x/2 - (x * x) / 8 + (x * x * x) / 16;	/* ��������� ���������� */
	result = fabs(result0 - result1);	/* �������� ������ */
	
	/* ����� �����������*/
	printf("\n��������� ��������� (1 - x)^0.5 = %lf\n", result0);
	printf("��������� ��������� 1+x/2-(x^2)/8+(x^3)/16 = %lf\n\n\n", result1);
	printf("�������� ������ = %lf\n\n\n", result);
	    
    system("pause");
    return 0;
}
