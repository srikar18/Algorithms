// Problem Link https://www.geeksforgeeks.org/greatest-contiguous-sub-array-of-size-k/
#include<bits/stdc++.h>
using namespace std;

vector <int> maxContiguous(int arr[],int n,int k){
  vector < vector<int> > ans;
  for(int i=0;i<n-k+1;i++){
    vector <int> temp;
    for(int j=i;j<i+k;j++){
      temp.push_back(arr[j]);
    }
    ans.push_back(temp);
  }
  sort(ans.begin(),ans.end());
  return ans[ans.size()-1];
}

int main(){
  int n,k,*arr;
  cout<<"Enter the size of the array"<<endl;
  cin>>n;
  cout<<"Enter array elements"<<endl;
  arr=new int[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  cout<<"Enter value of k(for greatest contiguous subarray)"<<endl;
  cin>>k;
  vector<int> sol=maxContiguous(arr,n,k);
  for(int i=0;i<sol.size();i++)
    cout<<sol.at(i)<<" ";
  return 0;
}
