#include<stdio.h>
#include<stdlib.h>

void quickSort(int *arr,int n,int l,int h);

int main(){
  int n,*arr;
  printf("Enter array size : ");
  scanf("%d",&n);
  arr = (int*)malloc(sizeof(int)*n);
  printf("\nEnter array elements : \n");
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("\nBefore sorting : \n");
  for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
  quickSort(arr,n,0,n-1);
  printf("\nAfter sorting : \n");
  for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
  return 0;
}

void quickSort(int *arr,int n,int low,int high){
  int i,j,key,temp;
  if(low<high){
    key=low;
    i=low;
    j=high;
    while(i<j){
      while(arr[i]<=arr[key])
        i++;
      while(arr[j]>arr[key])
        j--;
      if(i<j){
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }
    temp=arr[key];
    arr[key]=arr[j];
    arr[j]=temp;
    quickSort(arr,n,low,j-1);
    quickSort(arr,n,j+1,high);
  }
}