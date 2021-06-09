#include<bits/stdc++.h>
using namespace std;

map<int,list<int>>adj;
map<int,bool>visited;
map<int,int>in;
map<int,int>low;
set<int>AP;
int timer;

void addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node,int par)
{
    visited[node] = true;
    in[node] = low[node] = timer++;
    int child_cnt = 0;
    list<int>::iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++)
    {
        if(par == *it)
        {
            continue;
        }

        if(visited[*it] == true)
        {
            low[node] = min(low[node],in[*it]);
        }
        else
        {
            dfs(*it,node);
            child_cnt++;
            low[node] = min(low[node],low[*it]);
            if(in[node]<=low[*it] && par!=-1)
            {
                AP.insert(node);
            }
        }
    }

    if(par == -1 && child_cnt > 1)
    {
        AP.insert(node);
    }
}

int main()
{
    int n,m,a,b;

    while(1)
    {
        cin>>n>>m;
        if(n==0 && m==0)
        {
            break;
        }
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
            visited[i] = 0;
        }
        AP.clear();
        timer = 1;
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            addEdge(a,b);
        }

        for(int i=1;i<=n;i++)
        {
            if(visited[i] == false)
            {
                dfs(i,-1);
            }
        }

        cout<<AP.size()<<endl;
    }
}