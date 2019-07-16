#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct vertex{
  char label;
  bool visited;
};

#define MAX 5

int adj[MAX][MAX],count=0,top=-1,stack[MAX];
struct vertex* vertices[MAX];

void addEdge(int,int);
void addVertex(char);
int getAdj(int);
void display(int);
void dfs();
void push(int);
int peek();
int pop();
int isEmpty();

int main(){
  for(int i=0;i<MAX;i++){
    for(int j=0;j<MAX;j++){
      adj[i][j]=0;
    }
  }
  addVertex('S');
  addVertex('A');
  addVertex('B');
  addVertex('C');
  addVertex('D');

  addEdge(0,1);    
  addEdge(0,2);    
  addEdge(0,3);    
  addEdge(1,4);    
  addEdge(2,4);    
  addEdge(3,4);    

  printf("Depth First Search: ");
  dfs(); 

  return 0;   
}


void addEdge(int i,int j){
  adj[i][j]=1;
  adj[j][i]=1;
}

void addVertex(char label){
  struct vertex* v=(struct vertex*)malloc(sizeof(struct vertex));
  v->visited=false;
  v->label=label;
  vertices[count++]=v;
}

int getAdj(int i){
  for(int j=0;j<MAX;j++){
    if(adj[i][j]==1 && vertices[j]->visited==false)
      return j;
  }
  return -1;
}

void display(int i){
  printf("%c ",vertices[i]->label);
}

void dfs(){
  display(0);
  push(0);
  vertices[0]->visited=true;

  while(!isEmpty()){
    int adj=getAdj(peek());
    if(adj==-1)
      pop();
    else{
      vertices[adj]->visited=true;
      display(adj);
      push(adj);
    }
  }
}

void push(int i){
  stack[++top]=i;
}

int pop(){
  return stack[top--];
}

int peek(){
  return stack[top];
}

int isEmpty(){
  return top==-1;
}

