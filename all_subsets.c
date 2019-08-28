
// Problem Link https://www.geeksforgeeks.org/print-subsets-given-size-set/
#include<stdio.h>
void printCombinations(int arr[],int,int);
void combinationsUtil(int arr[],int,int,int,int data[],int);

void printCombinations(int arr[],int n,int size){
  int subsets[size];
  combinationsUtil(arr,n,size,0,subsets,0);
}

void combinationsUtil(int arr[],int n,int size,int subIndex,int subsets[],int arrIndex){
  if(subIndex==size){
    for(int i=0;i<size;i++)
      printf("%d ",subsets[i]);
    printf("\n");
    return;
  }
  if(arrIndex>=n)
    return;
  subsets[subIndex]=arr[arrIndex];
  combinationsUtil(arr,n,size,subIndex+1,subsets,arrIndex+1);
  combinationsUtil(arr,n,size,subIndex,subsets,arrIndex+1);
}
int main(){
  int n;
  printf("Enter the size of the array: \n");
  scanf("%d",&n);
  int arr[n];
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  for(int i=1;i<=n;i++)
    printCombinations(arr,n,i);
  return 0;
}