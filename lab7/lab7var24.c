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
	while (printf("\taddmision (dd.mm.yyyy): "),
				fflush(stdin),
                scanf("%d.%d.%d", &p->d, &p->m, &p->y) != 3)
            printf("Wrong data! Pls, try again (example: 08.10.2021)\n");
}

void InputCondition(Condition *p) 
{
	while (printf("\tcondition (1 - done or 0 - not, 1 - paid or 0 - not):"),
				fflush(stdin),
            	scanf("%d, %d", &p->complited, &p->paid) != 2)
            printf("Error! Pls, try again (example: 1, 0)\n");
}

void InputOrder(Orders * p)
{
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
	printf("%02d.%02d.%04d\n", p->d, p->m, p->y);
}

void PrintCondition(const Condition *p)
{	
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
	int i;
	for (i = 0; i < n; i++)
	{
		printf("Order %d info:\n", i+1);
		PrintOrder(a + i);
		printf("\n");
	}
}

double SummPrice(const Orders *a, int n)
{
	
}

int main()
{
	Orders a[20];
	
	int n = 0;
	printf("Enter count: ");
	scanf("%d", &n);
	
	InputOrdersArray(a, n);
	PrintOrdersArray(a, n);
	
	
	system("pause");
	return 0;
}
