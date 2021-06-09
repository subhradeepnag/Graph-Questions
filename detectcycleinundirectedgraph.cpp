#include<bits/stdc++.h>
using namespace std;

map<int,bool>visited;
map<int,list<int>>adj;

void addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool dfs(int v,int parent)
{
    visited[v] = true;
    list<int>::iterator it;
    for(it=adj[v].begin();it!=adj[v].end();it++)
    {
        if(visited[*it] == false)
        {
            bool res = dfs(*it,v);
            if(res == true)
            {
                return true;
            }
        }
        else
        {
            if(parent != *it)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    addEdge(1,2);
    addEdge(2,3);
    addEdge(3,4);
    addEdge(2,4);
    addEdge(4,5);
    cout<<dfs(1,0);

}