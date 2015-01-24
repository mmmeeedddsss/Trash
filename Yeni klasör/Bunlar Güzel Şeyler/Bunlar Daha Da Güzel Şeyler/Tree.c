#include<stdio.h>
#include<stdlib.h>
struct Tree{
     int value;
     struct Tree *right,*left;   
};

int insert(int x,struct Tree *root)
{
         struct Tree *temp;
         temp=(struct Tree*)malloc(sizeof(struct Tree));
         if(x>root->value)
         {     
               if(root->right==NULL)
               {
                    root->right=temp;
                    temp->value=x;
                    temp->right=NULL;
                    temp->left=NULL;
                    return 0;
               }
               else
                    insert(x,root->right);
         }
         else
         {
               if(root->left==NULL)
               {
                    root->left=temp;
                    temp->value=x;
                    temp->right=NULL;
                    temp->left=NULL;
                    return 0;
               }
               else
                    insert(x,root->left);
          }
}

void display(struct Tree *root)
{
     if(root!=NULL)
     {
          display(root->left);
          printf("%d\n",root->value);
          display(root->right);
     }
} 

int main()
{
         struct Tree *root;
         root=(struct Tree*)malloc(sizeof(struct Tree));
         root->right=NULL;
         root->left=NULL;
         int x,j,i;
         scanf("%d",&root->value);
         scanf("%d",&x);
         for(i=0;i<x;i++)
         {
               scanf("%d",&j);
               insert(j,root);
         }
         display(root);
         getch();
}
