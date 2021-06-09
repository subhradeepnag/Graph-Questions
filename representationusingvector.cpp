#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
        map<int,bool>visited;
        map<int,list<int>>adj;

        void addEdge(int v,int w);

        void print();
};

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::print()
{
    list<int>::iterator it;

    for(auto i:adj)
    {
        for(it=adj[i.first].begin();it!=adj[i.first].end();it++)
        {
            cout<<i.first<<" "<<(*it)<<endl;
        }
    }
}


int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.print();
}