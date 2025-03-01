//----->>>>Binary sarch for finding a number that is less than k

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int binary_sarch(int f,int l,int arr[],int k){
  int ans;
  while(f<=l){
    int mid=(f+l)/2;
    if(arr[mid]<k){
      ans=arr[mid];
       f=mid+1;

    }else{
       l=mid-1;
    }
  }
  return ans;
}
int main(){
 int n;
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++){
  cin>>arr[i];
 }
 int k;
 cin>>k;
 cout<<binary_sarch(0,n,arr,k)<<endl;
    return 0;
}