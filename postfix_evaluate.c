#include<stdio.h>
#include<ctype.h>
int stack[20];
int top=-1;

void push(int);
int pop();

int main(){
  char exp[20],*e;
  int num,n1,n2;
  printf("Enter postfix expression to be evaluated : ");
  scanf("%s",exp);
  e=exp;
  while(*e!='\0'){
    if(isdigit(*e)){
      num=*e-'0';
      push(num);
    }
    else{
      n1=pop(); // second operand
      n2=pop(); // first operand
      switch(*e){
        case '+':push(n1+n2);
                 break;
        case '-':push(n2-n1);
                 break;
        case '*':push(n1*n2);
                 break;
        case '/':push(n2/n1);
                 break;
      }
    }
    e++;
  }
  printf("Postfix evaluation result is %d",pop());
  return 0;
}

void push(int x){
  stack[++top]=x;
}

int pop(){
  return stack[top--];
}