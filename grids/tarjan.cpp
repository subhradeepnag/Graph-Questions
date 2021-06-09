#include<bits/stdc++.h>
using namespace std;

vector<int>in;
vector<int>low;
map<int,list<int>>g;
map<int,bool>vis;
map<int,bool>onstack;
stack<int>st;
int timer = 1,SCC=0;

void dfs(int node)
{
    vis[node] = 1;
    in[node] = low[node] = timer++;
    onstack[node] = true;
    st.push(node);

    for(auto it=g[node].begin();it!=g[node].end();it++)
    {
        if((vis[*it] == true) && onstack[*it] == true)
        {
            low[node] = min(low[node],in[*it]);
        }
        else
        {
            if(vis[*it] == false)
            {
                dfs(*it);

                if(onstack[*it] == true)
                {
                    low[node] = min(low[node],low[*it]);
                }
            }
        }
    }

    if(in[node] == low[node])
    {
        SCC++;
        cout<<SCC<<endl;
        int u;
        while(1)
        {
            u = st.top();
            st.pop();
            onstack[u] = false;
            cout<<u;
            if(u == node)
            {
                break;
            }
        }
    }
}

int main()
{
    int n,m,a,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
    {
        vis[i] = onstack[i] = false;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i] == false)
        {
            dfs(i);
        }
    }
}