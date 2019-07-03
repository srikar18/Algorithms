#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *l;
  struct node *r;
};

struct node *temp,*t1,*root=NULL;

void create();
void insert();
void del();
void searchInsert(struct node*);
void searchDelete(struct node*,int);
void deleteNode(struct node*);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
void levelorder(struct node*);
void printLevel(struct node*,int);
int smallest();
int largest();
int height(struct node*);
int largestNode();
int smallestNode();
void printLeafNodes(struct node*);
struct node* leafDelete(struct node*);
int isBST(struct node*);
int checkFull(struct node*);
void printRange(struct node*,int,int);
void deleteRange(struct node*,int,int);
struct node* deleteOutsideRange(struct node*,int,int);
void kthLargest(struct node*,int);
void kthSmallest(struct node*,int);


int main(){
  int ch;
  do{
    printf("\n1-INSERT 2-DELETE 3-INORDER 4-PREORDER 5-POSTORDER 6-LEVELORDER 7-EXIT\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:insert();
             break;
      case 2:del();
             break;
      case 3:inorder(root);
             break;
      case 4:preorder(root);
             break;
      case 5:postorder(root);
             break;
      case 6:levelorder(root);
             break;
      case 7:printf("Exiting..\n");
             break;
      default:printf("Invalid choice");
    }
  }while(ch!=7);
  return 0;
}

void insert(){
  create();
  if(root==NULL)
    root=temp;
  else
    searchInsert(root);
}

void create(){
  int data;
  temp=(struct node*)malloc(sizeof(struct node));
  printf("Enter data to be inserted into the node : ");
  scanf("%d",&data);
  temp->data=data;
  temp->l=temp->r=NULL;
}

void searchInsert(struct node *k){
  if(temp->data>k->data && k->r!=NULL)
    searchInsert(k->r);
  else if(temp->data>k->data && k->r==NULL)
    k->r=temp;
  else if(temp->data<=k->data && k->l!=NULL)
    searchInsert(k->l);
  else if(temp->data<=k->data && k->l==NULL)
    k->l=temp;
}

void inorder(struct node* t){
  if(t){
    inorder(t->l);
    printf("%d ",t->data);
    inorder(t->r);
  }
}

void preorder(struct node* t){
  if(t){
    printf("%d ",t->data);
    preorder(t->l);
    preorder(t->r);
  }
}

void postorder(struct node* t){
  if(t){
    postorder(t->l);
    postorder(t->r);
    printf("%d ",t->data);
  }
}

void levelorder(struct node* t){
  int h=height(root);
  for(int i=1;i<=h;i++)
    printLevel(root,i);
}

void printLevel(struct node* t,int h){
  if(t==NULL)
    return;
  if(h==1)
    printf("%d ",t->data);
  else if(h>1){
    printLevel(t->l,h-1);
    printLevel(t->r,h-1);
  }
}

int height(struct node* t){
  if(t==NULL)
    return 0;
  else{
    int lheight=height(t->l);
    int rheight=height(t->r);

    if(lheight>rheight)
      return lheight+1;
    else
      return rheight+1;
  }
}

void del(){
  int data;
  printf("Enter value of the node which needs to be deleted : ");
  scanf("%d",&data);
  if(root==NULL){
    printf("Empty tree,cannot delete\n");
    return;
  }
  t1=root;
  searchDelete(root,data);
}

void searchDelete(struct node* p,int d){
  if(d>p->data){
    t1=p;
    searchDelete(p->r,d);
  }
  else if(d<p->data){
    t1=p;
    searchDelete(p->l,d);
  }
  else
    deleteNode(p);
}

void deleteNode(struct node* p){
  int k;
  // node to be deleted has no children i.e, it is a leaf node
  if(p->l==NULL && p->r==NULL){
    if(t1->l==p)
      t1->l=NULL;
    else
      t1->r=NULL;
    p=NULL;
    free(p);
    return;
  }
  // node having left child
  else if(p->r==NULL){
    // node to be deleted is root
    if(p==t1){
      root=p->l;
      t1=root;
    }
    else if(t1->l=p)
      t1->l=p->l;
    else
      t1->r=p->l;
    p=NULL;
    free(p);
    return;
  }
  // node having right child
  else if(p->l==NULL){
    if(p==t1){
      root=p->r;
      t1=root;
    }
    else if(t1->l==p)
      t1->l=p->r;
    else
      t1->r=p->r;
    p=NULL;
    free(p);
    return;
  }
  // node having both left and right child
  else{
    // search for largest in left sub-tree
    if(p->l!=NULL)
      k=largest(p->l);
    // search for smallest in right sub-tree
    else
      k=smallest(p->r);
    searchDelete(root,k);
    p->data=k;
  }
}

int smallest(struct node* p){
  if(p->l!=NULL)
    return smallest(p->l);
  else  
    return p->data;
}

int largest(struct node* p){
  if(p->r!=NULL)
    return largest(p->r);
  else
    return p->data;
}

int largestNode(){
  t1=root;
  while(t1->r!=NULL)
    t1=t1->r;
  return t1->data;
}

int smallestNode(){
  t1=root;
  while(t1->l!=NULL)
    t1=t1->l;
  return t1->data;
}

void printLeafNodes(struct node* p){
  if(!p)
    return;
  if(!p->l && !p->r){
    printf("%d ",p->data);
    return;
  }

  if(p->l)
    printLeafNodes(p->l);

  if(p->r)
    printLeafNodes(p->r);    
}

struct node* leafDelete(struct node* p){
  if(!p)
    return NULL;
  if(!p->l && !p->r){
    free(p);
    return NULL;
  }
  p->l=leafDelete(p->l);
  p->r=leafDelete(p->r);
}

int isBST(struct node* p){
  if(!p)
    return 1;
  // for each node check if data in it is greater than max in right sub-tree and min in left sub-tree
  if(p->l!=NULL && largest(p->l)>p->data)
    return 0;
  if(p->r!=NULL && smallest(p->r)<p->data)
    return 0;
  // check right and left noodes recursively,return false if any one fails
  if(!isBST(p->l)||!isBST(p->r))
    return 0;
  return 1;
}

int checkFull(struct node* p){
  // every node must have 0 or 2 children for the tree to be full
  if(!p)
    return 1;
  if(!p->l && !p->r)
    return 1;
  if(p->l && p->r)
    return (checkFull(p->l) && checkFull(p->r));
  return 0;
}

void printRange(struct node* p,int l,int h){
  if(!p)
    return;
  // if node data is greater than lower limit,check for lesser values i.e, left sub-tree
  if(p->data>l)
    printRange(p->l,l,h);
  // if node data lies in the range,print it
  if(p->data>=l && p->data<=h)
    printf("%d ",p->data);
  // if node data is less than upper limit,check for higher values i.e, right sub-tree
  if(p->data<h)
    printRange(p->r,l,h);
}

void deleteRange(struct node* p,int l,int h){
  if(!p)
    return;
  if(p->data>l)
    deleteRange(p->l,l,h);
  if(!(p->data>=l && p->data<=h))
    searchDelete(root,p->data);
  if(p->data<h)
    deleteRange(p->r,l,h);
}

struct node* deleteOutsideRange(struct node* p,int l,int h){
  if(!p)
    return NULL;
  // check recursivley until leaf nodes are reached
  p->l=deleteOutsideRange(p->l,l,h);
  p->r=deleteOutsideRange(p->r,l,h);
  // if value of node is less than min,it means all nodes in left sub-tree have already been deleted
  // this is because we are traversing in post-order
  // so traverse to right of that node
  if(p->data<l)
    return p->r;
  // if value of node is grater than max,all nodes in right sub-tree have already been deleted
  // so traverse to the left of the node
  if(p->data>h)
    return p->l;
  // if in given range,return reference of that node
  return p;
}

void kthLargest(struct node* p,int k){
  static int count;
  if(!p||count>=k)
    return;
  kthLargest(p->r,k);
  count++;
  if(count==k){
    printf("%d is answer",p->data);
    return;
  }
  kthLargest(p->l,k);
}

void kthSmallest(struct node* p,int k){
  static int count;
  if(!p||count>=k)
    return;
  kthSmallest(p->l,k);
  count++;
  if(count==k){
    printf("%d is answer",p->data);
    return;
  }
  kthSmallest(p->r,k);
}