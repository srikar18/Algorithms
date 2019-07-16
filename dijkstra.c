#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 10

void dijkstra(int graph[MAX][MAX],int n,int start);

int main(){
  int graph[MAX][MAX],n,u;
  printf("Enter number of vertices : ");
  scanf("%d",&n);
  printf("Enter adjacency matrix :\n");
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf("%d",&graph[i][j]);
    }
  }
  printf("\nEnter the starting node : ");
  scanf("%d",&u);
  dijkstra(graph,n,u);
  return 0;
}

void dijkstra(int graph[MAX][MAX],int n,int start){
  int cost[MAX][MAX],distance[MAX],pred[MAX],visited[MAX],count,minDist,next;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(graph[i][j]==0)
        cost[i][j]=INFINITY;
      else
        cost[i][j]=graph[i][j];
    }
  }
  for(int i=0;i<n;i++){
    distance[i]=cost[start][i];
    pred[i]=start;
    visited[i]=0;
  }
  distance[start]=0;
  visited[start]=1;
  count=1;
  while(count<n-1){
    minDist=INFINITY;
    for(int i=0;i<n;i++){
      if(distance[i]<minDist && !visited[i]){
        minDist=distance[i];
        next=i;
      }
      visited[next]=1;
    }
    for(int i=0;i<n;i++){
      if(minDist+cost[next][i]<distance[i]){
        distance[i]=minDist+cost[next][i];
        pred[i]=next;
      }
    }
    count++;
  }
  for(int i=0;i<n;i++){
    if(i!=start){
      printf("\nDistance from %d to %d is %d",start,i,distance[i]);
      printf("\nPath = %d",i);
      int j=i;
      do{
        j=pred[j];
        printf(" <- %d",j);
      }while(j!=start);
    }
  }
}