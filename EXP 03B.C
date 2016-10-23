/* program to evaluate postfix expression*/
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define max 100
float st[max];
int top=-1;
void push(float val);
float pop();
float evaluatepostfixexp(char exp[]);
main()
{ float val;
  char exp[100];
  clrscr();
  printf("\n enter any postfix expression:");
  gets(exp);
  val=evaluatepostfixexp(exp);
  printf("\n value of the postfix expression=%.2f",val);
  getch();
  return 0;
}
float evaluatepostfixexp(char exp[])
{ int i=0;
  float op1,op2,value;
  while(exp[i]!='\0')
  { if(isdigit(exp[i]))
    push((float)exp[i]-'0');
    else
    { op2=pop();
      op1=pop();
      switch(exp[i])
      { case '+': value=op1+op2; break;
	case '-': value=op1-op2; break;
	case '/': value=op1/op2; break;
	case '*': value=op1*op2; break;
	case '%': value=(int)op1%(int)op2; break;
	default: printf("wroung statement");
      }
     push(value);
    }
    i++;
  }
  return(pop());
}
void push(float val)
{ if(top==max-1)
 printf("\n stack overflow");
 else{ top++; st[top]=val;}
}
float pop()
{ float val=-1;
 if(top==-1)
 printf("\n stack underflow");
 else{ val=st[top]; top--;}
return val;
}

