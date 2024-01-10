/* 	Ëàáîðàòîðíàÿ ðàáîòà 6
	Ëàáîðàòîðíàÿ ðàáîòà 4, âàðèàíò 14. Çàäàí ðàçìåð ìàññèâà âåùåñòâåííûõ ÷èñåë è çíà÷åíèÿ åãî
	ýëåìåíòîâ. Îïðåäåëèòü, ÿâëÿþòñÿ ëè åãî ýëåìåíòû ÷ëåíàìè
	ãåîìåòðè÷åñêîé ïðîãðåññèè è âûâåñòè çíà÷åíèå çíàìåíàòåëÿ ïðîãðåññèè.	*/

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
    printf("Ââåäèòå ýëåìåíòû ìàññèâà:\n");
    int i;
    for (i = 0; i < size; i++) {
        while (printf("%d:", i + 1),
                fflush(stdin),
                scanf("%lf", &arr[i]) != 1)
            printf("Âû ÷òî-òî íå òî ââåëè!\n");
    }
}

void sort_array(double arr[], int size) {
	int i, x;
	double xx, ii;
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
}

int main() {
    system("chcp 1251 > nul");  /* ïîääåðæêà ðóññêîãî ÿçûêà */
    int size;
    while (printf("Ââåäèòå ðàçìåð ìàññèâà: "),
            fflush(stdin),
            scanf("%d", &size) != 1 || size < 2)
        printf("Ìàññèâ äîëæåí ñîäåðæàòü êàê ìèíèìóì äâà ýëåìåíòà, ëèáî âû ÷òî-òî íå òî ââåëè\n");
    double arr[size];
    input_array(arr, size); /* ââîä ìàññèâà */
    sort_array(arr, size); /* ñîðòèðîâêà ìàññèâà íåçàâèñèìî îò çíàêà */
    double ratio;
    ratio = check_geometric_progression(arr, size);	/* ïðîâåðêà íà ïðîãðåññèþ */
    if (ratio == 0)
    {
    	printf("Ýëåìåíòû ìàññèâà íå îáðàçóþò ãåîìåòðè÷åñêóþ ïðîãðåññèþ\n");
        system("pause");
        return 0;
	}
	printf("Ýëåìåíòû ìàññèâà îáðàçóþò ãåîìåòðè÷åñêóþ ïðîãðåññèþ ñ çíàìåíàòåëåì %.2f\n", ratio);
    system("pause");
    return 0;
}
