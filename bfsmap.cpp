#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
        map<int,bool>visited;
        map<int,list<int>>adj;
        queue<int>q;

        void addEdge(int v,int u);

        void BFS(int v);
};

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
    visited[v] = false;
}

void Graph::BFS(int v)
{
    visited[v] = true;
    q.push(v);
    list<int>::iterator i;

    while(!q.empty())
    {
        int s = q.front();
        cout<<s<<" ";
        q.pop();

        for(i = adj[s].begin();i!=adj[s].end();i++)
        {
            if(visited[*i] == false)
            {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
}

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}