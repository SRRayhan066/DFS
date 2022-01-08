#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>>vec;
map<int,bool>vis;

void dfs(int source){
    vis[source]=true;
    for(auto i : vec[source]){
        if(!vis[i]) dfs(i);
    }
}

int main(){
    int node,edge;
    cin>>node>>edge;// Taking the number of node and edge
    for(int i=0;i<edge;i++){
        int x,y;
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);// Using adjacency list
    }

    int ans = 0;
    for(auto it=vec.begin();it!=vec.end();it++){
        if(!vis[it->first]){
            ans++;
            dfs(it->first);
        }
    }
    cout<<ans<<endl;
}