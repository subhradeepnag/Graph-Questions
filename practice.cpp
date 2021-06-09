#include<bits/stdc++.h>
using namespace std;

map<int,bool>visited;
map<int,list<int>>adj;

void addEdge(int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void DFSutil(int v)
{
    visited[v] = true;
    // cout<<v<<" ";
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(visited[*i] == false)
        {
            DFSutil(*i);
        }
    }
}

void DFS(int n,int e)
{
    int count = 0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i] == false)
        {
            DFSutil(i);
            // cout<<endl;
            count++;
        }
    }
    cout<<count;
}

int main()
{
    int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		int u,v;
		cin>>u>>v;
		addEdge(u,v);
        // cout<<u<<" "<<v<<endl;
	}
	DFS(n,e);
}