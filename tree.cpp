#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10e5;
bool vis[N]={0};
int level[N]={0};
vector<int> graph[N];

void insert(int a,int b){
   graph[a].push_back(b);
   graph[b].push_back(a);
}

void bfs(int a){
   queue<int>q;
   q.push(a);
   vis[a]=true;
   while(!q.empty()){
      int ok=q.front();
      q.pop();
      cout<<ok<<" ";
      for(auto it:graph[ok]){
         if(!vis[it]) {
           q.push(it);
            vis[it]=true;
           level[it]=level[ok]+1;
         }

      }
   }
}
int main(){

    return 0;
}