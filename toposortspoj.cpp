#include<bits/stdc++.h>
using namespace std;

map<int,list<int>>adj;
map<int,int>in;
vector<int>res;

bool addEdge(int x,int y)
{
    adj[x].push_back(y);
    in[y]++;
}

void kahn(int n)
{
    priority_queue<int,vector<int>,greater<int>>pq;

    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
        {
            pq.push(i);
        }
    }
    list<int>::iterator it;
    while(!pq.empty())
    {
        int curr = pq.top();
        res.push_back(curr);
        pq.pop();

        for(it=adj[curr].begin();it!=adj[curr].end();it++)
        {
            in[*it]--;
            if(in[*it] == 0)
            {
                pq.push(*it);
            }
        }
    }

    return res.size()==n;
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        addEdge(x,y);
    }
    if(!kahn(n))
    {
        cout<<"Sandro fails,";
    }
    else
    {
        for(int i=1;i<=res.size();i++)
        {
            cout<<i<<" ";
        }
    }
}