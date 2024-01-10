/* 	Ëàáîðàòîðíàÿ ðàáîòà 4
	Âàðèàíò 14. Çàäàí ðàçìåð ìàññèâà âåùåñòâåííûõ ÷èñåë è çíà÷åíèÿ åãî
	ýëåìåíòîâ. Îïðåäåëèòü, ÿâëÿþòñÿ ëè åãî ýëåìåíòû ÷ëåíàìè
	ãåîìåòðè÷åñêîé ïðîãðåññèè è âûâåñòè çíà÷åíèå çíàìåíàòåëÿ ïðîãðåññèè.	*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 1251 > nul");  /* ïîääåðæêà ðóññêîãî ÿçûêà */
    int size, i, x;
    while (printf("Ââåäèòå ðàçìåð ìàññèâà (áîëüøå 2 è íå áîëüøå 20): "),
            fflush(stdin),
            scanf("%d", &size) != 1 || size < 2 || size > 20)
        printf("Ìàññèâ äîëæåí ñîäåðæàòü êàê ìèíèìóì äâà ýëåìåíòà, ëèáî âû ÷òî-òî íå òî ââåëè\n");
    double arr[size], xx, ii;
    printf("Ââåäèòå ýëåìåíòû ìàññèâà:\n");
    for (i = 0; i < size; i++) {
        while (printf("%d:", i + 1),
                fflush(stdin),
                scanf("%lf", &arr[i]) != 1)
            printf("Âû ÷òî-òî íå òî ââåëè!\n");
    }
    
    for (i = 0; i < size; i++)	/* ñîðòèðîâêà ïî âîçðàñòàíèþ íåçàâèñèìî îò çíàêà */
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
    
    double ratio = arr[1] / arr[0];
    for (i = 2; i < size; i++) {
		if (arr[i] / arr[i - 1] != ratio) {
            printf("Ýëåìåíòû ìàññèâà íå îáðàçóþò ãåîìåòðè÷åñêóþ ïðîãðåññèþ\n");
            system("pause");
            return 0;
        }
    }
    printf("Ýëåìåíòû ìàññèâà îáðàçóþò ãåîìåòðè÷åñêóþ ïðîãðåññèþ ñ çíàìåíàòåëåì %.2f\n", ratio);
    system("pause");
    return 0;
}
