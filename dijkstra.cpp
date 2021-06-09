#include<bits/stdc++.h>
using namespace std;

map<int,list<pair<int,int>>>adj;

int main()
{
    int n,m,a,b,w;
    cin>>n>>m;

    while(m--)
    {
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    vector<int>dist(n+1,INT_MAX);
    pq.push({0,1});
    dist[1] = 0;

    while(!pq.empty())
    {
        int curr = pq.top().second;
        int curr_d = pq.top().first;
        // cout<<curr<<" "<<curr_d<<endl;
        pq.pop();

        for(auto it = adj[curr].begin();it!=adj[curr].end();it++)
        {
            if((curr_d + it->second) < dist[it->first])
            {
                dist[it->first] = curr_d + it->second;
                // cout<<dist[it->first]<<" ";
                pq.push({dist[it->first],it->first});
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    
}

// I/P-
// 6 9
// 1 2 4
// 1 6 2
// 2 3 5
// 2 6 1
// 6 3 8
// 6 5 10
// 3 4 6 
// 3 5 3
// 5 4 5
// Output
// 0 3 8 14 11 2 


▲
