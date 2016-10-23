#include<stdio.h>
#include<conio.h>
struct node
{ int data;
struct node *next;
}*start=NULL;
//struct node *start=NULL;
void create_ll();
void insert_after();
void insert_before();
void insert_beginning();
void insert_sortedlist();
void delete_beggining();
void delete_end();
void delete_node();
void delete_after();
void display();
main()
{ int option;
  clrscr();
  do
  { printf("\n 1. insert");
    printf("\n 2. display");
    printf("\n 3. insert at beginning");
    printf("\n 4. insert after");
    printf("\n 5. inserted before");
    printf("\n 6. insertion in sorted list");
    printf("\n 7. delete from beginning");
    printf("\n 8. delete from end");
    printf("\n 9. exit");
    printf("\n enter your choice");
    scanf("%d",&option);
    switch(option)
    { case 1: create_ll();
	      break;
      case 2: display();
	      break;
      case 3: insert_beginning();
	      break;
      case 4: insert_after();
	      break;
      case 5: insert_before();
	      break;
      case 6: insert_sortedlist();
	      break;
      case 7: delete_beggining();
	      break;
      case 8: delete_after();
	      break;
      case 9: exit(0);
	      break;
      default: printf("\n wroung option");
    }
  } while(option);
 getch();
 return 0;
}
void delete_beggining()
{ struct node *ptr;
  if(start==NULL)
  printf("\n linked list empty");
  else
  {
  ptr=start;
  printf("\n value deleted is =%d",start->data);
  start=start->next;
  free(ptr);
  }
}
void delete_end()
{ struct node *ptr,*preptr;
  if(start==NULL)
  printf("\n linked list empty");
  else
  {preptr=ptr=start;
   while(ptr->next!=NULL)
  {  preptr=ptr;
     ptr=ptr->next;
  }
  if(preptr==start && ptr==start)
  { start=NULL;
  }
  else
  preptr->next=NULL;
  printf("\n value deleted is =%d",ptr->data);
  free(ptr);  }}
void delete_node()
{ struct node *ptr,*preptr; int val;
  if(start==NULL)
  printf("\n linked list empty");
  else
  { printf("\n value u want to delete");
    scanf("%d",&val);
    preptr=ptr=start;
	while(ptr->data!=val && ptr->next!=NULL)
		{ preptr=ptr;
		  ptr=ptr->next;
		}
		if(ptr->data==val)
		{
		  if(preptr==start && ptr==start)
		   start=ptr->next;
		else
		 preptr->next=ptr->next;
		  printf("\n value deleted");
		  free(ptr);
		}
		else
		 printf("\n no data available");   }}
void delete_after()
{ struct node *ptr,*preptr; int val;
  if(start==NULL)
  printf("\n linked list empty");
  else
  { printf("\n value u want to delete");
    scanf("%d",&val);
    preptr=ptr=start;
	while(ptr->data!=val && ptr->next!=NULL)
		{ ptr=ptr->next;
		}

		if(ptr->data==val && ptr->next!=NULL)
		{ preptr=ptr;
		  ptr=ptr->next;
		  preptr->next=ptr->next;
		  printf("\n value deleted is =%d",ptr->data);
		  free(ptr);
		}
		else
		 printf("\n no data available");
   }}

void create_ll()
{ struct node *newnode,*ptr; int val;
  printf("\n enter new element");
  scanf("%d",&val);
  newnode=(struct node *) malloc(sizeof(struct node));
  if(start==NULL)
  { newnode->data=val;
    newnode->next=NULL;
    start=newnode;
  }
  else
  { ptr=start;
    while(ptr->next!=NULL)
    { ptr=ptr->next;
	}
    newnode->data=val;
    ptr->next=newnode;
    newnode->next=NULL;
    }
}
void display()
{   struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {printf("%d\t",ptr->data);
     ptr=ptr->next;
    }
}
void insert_beginning()
{ struct node *newnode; int val;
  printf("\n enter new element");
  scanf("%d",&val);
  newnode=(struct node *) malloc(sizeof(struct node));
  if(start==NULL)
  { newnode->data=val;
    newnode->next=NULL;
    start=newnode;
  }
  else{
    newnode->data=val;
    newnode->next=start;
    start=newnode;
      }
}
 void insert_after()
{ struct node *newnode,*ptr; int val,val1;
  printf("\n current linked list");
  display();
  printf("\n enter element value after which your want to insert ");
  scanf("%d",&val1);
  printf("\n enter new element");
  scanf("%d",&val);
  newnode=(struct node *) malloc(sizeof(struct node));
  if(start==NULL)
  { printf("\n empty ll");
  }
  else{ ptr=start;
    while((ptr->data!=val1)&&(ptr->next!=NULL))
    {ptr=ptr->next; }
     if(ptr->data==val1)
       {  newnode->data=val;
	  newnode->next=ptr->next;
	  ptr->next=newnode;
       }
       else
       {
	printf("\n data not found");
       }

}
}


 void insert_before()
{ struct node *newnode,*ptr,*pre_ptr; int val,val1;
  printf("\n current linked list");
  display();
  printf("\n enter element value before which your want to insert ");
  scanf("%d",&val1);
  printf("\n enter new element");
  scanf("%d",&val);
  
  if(start==NULL)
  { printf("\n empty ll");
  }
  else{ pre_ptr=ptr=start;
    while((ptr->data!=val1)&&(ptr->next!=NULL))
    {pre_ptr=ptr;
     ptr=ptr->next; }
     if(ptr->data==val1)
       {newnode=(struct node *) malloc(sizeof(struct node));  
	newnode->data=val;
	  newnode->next=ptr;
	  if(pre_ptr==start && ptr==start)
	  { start=newnode;
	  }
	  else
	  {pre_ptr->next=newnode;}
       }
       else
       {
	printf("\n data not found");
       }

}
}
 void insert_sortedlist()
{ struct node *newnode,*ptr,*pre_ptr; int val;
  printf("\n current linked list");
  display();
  printf("\n enter new element");
  scanf("%d",&val);
  newnode=(struct node *) malloc(sizeof(struct node));
   if(start==NULL)
  { newnode->data=val;
    newnode->next=NULL;
    start=newnode;
  }
  else{ pre_ptr=ptr=start;
    while((ptr->data<=val)&&(ptr!=NULL))
    {pre_ptr=ptr;
     ptr=ptr->next; }

	newnode->data=val;
	  newnode->next=ptr;
	  if(pre_ptr==start && ptr==start)
	  { start=newnode;
	  }
	  else
	  {pre_ptr->next=newnode;}

}
}