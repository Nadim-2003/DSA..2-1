#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int parent[N];
int size[N];
int Rank[N];

void make(int v) {
    parent[v] = v;
    size[v] = 1;
    Rank[v]=0;
}

int find(int v) {
    if (v == parent[v]) 
        return v;
    return parent[v] = find(parent[v]); // Path compression
}

void Union(int a, int b) {   //Union by size
    a = find(a);
    b = find(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b]; // Update size
    }
}

void UnionRank(int a,int b){
   int a=find(a);
   int b=find(b);
   if(a!=b){
      if(Rank[a]<Rank[b]){
         parent[a]=b;
      }else if(Rank[a]>Rank[b]){
         parent[b]=a;
      }else{
         parent[b]=a;
         Rank[a]++;
      }
   }
}
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        make(i);
    }
    int u, v;
    while (k--) {
        cin >> u >> v;
        Union(u, v);
    }
    int connected = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) 
            connected++;
    }
    cout << connected << endl; // Print the number of connected components
    return 0;
}
