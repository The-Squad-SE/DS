/* Aim: Implementation of Searching methods (INDEX SEQUENTIAL, INTERPOLATION SEARCH) menu driven program  */

#include<stdio.h>
int a[10],i,n,item;
void interpolation()
{
    int mid,low,high,f=0;
    low=0;
    high=n-1;
    printf("Enter the element for search");
    scanf("%d",&item);
    while(low<=high)
    {
       mid=(low+(high-low)*((item-a[low])/(a[high]-a[low])));
       if(item==a[mid])
       {
	  f=1;
	  break;
       }
       else if(item<a[mid])
       high=mid-1;
       else
       low=mid+1;
    }
    if(f)
    printf("item found at position  %d",mid+1);
    else
    printf("Item not found");
}
void index_search()
{
   int f=0,item,i,j=0,k=0,index[20][20],p,x;
   int h,l,pos;
    for(i=n;i>1;i=i/2)
    p=i;
    printf("Enter the item for search:");
    scanf("%d",&item);
   for(i=p;i<n;i=i+p)
   {
      index[j][0]=a[i];
      index[j][1]=i;
      j++;
   }
  index[j][0]=a[n-1];
  index[j][1]=n-1;
  for(i=0;i<=j;i++)
   {
       if(item==index[i][0])
     {
       f=1;
       break;
     }
     else if(item>index[i][0]&&item<index[i+1][0])
     {
	l=index[i][1];
	h=index[i+1][1];
     }
     else
     {
	if (item<index[i][0]&&i==0)
	{
	  l=0;
	  h=index[i][1];
	}
     }

   }
    if(!f)
    {
       for(i=l;i<h;i++)
      {
       if(item==a[i])
       {
	f=1;
	break;
       }
       }
    }
   if(f==1)
   printf("Item Found  ");
   else
   printf("Item not found\n");

}
void read()
{
       printf("Enter the no of elements");
	scanf("%d",&n);

	printf("\nEnter the array \n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);

}
void display()
{
   printf("Array is\n");
   for(i=0;i<n;i++)
   printf("%d\t",a[i]);
}
void main()
{
    int op;
    clrscr();

    do
    {
	printf("\n1:Read\t2:Index Sequential Search\t3:Interpolation\t4:Display\t5:Exit\n");
	printf("Enter the option");
	scanf("%d",&op);
	switch(op)
	{
	  case 1:read();break;
	  case 2:index_search();
		  break;
	   case 3:interpolation();
		   break;
	   case 4:display();break;
	   case 5:exit();
		  break;
	}

    }
    while(op);
    getch();
}

