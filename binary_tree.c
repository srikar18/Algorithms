#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* left;
  struct node* right;
};

struct node* create();
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);

int main(){
  struct node* root;
  root=create();
  int ch;
  do{
    printf("\n1-INORDER 2-PREORDER 3-POSTORDER 4-EXIT\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:inorder(root);
             break;
      case 2:preorder(root);
             break;
      case 3:postorder(root);
             break;
      case 4:printf("Exiting..\n");
             break;
      default:printf("Invalid choice");
    }
  }while(ch!=4);
  return 0;
}

struct node* create(){
  int data;
  struct node* n;
  printf("Enter data to be inserted into the node(-1 for no data) : ");
  scanf("%d",&data);

  if(data==-1)
    return NULL;

  n=(struct node*)malloc(sizeof(struct node));
  n->data=data;
  n->left=create();
  n->right=create();
  return n;
}

void inorder(struct node* n){
  if(n){
    inorder(n->left);
    printf("%d ",n->data);
    inorder(n->right);
  }
}

void preorder(struct node* n){
  if(n){
    printf("%d ",n->data);
    preorder(n->left);
    preorder(n->right);
  }
}

void postorder(struct node* n){
  if(n){
    postorder(n->left);
    postorder(n->right);
    printf("%d ",n->data);
  }
}