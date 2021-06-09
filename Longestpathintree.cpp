#include<bits/stdc++.h>
using namespace std;

map<int,bool>visited;
map<int,list<int>>adj;
int maxD,maxNode;

void addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int v,int d)
{
    visited[v] = true;
    if(d>maxD)
    {
        maxD = d;
        maxNode = v;
    }
    list<int>::iterator it;
    for(it = adj[v].begin();it!=adj[v].end();it++)
    {
        if(visited[*it] == false)
        {
            dfs(*it,d+1);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
    }
    maxD = -1;
    dfs(1,0);

    for(int i=1;i<=n;i++)
    {
        visited[i] = false;
    }

    maxD = -1;
    dfs(maxNode,0);

    cout<<maxD<<endl;
    

}