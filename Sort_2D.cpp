#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void merge(vector<vector<int>> &arr, int left, int mid, int right) {
    
    vector<vector<int>> temp;
    int first=left;
    int last=mid+1;
    
    while(first<=mid && last<=right){
        if(arr[first][1] < arr[last][1] || (arr[first][1] == arr[last][1] && arr[first][0] <= arr[last][0])){
          temp.push_back({arr[first][0],arr[first][1]});
          first++;
        }else{
             temp.push_back({arr[last][0],arr[last][1]});
           last++;
        }
    }
    while(first<=mid){
      temp.push_back({arr[first][0],arr[first][1]});
          first++;
    }
    while(last<=right){
        temp.push_back({arr[last][0],arr[last][1]});
           last++;
    }
    for(int i=left;i<=right;i++){
      arr[i][0]=temp[i-left][0];
      //arr[i][1]=temp[i-left][1];
    }
}

void mergeSort(vector<vector<int>> &arr, int left, int right) {
    if (left >= right) return;
        int mid = (left +right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    
}
int main(){
 
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0;i < n;i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    mergeSort(arr, 0, n - 1);

    for (int i=0; i<n ;i++) {
        cout << arr[i][0]<<endl;
    }

    return 0;
}
