// Problem Link https://www.geeksforgeeks.org/sudoku-backtracking-7/
#include<stdio.h>
#include<stdbool.h>

#define N 9
int r=0,c=0;

void printSolution(int sol[N][N]);
bool fillGrid(int sol[N][N],int,int);
bool isSafe(int,int,int,int sol[N][N]);
bool isComplete(int sol[N][N]);
bool solvePuzzle();
bool solveUtilPuzzle(int sol[N][N]);

void printSolution(int sol[N][N]){
  printf("\n\n*****SOLUTION*****\n\n");
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      printf("%d ",sol[i][j]);
    printf("\n");
  }
}

bool isComplete(int sol[N][N]){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(sol[i][j]==0){
        r=i;
        c=j;
        return false;
      }
    }
  }
  return true;
}

bool solvePuzzle(){
  int sol[N][N];
  printf("Enter Sudoku puzzle in matrix format(0 for empty cell)\n");
  for(int i=0;i<N;i++){
    printf("ROW %d : ",i+1);
    for(int j=0;j<N;j++)
      scanf("%d",&sol[i][j]);
  } 
  if(solveUtilPuzzle(sol)==false){
    printf("Solution does not exist\n");
    return false;
  }
  printSolution(sol);
  return true;
}

bool solveUtilPuzzle(int sol[N][N]){
  if(isComplete(sol))
    return true;
  fillGrid(sol,r,c);
}

bool fillGrid(int sol[N][N],int i,int j){
  for(int k=1;k<=N;k++){
    if(isSafe(i,j,k,sol)){
      sol[i][j]=k;

      if(solveUtilPuzzle(sol))
        return true;
      
      sol[i][j]=0;
    }
  }
  return false;
}

bool isSafe(int row,int col,int num,int sol[N][N]){
  for(int i=0;i<N;i++){
    if(sol[row][i]==num)
      return false;
  }
  for(int i=0;i<N;i++){
    if(sol[i][col]==num)
      return false;   
  }
  int currentBoxRow=row/3;
  int currentBoxCol=col/3;
  for(int i=currentBoxRow*3;i<(currentBoxRow*3)+3;i++){
    for(int j=currentBoxCol*3;j<(currentBoxCol*3)+3;j++){
      if(sol[i][j]==num)
        return false;
    }
  }
  return true;
}

int main(){
  solvePuzzle();
  return 0;
}