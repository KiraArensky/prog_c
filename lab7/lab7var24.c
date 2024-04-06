#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Date {
    unsigned int d: 5;
    unsigned int m: 4;
    int y: 13;
} Date;

typedef struct Condition {
    unsigned int complited: 1;
    unsigned int paid: 1;
} Condition;


typedef struct Orders {
    char name_company[51];
    Date addmision;
    double time;
    double price;
    Condition condition;
} Orders;

void InputDate(Date *p) {
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

void InputCondition(Condition *p) {
    if (!p)
        return;
    int complited, paid;
    while (printf("\tcondition (1 - done or 0 - not, 1 - paid or 0 - not): "),
            fflush(stdin),
            scanf("%d, %d", &complited, &paid) != 2 || !(complited >= 0 && complited <= 1) || !(paid >= 0 && paid <= 1))
        printf("Error! Pls, try again (example: 1, 0)\n");
    p->complited = complited;
    p->paid = paid;
}

void InputOrder(Orders *p) {
    if (!p)
        return;
    printf("Enter order info:\n\tcompany name: ");
    fflush(stdin);
    scanf("%[^\n]s", p->name_company);
    InputDate(&p->addmision);
    while (printf("\ttime (in minutes): "),
            fflush(stdin),
            scanf("%lf", &p->time) != 1)
        printf("Error! Pls, try again (example: 60)\n");
    while (printf("\tprice: "),
            fflush(stdin),
            scanf("%lf", &p->price) != 1)
        printf("Error! Pls, try again (example: 999)\n");
    InputCondition(&p->condition);
}

void PrintDate(const Date *p) {
    if (!p)
        return;
    printf("%02d.%02d.%04d\n", p->d, p->m, p->y);
}

void PrintCondition(const Condition *p) {
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

void PrintOrder(const Orders *p) {
    if (!p)
        return;
    printf("\tcompany name: %s\n", p->name_company);
    printf("\taddmision: ");
    PrintDate(&p->addmision);
    printf("\ttime: %.2lf minutes\n ", p->time);
    printf("\tprice: %.2lf$\n", p->price);
    PrintCondition(&p->condition);
    printf("\n");
}

void InputOrdersArray(Orders *a, int n) {
    if (!a)
        return;
    int i;
    for (i = 0; i < n; i++) {
        printf("Order %d\n", i + 1);
        InputOrder(a + i);
        printf("\n");
    }
}

void PrintOrdersArray(const Orders *a, int n) {
    if (!a)
        return;
    int i;
    for (i = 0; i < n; i++) {
        printf("Order %d info:\n", i + 1);
        PrintOrder(a + i);
        printf("\n");
    }
}

double SummPrice(const Orders *a, int n) {
    if (!a)
        return;
    double summ = 0;
    int i = 0;
    for (i; i < n; i++) {
        if ((a + i)->condition.complited == 0 && (a + i)->condition.paid == 1)
            summ += (a + i)->price;
    }
    return summ;
}

double SummTime(const Orders *a, int n) {
    if (!a)
        return;
    double summ = 0;
    int i = 0;
    for (i; i < n; i++) {
        if ((a + i)->condition.paid == 0)
            summ += (a + i)->time;
    }
    return summ;
}

void SearchName(const Orders *a, const char name[51], int n) {
    int i = 0, flag = 1;
    for (i; i < n; i++) {
        if (!(strcmp((a + i)->name_company, name))) {
            PrintOrder(a + i);
            flag = 0;
        } else if (i == n - 1 && flag)
            printf("No orders found");
    }
}

typedef int (*Comparator)(const Orders *b, const Orders *a);

int CompWeight(const Orders *b, const Orders *a) {
    return (a->addmision.y < b->addmision.y) ||
           (a->addmision.y == b->addmision.y && a->addmision.m < b->addmision.m) ||
           (a->addmision.y == b->addmision.y && a->addmision.m == b->addmision.m &&
            a->addmision.d < b->addmision.d);
}

void DataSort(Orders *a, int n, Comparator cmp) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (cmp(&a[j], &a[j + 1])) {
                Orders p;
                p = a[j];
                a[j] = a[j + 1];
                a[j + 1] = p;
            }
}

int main() {
    Orders a[20];
    char name_company_search[51];
    int n = 0;

    while (printf("Enter count (>0 and <20): "),
            fflush(stdin),
            scanf("%d", &n) != 1 || !(n > 0 && n < 20))
        printf("Error! Pls, try again\n");

    InputOrdersArray(a, n);

    printf("\n\n__________________________________________\n\n");

    PrintOrdersArray(a, n);

    printf("The cost of unfulfilled and paid orders = %.2lf\n", SummPrice(a, n));
    printf("Total duration of unpaid orders = %.2lf\n\n", SummTime(a, n));

    printf("Company name for the search: ");
    fflush(stdin);
    scanf("%[^\n]s", name_company_search);

    SearchName(a, name_company_search, n);

    printf("Sorting by date:\n\n");
    DataSort(a, n, CompWeight);
    PrintOrdersArray(a, n);


    system("pause");
    return 0;
}
