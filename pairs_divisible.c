// Problem Link https://www.geeksforgeeks.org/count-pairs-in-array-whose-sum-is-divisible-by-k/
#include<stdio.h>
int countDivisible(int arr[],int n,int k);

int main(){
  int n,k;
  printf("Enter number of array elements : ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter array elements : \n");
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  printf("Enter k value(number by which the pair is to be divisible) : ");
  scanf("%d",&k);
  printf("%d",countDivisible(arr,n,k));
  return 0;
}

int countDivisible(int arr[],int n,int k){
  int rem[k],count=0;
  for(int i=0;i<k;i++)
    rem[i]=0;
  for(int i=0;i<n;i++)
    rem[arr[i]%k]++;
  count=(rem[0]*(rem[0]-1))/2;
  for(int i=1;i<=k/2 && i!=(k-i);i++)
    count+=(rem[i]*rem[k-i]);
  if(k%2==0)
    count+=(rem[k/2]*(rem[k/2]-1))/2;
  return count;
}