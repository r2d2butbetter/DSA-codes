#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct single_linked_list
{
    struct single_linked_list *next;
    int data;
}node;

node *head=NULL;

int createlist()
{
    printf("How many elements would you like to input?");
    int x;
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        node* nn=(node*)malloc(sizeof(node));
        int ele;
        printf("Enter data for element %d", i);
        scanf("%d", &ele);
        if (head==NULL)
        {
            head->data=ele;
        }
        
    }
}

void insertatbeg(node* head)
{
    printf("Insert val to put at begenning");
    int x;
    scanf("%d", &x);

    node* nn=(node*) malloc(sizeof(node));
    nn->data=x;
    nn->next=head; //make the link to next node
    head=nn;   //change head pointer to the new start of list
}

void insertatend(node* head)
{
    int x;
    printf("Insert val to put at begenning");
    scanf("%d", &x);

    node *nn=(node*)malloc(sizeof(node));
    nn->data=x;
    nn->next=NULL;

    node* temp=head; //not necessary but better
    while (temp->next !=NULL)//go to the last node
    {
        temp=temp->next;
    }
    temp->next=nn;
}

void insertatpos(node* head)
{
    int x, pos, i = 1;
    printf("Enter The Value To Be Inserted \n");
    scanf("%d", &x);
    printf("Enter the Position\n");
    scanf("%d", &pos);

    node* nn=(node*)malloc(sizeof(node));
    node* temp=head;
    nn->data=x;

    while (i<pos-1)//goto the node just before pos
    {
        temp=temp->next;
    }
    nn->next=temp->next;
    temp->next=nn;
}

int main()
{
    int choice;
    while (true) {
        printf("\nMenu:\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createlist();
                break;
            case 2:
                insertatbeg(head);
                break;
            case 3:
                insertatend(head);
                break;
            case 4:
                insertatpos(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

}