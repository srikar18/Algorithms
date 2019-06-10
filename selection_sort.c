#include<stdio.h>
#include<stdlib.h>

void selectionSort(int *arr,int n);

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
    printf("%d ",arr[i]);
  selectionSort(arr,n);
  printf("\nAfter sorting : \n");
  for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
  return 0;
}

void selectionSort(int *arr,int n){
  int temp,min;
  for(int i=0;i<n-1;i++){
    min=i;
    for(int j=i+1;j<n;j++){
      if(arr[min]>arr[j])
        min=j;
      }
      temp=arr[i];
      arr[i]=arr[min];
      arr[min]=temp;
    }
  }
