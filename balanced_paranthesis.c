#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void push(char*,char);
char pop(char*);
int isEmpty();
int isMatching(char,char);

int top=-1;

int main(){
  char expr[50],ch;
  int temp=1;
  // {,(,[,},),] allowed 
  printf("Enter a expression : ");
  scanf("%s",expr);
  for(int i=0;i<strlen(expr);i++){
    ch=expr[i];
    if(ch=='('||ch=='{'||ch=='[')
      push(expr,ch);
    else if(ch==')'||ch=='}'||ch==']')
      if(!isMatching(ch,pop(expr))){
        temp=0;
        break;
      }
  }
  if(!isEmpty()||temp==0)
    printf("Not Balanced");
  else
    printf("Balanced");
  return 0;
}

void push(char* expr,char c){
  expr[++top]=c;
}

char pop(char* expr){
  return expr[top--];
}

int isEmpty(){
  return (top==-1);
}

int isMatching(char a,char b){
  if((a==')'&& b=='(')||(a==']'&& b=='[')||(a=='}'&& b=='{'))
    return 1;
  return 0;
}