#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* link;
};

struct node* front=NULL;
struct node* rear=NULL;
struct node* temp;

void insert(int);
void del();
void display();

int main(){
  int ch,data;
  do{
    printf("\n1-INSERT 2-DELETE 3-DISPLAY 4-EXIT\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    switch(ch){
      case 1:printf("Enter data to be inserted into the queue : ");
             scanf("%d",&data);
             insert(data);
             break;
      case 2:del();
             break;
      case 3:display();
             break;
      case 4:printf("Exiting..\n");
             break;
      default:printf("Invvalid choice\n");
    }
  }while(ch!=4);
  return 0;
}

void insert(int data){
  struct node* n;
  n=(struct node*)malloc(sizeof(struct node));
  n->data=data;
  n->link=NULL;
  if(rear==NULL){
    front=rear=n;
  }
  else{
    rear->link=n;
    rear=n;
  }
}

void del(){
  if(front==NULL)
    printf("Queue is empty,cannot delete\n");
  else{
    temp=front;
    front=temp->link;
    printf("%d deleted from queue\n",temp->data);
    temp->link=NULL;
    free(temp);
  }
}

void display(){
  if(front==NULL)
    printf("Queue is empty,cannot display\n");
  else{
    temp=front;
    while(temp!=NULL){
      printf("%d ",temp->data);
      temp=temp->link;
    }
  }
}