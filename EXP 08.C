#include <stdio.h>
#include<malloc.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
}*root=NULL;
typedef struct node *tree;
void create();
void insertleft(tree,tree);
void insertright(tree,tree);
void insert(tree,tree);
void inorder(tree);
void preorder(tree);
void postorder(tree);
int main()
{
   int c;
   do
   {printf("1.create\t2.inorder\t3.preorder\t4.postprder\n");
   scanf("%d",&c);
   switch(c)
   {    case 1:create();break;
        case 2:inorder(root);break;
        case 3:preorder(root);break;
        case 4:postorder(root);break;
        default: printf("wroung choice"); 
    }
   }while(c>=1 && c<=4);
    return 0;
}

void create()
{tree temp;
 int i,n,item;
 printf("enter the number of nodes");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 { temp=(struct node *)malloc(sizeof(struct node));
 printf("enter item:");
 scanf("%d",&item);
 temp->data=item;
 temp->left=temp->right=NULL;
 if(root==NULL)
 root=temp;
 else
 { insert(root,temp);
 }
}
}

void insertleft(tree p,tree temp)
{ if(p->left==NULL)
  p->left=temp;
  else
  insert(p->left,temp);
}

void insertright(tree p,tree temp)
{ if(p->right==NULL)
  p->right=temp;
  else
  insert(p->right,temp);
}

void insert(tree root,tree temp)
{char c;
printf("insert left(l) or right(r)");
scanf("%c",&c); c = getchar();
if(c=='l')
insertleft(root,temp);
else if(c=='r')
insertright(root,temp);
else 
printf("wrong choice");
}

void inorder(tree p)
{ if(p!=NULL)
   { inorder(p->left);
     printf("%d\t",p->data);
     inorder(p->right);
   }
}   
void preorder(tree p)
{ if(p!=NULL)
   { 
     printf("%d\t",p->data);
     preorder(p->left);
     preorder(p->right);
   }
}  
void postorder(tree p)
{ if(p!=NULL)
   { postorder(p->left);
     postorder(p->right);
     printf("%d\t",p->data);
   }
}  
