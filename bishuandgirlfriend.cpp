#include<bits/stdc++.h>
using namespace std;

map<int,bool>visited;
map<int,list<int>>adj;
map<int,int>dist;

void addEdge(int u,int v)
{
    adj[u].push_back(v);
}

void dfs(int v,int d)
{
    visited[v] = true;
    dist[v] = d;
    list<int>::iterator it;
    for(it = adj[v].begin();it!=adj[v].end();it++)
    {
        if(visited[*it] == false)
        {
            dfs(*it,dist[v] + 1);
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
    dfs(1,0);
    int q;
    cin>>q;
    int ans = -1,min_dist = INT_MAX;
    while(q--)
    {
        int girl_city;
        cin>>girl_city;
        if(dist[girl_city]<min_dist)
        {
            min_dist = dist[girl_city];
            ans = girl_city;
        }
        else
        {
            if(dist[girl_city]==min_dist && girl_city < ans)
            {
                ans = girl_city;
            }
        }
    }
    cout<<ans;
}