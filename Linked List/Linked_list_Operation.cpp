#include <iostream>
using namespace std;

typedef struct node
{
    int info;
    struct node *next;
} node;

void insert(node **head, int n)
{
    node *p = (node *)malloc(sizeof(node));
    if (p)
    {
        p->info = n;
        p->next = NULL;
        if (*head == NULL)
        {
            *head = p;
        }
        else
        {
            p->next = *head;
            *head = p;
        }
    }
    else
    {
        cout << "MEMORY ERROR!";
    }
}

void display(node *head)
{
    while (head != NULL)
    {
        cout << head->info << " ";
        head = head->next;
    }
}

int Listlength(node *head)
{
    int c = 0;
    while (head != NULL)
    {
        head = head->next;
        c++;
    }
    return c;
}
int main()
{
    node *head = NULL;
    int choice;
    while (1)
    {
        cout << "\n1,2,3 Insert at begin end and mid" << endl;
        cout << "4 display 5 length count" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int n;
            cin >> n;
            insert(&head, n);
            break;
        case 2:
            int n;
            cin >> n;
            insert_at_end(&head, n);
            break;
        case 3:
            break;
        case 4:
            display(head);
            break;
        case 5:
            cout << Listlength(head) << endl;
            break;
        }
    }
}
