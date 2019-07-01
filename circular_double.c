#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* left;
  struct node* right;
};

struct node* temp;
struct node* front=NULL;
struct node* rear=NULL;

void create();
void del();
void display();
void displayReverse();

int main(){
  int ch;
  do{
    printf("\n1-CREATE 2-DELETE 3-DISPLAY 4-DISPLAY REVERSE 5-EXIT\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    switch(ch){
      case 1:create();
             break;
      case 2:del();
             break;
      case 3:display();
             break;
      case 4:displayReverse();
             break;
      case 5:printf("Exiting..\n");
             break;
      default:printf("Invalid choice\n");
    }
  }while(ch!=5);
  return 0;
}

void create(){
  struct node* n;
  n=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter the data to be inserted into the node : ");
  scanf("%d",&n->data);
  n->right=NULL;
  n->left=NULL;
  if(rear==NULL)
    front=rear=n;
  else{
    rear->right=n;
    n->left=rear;
    rear=n;
  }
  front->left=rear;
  rear->right=front;
}

void del(){
  if(front==NULL){
    printf("Cannot delete,list is empty");
    return;
  }
  else if(front==rear)
    front=rear=NULL;
  else{
    temp=front;
    front=front->right;
    front->left=rear;
    rear->right=front;
  }
  temp->left=NULL;
  temp->right=NULL;
  free(temp);
}

void display(){
  temp=front;
  if(front==NULL)
    printf("List is empty\n");
  else{
    temp=front;
    while(temp->right!=front){
      printf("%d ",temp->data);
      temp=temp->right;
    }
    printf("%d",temp->data);
  }
}

void displayReverse(){
  temp=rear;
  while(temp->left!=rear){
    printf("%d ",temp->data);
    temp=temp->left;
  }
  printf("%d",temp->data);
}