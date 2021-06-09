#include<bits/stdc++.h>
using namespace std;

int dist[1001][1001];
int visited[1001][1001];
int N,M;

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

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void bfs(int srcx,int srcy)
{
    queue<pair<int,int>>q;
    q.push({srcx,srcy});
    visited[srcx][srcy] = 1;

    while(!q.empty())
    {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            if(isValid(currX + dx[i] , currY + dy[i]))
            {
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                dist[newX][newY] = dist[currX][currY] + 1;
                visited[newX][newY] = 1;
                q.push({newX,newY});
            }
        }


    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    cin>>N>>M;
    bfs(1,1);
}