#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *arr,int n);

int main(){
  int n;
  int *arr;
  printf("Enter number of array elements : ");
  scanf("%d",&n);
  arr = (int*)malloc(sizeof(int)*n);
  printf("\nEnter array elements : \n");
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("\nBefore sorting : \n");
  for(int i=0;i<n;i++)
    printf("%d",arr[i]);
  insertionSort(arr,n);
  printf("\nAfter sorting : \n");
  for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
  return 0;
}

void insertionSort(int *arr,int n){
  int temp,j;
  for(int i=1;i<n;i++){
    j=i;
    while(j>0 && arr[j-1]>arr[j]){
      temp=arr[j-1];
      arr[j-1]=arr[j];
      arr[j]=temp;
      j--;
    }
  }
}
