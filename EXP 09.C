#include<stdlib.h>
#include<malloc.h>
#include<stdio.h>
#include<conio.h>
struct node
{ struct node *left;
  char data;
  struct node *right;
}*root=NULL;
typedef struct node *tree;
 int top=-1;
 tree stack[10];
 void create()
 { char postfix[10];
   int i;
   tree a,b;
   tree temp;
   printf("Enter the expression");
   scanf("%s",postfix);
   for(i=0; postfix[i]!='\0';i++)
   {temp=(struct node *)malloc(sizeof(struct node));
    temp->data=postfix[i];
    temp->left=NULL;
    temp->right=NULL;

    if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='%')
     { b=stack[top];
       top--;
       a=stack[top];
       top--;
       temp->right=b;
       temp->left=a;
     }
     top++;
     stack[top]=temp;
     }
     root=stack[top];

     top--;
    }

  tree inorder(tree p)
 { if(p!=NULL)
  { inorder(p->left);
    printf("%c\t",p->data);
    inorder(p->right);
    }
  return p;
  }

  tree postorder(tree p)
  { if(p!=NULL)
   {postorder(p->left);
   postorder(p->right);
    printf("%c\t",p->data);
    }
   return p;
  }
  tree preorder(tree p)
  { if(p!=NULL)
   {printf("%c\t",p->data);
     preorder(p->left);
     preorder(p->right);
    }
   return p;
  }

   void main()
   { int c;
     clrscr();
     do
     {
     printf("\n\n 1.Create 2.Inorder 3.Preorder 4.Postorder 5.Exit");
     printf("\nEnter the choice");
     scanf("%d",&c);
     switch(c)
     { case 1: create();
	       break;
       case 2: inorder(root);
	       break;
       case 3: preorder(root);
	       break;
       case 4: postorder(root);
	       break;
       case 5: exit(0);
       }
     }
     while(c);
     getch();
   }
