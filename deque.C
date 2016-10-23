/* Dequeue code */
#include<stdio.h>
#include<conio.h>
#define max 10
int deque[max];
int front=-1,rear=-1;
int delete_r();
int delete_f();
void insert_f(int val);
void insert_r(int val);
void display();
void input_deque();
void output_deque();
int main()
{int option;
 clrscr();
 printf("\n ********** menu ********");
 printf("\n 1.input restricted");
 printf("\n 2. output restricted");
 printf("\n enter your choice");
 scanf("%d",&option);
 switch(option)
 { case 1: input_deque();
	   break;
   case 2: output_deque();
	   break;
   default: printf("\n wroung statement");
 }
 getch();
 return 0;
}
void input_deque()
{ int option,val;
 clrscr();
do{ printf("\n ********** input deque menu ********");
 printf("\n 1.insert at right");
 printf("\n 2. delete from left");
 printf("\n 3. delete from right");
 printf("\n 4. display");
 printf("\n enter your choice");
 scanf("%d",&option);
 switch(option)
 { case 1: printf("\n enter value to be inserted");
	   scanf("%d",&val);
	   insert_r(val);
	   break;
   case 2: val=delete_f();
	   if(val!=-999)
	   printf("\n value deleted from left is = %d",val);
	   break;
   case 3: val=delete_r();
	   if(val!=-999)
	   printf("\n value deleted from right is = %d",val);
	   break;
   case 4: display();
	   break;

   default: printf("\n wroung statement");
 }
}while(option<=4 && option>=1);
}
void output_deque()
{ int option,val;
 clrscr();
do{ printf("\n ********** output deque menu ********");
 printf("\n 1.insert at right");
 printf("\n 2. insert at left");
 printf("\n 3. delete from left");
 printf("\n 4. display");
 printf("\n enter your choice");
 scanf("%d",&option);
 switch(option)
 { case 1: printf("\n enter value to be inserted from right");
	   scanf("%d",&val);
	   insert_r(val);
	   break;
   case 2: printf("\n enter value to be inserted from left");
	   scanf("%d",&val);
	   insert_f(val);
	   break;
   case 3: val=delete_f();
	   if(val!=-999)
	   printf("\n value deleted from left is = %d",val);
	   break;
   case 4: display();
	   break;

   default: printf("\n wroung statement");
 }
}while(option<=4 && option>=1);
}

void insert_r(int val)
{ if((front==0 && rear==max-1) || ( front==rear+1))
  { printf("\nqueue full");}
 else
 {
  if(front==-1 && rear==-1)
  {front=0;
   rear=0;
  }
  else if(rear==max-1)
       rear=0;
  else
      rear++;

   deque[rear]=val;
}
}
void insert_f(int val)
{ if((front==0 && rear==max-1) || ( front==rear+1))
  { printf("\nqueue full");}
 else
 {
  if(front==-1 && rear==-1)
  {front=0;
   rear=0;
  }
  else if(front==0)
       front=max-1;
  else
      front--;

   deque[front]=val;
}
}
int delete_f()
{ int val;
if(front==-1)
 { printf(" queue empty"); val=-999;}
  else
  {  val=deque[front];
     if(front==rear)
     front=rear=-1;
     else if(front==max-1)
     front=0;
     else
     front++;
  }
  return val;
}
int delete_r()
{ int val;
if(front==-1)
 { printf(" queue empty"); val=-999; }
  else
  {  val=deque[rear];
     if(front==rear)
     front=rear=-1;
     else if(rear==0)
     rear=max-1;
     else
     rear--;
  }
  return val;
}

void display()
{int i;
 if(front==-1)
  { printf("\n underflow");

  }
  else
    { if(front<=rear)
      {
	  for(i=front;i<=rear;i++)
	  printf("\t%d",deque[i]);
      }
      else
      {   for(i=front;i<=max-1;i++)
	  printf("\t%d",deque[i]);
	   for(i=0;i<=rear;i++)
	  printf("\t%d",deque[i]);
      }
}   }
