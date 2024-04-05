#include <stdio.h>
#include <stdlib.h>


typedef struct Date
{
	unsigned int d:5;
	unsigned int m:4;
	int y:13;
} Date;

typedef struct Condition
{
	unsigned int complited:1;
	unsigned int paid:1;
} Condition;


typedef struct Orders
{
	char name_company[51];
	Date addmision;
	double time;
	double price;
	Condition condition;
} Orders;

void InputDate(Date *p) 
{
	if (!p)
		return;
	int d, m, y;
	while (printf("\taddmision (dd.mm.yyyy): "),
				fflush(stdin),
                scanf("%d.%d.%d", &d, &m, &y) != 3 || !(d > 0 && d <= 31) || !(m > 0 && m <= 12))
            printf("Wrong data! Pls, try again (example: 08.10.2021)\n");
	p->d = d;
	p->m = m;
	p->y = y;

}

void InputCondition(Condition *p) 
{
	if (!p)
		return;
	int complited, paid;
	while (printf("\tcondition (1 - done or 0 - not, 1 - paid or 0 - not):"),
				fflush(stdin),
            	scanf("%d, %d", &complited, &paid) != 2 || !(complited >= 0 && complited <= 1) || !(paid >= 0 && paid <= 1))
            printf("Error! Pls, try again (example: 1, 0)\n");
    p->complited = complited;
	p->paid = paid;
}

void InputOrder(Orders * p)
{
	if (!p)
		return;
	printf("Enter order info:\n\tcompany name: ");
	fflush(stdin);
	scanf("%[^\n]s", p->name_company);
	InputDate(&p->addmision);
	while (printf("\ttime (in minutes): "),
				fflush(stdin),
            	scanf("%d", &p->time) != 1)
            printf("Error! Pls, try again (example: 60)\n");
	while (printf("\tprice: "),
				fflush(stdin),
            	scanf("%d", &p->price) != 1)
            printf("Error! Pls, try again (example: 999)\n");
	InputCondition(&p->condition);
}

void PrintDate(const Date *p)
{
	if (!p)
		return;
	printf("%02d.%02d.%04d\n", p->d, p->m, p->y);
}

void PrintCondition(const Condition *p)
{	
	if (!p)
		return;
	if (p->complited == 1 && p->paid == 1)
		printf("\tcondition: done, paid\n");
	else if (p->complited == 1 && p->paid == 0)
		printf("\tcondition: done, not paid\n");
	else if (p->complited == 0 && p->paid == 1)
		printf("\tcondition: not done, paid\n");
	else
		printf("\tcondition: not done, not paid\n");
}

void PrintOrder(const Orders * p)
{
	if (!p)
		return;
	printf("\tcompany name: %s\n", p->name_company);
	printf("\taddmision: ");
	PrintDate(&p->addmision);
	printf("\ttime: %d minutes\n ", p->time);
	printf("\tprice: %d$\n", p->price);
	PrintCondition(&p->condition);
	printf("\n");
}

void InputOrdersArray(Orders *a, int n)
{
	if (!a)
		return;
	int i;
	for (i = 0; i < n; i++)
	{
		printf("Order %d\n", i+1);
		InputOrder(a + i);
		printf("\n");
	}
}

void PrintOrdersArray(const Orders *a, int n)
{
	if (!a)
		return;
	int i = 0;
	for (i; i < n; i++)
	{
		printf("Order %d info:\n", i+1);
		PrintOrder(a + i);
		printf("\n");
	}
}

double SummPrice(const Orders *a, int n) 
{
	if (!a)
		return;
	double summ = 0;
	int i = 0;
	for (i; i < n; i++)
		{
			
			if (Orders.condition.complited == 0 && Ordera.condition.paid == 1)			
			summ += a[i].price;
	    }	
	return summ;
}

/*
void Sort(Person *a, int n, Comparator cmp)
{
	int i, j;
	for (i = 0; i < n-1; i++)
		for (j = 0; j < n - 1- i; j++)
			if (cmp(&a[j], &a[j+1]))
			{
				Person p;
				p = a[j];
				a[j] = a[j+1];
				a[j+1] = p;
			}
}
*/

int main()
{
	Orders a[20];
	
	int n = 0;
	while (printf("Enter count (>0 and <20): "),
			fflush(stdin),
            scanf("%d", &n) != 1 || !(n > 0 && n <20))
        printf("Error! Pls, try again\n");
	
	InputOrdersArray(a, n);
	PrintOrdersArray(a, n);
	printf("sum = %lf", SummPrice(a, n));
	
	system("pause");
	return 0;
}
