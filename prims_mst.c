#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>

int v;

int minKey(int key[],bool mstSet[]){
  int min=INT_MAX,min_index;
  for(int i=0;i<v;i++){
    if(mstSet[i]==false && key[i]<min){  
      min=key[i];
      min_index=i;
    }
  }
  return min_index;
}

int printMST(int parent[],int graph[v][v]){
  printf("EDGE \tWEIGHT\n");
  for(int i=1;i<v;i++)
    printf("%d - %d \t%d\n",parent[i],i,graph[i][parent[i]]);
}

void findMST(int graph[v][v]){
  int parent[v]; // store mst
  int key[v]; // pick edge with minimum weight
  bool mstSet[v]; // represents whether the vertices have been visited or not

  for(int i=0;i<v;i++){
    key[i]=INT_MAX;
    mstSet[i]=false;
  }
  key[0]=0;
  parent[0]=-1;
  for(int i=0;i<v-1;i++){
    int u=minKey(key,mstSet);
    mstSet[u]=true;

    for(int j=0;j<v;j++){
      if(graph[u][j] && mstSet[j]==false && graph[u][j]<key[j]){
        parent[j]=u;
        key[j]=graph[u][j];
      }
    }
  }
  printMST(parent,graph);
}


int main(){
  printf("Enter the number of vertices : ");
  scanf("%d",&v);
  int graph[v][v];
  printf("Enter data for the graph : \n");
  for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
      scanf("%d",&graph[i][j]);
    }
  }
  findMST(graph);
  return 0;
}