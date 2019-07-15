#include<stdio.h>
#include<stdlib.h>

#define MAX 100

void dfs(int);

int adj[MAX][MAX],visited[MAX],v;

int main(){
  printf("Enter the number of vertices : ");
  scanf("%d",&v);

  for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
      scanf("%d",&adj[i][j]);
    }
  }
  for(int i=0;i<v;i++)
    visited[i]=0;
  printf("DEPTH FIRST SEARCH : \n");
  dfs(0);
}

void dfs(int k){
  printf("%d ",k);
  visited[k]=1;

  for(int j=0;j<v;j++){
    if(!visited[j] && adj[k][j]==1)
      dfs(j);
  }
}
