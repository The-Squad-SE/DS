 /* infix to postfix converstion program */
 #include<stdio.h>
 #include<conio.h>
 #include<string.h>
 #include<ctype.h>
 # define Max 100
 char st[Max];
 int top=-1;
 void push(char);
 char pop();
 void intopost( char source[], char target[]);
 int getpriority(char);

 int main()
 { char infix[100],postfix[100];
   clrscr();
   printf("\nenter the infix expression");
   gets(infix);
   strcpy(postfix,"");
   intopost(infix,postfix);
   printf("\n the postfix expression");
   puts(postfix);
   getch();
   return 0;
}
  void intopost( char source[], char target[])
  {int i=0, j=0;
  char temp;
  while(source[i]!='\0')
  {
    if (source[i]=='(')
     {	 push(source[i]); i++;}

    else if (isdigit(source[i]) || isalpha(source[i]))
     {   target[j]=source[i];
	    i++; j++;
     }

     else if(source[i]=='%'||source[i]=='*'||source[i]=='/'||source[i]=='+'||source[i]=='-')
     {while(top!=-1 && st[top]!='(' && (getpriority(st[top])>getpriority(source[i])))
       {   target[j]=pop(); j++;
	}
	push(source[i]); i++;
     }
     else if (source[i]==')')
     {  while(top!=-1 && st[top]!='(')
	  { target[j]=pop(); j++;}
	  if(top==-1)
	  {printf("\nincorrect statement");}
	  else
	  {temp=pop(); i++;}
     }
     else
     { printf("\n incorrect statement in expression");
     }
  }
    while(top!=-1 && st[top]!='(')
    { target[j]=pop();
      j++;
     }
     target[j]='\0';
}

  int getpriority(char op)
  { int c;
  if (op=='/' || op=='*' || op=='%')
   c=1;
    else if(op=='+'|| op=='-')
    c=0;
    return c;
  }


  void push(char val)
  { if (top==Max-1)
	printf(" stack overflow");
    else
     { top++;
       st[top]=val;
      }
   }
   char pop()
   { char val='\0';
     if (top==-1)
      {	printf(" stack underflow"); }
    else
     {
       val=st[top];top--;
      }
      return val;
    }
