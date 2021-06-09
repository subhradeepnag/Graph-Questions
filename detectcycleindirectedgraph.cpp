#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V; // No. of vertices
    list<int>*adj; //Pointer to an array containing adjacent
    bool isCyclic(int V,bool visited[],bool *rs); //Used by isCyclicUtil

    public:
    Graph(int V); //Contstructor
    void addEdge(int v,int w); //to add an edge to graph
    bool isCyclic(); //returns true if there is cycle in this graph
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
}

bool Graph::isCyclicUtil(int v, bool visited[]bool *recStack)
{
    if(visited[v] == false)
    {
        //Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;

        //Recur for all the vertices adjacent to this vertex 
        list<int>::iterator i;
        for(int i = adj[v].begin();i!= adj[v].end();++i)
        {
            if(!visited[*i] && isCyclicUtil(*i,visited,recStack))
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

bool Graph::isCyclic()
{
    //Mark all vertices as not visited and not part of recurrsion stack

    bool *visited = new bool[V];
    bool *recStack  = new bool[V];

    for(int i=0;i<V;i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    //Call the recursive helper function to detect different DFS trees

    for(int i=0;i<V;i++)
    {
        if(isCyclicUtil(i,visited,recStack))
        {
            return true;
        }

        return false;
    }

}

int main()
{
    //Create a grpah given in the above figure

    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);

    if(g.isCyclic())
    {
        cout<<"Graph contains cycle";
    }
    else
    {
        cout<<"Graph doesn't contain cycle";
    }

    return 0;
    
}