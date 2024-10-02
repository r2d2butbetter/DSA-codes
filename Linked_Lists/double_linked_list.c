#include <stdio.h>
#include <stdalign.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct double_linked_list
{
    struct double_linked_list *prev;
    int data;
    struct double_linked_list *next;
}node;

void createlist(node** head, node** tail)
{
    printf("Enter the number of elements you want to enter: ");
    int x;
    scanf("%d", &x);

    for (int i = 0; i < x; i++)
    {
        node *nn = (node*)malloc(sizeof(node));
        int ele;
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &ele);
        nn->data = ele;
        nn->next = NULL;
        nn->prev = NULL;

        if (*head == NULL) // it's the first element
        {
            *head = *tail = nn;
        }
        else
        {
            (*tail)->next = nn;
            nn->prev = *tail;
            *tail = nn;
        }
    }
}

void insertatbeg(node** head)
{
    node* nn=(node*)malloc(sizeof(node));
    printf("Enter value to insert at begenning: ");
    int x;
    scanf("%d", &x);
    nn->data=x;
    nn->prev=NULL;
    
    nn->next=*head;
    (*head)->prev=nn;
    *head=nn;
}


void insertatend(node** head, node** tail)
{
    node* nn=(node*)malloc(sizeof(node));
    printf("Enter value to insert at end: ");
    int x;
    scanf("%d", &x);
    nn->data=x;
    nn->next=NULL;

    nn->prev=*tail;
    (*tail)->next=nn;
    *tail=nn;
}

void insertatpos(node** head)
{
    node* nn=(node*)malloc(sizeof(node));
    printf("Enter value to insert: ");
    int x;
    scanf("%d", &x);
    int index;
    printf("Enter the position at which to insert");

    if (index<1)
    {
        printf("Invalid index. Starts from 1");
    }
    

    if (index==1)
    {
        insertatbeg(head);
        return;
    }
    

    scanf("%d", &index);
    node* temp=*head;

    int i=0;
    while (i<index-1)
    {
        temp=temp->next;
        i++;
    }

    nn->prev=temp;
    nn->next=temp->next;
    temp->next=nn;
    nn->next->prev=nn; //setting backward link from node after newnode to the newnode itself
    
}


void delatbeg(node** head)
{
    if ((*head)==NULL)
    {
        printf("List is already empty!");
        return;
    }

    node* temp=(*head);
    *head=(*head)->next;

    if (*head !=NULL) //if list is not left empty after this delete
    {
        (*head)->prev=NULL; //remove the backward link
    }

    temp->next=NULL;
    free(temp);
    
}


void delatend(node** tail)
{
    if ((*tail)==NULL)
    {
        printf("List is already empty!");
        return;
    }

    node* temp= *tail;
    (*tail)=(*tail)->prev;
    if (*tail!=NULL)
    {
        (*tail)->next=NULL; //prev ndoe is now last node
    }

    temp->prev=NULL;
    free(temp);

}


void updateele(node* head)
{
    if (head==NULL)
    {
        printf("List is empty!");
        return;
    }

    node* temp=head;
    printf("Enter the element to update: ");
    int ele;
    scanf("%d", &ele);
    int val;
    printf("Enter the new val: ");
    scanf("%d", &val);

    while (temp->data!=ele && temp!=NULL)
    {
        temp=temp->next;
    }
    
    if (temp==NULL)
    {
        printf("Reached end of list but didn't find that element\n");
        return;
    }

    temp->data=val;
    printf("Updated element successfully!\n");

}

void updateatbeg(node* head)
{
    printf("Enter new val to update at first node: ");
    int c;
    scanf("%d", &c);

    head->data=c;
}

void updateatend(node* tail)
{
    printf("Enter value to update at the last node: ");
    int c;
    scanf("%d", &c);

    tail->data=c;
}

void displayrev(node** tail)
{
    node* temp=(*tail);

    if (temp==NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    while (temp!=NULL)
    {
        printf("%d ", temp->data);
        temp=temp->prev;
    }
    
    printf("\n"); //printing the last node
}

void display(node** head)
{
    node* temp=*head;
    while (temp!=NULL)
    {
        printf("%d ", temp->data );
        temp=temp->next;
    }
    
}

int main()
{
    int choice;
    node* head=NULL;
    node* tail=NULL;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create list\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Insert at position\n");
        printf("5. Delete at beginning\n");
        printf("6. Delete at end\n");
        printf("7. Update element\n");
        printf("8. Update at beginning\n");
        printf("9. Update at end\n");
        printf("10. Display list\n");
        printf("11. Display list in reverse\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createlist(&head, &tail);
                break;
            case 2:
                insertatbeg(&head);
                break;
            case 3:
                insertatend(&head, &tail);
                break;
            case 4:
                insertatpos(&head);
                break;
            case 5:
                delatbeg(&head);
                break;
            case 6:
                delatend(&tail);
                break;
            case 7:
                updateele(head);
                break;
            case 8:
                updateatbeg(head);
                break;
            case 9:
                updateatend(tail);
                break;
            case 10:
                display(&head);
                break;
            case 11:
                displayrev(&tail);
                break;
            case 12:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}