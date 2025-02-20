//linked list
#include<stdio.h>
#include<stdlib.h>
int c=0;

struct node
{
  int data;
  struct node *next;
};
struct node *start;

void create()
{
  if(c==0)
  {
    struct node *ptr,*temp;
    int item,n,i=0;
    printf("Enter no. of nodes to insert : ");
    scanf("%d",&n);
    if(n==0)
    {
      printf("\n No Creation");
    }
    else
    {
      while(i<n)
      {
        printf("\n Enter the element:");
        scanf("%d",&item);
        ptr=node* malloc(sizeof(node));
        ptr->data=item;
        if(c==0)
        {
          start=ptr;
          start->next=start;
          c=1;
          i++;
          temp=start;
        }
        else
        {
          temp->next=ptr;
          temp=temp->next;
          i++;
        }
      }
     temp->next=start; 
    }
  }
  else
  {
    printf("\nList already created");
  }   
}

void insbeg()
{
  struct node *ptr,*temp;
  int item;
  ptr=(node*) malloc(sizeof(node));
  printf("\nEnter the element to insert : ");
  scanf("%d",&item);
  ptr->data=item;
  if(start==NULL)
  {
    start=ptr;
    ptr->next=start;      //
    c=1;
  }
  else
  {
    temp=start;
    while(temp->next!=start)
    {
      temp=temp->next;
    }
    temp->next=ptr;
    ptr->next=start;
    start=ptr;
  }
}

void insend()
{
  struct node *temp,*ptr;
  int item;
  ptr=(node*) malloc(sizeof(node));
  printf("\n Enter the element to insert : ");
  scanf("%d",&item);
  ptr->data=item;
  if(start==NULL)
  {
    start=ptr;
    start->next=start;     //
    c=1;
  }
  else
  {
    temp=start;
    while(temp->next!=start)
    {
      temp=temp->next;  //to find last node
    }
    temp->next=ptr;
    ptr->next=start;      //
  }
}

void inspos()
{
  struct node *temp,*ptr;
  int item,count=0,pos ;
  ptr=(node*) malloc(sizeof(node));
  printf("\nEnter the position to insert : ");
  scanf("%d",&pos);
  printf("\n Enter the element to insert : ");
  scanf("%d",&item);
  ptr->data=item;
  if(pos==1)
  {
    temp=start;
    while(temp->next!=start)
    {
      temp=temp->next;
    }
    temp->next=ptr;
    ptr->next=start;
    start=ptr;
  }
  else
  {
  temp=start;
  while(count<pos-2) // to exact pos 2
  {
    temp=temp->next;
    count++;
  }
  ptr->next=temp->next;
  temp->next=ptr;
  }
}

void delbeg()
{
  struct node *temp,*prev;
  if(start==NULL)
  {
    printf("\n List is empty");
  }
  else
  {
    temp=start;
    if(start->next=start)
    {
      start=NULL;
    }
    else
    {
      prev=NULL;
      while(temp->next!=start)
      {
        prev=temp;
        temp=temp->next;
      }
      prev->next=start->next;
      start=start->next;
    }
    if(start == NULL)
    {
      c=0;
    }
  }
}

void delend()
{
  struct node *ptr,*temp;
  if(start==NULL)
  {
    printf("\n List is empty");
  }
  else if(start->next==start) 
  {
    start=NULL;
    free(start);
    c=0;
  }
  else
  {
    temp=start;
    while(temp->next->next!=start)//to find node before last node 
    {
      temp=temp->next; // to find last node
    }
    ptr=temp->next;
    temp->next=start;
    free(ptr); //to delete ptr memory space
  }
}

void delpos()
{
  struct node *temp,*ptr;
  int item,count=0,pos ;
  printf("\nEnter the position to delete : ");
  scanf("%d",&pos);
  if(start==NULL)
  {
    printf("\n List is empty");
  }
  else if(pos==1)
  {
    temp=start;
    if(temp->next==start)
    {
      start=NULL;
    }
    else
    {
      start=start->next;  
    }
    free(temp);
    if(start == NULL)
    {
      c=0;
    }
  }
  else
  {
  temp=start;
  while(count<pos-2 && temp!=NULL) // to exact pos 2
  {
    temp=temp->next;
    count++;
  }
  if(temp==NULL || temp->next==NULL)
  {
    printf("\nPosition out of bounds");
  }
  else 
  {
    ptr=temp->next;
    temp->next=ptr->next;
    free(ptr);
  }
  }
}

void disp()
{
  struct node *ptr;
  ptr=start;
  if(ptr==NULL)
  {
    printf("\n List is empty");
  }
  else
  {
    printf("\nList : ");
    /*while(ptr->next!=start)
    {
      printf("%d ",ptr->data);
      ptr=ptr->next;
    }*/
    do
    {
      printf("%d ",ptr->data);
      ptr=ptr->next;
    }while(ptr!=start);
  }
}

int main(void)
{
   int ch;
   while(1)
   {
     printf("\n\n1.Create \n2.Display \n3.Insert at beginning \n4.Insert at end \n5.Delete at beginning \n6.Delete at end \n7.Insert at pos\n8.Delete at pos\n9.Exit\n\nEnter Your Choice:");
     scanf("%d",&ch);
     switch(ch)
     {
       case 1:
         create();
         break;
       case 2:
         disp();
         break;
       case 3:
         insbeg();
         break;
       case 4:
         insend();
         break;
       case 5:
         delbeg();
         break;
       case 6:
         delend();
         break;
       case 7:
         inspos();
         break;
       case 8:
         delpos();
         break;
       case 9:
         exit(0);
         break;
       default:
       printf("\nEnter valid choice");
     }
   }
   return 0;
}
