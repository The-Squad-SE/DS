//circular queue//



#include<stdio.h>
#include<conio.h>
#define max 100
int queue[max];
int front=-1,rear=-1;
void insert(int value);
int delete_element();
int peep();
void display();
int main()
{
int option,value;
clrscr();
do{
printf("\nmenu");
printf("\n1.insert");
printf("\n2.delete");
printf("\n3.peep");
printf("\n4.display");
printf("\n5.Enter your choice");
scanf("%d",&option);
switch(option)
{
case 1 : printf("\nEnter an element");
	 scanf("%d",&value);
	 insert(value);
	 break;
case 2 : value=delete_element();
	 if(value!=-999)
	 printf("\nvalue deleted is %d",value);
case 3 : value=peep();
	 if(value!=-999)
	 printf("\nthe first value in queue is %d",value);
	 break;
case 4 : display();
	 break;
default: printf("\nwrong option");
}
}while(option<=4 && option>=1);
getch();
return 0;
}
void insert(int value)
{
if((front==0 && rear==max-1) || (front==rear+1))
{
printf("queue full");
}
else
{
if(front==-1 && rear==-1)
{
front=0;
rear=0;
}
else if(front!=0 && rear==max-1)
{
rear=0;
}
else{
rear++;
}
queue[rear]=value;
}
}
int delete_element()
{
int value;
if(front==-1)
{
printf("queue empty");
value=-999;
}
else
{
value=queue[front];
if(front==rear)
{
front=-1;
rear=-1;
}
else if(front==max-1)
{
front=0;
}
else
{
front++;
}
}
return value;
}
int peep()
{
int value;
if(front==-1)
{
printf("queue empty");
value=-999;
}
else
{
value=queue[front];
}
return value;
}
void display()
{
int i;
if(front==-1)
{
printf("queue empty");
}
else
{
if(front<=rear)
for(i=front;i<=rear;i++)
{
printf("%d",queue[i]);
}
else
{
for(i=front;i<=max-1;i++)
{
printf("%d",queue[i]);
}
for(i=0;i<=rear;i++)
{
printf("%d",queue[i]);
}
}
}
}



 
