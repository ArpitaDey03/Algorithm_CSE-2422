#include<bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

vector<int>graph[5];

bool visited[5];
void dfs(int source){
 visited[source]=1;
 for(int i=0;i<graph[source].size();i++){
    int next=graph[source];
    if(visited[next]==0)
        dfs(next);
 }
 }
int main(){
int nodes,edges;
cin>>nodes >> edges;
for(int i=0;i<edges;i++){
    int u,v;
    cin>>u>>v;
    graph[u].push.back(v);
    graph[v].push.back(u);
}
}
    dfs(0);
    for(int i=0;i<nodes;i++){
        if(visited==1){
            cout<<"Node"<<i<<"is visited."<<endl;
        }
        else{
            cout<<"Node"<<i<<"is not visited."<<endl;

        }
    }
return 0;
}

