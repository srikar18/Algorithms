#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* link;
};

struct node* head=NULL;
struct node* temp;

void push(int);
void pop();
void display();

int main(){
  int ch,data;
  do{
    printf("\n1-PUSH 2-POP 3-DISPLAY 4-EXIT\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    switch(ch){
      case 1:printf("\nEnter data to insert into the stack : ");
             scanf("%d",&data);
             push(data);
             break;
      case 2:pop();
             break;
      case 3:display();
             break;
      case 4:printf("Exiting...!\n");
             break;
      default:printf("Invalid choie\n");
    }
  }while(ch!=4);
  return 0;
}

void push(int data){
  struct node* n;
  n=(struct node*)malloc(sizeof(struct node));
  n->data=data;
  n->link=NULL;
  if(head==NULL)
    head=n;
  else{
    n->link=head;
    head=n;
  }
}

void pop(){
  if(head==NULL)
    printf("Stack is empty,cannot pop\n");
  else{
    temp=head;
    head=temp->link;
    printf("%d popped from stack\n",temp->data);
    temp->link=NULL;
    free(temp);
  }
}

void display(){
  if(head==NULL)
    printf("Stack is empty,cannot display\n");
  else{
    temp=head;
    while(temp!=NULL){
      printf("%d ",temp->data);
      temp=temp->link;
    }
  }
}