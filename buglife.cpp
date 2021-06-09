#include<bits/stdc++.h>
using namespace std;

map<int,int>visited;
map<int,bool>color;
map<int,list<int>>adj;

void addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool dfs(int v,int c)
{
    visited[v] = 1;
    color[v] = c;
    list<int>::iterator it;
    for(it=adj[v].begin();it!=adj[v].end();it++)
    {
        if(visited[*it] == 0)
        {
            bool res = dfs(*it,c^1);
            if(res == false)
            {
                return false;
            }
        }
        else
        {
            if(color[v] == color[*it])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    int q = 1;
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

        bool flag = true;
        for(int i=1;i<=n;i++)
        {
            if(visited[i] == 0)
            {
                bool res = dfs(i,0);

                if(res == false)
                {
                    flag = false;
                }
            }
        }

        cout<<"Scenario #"<<q<<":"<<endl;

        if(flag == false)
        {
            cout<<"Suspicious bugs found!"<<endl;
        }
        else
        {
            cout<<"No suspicious bugs found!"<<endl;
        }
        q++;
    }
}