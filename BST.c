#include <stdio.h>
#include<malloc.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
}*root=NULL;
typedef struct node *tree;
void create(int);
void deletenode(int);
void delete1(tree);
int smallest(tree);
void search(tree,int);
void inorder(tree);
void preorder(tree);
void postorder(tree);
tree parentptr=NULL;
int main( )
{
   int val,c;
   do
   {printf("1.create\t2.inorder\t3.preorder\t4.postprder\t5.delete\n");
   scanf("%d",&c);
   switch(c)
   {    case 1:printf("Enter the value to insert in tree");
	       scanf("%d",&val);
               create(val);
               break;
        case 2:inorder(root);break;
        case 3:preorder(root);break;
        case 4:postorder(root);break;
        case 5:printf("Enter the value to delete in tree");
	       scanf("%d",&val);
               deletenode(val);break;
        default: printf("wroung choice"); 
    }
   }while(c>=1 && c<=5);
return 0;
    
}
void create(int val)
{ tree newnode,ptr;
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=val;
  newnode->left=newnode->right=NULL;
  if(root==NULL)
   root=newnode;
  else
  { ptr=root;
    while(ptr!=NULL)
    {parentptr=ptr;
     if(val>ptr->data)
      ptr=ptr->right;
     else 
       ptr=ptr->left;
     }
    if(val>parentptr->data)
      parentptr->right=newnode;
     else 
       parentptr->left=newnode;
   }
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
 
void deletenode(int val)
{ parentptr=root;
  search(root,val);
}
int smallest(tree p)
{ if(p==NULL)
   {printf("tree is not created");
   }
 else
{
while(p->left!=NULL)
   {p=p->left;
   }
 return(p->data);
}
}
void search(tree p,int val)
{ if(p==NULL) printf("tree not created\n");
  else
   { 
      if(val>p->data)
      {parentptr=p;
       search(p->right,val);
      }
      else if(val<p->data)
      {parentptr=p;
       search(p->left,val);
      }
     else if(val==p->data) 
       delete1(p);
   }
}
void delete1(tree p)
{ int k; tree p2;
  if((p->left==NULL)&&(p->right==NULL))
  { if(parentptr->left==p)
        parentptr->left=NULL;
    else 
        parentptr->right=NULL;
     p=NULL;
     free(p);
     return;
  }
    else if(p->right==NULL)
     {  if(p==root)
           root=p->left;
        else if( parentptr->left==p)
        parentptr->left=p->left;
        else if( parentptr->right==p)
        parentptr->right=p->left; 
        p=NULL;
     free(p);
     return;
     }
    else if(p->left==NULL)
     {  if(p==root)
           root=p->right;
        else if( parentptr->left==p)
        parentptr->left=p->right;
        else if( parentptr->right==p)
        parentptr->right=p->right; 
        p=NULL;
     free(p);
     return;
     }
    else if((p->left!=NULL)&&(p->right!=NULL))
    {
      k=smallest(p->right);
      p2=p;
      search(root,k);
      p2->data=k;
      return;
     }
      
}   
