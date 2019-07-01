#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* link;
};

struct node* front=NULL;
struct node* rear=NULL;
struct node* temp;

void create();
void del();
void display();
void displayReverse(struct node* p);
void reverseList();

int main(){
  int ch;
  do{
    printf("\n1-CREATE 2-DELETE 3-DISPLAY 4-DISPLAY REVERSE 5-REVERSE LIST 6-EXIT\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:create();
             break;
      case 2:del();
             break;
      case 3:display();
             break;
      case 4:displayReverse(front);
             break;
      case 5:reverseList();
             break;
      case 6:printf("Exiting...\n");
             break;
      default:printf("Invalid choice\n");
    }
  }while(ch!=6);
  return 0;
}

void create(){
  struct node* n;
  n=(struct node*)malloc(sizeof(struct node));
  printf("Enter data : ");
  scanf("%d",&n->data);
  n->link=NULL;
  if(rear==NULL)
    front=rear=n;
  else{
    rear->link=n;
    rear=n;
  }
  rear->link=front;
}

void del(){
  temp=front;
  if(front==NULL){
    printf("List is empty\n");
    return ;
  }
  else if(front==rear)
    front=rear=NULL;
  else{
    front=front->link;
    rear->link=front;
  }
  temp->link=NULL;
  free(temp);
}

void display(){
  temp=front;
  while(temp->link!=front){
    printf("%d ",temp->data);
    temp=temp->link;
  }
  printf("%d",temp->data);
}

void displayReverse(struct node* k){
  if(k->link==front){
    printf("%d ",k->data);
    return;
  }
  displayReverse(k->link);
  printf("%d ",k->data);
}

void reverseList(){
  struct node* temp1;
  struct node* p=front;
  if(p->link!=front){
    temp=p;
    temp1=p->link;
    p=p->link;

    while(p->link!=front){
      p=p->link;
      temp1->link=temp;
      temp=temp1;
      temp1=p;
    }
    p->link=temp;
    front->link=p;
    rear=front;
    front=temp1;
  }
}