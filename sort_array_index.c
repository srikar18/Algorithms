// Problem Link https://www.geeksforgeeks.org/reorder-a-array-according-to-given-indexes/
#include<stdio.h>

void reorder(int arr[],int index[],int n){
  for(int i=0;i<n;i++){
    while(index[i]!=i){
      int tempIndex=index[index[i]];
      int tempValue=arr[index[i]];

      arr[index[i]]=arr[i];
      index[index[i]]=index[i];

      arr[i]=tempValue;
      index[i]=tempIndex;
    }
  }
}
int main(){
  int n;
  printf("Enter the size of the array : ");
  scanf("%d",&n);
  int arr[n],index[n];
  printf("Enter array elements :\n");
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("\nEnter index elements:\n");
  for(int i=0;i<n;i++)
    scanf("%d",&index[i]);
  reorder(arr,index,n);
  printf("Reordered array is \n");
  for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
  return 0;
}