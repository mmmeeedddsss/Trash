#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct LinkedList
{
     int value;
     struct LinkedList *next;
};

void insert(int x,int w,struct LinkedList *head)
{
     struct LinkedList *temp,*temp2,*temp3;
     temp=head;
     //w--;
     int i;
     for(i=0;i<w;i++) temp=temp->next;
     temp2 = (struct LinkedList*)malloc(sizeof(struct LinkedList));
     temp3 = (struct LinkedList*)malloc(sizeof(struct LinkedList));
     temp3=temp->next;
     temp->next=temp2;
     temp2->next=temp3;
     temp2->value=x;
     
     printf("Inserted %d to %d and replaced with %d ...\n\n",temp2->value,w,temp3->value);
}

void display(struct LinkedList *head)
{
     struct LinkedList *iterator;
     //iterator=(struct LinkedList)malloc(sizeof(struct LinkedList));
     iterator=head;
     int i=0;
     //printf("--> %d\n",iterator->value);
     printf("\nHead --> %d\n",head->value);
     i++;
     if(iterator->next!=NULL)
     {
           iterator=iterator->next;
          while(iterator->next!=NULL)
          {
               printf("%d .--> %d\n",i-1,iterator->value);
               i++;
               iterator=iterator->next;
          }
     printf("%d .--> %d\n",i-1,iterator->value);
     }
}

void look(int x,struct LinkedList *head)
{
     int i;
     struct LinkedList *iterator;
          iterator=head;
          for(i=1;i<x;i++)
                  if(iterator->next!=NULL){ iterator=iterator->next; }
                  else break;
     printf("%d. value is %d\n",i-1,iterator->value);
}
void insert_last(int x,struct LinkedList *head)
{
     struct LinkedList *iterator,*temp2;
     iterator=head;
     while(iterator->next!=NULL) iterator=iterator->next;
     temp2 = (struct LinkedList*)malloc(sizeof(struct LinkedList));
     iterator->next=temp2;
     temp2->next=NULL;
     temp2->value=x;
     printf("Inserted --> %d\n",iterator->next->value);
}
int main()
{
     struct LinkedList *head;
     head=(struct LinkedList*)malloc(sizeof(struct LinkedList));
     head->value=123;
     head->next=NULL;
     char x;
     int i,j;
     while(1)
     {
            scanf("%c",&x);
            switch(x)
            {
               case'i': scanf("%d",&i); scanf("%d",&j); insert(i,j,head); break;
               case's': scanf("%d",&i); insert_last(i,head); break;
               case'd': display(head); break;
               case'l': scanf("%d",&i); look(i,head); break;
            }  
     }
}
