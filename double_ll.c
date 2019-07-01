#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* left;
  struct node* right;
};

struct node* head=NULL;
struct node* temp;
struct node* temp1;

void insertBegin();
void insertPosition();
void insertEnd();
void deleteBegin();
void deletePosition();
void deleteEnd();
void display();
void displayReverse();
void reverseList();

int main(){
  int data,ch;
  do{
    printf("\n1-INSERT BEGIN 2-INSERT POSITION 3-INSERT END\n4-DELETE BEGIN 5-DELETE POSITION 6-DELETE END\n"
            "7-DISPLAY 8-DISPLAY REVERSE\n9-REVERSE LIST\n10-END\n");
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
      case 8:displayReverse();
             break;
      case 9:reverseList();
             break;
      case 10:printf("Exiting...\n");
              break;
      default:printf("Invalid choice\n");
    }
  }while(ch!=10);
  return 0;
}

void display(){
  temp=head;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->right;
  }
}

void displayReverse(){
  temp=head;
  while(temp->right!=NULL)
    temp=temp->right;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->left;
  }
}

void insertBegin(){
  int data;
  struct node* n;
  n=(struct node*)malloc(sizeof(struct node));
  printf("Enter data to be inserted into the node : ");
  scanf("%d",&data);
  n->data=data;
  n->left=NULL;
  n->right=NULL;
  if(head==NULL)
    head=n;
  else{
    n->right=head;
    head->left=n;
    head=n;
  }
}

void insertPosition(){
  int data,pos;
  struct node* n;
  n=(struct node*)malloc(sizeof(struct node));
  printf("Enter data to be inserted into the node : ");
  scanf("%d",&data);
  n->data=data;
  n->left=NULL;
  n->right=NULL;
  // position is 1 for insertion at begin
  // cannot insert at end
  printf("\nEnter position at  which you want to insert the node : ");
  scanf("%d",&pos);
  if(pos==1){
    n->right=head;
    head->left=n;
    head=n;
  }
  else{
    temp=head;
    for(int i=0;i<pos-2;i++)
      temp=temp->right;
    temp1=temp->right;
    n->left=temp;
    n->right=temp1;
    temp->right=n;
    temp1->left=n;
  }
}

void insertEnd(){
  int data;
  struct node* n;
  n=(struct node*)malloc(sizeof(struct node));
  printf("Enter data to be inserted into the node : ");
  scanf("%d",&data);
  n->data=data;
  n->left=NULL;
  n->right=NULL;
  if(head==NULL)
    head=n;
  else{
    temp=head;
    while(temp->right!=NULL)
      temp=temp->right;
    temp->right=n;
    n->left=temp;
  }
}

void deleteBegin(){
  temp=head;
  temp1=head->right;
  temp1->left=NULL;
  temp->right=NULL;
  head=temp1;
  free(temp);
}

void deletePosition(){
  int pos;
  // for delete at begin position is 1
  // cannot delete last element
  printf("\nEnter position at which the node needs to be deleted : ");
  scanf("%d",&pos);
  if(pos==1)
    deleteBegin();
  else{
    temp=head;
    for(int i=0;i<pos-2;i++)
      temp=temp->right;
    temp1=temp->right;
    temp->right=temp1->right;
    temp1->right->left=temp1->left;
    temp1->left=NULL;
    temp1->right=NULL;
    free(temp1);
  }
}

void deleteEnd(){
  temp=head;
  while(temp->right!=NULL){
    temp1=temp;
    temp=temp->right;
  }
  temp1->right=NULL;
  temp->left=NULL;
  free(temp);
}

void reverseList(){
  temp=head;
  temp1=NULL;
  if(temp->right!=NULL && temp!=NULL){
    while(temp!=NULL){
    temp1=temp->left;
    temp->left=temp->right;
    temp->right=temp1;
    temp=temp->left;
    }
    head=temp1->left;
  }
}