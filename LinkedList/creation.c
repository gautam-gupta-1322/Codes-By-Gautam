// CODE TO CREATE LINKED LIST AND DISPLAYING ELEMENTS OF LINKED LIST ----->
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head = 0, *ptr = 0, *end = 0;

void new ()
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node) * 1);
    printf("\n Enter data for this node -> ");
    scanf("%d", &new->data);
    if (head == 0)
    {
        head = new;
        ptr = new;
        ptr->next = 0;
        end = new;
    }
    else
    {
        ptr->next = new;
        ptr = new;
        ptr->next = 0;
        end = new;
    }
}
void display()
{
    ptr = head;
    if (head == 0)
    {
        printf("\nnList is empty !!!");
        return;
    }
    printf("\nYour list is = ");
    while (ptr != 0)
    {
        printf("%d,", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    int n;
    printf("Enter how many elements you want in your list = ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        new ();
    }
    display();
}