#include<stdio.h>
#include<stdlib.h>

int front=0,rear=-1,n;

void insert(int *arr,int elem);
void del(int *arr);
void display(int *arr);
int isFull();
int isEmpty();

int main(){
  int *arr,elem,choice;
  printf("Enter array size : ");
  scanf("%d",&n);
  arr=(int*)malloc(sizeof(int)*n);
  do{
    printf("\nEnter your choice : \n");
    printf("1-INSERT 2-DELETE 3-DISPLAY 4-EXIT\n");
    scanf("%d",&choice);
    switch(choice){
      case 1:if(isFull())
              printf("Cannot insert,queue is full\n");
             else{
               printf("Enter element to be inserted into the queue\n");
               scanf("%d",&elem);
               insert(arr,elem);
             }
             break;
      case 2:if(isEmpty())
              printf("Cannot delete,queue is empty\n");
             else
               del(arr);
             break;
      case 3:if(isEmpty())
              printf("Cannot display,queue is empty\n");
             else
               display(arr);
             break;
      case 4:printf("Exiting..");
             break;
      default:printf("Invalid choice\n");
    }
  }while(choice!=4);
  return 0;
}

void insert(int *arr,int elem){
  arr[++rear]=elem;
}

void del(int *arr){
  printf("%d deleted from queue\n",arr[front++]);
}

void display(int *arr){
  printf("Queue elements are\n");
  for(int i=front;i<=rear;i++)
    printf("%d ",arr[i]);
  printf("\n");
}

int isEmpty(){
  if(front>rear)
    return 1;
  return 0;
}

int isFull(){
  if(rear==n-1)
    return 1;
  return 0;
}