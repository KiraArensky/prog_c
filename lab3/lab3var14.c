/*  ������������ ������ 3
	������� 14. ������ ����� A � Omega. 
	��������� �������� ������������ �����-������, 
	���������� �������� ������ ������� y = A*sin(Omega*x)	*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x, y;	/* ���������� ������ � ����� ������� */
    double a, omega;	/* ���������� ����� */

    system("chcp 1251 > nul");  /* ��������� �������� ����� */

    /* ���� ���������� (���������� ������� � �����) */
	while ( printf("������� ����� A � ����� (����� ������): "),
				fflush(stdin),
				scanf("%lf %lf", &a, &omega) != 2 )
		printf("�� ���-�� �� �� �����! ���������� ��� ���\n");

    /* ��������� �������� ��� ������ ������� � ������� */
    printf("�������� ����� ���������������!\n\n");
    system("pause");
    system("mode con: cols=1200 lines=1200");
    
    /* ������ ������� */
    printf("������ y = A * sin(omega * x):\nA = %lf, omega = %lf\n\n", a, omega);
    
	/* ���������� ������� �� �������*/
    if (a > 0){
    for (y = a + 0.2; y >= -1 * a - 0.2; y -= 0.02)
	{
		for (x = -3.16; x <= 3.16; x += 0.02)
		{
            int y_check, fx_check;
            if (y > 0)
                y_check = (int) (y * 100 + 0.5);
            else
                y_check = (int) (y * 100 - 0.5);
            if ((a * sin(omega * x)) * 100 > 0){
                fx_check = (int) ((a * sin(omega * x)) * 100 + 0.5);
                if (fx_check % 2 != 0)
                    fx_check -= 1;}
            else{
                fx_check = (int) ((a * sin(omega * x)) * 100 - 0.5);
                if (fx_check % 2 != 0)
                    fx_check += 1;}
            if (y_check == (int)((a + 0.2) * 100 + 0.5) && (int)(x * 100 + 0.5) == 0)
                printf("^ y");
            else if ((int)(x * 100 + 0.5) == 314 && y_check == 0)
                printf("> x");
            else if (y_check == fx_check)
                printf("*");
            else if (y_check == (int)(a * 100 + 0.5) && (int)(x * 100 + 0.5) == -3)
                printf("%.1f", a);
            else if ((int)(x * 100 + 0.5) == 154 && y_check == -2)
                printf("PI/2");
			else if (y_check == 0)
				printf("-");
			else if ((int)(x * 100 + 0.5) == 0)
				printf("|");
			else
				printf(" ");
 		}
		printf("\n");
	}}
    else{
    for (y = -1 * a + 0.2; y >= a - 0.2; y -= 0.02)
        {
            for (x = -3.16; x <= 3.16; x += 0.01)
            {
                int y_check, fx_check;
                if (y > 0)
                    y_check = (int) (y * 100 + 0.5);
                else
                    y_check = (int) (y * 100 - 0.5);
                if ((a * sin(omega * x)) * 100 > 0){
                    fx_check = (int) ((a * sin(omega * x)) * 100 + 0.5);
                    if (fx_check % 2 != 0)
                        fx_check -= 1;}
                else{
                    fx_check = (int) ((a * sin(omega * x)) * 100 - 0.5);
                    if (fx_check % 2 != 0)
                        fx_check += 1;}
                if (y_check == (int)((-1 * a + 0.2) * 100 + 0.5) && (int)(x * 100 + 0.5) == 0)
                    printf("^ y");
                else if ((int)(x * 100 + 0.5) == 314 && y_check == 0)
                    printf("> x");
                else if (y_check == fx_check)
                    printf("*");
                else if (y_check == (int)(-1 * a * 100 + 0.5) && (int)(x * 100 + 0.5) == -3)
                    printf("%.1f", -1 * a + 0.5);
                else if ((int)(x * 100 + 0.5) == 154 && y_check == 2)
                    printf("PI/2");
                else if (y_check == 0)
                    printf("-");
                else if ((int)(x * 100 + 0.5) == 0)
                    printf("|");
                else
                    printf(" ");
            }
            printf("\n");
        }}
    
    system("pause");
    return 0;
}
