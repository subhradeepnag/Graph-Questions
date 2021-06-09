#include<bits/stdc++.h>
using namespace std;

map<int,list<int>>adj;
map<int,bool>visited;
map<int,list<int>>tr;
vector<int>order;
vector<int>SCC;

void dfs(int node)
{
    visited[node] = 1;
    for(auto it=adj[node].begin();it!=adj[node].end();it++)
    {
        if(visited[*it] == false)
        {
            dfs(*it);
        }
    }

    order.push_back(node);
}

void dfs1(int node)
{
    visited[node] = 1;
    for(auto it=adj[node].begin();it!=adj[node].end();it++)
    {
        if(visited[*it] == false)
        {
            dfs1(*it);
        }
    }
    SCC.push_back(node);
}

int main()
{
    int t,a,b,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
            tr[i].clear();
            visited[i] = 0;
        }
        order.clear();
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
            tr[b].push_back(a);
        }
        for(int i=1;i<=n;i++)
        {
            if(visited[i] == 0)
            {
                dfs(i);
                //We have our Order.
            }
        }

        for(int i=1;i<=n;i++)
        {
            visited[i] == 0;
        }

        for(int i=1;i<=n;i++)
        {
            if(visited[order[n-i]] == 0)
            {
                SCC.clear();
                dfs1(order[n-i]);
                //We have our SCC.
                cout<<order[n-i]<<endl;
                for(int node:SCC)
                {
                    cout<<node<<" ";
                    cout<<endl;
                }
            }   
        }

    }
}