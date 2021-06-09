#include<bits/stdc++.h>
using namespace std;

char arr[1001][1001];
bool visited[1001][1001];
int N,M;

bool isValid(int x,int y)
{
    if(x<1 || x>N || y<1 || y>M)
    {
        return false;
    }
    if(visited[x][y] == true || arr[x][y] == '#')
    {
        return false;
    }

    return true;
}

void dfs(int x,int y)
{
    visited[x][y] = true;
    
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
            cin>>arr[i][j];
        }
    }
    int cnt = 0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(visited[i][j] == false and arr[i][j] == '.')
            {
                dfs(i,j);
                cnt++;
                
            }
        }
    }

    cout<<cnt<<endl;
}