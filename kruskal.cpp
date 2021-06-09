#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int a;
    int b;
    int w;
};

edge arr[100000];
int par[100000];

bool comp(edge a, edge b)
{
    if(a.w < b.w)
    {
        return true;
    }

    return false;
}

int find(int a)
{
    if(par[a] == -1)
    {
        return a;
    }

    return par[a] = find(par[a]);
}

void merge(int a,int b)
{
    par[a] = b;
}

int main()
{
    int n,m,a,b;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        par[i] = -1;
    }

    for(int i=0;i<m;i++)
    {
        cin>>arr[i].a>>arr[i].b>>arr[i].w;
    }

    int sum = 0;

    sort(arr,arr+m,comp);

    for(int i=0;i<m;i++)
    {
        a = find(arr[i].a);
        b = find(arr[i].b);

        if(a!=b)
        {
            sum+=arr[i].w;
            merge(a,b);
        }
    }

    cout<<sum<<endl;


}