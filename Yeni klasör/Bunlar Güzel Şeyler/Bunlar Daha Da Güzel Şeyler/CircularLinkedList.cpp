#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct List{
     int value;
     struct List *next,*prev;
};

void change_head(int x,struct List **head)
{
     struct List *temp;
     temp=(struct List *)malloc(sizeof(struct List));
     if(*head==NULL) 
     {
          //*(head)=temp;
          (*head)->next=NULL;
          (*head)->prev=NULL;
          (*head)->value=x;
     }
     else
     {
              temp->next=*head;
              (*head)->prev=temp;
              temp->prev=NULL;
              temp->value=x;
     }
}

void insert(int x,struct List *head)
{
     struct List *iterator,*temp;
     iterator=head;
     temp=(struct List *)malloc(sizeof(struct List));
     iterator=(struct List *)malloc(sizeof(struct List));
         //while(iterator->next!=NULL) iterator=iterator->next;
         
         iterator->next=temp;
         temp->prev=iterator;
         temp->value=x;
         iterator->next=NULL;
}

void display(struct List *head)
{
     struct List *iterator;
     iterator=head;
     printf("\n--> %d",iterator->value);
     while(iterator->next!=NULL)
     {
          iterator=iterator->next; 
          printf("\n--> %d",iterator->value);
     }
}

int main()
{
     struct List *head;
     head=(struct List*)malloc(sizeof(struct List));
     head=NULL;
     change_head(10,&head);
     head->next=NULL;
     printf("%d",head->value);
     insert(12,head);
     insert(12,head);
     insert(12,head);
     insert(12,head);
     display(head);
     getch();
}
