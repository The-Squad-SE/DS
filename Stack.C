
#include<stdio.h>
#include<conio.h>
#define max 10
int stack[max],top=-1;
void push(int val);
void pop();
void peep();
void display();
int main()
{ int val ,option;
  clrscr();
  do
  {
     printf("\n **** Main Menu *****");
     printf("\n 1. Push");
     printf("\n 2.pop");
     printf("\n 3. peep");
     printf("\n 4. display");
     printf("\n*******");
     printf("\n Enter your option");
     scanf("%d",&option);
     switch(option)
     { case 1: printf("\n Enter number to be pushed on to the stack");
	       scanf("%d",&val);
	       push(val);
	       break;
       case 2: pop();
	       break;
       case 3: peep();
	       break;
       case 4: display();
	       break;
       default: printf("\n wroung option");
     }
  }while(option>=1 && option<=4);
  getch();
  return 0;
}

void push(int val)
{ if(top==max-1)
  { printf("\n stack overflow");
  }
  else
  { top++;
    stack[top]=val;
  }
}
void pop()
{ int val;
  if(top==-1)
  { printf("\n stack underflow");
  }
  else
  { val=stack[top];
    top--;
    printf("\n the value deleted from the stack is:%d",val);
  }
}
void peep()
{ int val;
  if(top==-1)
  { printf("\n stack underflow");
  }
  else
  { val=stack[top];
    printf("\n the value at the top of the stack is:%d",val);
  }
}
void display()
{ int i;
  if(top==-1)
  { printf("\n stack underflow");
  }
  else
  { for(i=top;i>=0;i--)
      printf("\n %d",stack[i]);
  }
}

