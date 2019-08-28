// Problem Link https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/
#include<stdio.h>
#include<stdbool.h>
#define N 8

bool solveProb();
bool isSafe(int,int,int sol[N][N]);
void printSolution(int sol[N][N]);
bool solveProbUtil(int,int,int,int sol[N][N],int*,int*);

bool solveProb(){
  int sol[N][N];
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
    sol[i][j]=-1;
  int xMove[8]={2,1,-1,-2,-2,-1,1,2};
  int yMove[8]={1,2,2,1,-1,-2,-2,-1};
  sol[0][0]=0;

  if(solveProbUtil(0,0,1,sol,xMove,yMove)==false){
    printf("Solution does not exist");
    return false;
  }
  else
    printSolution(sol);
  return true;
}

bool solveProbUtil(int x,int y,int count,int sol[N][N],int xMove[N],int yMove[N]){
  int next_x,next_y;
  if(count==N*N)
    return true;
  for(int k=0;k<8;k++){
    next_x=x+xMove[k];
    next_y=y+yMove[k];

    if(isSafe(next_x,next_y,sol)){
      sol[next_x][next_y]=count;
      if(solveProbUtil(next_x,next_y,count+1,sol,xMove,yMove))
        return true;
      else
        sol[next_x][next_y]=-1;
    }
  }
  return false;
}

bool isSafe(int x,int y,int sol[N][N]){
  return (x>=0 && x<N && y>=0 && y<N && sol[x][y]==-1);
}

void printSolution(int sol[N][N]){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      printf("%d\t",sol[i][j]);
    printf("\n");
  }
}

int main(){
  solveProb();
  return 0;
}