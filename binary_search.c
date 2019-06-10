#include<stdio.h>
#include<stdlib.h>

void quickSort(int *arr,int n,int low,int high);
int binarySearch(int *arr,int n,int key,int low,int high);

int main(){
  int n,*arr,key,pos;
  printf("Enter array size : ");
  scanf("%d",&n);
  arr=(int*)malloc(sizeof(int)*n);
  printf("\nEnter array elements : \n");
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  quickSort(arr,n,0,n-1);
  printf("\nEnter element to be found : \n");
  scanf("%d",&key);
  pos=binarySearch(arr,n,key,0,n-1);
  if(pos==-1)
    printf("%d not found in the array",key);
  else
    printf("%d found in the array",key,pos);
  return 0;
}

int binarySearch(int *arr,int n,int key,int low,int high){
  int mid;
  while(low<=high){
    mid=(low+high)/2;
    if(arr[mid]==key)
      return mid;
    else if(key>arr[mid])
      return binarySearch(arr,n,key,mid+1,high);
    else
      return binarySearch(arr,n,key,low,mid-1);
  }
  return -1;
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
      while(arr[key]<arr[j])
        j--;
      if(i<j){
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }
    temp=arr[j];
    arr[j]=arr[key];
    arr[key]=temp;
    quickSort(arr,n,low,j-1);
    quickSort(arr,n,j+1,high);
  }
}
