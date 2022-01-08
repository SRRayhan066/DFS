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
    cin>>node>>edge;//Taking the number of node and number of edge

    for(int i=0;i<edge;i++){
        int x,y;
        cin>>x>>y;//taking two nodes
        vec[x].push_back(y);
        vec[y].push_back(x);//using adjacency list
    }

    int source;
    cin>>source;
    dfs(source);//DFS call

    for(auto it=vec.begin();it!=vec.end();it++){
        cout<<"vis["<<it->first<<"] :: "<<vis[it->first]<<endl; // checking that all nodes are visited or not
    }
    return 0;
}
