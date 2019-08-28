// Problem Link https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/
#include<stdio.h>
#include<stdbool.h>

#define N 4

void printSolution(int sol[N][N]);
bool isSafe(int,int,int sol[N][N]);
bool solveProb();
bool solveProbUtil(int sol[N][N],int);

void printSolution(int sol[N][N]){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      printf("%d\t",sol[i][j]);
    printf("\n");
  }
}

bool solveProb(){
  int sol[N][N];
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      sol[i][j]=0;
  if(solveProbUtil(sol,0)==false){
    printf("Solution does not exist\n");
    return false;
  }
  printSolution(sol);
  return true;
}

bool solveProbUtil(int sol[N][N],int count){
  if(count>=N)
    return true;
  for(int i=0;i<N;i++){
    if(isSafe(i,count,sol)){
      sol[i][count]=1;

      if(solveProbUtil(sol,count+1))
        return true;

      sol[i][count]=0;
    }
  }
  return false;
}

bool isSafe(int row,int col,int sol[N][N]){
  for(int i=0;i<col;i++){
    if(sol[row][i])
      return false;
  }
  for(int i=row,j=col;i>=0 && j>=0;i--,j--){
    if(sol[i][j])
      return false;
  }
  for(int i=row,j=col;i<N && j>=0;i++,j--){
    if(sol[i][j])
      return false;
  }
  return true;
}
int main(){
  solveProb();
  return 0;
}