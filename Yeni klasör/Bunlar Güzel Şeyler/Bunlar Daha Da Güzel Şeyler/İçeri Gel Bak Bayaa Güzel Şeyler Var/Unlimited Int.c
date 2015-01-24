#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

struct list_el {
     int val;
     struct list_el *next;
};

     typedef struct list_el item;
     
void carp(int i,struct list_el *head)
{
     item *iterator = head;
     int eklencek = 0;
     while(iterator->next != NULL)
     {
          iterator->val *= i;
          iterator->val += eklencek;
          eklencek = 0;
          
          if(iterator->val >= 10 )
          {
               eklencek = ( iterator->val / 10 ); // Eldeyi Verdi ..
               iterator->val = iterator->val - (iterator->val / 10) * 10;
          }
          iterator = iterator->next;
     }
     iterator->next = (item *)malloc(sizeof(item));
     iterator->next->val = 0;
     iterator->next->next = NULL;
     iterator->val *= i;
     iterator->val += eklencek;
     
     if(iterator->val >= 10 )
     {
          iterator->next->val += ( iterator->val / 10 ); // Eldeyi Verdi ..
          iterator->val = iterator->val - (iterator->val / 10) * 10;
     }
}

int main()
{
     item *curr,*head,*iterator;
     int i;
     iterator = NULL;
     head = NULL;

     while(1)
     {
          curr = (item *)malloc(sizeof(item));
          i = getche();
          if(i == '-')
          {
               curr->next = NULL;
               break;
          }
          curr->val = i-48;
          curr->next = head;
          head = curr;
     }
     /*
     iterator = head;
     puts("\n");
     while(iterator->next != NULL)
     {
          printf("%d",iterator->val);
          iterator = iterator->next;
     }
     printf("%d\n\n\n",iterator->val);
     */
     
     printf("a");
     iterator = head;
     carp(2,head);
     printf("\n");
     while(iterator->next != NULL )
     {
          printf("%d",iterator->val);
          iterator = iterator -> next;
     }
     printf("%d",iterator->val);
     getch();
}
