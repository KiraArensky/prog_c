/* 	Ëàáîðàòîðíàÿ ðàáîòà 5
	Âàðèàíò 5. Çàäàíî êîëè÷åñòâî ñòðîê è ñòîëáöîâ
    ïðÿìîóãîëüíîãî ìàññèâà è äåéñòâèòåëüíûå çíà÷åíèÿ
    åãî ýëåìåíòîâ. Äîïîëíèòü ìàññèâ ñòðîêîé è ñòîëáöîì,
    ñîäåðæàùèõ ñóììû ýëåìåíòîâ ïî ñòîëáöàì è ñòðîêàì ñîîòâåòñòâåííî.	*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 1251 > nul");  /* ïîääåðæêà ðóññêîãî ÿçûêà */

    int rows, cols, i, j;
    while (printf("Ââåäèòå êîëè÷åñòâî ñòðîê (íàòóðàëüíîå ÷èñëî íå áîëüøå 15): "),
            fflush(stdin),
            scanf("%d", &rows) != 1 || rows <= 0 || rows > 15)
        printf("Âû ÷òî-òî íå òî ââåëè!\n");

    while (printf("Ââåäèòå êîëè÷åñòâî ñòîëáöîâ (íàòóðàëüíîå ÷èñëî íå áîëüøå 15): "),
            fflush(stdin),
            scanf("%d", &cols) != 1 || cols <= 0 || cols > 15)
        printf("Âû ÷òî-òî íå òî ââåëè!\n");

    double array[rows + 1][cols + 1];
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            while (printf("Ââåäèòå ýëåìåíò array[%d][%d]: ", i, j),
                    fflush(stdin),
                    scanf("%lf", &array[i][j]) != 1)
                printf("Âû ÷òî-òî íå òî ââåëè!\n");
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

    printf("Èòîãîâûé ìàññèâ:\n");
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
