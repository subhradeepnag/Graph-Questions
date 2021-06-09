#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
        map<int,bool>visited;
        map<int,list<int>>adj;

        void addEdge(int v,int w);
        void DFSutil(int v);
        void DFS();
};

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}

void Graph::DFSutil(int v)
{
    visited[v] = true;
    cout<<v<<" ";
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(visited[*i] == false)
        {
            DFSutil(*i);
        }
    }
}

void Graph::DFS()
{
    for(auto i:adj)
    {
        if(visited[i.first] == false)
        {
            DFSutil(i.first);
        }
    }
}

int main()
{
    Graph g;
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(4, 1);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 4);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 1) \n";
    g.DFS();
}