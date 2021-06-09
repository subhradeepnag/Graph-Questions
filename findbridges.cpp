#include<bits/stdc++.h>
using namespace std;

map<int,list<int>>adj;
map<int,bool>visited;
map<int,int>in;
map<int,int>low;
int timer; 

void addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node,int par)
{
    visited[node] = true;
    in[node] = low[node] = timer;
    timer++;
    list<int>::iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++)
    {
        if(*it == par)
        {
            continue;
        }
        if(visited[*it] == true)
        {
            //BackEdge
            low[node] = min(low[node],in[*it]);

        }
        else
        {
            //Forward Edge
            dfs(*it,node);

            if(low[*it]>in[node])
            {
                cout<<node<<" -> "<<*it<<" is a bridge";
            }

            low[node] = min(low[node],low[*it]);
        }
    }

}

int main()
{
    addEdge(1,2);
    addEdge(2,3);
    addEdge(3,4);
    addEdge(2,4);
    dfs(1,-1);
}