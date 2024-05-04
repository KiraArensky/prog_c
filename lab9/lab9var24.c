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
            scanf("%lf", &p->time) != 1 || !(p->time > 0))
        printf("Error! Pls, try again (example: 60)\n");
    while (printf("\tprice: "),
            fflush(stdin),
            scanf("%lf", &p->price) != 1 || !(p->price >= 0))
        printf("Error! Pls, try again (example: 999)\n");
    InputCondition(&p->condition);
}

void InputOrderIndex(Orders *p, int k, int *n) {
    int i;
    for (i = *n; i > k; i--){
        p[i] = p[i-1];
    }
    printf("Enter order info:\n\tcompany name: ");
    fflush(stdin);
    scanf("%[^\n]s", p[k].name_company);
    InputDate(&p[k].addmision);
    while (printf("\ttime (in minutes): "),
            fflush(stdin),
            scanf("%lf", &p[k].time) != 1 || !(p[k].time > 0))
        printf("Error! Pls, try again (example: 60)\n");
    while (printf("\tprice: "),
            fflush(stdin),
            scanf("%lf", &p[k].price) != 1 || !(p[k].price >= 0))
        printf("Error! Pls, try again (example: 999)\n");
    InputCondition(&p[k].condition);
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

void InputOrdersArray(Orders *a, int *n) {
    if (!a)
        return;
    int i, kk;
    while (printf("Enter count (>0 and <%d): ", 20 - *n),
            fflush(stdin),
            scanf("%d", &kk) != 1 || !(kk > 0 && kk < (20 - *n)))
        printf("Error! Pls, try again\n");
    *n = *n + kk;
    for (i = *n - kk; i < *n; i++) {
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

typedef int (*ComparatorSummPrice)(const Orders *a);

int CompSummPrice(const Orders *a) {
    return (a->condition.complited == 0 && a->condition.paid == 1);
}

double SummPrice(const Orders *a, int n, ComparatorSummPrice cmp) {
    if (!a)
        return -1;
    double summ = 0;
    int i = 0;
    for (i; i < n; i++) {
        if (cmp(&a[i]))
            summ += (a + i)->price;
    }
    return summ;
}

typedef int (*ComparatorSummTime)(const Orders *a);

int CompSummTime(const Orders *a) {
    return (a->condition.paid == 0);
}

double SummTime(const Orders *a, int n, ComparatorSummTime cmp) {
    if (!a)
        return -1;
    double summ = 0;
    int i = 0;
    for (i; i < n; i++) {
        if (cmp(&a[i]))
            summ += (a + i)->time;
    }
    return summ;
}

typedef int (*ComparatorSearch)(const Orders *a, const char name[51]);

int CompSearch(const Orders *a, const char name[51]) {
    return ((int) strstr(a->name_company, name));
}

void SearchName(const Orders *a, const char name[51], int n, ComparatorSearch cmp) {
    int i = 0, flag = 1;
    printf("Company name for the search: ");
    fflush(stdin);
    scanf("%[^\n]s", name);
    for (i; i < n; i++) {
        if (cmp(&a[i], name)) {
            PrintOrder(a + i);
            flag = 0;
        } else if (i == n - 1 && flag)
            printf("No orders found");
    }
}

typedef int (*ComparatorSort)(const Orders *b, const Orders *a);

int CompData(const Orders *b, const Orders *a) {
    return (a->addmision.y < b->addmision.y) ||
           (a->addmision.y == b->addmision.y && a->addmision.m < b->addmision.m) ||
           (a->addmision.y == b->addmision.y && a->addmision.m == b->addmision.m &&
            a->addmision.d < b->addmision.d);
}

void DataSort(Orders *a, int n, ComparatorSort cmp) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (cmp(&a[j], &a[j + 1])) {
                Orders p;
                p = a[j];
                a[j] = a[j + 1];
                a[j + 1] = p;
            }
    printf("Sort is done\n");
}

void DeleteOrder(Orders *a, int *n, int index) {
    int i = index;
    if (!a || index < 0 || index >= *n)
        return;
    for (i; i < (*n) - 1; i++)
        a[i] = a[i + 1];
    (*n)--;
    printf("Delete is done\n");
}

void DeleteAllOrders(Orders *a, int *n) {
    if (!a)
        return;
    *n = 0;
    printf("Delete is done\n");
}

void SaveOrdersToFile(const Orders *a, int n) {
    char filename[256];
    printf("Enter the filename to save: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Failed to open the file.\n");
        return;
    }
    fwrite(&n, sizeof(int), 1, file);
    fwrite(a, sizeof(Orders), n, file);
    fclose(file);
    printf("Data saved successfully.\n");
}

void LoadOrdersFromFile(Orders *a, int *n) {
    char filename[256];
    printf("Enter the filename to load: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open the file.\n");
        return;
    }
    fread(n, sizeof(int), 1, file);
    fread(a, sizeof(Orders), *n, file);
    fclose(file);
    printf("Data loaded successfully.\n");
}

void DestroyFileData() {
    char filename[256];
    printf("Enter the filename to destroy data: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Failed to open the file.\n");
        return;
    }
    fclose(file);
    printf("Data in file destroyed successfully.\n");
}

int main() {
    Orders a[20];
    char name_company_search[51];
    int n = 0, k = -1, i;

    while (printf("Select an action:\n\t1 - Adding an order\n\t2 - Adding multiple orders\n\t3 - Print order (need number)\n\t4 - Print all orders\n\t5 - Print cost of unfulfilled and paid orders\n\t6 - Print total duration of unpaid orders\n\t7 - Search by name\n\t8 - Sorting by date\n\t9 - Delete order (need number)\n\t10 - Delete all orders\n\t11 - Save data if file\n\t12 - Load data from file\n\t13 - Delete data in file\n\t-1 - Exit\n"),
            fflush(stdin),
            scanf("%d", &k) != 1 || !(k >= -1 && k < 14 && k != 0))
    printf("Error! Pls, try again\n");
    while (1) {
        switch ( k )
        {
            case 1:
                if (n < 20) {
                    printf("Enter the number under which to add the order: ");
                    if (scanf("%d", &k) != 1 || !(k > -1 && k <= n)) {
                        printf("Not in array\n");
                        break;
                    }
                    else {
                        InputOrderIndex(a, k - 1, &n);
                        n++;
                    }
                    break;
                }
                else {
                    printf("Orders array is maximum!\n\n");
                    break;
                }
            case 2:
                if (n < 20) {
                    InputOrdersArray(a, &n);
                    break;
                }
                else {
                    printf("Orders array is maximum!\n\n");
                    break;
                }
            case 3:
                if (n == 0) {
                    printf("Orders are empty");
                    break;
                }
                printf("The number of orders in the list: %d\n", n);
                printf("Number of order: ");
                if (scanf("%d", &i) != 1 || !(i > 0 && i <= n))
                    printf("Not in array\n");
                else
                    PrintOrder(a + i - 1);
                break;
            case 4:
                printf("The number of orders in the list: %d\n", n);
                PrintOrdersArray(a, n);
                break;
            case 5:
                printf("The cost of unfulfilled and paid orders = %.2lf\n", SummPrice(a, n, CompSummPrice));
                break;
            case 6:
                printf("Total duration of unpaid orders = %.2lf\n\n", SummTime(a, n, CompSummTime));
                break;
            case 7:
                SearchName(a, name_company_search, n, CompSearch);
                break;
            case 8:
                printf("Sorting by date:\n\n");
                DataSort(a, n, CompData);
                PrintOrdersArray(a, n);
                break;
            case 9:
                printf("The number of orders in the list: %d\n", n);
                printf("Number of order: ");
                if (scanf("%d", &i) != 1 || !(i > 0 && i <= n)) {
                    printf("Not in array\n");
                    break;
                }
                else
                    DeleteOrder(a, &n, i - 1);
                break;
            case 10:
                DeleteAllOrders(a, &n);
                break;
            case 11:
                SaveOrdersToFile(a, n);
                break;
            case 12:
                LoadOrdersFromFile(a, &n);
                break;
            case 13:
                DestroyFileData();
                break;
            case -1:
                system("pause");
                return 0;
        }
        while (printf("Select an action:\n\t1 - Adding an order\n\t2 - Adding multiple orders\n\t3 - Print order (need number)\n\t4 - Print all orders\n\t5 - Print cost of unfulfilled and paid orders\n\t6 - Print total duration of unpaid orders\n\t7 - Search by name\n\t8 - Sorting by date\n\t9 - Delete order (need number)\n\t10 - Delete all orders\n\t11 - Save data if file\n\t12 - Load data from file\n\t13 - Delete data in file\n\t-1 - Exit\n"),
                fflush(stdin),
                scanf("%d", &k) != 1 || !(k >= -1 && k < 14 && k != 0))
            printf("Error! Pls, try again\n");
    }
}
