#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct single_linked_list
{
    struct single_linked_list *next;
    int data;
} node;

node *head = NULL;

int createlist()
{
    printf("How many elements would you like to input?");
    int x;
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        node *nn = (node *)malloc(sizeof(node));
        int ele;
        printf("Enter data for element %d: ", i + 1);
        scanf("%d", &ele);
        nn->data = ele;
        nn->next = NULL;
        if (head == NULL)
        {
            head = nn;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = nn;
        }
    }
}

void insertatbeg(node *head)
{
    printf("Insert val to put at begenning");
    int x;
    scanf("%d", &x);

    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->next = head; // make the link to next node
    head = nn;       // change head pointer to the new start of list
}

void insertatend(node **head)
{
    int x;
    printf("Insert val to put at end");
    scanf("%d", &x);

    node *nn = (node *)malloc(sizeof(node));
    nn->data = x;
    nn->next = NULL;

    if (*head = NULL) // if the list is empty
    {
        *head = nn;
        return;
    }

    node *temp = *head;        // not necessary but better
    while (temp->next != NULL) // go to the last node
    {
        temp = temp->next;
    }
    temp->next = nn;
}

void insertatpos(node **head)
{
    int x, pos, i = 1;
    printf("Enter The Value To Be Inserted \n");
    scanf("%d", &x);
    printf("Enter the Position\n");
    scanf("%d", &pos);

    node *nn = (node *)malloc(sizeof(node));
    node *temp = *head;
    nn->data = x;

    if (pos == 1)
    {
        nn->next = *head;
        *head = nn;
        return;
    }

    while (i < pos - 1) // goto the node just before pos
    {
        temp = temp->next;
    }
    nn->next = temp->next;
    temp->next = nn;
}

void insertbefore(node *head)
{
    int c, d;
    node *nn = (node *)malloc(sizeof(node));
    printf("Enter The Value To Be Inserted \n");
    scanf("%d", &c);
    printf("Enter the val before which to insert:\n");
    scanf("%d", &d);

    nn->data = c;
    nn->next = NULL;

    if (head->data == d) // if head itself if the node before which to insert
    {
        nn->next = head;
        head = nn;
        return;
    }

    node *temp = head;
    while (temp->next->data != d && temp->next != NULL) // matching with the data of node to insert before
    {
        temp = temp->next;
    }
    nn->next = temp->next;
    temp->next = nn;
}

void insertafter(node *head)
{
    int c, d;
    node *nn = (node *)malloc(sizeof(node));
    printf("Enter The Value To Be Inserted \n");
    scanf("%d", &c);
    printf("Enter the val after which to insert:\n");
    scanf("%d", &d);

    nn->data = c;
    nn->next = NULL;

    node *temp = head;

    while (temp->data != d) // go to the node after which to insert
    {
        temp = temp->next;
    }

    nn->next = temp->next;
    temp->next = nn;
}

// deletion functions:
void delatbeg(node **head)
{
    if (*head == NULL)
    {
        printf("List already empty\n");
        return;
    }

    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteatend(node **head)
{
    if (*head == NULL)
    {
        printf("List is already empty\n");
        return;
    }

    node *temp = *head;

    if (temp->next == NULL)
    {
        free(temp);
        temp = NULL;
        return;
    }
    node *del = NULL;
    while (temp->next != NULL)
    {
        del = temp;
        temp = temp->next;
    }
    if (del != NULL) {
        del->next = NULL;
    } else {
        *head = NULL;
    }
    free(temp);
}

void updateele(node *head)
{
    int new;
    int ele;
    printf("Enter the element which should be updated: ");
    scanf("%d", &ele);
    printf("Enter new value: ");
    scanf("%d", &new);

    node *temp = head;

    while (temp->data != ele && temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->data == ele)
    {
        temp->data = new;
    }
    else
    {
        printf("Reached end of list but didn't find the value");
    }
}

void updateatbeg(node *head)
{
    printf("Enter the new value for first node: ");
    int new;
    scanf("%d", &new);

    head->data = new;
}

void updateatend(node *head)
{
    printf("Enter the new value for last node: ");
    int new;
    scanf("%d", &new);

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->data = new;
}

void display(node *head)
{
    node *temp = head;
    if (head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        int count = 0;
        while (temp!= NULL)
        {
            printf("%d ", temp->data);
            temp=temp->next;
            count++;
        }
        printf("Printed %d elements in the list\n", count);
    }
}

int main()
{
    int choice;
    while (true)
    {
        printf("\nMenu:\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Exit\n");
        printf("6. Insert Before\n");
        printf("7. Insert After\n");
        printf("8. Delete at Beginning\n");
        printf("9. Delete at End\n");
        printf("10. Update Element\n");
        printf("11. Update at Beginning\n");
        printf("12. Update at End\n");
        printf("13. Display List\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createlist();
            break;
        case 2:
            insertatbeg(head);
            break;
        case 3:
            insertatend(&head);
            break;
        case 4:
            insertatpos(&head);
            break;
        case 5:
            exit(0);
        case 6:
            insertbefore(head);
            break;
        case 7:
            insertafter(head);
            break;
        case 8:
            delatbeg(&head);
            break;
        case 9:
            deleteatend(&head);
            break;
        case 10:
            updateele(head);
            break;
        case 11:
            updateatbeg(head);
            break;
        case 12:
            updateatend(head);
            break;
        case 13:
            display(head);
            break;
        default:
            printf("Invalid choice, please try again.\n");
        }

        sleep(2);
    }
}
