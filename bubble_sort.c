#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *arr,int n);

int main(){
  int n;
  int *arr;
  printf("Enter number of array elements: ");
  scanf("%d",&n);
  arr = (int*)malloc(sizeof(int)*n);
  printf("\nEnter array elements: \n");
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("\nBefore Sorting : \n");
  for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
  bubbleSort(arr,n);
  printf("\nAfter Sorting : \n");
  for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
  return 0;
}

void bubbleSort(int *arr,int n){
  int temp;
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
      if(arr[j]>arr[j+1]){
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }
  }
}