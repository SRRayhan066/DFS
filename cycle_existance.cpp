#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>>vec;
map<int,bool>vis;

bool dfs(int source,int parent){ // tracking the parent node also
    vis[source]=true;
    for(auto i : vec[source]){
        if(vis[i] && i!=parent) return true; // Has found a neighbour node which is already visited but not it's parent 
        else if(!vis[i]) dfs(i,source);
    }
    return false; //Didn't found a cycle
}

int main(){
    int node,edge;
    cin>>node>>edge;// Taking the number of node and edge
    for(int i=0;i<edge;i++){
        int x,y;
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x); // using adjacency list
    }

    int source;
    cin>>source;
    bool check = dfs(source,-1); // DFS call

    if(check) cout<<"Cycle exist!!"<<endl;
    else cout<<"There is no cycle."<<endl;

    return 0;
}