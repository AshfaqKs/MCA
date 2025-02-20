//  stack using linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *prev;
};
struct node *top=NULL;

void push()
{
  struct node *ptr;
  int item;
  ptr=(node*) malloc(sizeof(node));
  printf("\nEnter the element to push : ");
  scanf("%d",&item);
  ptr->data=item;
  ptr->prev=top;
  top=ptr;
}

void pop()
{
  if(top==NULL)
  {
    printf("\nStack Underflow");
  }
  else
  {
    struct node *temp;
    temp=top;
    top=top->prev;
    free(temp);
    printf("\nStack element popped");
  }
}

void disp()
{
  struct node *ptr;
  ptr=top;
  if(ptr==NULL)
  {
    printf("\nStack is empty");
  }
  else
  {
    printf("\nStack : ");
    while(ptr!=NULL)
    {
      printf("%d ",ptr->data);
      ptr=ptr->prev;
    }
  }
}

int main(void)
{
   int ch;
   printf("\n\nMENU\n\n1.Display \n2.Push\n3.Pop\n4.Exit\n");
   while(1)
   {
     printf("\n\nEnter Your Choice : ");
     scanf("%d",&ch);
     switch(ch)
     {
       case 1:
         disp();
         break;
       case 2:
         push();
         break;
       case 3:
         pop();
         break;
       case 4:
         exit(0);
         break;
       default:
       printf("\nEnter valid choice");
     }
   }
   return 0;
}
