#include<bits/stdc++.h>
using namespace std;

map<int,bool>visited;
map<int,list<int>>adj;

void addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int v)
{
    visited[v] = true;
    list<int>::iterator it;
    for(it=adj[v].begin();it!=adj[v].end();it++)
    {
        if(visited[*it] == false)
        {
            dfs(*it);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        addEdge(a,b);
    }    
    int cc_count = 0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i] == false)
        {
            dfs(i);
            cc_count++;
        }
    }

    if((cc_count == 1) && (m == n-1))
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}