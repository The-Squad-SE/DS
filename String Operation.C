// Aim : Implementation of STRING Functions
#include<stdio.h>
#include<conio.h>
char a[44];
char b[20];
char c[20];
void length()
{	int i,j=0;
	printf("1. LENGTH\n");
	printf("Enter String\t");
	scanf("%s",a);
	printf("Entered string is ");
	puts(a);
	i=0;
	while(a[i]!='\0')
	{
	i++; j++;
	}
	printf("Number of characters : %d",j);
}
void concat()
{ 	 int i,j=0,k=0;
	printf("Concatenate\n");
	printf("Enter string 1 ");
	scanf("%s",a);
	printf("Enter string 2 ");
	scanf("%s",b);
	i=0;
	while(a[i]!='\0')
		{
			i++; j++;
		}
	i=0;
	while(b[i]!='\0')
		{	i++; k++;
		}
	for(i=0;i<k;i++)
		{
			a[i+j]=b[i];
		}
	a[k+j]='\0';

	printf("Concatenated String is ");
	puts(a);
}
void rev()
{  	int i,j=0,k;
	printf("Reverse of the string");
	printf("\nEnter String ");
	scanf("%s",a);
	i=0;
	while(a[i]!='\0')
		{
			i++;
			j++;
		}

	for(i=j-1,k=0;i>=0;i--,k++)
		{
			c[k]=a[i];
		}

	c[k]='\0';

	printf("Reverse is ");
	puts(c);
}
void copy()
{  int i,j,k;
	printf("Copies strings");
	printf("\nEnter String1 ");
	scanf("%s",a);
	i=0;
	while(a[i]!='\0')
	{
	i++;
	}
	for(k=0;k<i;k++)
	{
	b[k]=a[k];
	}
	b[k]='\0';
	printf("\nString 2 is:");
	puts(b);
}
void main()
{
char ch1='y';
int ch;
clrscr();
do{
	printf("\nEnter your choice : \t1:Length \t2:Concatenate \t3:Reverse \t4:Copy");
	printf("\n");
	scanf("%d",&ch);
	switch(ch)

	{	case 1: 	length();
					break;
		case 2:  concat();
					break;
		case 3: 	rev();
					break;
		case 4:  copy();
					break;
		default: printf("Invalid choice ");
					break;
	}
	printf("\nDo you want to continue (Y/N) :");
	scanf(" %c",&ch1);
	} while(ch1=='y'|| ch1 == 'Y');
getch();
}
