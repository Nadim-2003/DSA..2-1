 //Using DFS......
/*#include <bits/stdc++.h>
using namespace std;
const int N=10e5;
bool vis[N]={0};//initialize all the the visited array value as 0 which means false
vector<int> graph[N];

void makelink(int s,int d){
    graph[s].push_back(d);
    graph[d].push_back(s);
}

void dfs(int v){
    cout<<v<<endl;
    vis[v]=true;
    for(int child:graph[v]){
        cout<<"par "<<v<<" child "<<child<<endl;
        if(vis[child]) continue;
        dfs(child);
    }
}

int main()
{
    int v,e;
    cin>>v>>e;
    
    while(e--){
        int s,d;
        cin>>s>>d;
        makelink(s,d);
    }
    cout<<endl;
    dfs(v);

    return 0;
}*/

//  Conected Component....

/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10e5;
bool vis[N]={0};//initialize all the the visited array value as 0 which means false
vector<int> graph[N];
vector<int>cc_count;
vector<vector<int>> cc;

void makelink(int s,int d){
    graph[s].push_back(d);
    graph[d].push_back(s);
}

void dfs(int v){
    vis[v]=true;
    cc_count.push_back(v);
    for(int child:graph[v]){
        if(vis[child]) continue;
        dfs(child);
    }
}
int main(){
 int v,e;
    cin>>v>>e;
    
    while(e--){
        int s,d;
        cin>>s>>d;
        makelink(s,d);
    }
    int count=0;
    for(int i=1;i<=v;i++){
        if(vis[i]) continue;
        cc_count.clear();
           dfs(i);
           count++;
           cc.push_back(cc_count);
    }
  cout<<count<<endl;
  for(auto it:cc){
    for(auto ok:it){
        cout<<ok<<" ";
    }
    cout<<endl;
  }

    return 0;
}*/


// ####   BFS    ####
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6;
bool vis[N]={0};//initialize all the the visited array value as 0 which means false
vector<int> graph[N];
int level[N]={0};

void makelink(int s,int d){
    graph[s].push_back(d);
    graph[d].push_back(s);
}

void bfs(int initial){
    queue<int>q;
    q.push(initial);
    vis[initial]=true;

    while(!q.empty()){
        int recent=q.front();
             q.pop();
             cout<<recent<<" ";
             for(auto it:graph[recent]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=true;
                    level[it]=level[recent]+1;
                }
             }
    }
    cout<<endl;
}
int main(){
   int v;
   cin>>v;
   int n=v;
   while(v--){
    int a,b;
    cin>>a>>b;
    makelink(a,b);
   }
   bfs(1);
//    for(int i=1;i<=n;i++){
//     cout<<level[i]<<" "<<i<<endl;
//    }
    return 0;
}