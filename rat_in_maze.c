// Problem Link https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/
#include<stdio.h>
#include<stdbool.h>

int n;

bool solveMazeUtil(int path[n][n]);
bool solveUtil(int,int,int path[n][n],int sol[n][n]);
bool isSafe(int,int,int sol[n][n]);
void printSolution(int sol[n][n]);

int main(){
  printf("Enter size of the sqaure matrix : ");
  scanf("%d",&n);
  int path[n][n];
  printf("\nEnter the matrix representation(0-end 1-path) :\n");
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      scanf("%d",&path[i][j]);
  solveMazeUtil(path);
  return 0;
}

bool isSafe(int x,int y,int path[n][n]){
  return(x>=0 && x<n && y>=0 && y<n && path[x][y]==1);
}

void printSolution(int sol[n][n]){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      printf("%d\t",sol[i][j]);
    }
    printf("\n");
  }
}

bool solveMazeUtil(int path[n][n]){
  int sol[n][n];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      sol[i][j]=0;
  if(solveUtil(0,0,path,sol)==false){
    printf("Solution does not exist\n");
    return false;
  }
  printSolution(sol);
  return true;
}

bool solveUtil(int x,int y,int path[n][n],int sol[n][n]){
  if(x==n-1 && y==n-1){
    sol[x][y]=1;
    return true;
  }

  if(isSafe(x,y,path)){
    sol[x][y]=1;
    
    if(solveUtil(x+1,y,path,sol))
      return true;
    
    if(solveUtil(x,y+1,path,sol))
      return true;

    sol[x][y]=0;
    return false;
  }
  return false;
}