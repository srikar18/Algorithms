#include<stdio.h>
#include<stdlib.h>

int top=-1,n;

void push(int *arr,int elem);
void pop(int *arr);
void display(int *arr);
int isFull();
int isEmpty();

int main(){
  int *arr,num,choice;
  printf("Enter array size : ");
  scanf("%d",&n);
  arr=(int*)malloc(sizeof(int)*n);
  printf("\nEnter array elements : \n");
  do{
    printf("Enter your option : ");
    printf("\n1-PUSH 2-POP 3-DISPLAY 4-EXIT\n");
    scanf("%d",&choice);
    switch(choice){
      case 1:if(isFull())
              printf("Stack full,cannot push\n");
             else{
              printf("Enter element to push onto stack : ");
              scanf("%d",&num);
              push(arr,num);
             }
             break;
      case 2:if(isEmpty())
              printf("Stack empty,cannot pop\n");
             else
               pop(arr);
             break;
      case 3:if(isEmpty())
              printf("Stack empty,cannot display\n");
             else
              display(arr);
             break;
      case 4:printf("Exiting...");
             break;
      default:printf("Invalid choice\n");
    }
  }while(choice!=4);
  return 0;
  }
  
void push(int *arr,int elem){
    arr[++top]=elem;
}

void pop(int *arr){
    printf("%d removed from top of stack\n",arr[top--]);
}

void display(int *arr){
    printf("Stack elements are \n");
    for(int i=top;i>=0;i--)
      printf("%d ",arr[i]);
    printf("\n");
}

int isFull(){
  if(top==n-1)
    return 1;
  return 0;
}

int isEmpty(){
  if(top==-1)
    return 1;
  return 0;
}