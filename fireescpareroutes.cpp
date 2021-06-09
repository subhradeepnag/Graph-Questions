#include<bits/stdc++.h>
using namespace std;

map<int,bool>visited;
map<int,list<int>>adj;
int cc_size;

void addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); 
}

void dfs(int v)
{
    visited[v] = true;
    cc_size++;
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
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
            visited.clear();
        }
        for(int i=0;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;
            addEdge(a,b);
        } 
        int cnt = 0;
        int res = 1;
        for(int i=1;i<=n;i++)
        {
            if(visited[i] == 0)
            {
                cc_size = 0;
                dfs(i);
                cnt++;

                res = (res*cc_size)%1000000007;  
            }
        }
        cout<<cnt<<" "<<res<<endl;;
    }
}