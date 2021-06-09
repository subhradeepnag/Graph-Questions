#include<bits/stdc++.h>
using namespace std;

map<int,bool>recStack;
map<int,bool>visited;
map<int,list<int>>adj;

void addEdge(int u,int v)
{
    adj[u].push_back(v);
}

bool dfs(int v)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;

        list<int>::iterator i;
        for(i=adj[v].begin();i!=adj[v].end();i++)
        {
            if((visited[*i] == false) && dfs(*i))
            {
                return true;
            }
            else if(recStack[*i])
            {
                return true;
            }
        }
    }
    recStack[v] = false;
    return false;   
}

bool isCyclic(int V)
{
    for(int i=0;i<V;i++)
    {
        recStack[i] = false;
        visited[i] = false;
    }

    for(int i=0;i<V;i++)
    {
        if(dfs(i))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    addEdge(1,2);
    addEdge(2,3);
    addEdge(3,4);
    addEdge(4,2
    );
    addEdge(4,5);
    cout<<isCyclic(5);
}