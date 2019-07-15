#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int n,adj[MAX][MAX],state[MAX],queue[MAX],front=-1,rear=-1;

void create_graph();
void bfs_traversal();
void bfs(int);
void insert(int);
int del();
int isEmpty();

int main(){
  create_graph();
  bfs_traversal();
  return 0;
}

void create_graph(){
  printf("Enter the number of vertices : ");
  scanf("%d",&n);
  printf("\nEnter data of adjacency matrix :\n");
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf("%d",&adj[i][j]);
    }
  }
}

void bfs_traversal(){
  int v;
  for(int i=0;i<n;i++)
    state[i]=initial;
  printf("Enter the start vertex of BFS : ");
  scanf("%d",&v);
  bfs(v);
}

void bfs(int v){
  int i;
  insert(v);
  state[v]=waiting;
  while(!isEmpty()){
    v=del();
    printf("%d ",v);
    state[v]=visited;
    for(int i=0;i<n;i++){
      if(adj[v][i]==1 && state[i]==initial){
        insert(i);
        state[i]=waiting;
      }
    }
  }
}

void insert(int v){
  if(front==-1)
    front=0;
  queue[++rear]=v;
}

int del(){
  return queue[front++];
}

int isEmpty(){
  if(front==-1||front>rear)
    return 1;
  return 0;
}

