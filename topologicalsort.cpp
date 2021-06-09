#include<bits/stdc++.h>
using namespace std;

map<int,list<int>>arr;
vector<int>res;
map<int,int>in;

void addEdge(int x,int y)
{
    arr[x].push_back(y);
    in[y]++;
}

void kahn(int n)
{
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
        {
            q.push(i);
        }
    }
    list<int>::iterator node;
    while(!q.empty())
    {
        int curr = q.front();
        res.push_back(curr);
        q.pop();
        for(node=arr[curr].begin();node!=arr[curr].end();node++)
        {
            in[*node]--;
            if(in[*node]==0)
            {
                q.push(*node);
            }
        }
    }
    cout<<"Topological Sort: ";
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i];
    }
}

int main()
{
    addEdge(1,2);
    addEdge(1,8);
    addEdge(3,4);
    addEdge(2,9);
    addEdge(2,5);
    addEdge(4,5);
    addEdge(4,8);
    addEdge(5,9);
    addEdge(5,7);
    addEdge(6,7);

    kahn(9);
}