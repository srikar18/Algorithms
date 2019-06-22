#include<stdio.h>
#include<stdlib.h>

int front=0,rear=-1,n,count=0;

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
    printf("\nEnter your choice : ");
    printf("\n1-INSERT 2-DELETE 3-DISPLAY 4-EXIT\n");
    scanf("%d",&choice);
    switch(choice){
      case 1:if(isFull())
              printf("\nCircular Queue is full,cannot insert\n");
             else{
               printf("Enter item to be inserted into the circular queue : ");
               scanf("%d",&elem);
               insert(arr,elem);
             }
             break;
      case 2:if(isEmpty())
              printf("\nCircular queue is empty,cannot delete\n");
             else
              del(arr);
             break;
      case 3:if(isEmpty())
              printf("Circular queue is empty,cannot display\n");
             else
              display(arr);
             break;
      case 4:printf("\nExiting..\n");
             break;
      default:printf("Inalid choice\n");
    }
  }while(choice!=4);
  return 0;
}

void insert(int *arr,int elem){
  if(rear==n-1)
    rear=-1;
  arr[++rear]=elem;
  count++;
}

void del(int *arr){
  printf("%d deleted from circular queue\n",arr[front++]);
  count--;
  if(front==n)
    front=0;
}

void display(int *arr){
  if(front<=rear){
    for(int i=front;i<=rear;i++)
      printf("%d ",arr[i]);
  }
  else{
    for(int i=front;i<n;i++)
      printf("%d ",arr[i]); 
    for(int i=0;i<=rear;i++)
      printf("%d ",arr[i]);
  }
  printf("\n");
}

int isFull(){
  if(count==n)
    return 1;
  return 0;
}

int isEmpty(){
  if(count==0)
    return 1;
  return 0;
}