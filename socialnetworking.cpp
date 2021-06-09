#include<bits/stdc++.h>
using namespace std;

map<int,list<int>>adj;
map<int,int>level;
map<int,bool>visited;
map<int,int>dist;

void bfs(int v)
{
    queue<int>q;
    q.push(v);
    visited[v] = true;
    dist[v] = 0;
    list<int>::iterator it;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(it = adj[curr].begin();it!=adj[curr].end();it++)
        {
            if(visited[*it] == false)
            {
                dist[*it] = dist[curr] + 1;
                q.push(*it);
                level[dist[child]]++;
            }
        }
    }
}

int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=1;i<=e;i++)
    {
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
    }
    int m;
    for(int i=1;i<=m;i++)
    {
        int src,t;
        cin>>src>>t;
        for(int i=0;i<=n;i++)
        {
            level[i] = 0;
            visited[i] = 0;

            bfs(src);

            cout<<level[d]<<endl;
        }
    }
}