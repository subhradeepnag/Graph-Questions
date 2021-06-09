#include<bits/stdc++.h>
using namespace std;

map<int,bool>visited;
map<int,list<int>>adj;
map<int,int>dist;
int count;

void addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

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

        for(it=adj[curr].begin();it!=adj[curr].end();it++)
        {
            if(visited[*it] == false)
            {
                q.push(*it);
                dist[*it] = dist[curr] + 1;
                visited[*it] = true; 
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
            visited[i] = 0;
        }

        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;
            addEdge(a,b);
        }
        bfs(1);
        cout<<dist[n]<<endl;



    }
}