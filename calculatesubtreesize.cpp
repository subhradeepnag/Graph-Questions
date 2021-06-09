#include<bits/stdc++.h>
using namespace std;

map<int,bool>visited;
map<int,list<int>>adj;
map<int,int>suSize;

void addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int dfs(int v)
{
    visited[v] = true;
    int cur_size = 1;
    list<int>::iterator it;
    for(it=adj[v].begin();it!=adj[v].end();it++)
    {
        if(visited[*it] == false)
        {
            cur_size+=dfs(*it);
        }
    }
    suSize[v] = cur_size;
    return cur_size;
}

int main()
{
    addEdge(1,2);
    addEdge(2,3);
    addEdge(2,4);
    addEdge(3,7);
    addEdge(4,5);
    addEdge(4,6);
    dfs(1
    );
    for(auto it:suSize)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
}