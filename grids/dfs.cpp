#include<bits/stdc++.h>
using namespace std;

int N,M;
bool visited[1001][1001];

bool isValid(int x,int y)
{
    if(x<1 || x>N || y<1 || y>M)
    {
        return false;
    }
    if(visited[x][y] == true)
    {
        return false;
    }

    return true;
}

void dfs(int x,int y)
{
    visited[x][y] = true;

    cout<<x<<" "<<y<<endl;

    if(isValid(x-1,y))
    {
        dfs(x-1,y); //Up
    }
    if(isValid(x,y+1))
    {
        dfs(x,y+1); //Right
    }
    if(isValid(x+1,y))
    {
        dfs(x+1,y); // Down
    }
    if(isValid(x,y-1))
    {
        dfs(x,y-1); //Left
    }
}

int main()
{
    cin>>N>>M;
    dfs(1,1);
}
