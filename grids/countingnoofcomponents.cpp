#include<bits/stdc++.h>
using namespace std;

int arr[1001][1001];
int visited[1001][1001];

bool isValid(int x,int y)
{
    if(x<1 || x>N || y<1 || y>M)
    {
        return false;
    }
    if(visited[x][y] == 1 || arr[x][y] == 0)
    {
        return false;
    }

    return true;
}

void dfs(int x,int y)
{
    visited[x][y] = 1;
    if(isValid(x-1,y))
    {
        dfs(x-1,y);
    }
    if(isValid(x,y+1))
    {
        dfs(x,y+1);
    }
    if(isValid(x+1,y))
    {
        dfs(x+1,y);
    }
    if(isValid(x,y-1))
    {
        dfs(x,y-1);
    }
}

int main()
{   
    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cin>>arr[i];
        }
    }
    int cnt = 0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<M;j++)
        {
            if(visited[i][j] == 0 && arr[x][y] == 1)
            {
                dfs(i,j);
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;
}