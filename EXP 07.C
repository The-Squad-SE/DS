#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *link;
};
typedefstruct node* NODE;
NODE create();
void display();
void count();
void copy();
voidconcat();
void split();
void reverse();
void main()
{
	intch;
	clrscr();
	do
	{
		printf("Linked List Operations\n");
		printf("1.COPY 2.SPLIT 3. REVERSE 4.COUNT 5.CONCATENATE 6.EXIT\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:copy();
			break;
			case 2:split();
			break;
			case 3:reverse();
			break;
			case 4:count();
			break;
			case 5:concat();
			break;
			case 6:ch=-1;
		}
	}while(ch!=-1);
	}
void count()
{
	NODE p;
	int c=0;
	p=create();
	while(p!=NULL)
	{
		c++;
		p=p->link;
	}
	printf("COUNT is : %d\n",c);
}

NODE create()
{
	NODE temp,start=NULL,p=start;
	int item;
	intn,i;
	printf("Enter No of Elements of Linked List : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter Item : ");
		scanf("%d",&item);
		temp->data=item;
		temp->link=NULL;
		if(start==NULL)
		start=temp;
		else
		{
		p=start;
		while(p->link!=NULL)
		p=p->link;
		p->link=temp;
		}
	}
	return start;
}
void display(NODE start)
{
	while(start!=NULL)
	{
	printf("%d\t",start->data);
	start=start->link;
	}
	printf("\n");
}
void copy()
{
	NODE p,q,r,temp1,temp,t=NULL;
	p=create();
	q=p;
	r=q;
	while(p!=NULL)
	{
		temp1=(struct node *)malloc(sizeof(struct node));
		temp1->data=p->data;
		temp1->link=NULL;
		if(t==NULL)
		{
		       q=t=temp1;
		}
		else
		{
			q->link=temp1;
			q=temp1;
		}
		p=p->link;

	}
	temp->link=NULL;
	printf("ORIGINAL LIST : \n");
	display(r);
	printf("COPIED LIST : \n");
	display(t);
}

voidconcat()
{
   NODE p,start,t;
start=create();
   t=create();
   p=start;
while(p->link!=NULL)
   {
      p=p->link;
   }
p->link=t;
display(start);
}

void reverse()
{
   NODE t,start,p1,p2,p3;
start=create();
if(start->link==NULL)
printf("Reverse is the same");
else if(start->link->link==NULL)
   {
      p1=start;
      p2=p1->link;
      p1->link=NULL;
      p2->link=p1;
      t=p2;
   }
else
   {
      p1=start;
      p2=p1->link;
      p3=p2->link;
      p1->link=NULL;
      p2->link=p1;
while(p3->link!=NULL)
      {
	 p1=p2;
	 p2=p3;
	 p3=p3->link;
	 p2->link=p1;
      }
      p3->link=p2;
      t=p3;
   }
display(t);
}

void split()
{
 NODE p,t,start;
int item;
start=create();
printf("Enter the data");
scanf("%d",&item);
 p=start;
while(p->data!=item)
 {
   p=p->link;
 }
   t=p->link;
p->link=NULL;
printf("FIRST LIST\n");
display(start);
printf("SECOND LIST\n");
display(t);
}
