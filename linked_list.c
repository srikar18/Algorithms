#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* link;
};

struct node* head=NULL;
struct node* temp;
struct node* temp1;
struct node* p;

void insertBegin();
void insertPosition();
void insertEnd();
void deleteBegin();
void deletePosition();
void deleteEnd();
void display();
void displayReverse(struct node* p);
void reverseList();
// void sortList();

int main(){
  int ch;
  do{
    printf("\n1-INSERT BEGINNING 2-INSERT POSITION 3-INSERT END\n4-DELETE BEGINNING 5-DELETE POSITION 6-DELETE END\n7-DISPLAY 8-DISPLAY REVERSE\n9-REVERSE LIST\n10-SORT LIST\n10-EXIT\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    switch(ch){
      case 1:insertBegin();
             break;
      case 2:insertPosition();
             break;
      case 3:insertEnd();
             break;
      case 4:deleteBegin();
             break;
      case 5:deletePosition();
             break;
      case 6:deleteEnd();
             break;
      case 7:display();
             break;
      case 8:displayReverse(head);
             break;
      case 9:reverseList();
             break;
      case 10:sortList();
              break;
      case 11:printf("Exiting...\n");
             break;
      default:printf("Invalid choice");
    }
  }while(ch!=11);
  return 0;
}

void display(){
  struct node* temp=head;
  if(head==NULL)
    printf("Linked List is empty,nothing to display\n");
  else{
    while(temp!=NULL){
      printf("%d ",temp->data);
      temp=temp->link;
    }
  }
}

void displayReverse(struct node* p){
  if(p==NULL)
    return;
  displayReverse(p->link);
  printf("%d ",p->data);
}

void insertBegin(){
  struct node* n;
  int data;
  n=(struct node*)malloc(sizeof(struct node));
  printf("Enter data to be inserted into the node(at the beginning) : ");
  scanf("%d",&data);
  n->data=data;
  n->link=NULL;
  if(head==NULL)
    head=n;
  else{
    n->link=head;
    head=n;
  }
}

void insertPosition(){
  struct node* n;
  int data,pos;
  n=(struct node*)malloc(sizeof(struct node));
  printf("Enter the data to be inserted into the node : ");
  scanf("%d",&data);
  printf("\nEnter the position where the node needs to be inserted : ");
  scanf("%d",&pos);
  n->data=data;
  n->link=NULL;
  if(pos==1){
    n->link=head;
    head=n;
  }
  else{
    temp=head;
    for(int i=0;i<pos-2;i++)
      temp=temp->link;
    n->link=temp->link;
    temp->link=n;
  }
}

void insertEnd(){
  struct node* n;
  int data;
  n=(struct node*)malloc(sizeof(struct node));
  printf("Enter data to be inserted into the node(at the end) :  ");
  scanf("%d",&data);
  n->data=data;
  n->link=NULL;
  if(head==NULL)
    printf("Please use insert begin operation\n");
  else{
    temp=head;
    while(temp->link!=NULL)
      temp=temp->link;
    temp->link=n;
  }
}

void deleteBegin(){
  temp=head;
  head=temp->link;
  temp->link=NULL;
  free(temp);
}

void deletePosition(){
  int pos;
  printf("Enter position at which the node needs to be deleted : ");
  scanf("%d",&pos);
  temp=head;
  if(pos==1){
    deleteBegin();
  }
  else{
    for(int i=0;i<pos-2;i++)
      temp=temp->link;
    temp1=temp->link;
    temp->link=temp1->link;
    temp1->link=NULL;
    free(temp1);
  }
}

void deleteEnd(){
  temp=head;
  while(temp->link!=NULL){
    temp1=temp;
    temp=temp->link;
  }
  temp->link=NULL;
  temp1->link=NULL;
  free(temp);
}

void reverseList(){
  p=head;
  if(p!=NULL){
    temp=p;
    temp1=p->link;
    p=p->link;

    while(p!=NULL){
      p=p->link;
      temp1->link=temp;
      temp=temp1;
      temp1=p;
    }
    head->link=NULL;
    head=temp;
  }
}

void sortList(){
//  implement
}
