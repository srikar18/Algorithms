#include<stdio.h>
#include<stdlib.h>

void mergeSort(int *arr,int n,int low,int high);
void mergeArray(int *arr,int n,int low,int mid,int high);

int main(){
  int n,*arr;
  printf("Enter array size : ");
  scanf("%d",&n);
  arr=(int*)malloc(sizeof(int)*n);
  printf("\nEnter array elements : \n");
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("\nBefore sorting : \n");
  for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
  mergeSort(arr,n,0,n-1);
  printf("\nAfter sorting : \n");
  for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
  return 0;
}

void mergeSort(int *arr,int n,int low,int high){
  int mid;
  if(low<high){
    mid=(low+high)/2;
    mergeSort(arr,n,low,mid);
    mergeSort(arr,n,mid+1,high);
    mergeArray(arr,n,low,mid,high);
  }
}

void mergeArray(int *arr,int n,int low,int mid,int high){
  int i,j,k;
  int a=mid-low+1; //Size of first sub-array
  int b=high-mid; //Size of second sub-array

  int lSub[a],rSub[b];

  for(i=0;i<a;i++)
    lSub[i]=arr[low+i];

  for(j=0;j<b;j++)
    rSub[j]=arr[mid+1+j];

  i=0;
  j=0;
  k=low;

  while(i<a && j<b){
    if(lSub[i]<=rSub[j]){
      arr[k]=lSub[i];
      i++;
    }
    else{
      arr[k]=rSub[j];
      j++;
    }
    k++;
  }
  while(i<a){
    arr[k]=lSub[i];
    i++;
    k++;
  }
  while(j<b){
    arr[k]=rSub[j];
    j++;
    k++;
  }
}