#include<stdio.h>
#include<stdlib.h>

int linearSearch(int *arr,int n,int key);

int main(){
  int n,*arr,key,pos;
  printf("Enter array size : ");
  scanf("%d",&n);
  arr = (int*)malloc(sizeof(int)*n);
  printf("\nEnter array elements : \n");
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("Enter element to search : ");
  scanf("%d",&key);
  pos=linearSearch(arr,n,key);
  if(pos==-1)
    printf("%d not found in array",key);
  else
    printf("First occurence of %d found at %d position in the array",key,pos);
  return 0;
}

int linearSearch(int *arr,int n,int key){
  for(int i=0;i<n;i++){
    if(arr[i]==key)
      return i;
  }
  return -1;
}